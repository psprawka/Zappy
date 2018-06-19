# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    AiClass.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 13:57:45 by tle-huu-          #+#    #+#              #
#    Updated: 2018/06/05 13:57:47 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


import random
import sys
import os
from threading import Thread , Lock
import threading
import time
from player.playerClass import Player

tty = os.open("/dev/ttys005", os.O_RDWR)

def calc_max_pos(n):
	return (n*n + 2*n)

class Ai(Thread):

	def __init__(self, team_name, ip, port, character):
		Thread.__init__(self)
		self.team_name = team_name
		self.player = Player(team_name, ip, port, character)
		self.max_position = 3 ## n^2 + 2n
		self.character = character
		self.aqueue = []
		self.current_role = "get_food"
		self.last_action_state = False
		self.check_food = 15
		self.ready_to_levelup = False
		self.alltogether = False
		self.elevating = False


####################################################################################################
# !!!!!!!!!!!!!!!! DEPRECATED DEPRECATED !!!!!!!!!!!!!!!!!!!!!
####################################################################################################
	def add_action(self, action):
		print("Addin action : {} to queue".format(action))
		self.aqueue.append(action)
####################################################################################################
# !!!!!!!!!!!!!!!! DEPRECATED DEPRECATED !!!!!!!!!!!!!!!!!!!!!
####################################################################################################

# 	=========================================================================
#	Send Broadcast Wrapper
# 	=========================================================================
	def send_broadcast(self, message):
		self.player.broadcast(message + " {}\n".format(self.team_name))


# 	=========================================================================
#	Movements
# 	=========================================================================

	def move(self, position):
		self.last_op_name = 'move'
		self.vision_uptodate = False
		print("move to {}".format(position))
		if position < 0:
			direction = random.randint(0,2)
			self.vision_uptodate = False
			if direction == 0:
				self.player.advance()
			elif direction == 1:
				self.player.turn_right()
			elif direction == 2:
				self.player.turn_left()
		elif position <= self.max_position:
			self.go_to_position(position)
		else:
			sys.stderr.write("Move failed, don't see position.. moving forward\n")
			self.player.advance()

	def go_to_position(self, position):
		print("go to postion v2")
		if (position > self.max_position):
			sys.stderr.write("Go to position failed\n")
			return False
		if position == 0:
			return True
		turn = 0
		n = 1
		maxpos = 3
		while position > maxpos:
			n += 1
			maxpos = calc_max_pos(n)
		turn = position - (maxpos - n)
		for i in range(n):
			self.player.advance()
		if turn > 0:
			self.player.turn_right()
		elif turn < 0:
			self.player.turn_left()
		else:
			return True
		for i in range(abs(turn)):
			self.player.advance()
		return True

	def go_to_broadcast(self, key):
		square = self.player.cli.messages[key]
		print("\ngo_to_broadcast... {}\n".format(square))
		if square < 0 or square > 8:
			# self.player.advance()
			return True
		if not square:
			return True
		if square in [2, 3, 4]:
			self.player.turn_left()
		elif square in [6, 7, 8]:
			self.player.turn_right()
		elif square == 5:
			self.player.turn_right()
			self.player.turn_right()
		self.player.advance()
		if square in [2, 6]:
			self.player.turn_right()
			self.player.advance()
		elif square in [4, 8]:
			self.player.turn_left()
			self.player.advance()
		self.player.cli.messages[key] = -1
		return True

# 	=========================================================================
#	Look for objet in face of the player
# 	=========================================================================

	def search_object(self, vision, objet):
		print("Searching object [{}]...".format(objet))
		self.last_op_name = 'search_object'
		for i in range(0, self.max_position + 1):
			sys.stdout.write("vision [{}] :".format(i))
			print(vision[i])
			if objet in vision[i] and vision[i][objet] > 0:
				print("Object seen in {}".format(i))
				return (i)
		print("I dont see no {}".format(objet))
		return (-1)

# 	=========================================================================
#	Analyse sound received
# 	=========================================================================

	def assay_sound(self, sound):
		if (sound.count(',')):
			split = sound[8:].split(',')
			sound_from, message = split[0] , split[1]
		else:
			sys.stderr.write("Assay sound: Wrong sound format\n")
			return (False)
		print("Youhou I received : |{}| from |{}|".format(sound_from, message))
		return (True)

# 	=========================================================================
#	Do next action in the actions queue !!!!! DEPRECATED !!!!!!
# 	=========================================================================
	def action(self):
		if not self.check_food:
			self.player.peek_inventory()
			self.check_food = 15
		else:
			try:
				self.aqueue.pop(0)()
				print("JE POP")
				self.check_food -= 1
			except:
				pass

# 	=========================================================================
#	Strategies
# 	=========================================================================

	def get_object(self, objet):
		if objet == "food":
			self.current_role = "get_food"
		self.player.see()
		position = self.search_object(self.player.vision, objet)
		if position != 0:
			self.move(position)
		else:
			self.player.pick_up(objet)
		self.player.peek_inventory()

	def get_stones(self):
		print("Getting stones")
		self.current_role = "get_stones"
		# prerequisite = self.player.levelup_prerequisite[self.player.cli.level - 1]
		prerequisite = self.player.get_prerequisite()
		sys.stdout.write("Prerequisites : ")
		print(prerequisite)
		self.player.peek_inventory()
		self.ready_to_levelup = True
		for stones in self.player.inventory:
			# if stones != "food":
				# print("I need {} of {}\n".format(prerequisite[stones], stones))
			if stones != "food" and self.player.inventory[stones] < prerequisite[stones]:
				objet = stones
				self.ready_to_levelup = False
				break
		if not self.ready_to_levelup:
			print("Look for {}...".format(stones))
			self.get_object(objet)

####################################################################################################
# !!!!!!!!!!!!!!!! DEPRECATED DEPRECATED !!!!!!!!!!!!!!!!!!!!!
####################################################################################################
	def call_friends(self):
		self.current_role = "call_friends"
		nb_player_required = self.player.levelup_prerequisite[self.player.cli.level - 1]["nb_players"]
		self.player.see()
		if self.player.vision[0]["player"] == nb_player_required:
			self.alltogether = True
		else:
			self.broadcast("T" + self.team_name +   "L" + self.player.cli.level)

	def start_incantation(self):
		self.current_role = "start_incantation"
		self.player.incantation()
####################################################################################################
# !!!!!!!!!!!!!!!! DEPRECATED DEPRECATED !!!!!!!!!!!!!!!!!!!!!
####################################################################################################

# 	=========================================================================
#	Roles
# 	=========================================================================

	def mother(self):
		print("Mother")
		self.send_broadcast("NICK NICK")
		self.player.peek_inventory()
		k = 0
		while self.player.inventory["food"] > 7:
			self.get_object("food")
			self.player.peek_inventory()
			self.send_broadcast("NICK NICK")
			self.player.lay_egg()
			self.player.peek_inventory()
		# while (self.player.inventory["food"] > 1):
		# 	self.send_broadcast("NICK NICK")
		# 	if not k:
		# 		self.player.peek_inventory()
		# 	k += 1
		# 	k = k % 10
		self.player.see()
		self.send_broadcast("NICK NICK")

	def follower(self):
		self.player.peek_inventory()
		# while self.player.inventory["food"] < 20:
			# self.get_object("food")
		# sys.exit(1)
		# return True
		while self.player.inventory["food"] > 2:
			# self.player.connect_nbr()s
			self.player.pick_up("food")
			if self.player.cli.messages["nicknick"] == 0:
				self.send_broadcast("COMING")
			else:
				self.go_to_broadcast("nicknick")
			# self.player.connect_nbr()
			# self.player.peek_inventory()

	def stones_seeker(self):
		print("Stone seeker")

		self.player.peek_inventory()

		while self.player.inventory["food"] < 15 and self.player.cli.alive:
			self.get_object("food")
			self.player.peek_inventory()
        #
		# while self.player.inventory["food"] > 10 and not self.ready_to_levelup:
		# 	self.get_stones()
		# 	self.player.peek_inventory()
        #
		# if self.player.cli.level == 1:
		# 	self.player.drop("linemate")
		# 	self.player.incantation()
        #
		# self.send_broadcast("COMING")
        #
		# while self.player.inventory["food"] > 2:
		# 	if not self.player.cli.messages["nicknick"]:
		# 		self.send_broadcast("KWAME")
		# 	else:
		# 		self.go_to_broadcast("nicknick")
		# 	self.player.peek_inventory()
        #
		# self.player.peek_inventory()

		while self.player.inventory["food"] > 10 and self.player.cli.alive and not self.ready_to_levelup:
			self.get_stones()
			self.player.peek_inventory()

		if self.player.cli.level == 1:
			self.player.drop("linemate")
			self.player.incantation()
		if self,player.inventory["food"] > 7:
			self.go_to_broadcast("nicknick")
			self.player.peek_inventory()

        #
		# self.player.see()
		# while self.player.inventory["food"] > 2 and self.player.cli.alive:
		# 	if self.player.cli.messages["nicknick"] > 0:
		# 		self.go_to_broadcast("nicknick")
		# 	if self.player.cli.messages["nicknick"] == 0:
		# 		self.player.drop("linemate")
		# 		self.player.incantation()
		# 	else:
		# 		self.player.see()
		# 		self.go_to_position(self.search_object(self.player.vision, "player"))
		# 	self.player.peek_inventory()


	def food_seeker(self):
		print("Food seeker")

		self.player.peek_inventory()
		while self.player.inventory["food"] < 60:
			self.get_object("food")

		self.player.peek_inventory()

		while self.player.inventory["food"] > 10:
			if not self.player.cli.messages["nicknick"]:
				self.player.drop("food")
			else:
				self.go_to_broadcast("nicknick")
			self.player.peek_inventory()
		self.player.peek_inventory()

	def warrior(self):
		print("Warrior")
		self.player.see()

		while self.player.inventory["food"] < 15:
			self.get_object("food")

		while self.player.inventory["food"] > 5:
			if not self.player.cli.messages["enemy"]:
				self.player.kick()
			elif (self.player.cli.messages["enemy"] != -1):
				self.go_to_broadcast("enemy")
			else:
				self.go_to_broadcast("nicknick")
			self.player.peek_inventory()
		self.player.peek_inventory()
# 	=========================================================================
#	Main Brain
# 	=========================================================================

	def analyse_situation(self):
		print("A {} is Analysing situation... ".format(self.character))


		# self.player.advance()
		# self.player.pick_up("food")
		# self.player.turn_right()
		# self.player.turn_left()
		# self.player.turn_left()
		# self.player.peek_inventory()
		# self.player.kick()
		# self.player.incantation()
		# self.send_broadcast("testzer")
		# self.lay_egg()
		# self.connect_nbr()
		# sys.exit(0)

		if self.player.inventory["food"] < 10:
			self.get_object("food")
		elif self.character == "mother":
			self.mother()
		elif self.character == "follower":
			self.follower()
		elif self.character == "food_seeker":
			self.food_seeker()
		elif self.character == "stones_seeker":
			self.stones_seeker()
		elif self.character == "warrior":
			self.warrior()


		# elif not self.ready_to_levelup:
        #
		# 	# if self.current_role != "get_stones":
		# 	# 	self.aqueue.clear()
		# 	self.get_stones()
        #
		# elif not self.alltogether:
		# 	# print("Come together")
        #
		# 	# if self.current_role != "call_friends":
		# 	# 	self.aqueue.clear()
		# 	# 	self.call_friends()
        #
		# 	if self.elevating:
		# 		return True
		# 	if self.player.inventory["food"] < 5:
		# 		self.get_object("food")
		# 	elif not self.elevating:
		# 		self.elevating = True
		# 		self.player.drop("linemate")
		# 		self.player.incantation()
		# 		self.ready_to_levelup = False
		# 		self.elevating = False
		# else:
		# 	print("Rien")
			# if self.current_role != "start_incantation":
			# 	self.aqueue.clear()
			# 	self.start_incantation()

# 	=========================================================================
#	Main Loop
# 	=========================================================================

	def run(self):
		print("Launching Ai {}...".format(self.character))
		k = 3
		self.player.live()
		while self.player.cli.alive and self.player.cli.connected:
			try:
				self.analyse_situation()
				# self.action()
				# print("Answer : {}".format(self.last_action_answer))
			except Exception as e:
				print("Exception LAUNCH AI (RUN): {}".format(e))
				self.player.cli.alive = False
				pass
			k -= 1
		self.player.die()
