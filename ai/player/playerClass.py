# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    player.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/26 20:33:46 by tle-huu-          #+#    #+#              #
#    Updated: 2018/05/26 20:44:26 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# 	=========================================================================
#	Player Class is the body of the player ==> all the actions and listening
# 	to the Server thanks to the Client Object (See Client Class)
# 	=========================================================================



import sys
import random
import time
import subprocess
from client.clientClass import Client
from threading import Thread , Lock
import threading

import os

tty = os.open("/dev/ttys004", os.O_RDWR)
tty2 = os.open("/dev/ttys005", os.O_RDWR)

g_ressources = {
	"food":			9,
	"linemate":		0,
	"deraumere":	0,
	"sibur":		0,
	"mendiane":		0,
	"phiras":		0,
	"thystame":		0,
}


g_tolevel2 = {
	"nb_players":	1,
	"linemate":		1,
	"deraumere":	0,
	"sibur":		0,
	"mendiane":		0,
	"phiras":		0,
	"thystame":		0,
}
g_tolevel3 = {
	"nb_players":	2,
	"linemate":		1,
	"deraumere":	1,
	"sibur":		1,
	"mendiane":		0,
	"phiras":		0,
	"thystame":		0,
}
g_tolevel4 = {
	"nb_players":	2,
	"linemate":		2,
	"deraumere":	0,
	"sibur":		1,
	"mendiane":		0,
	"phiras":		2,
	"thystame":		0,
}
g_tolevel5 = {
	"nb_players":	4,
	"linemate":		1,
	"deraumere":	1,
	"sibur":		2,
	"mendiane":		0,
	"phiras":		1,
	"thystame":		0,
}
g_tolevel6 = {
	"nb_players":	4,
	"linemate":		1,
	"deraumere":	2,
	"sibur":		1,
	"mendiane":		3,
	"phiras":		0,
	"thystame":		0,
},

g_tolevel7 = {
	"nb_players":	6,
	"linemate":		1,
	"deraumere":	2,
	"sibur":		3,
	"mendiane":		0,
	"phiras":		1,
	"thystame":		0,
}
g_tolevel8 = {
	"nb_players":	6,
	"linemate":		2,
	"deraumere":	2,
	"sibur":		2,
	"mendiane":		2,
	"phiras":		2,
	"thystame":		1,
}

g_prerequisites = [g_tolevel2, g_tolevel3, g_tolevel4, g_tolevel5, g_tolevel6,
				g_tolevel7, g_tolevel8]

def init_vision(max_level):
	nbr = 0
	vision = []
	for k in range(1, max_level + 1):
		nbr += 1 + 2*k
	for k in range(nbr):
		vision.append({})
	return (vision)

def clear_vision(vision):
	for i in range(len(vision)):
		vision[i].clear()


class Player(Thread):

	def __init__(self, team_name, ip, port, character):
		self.max_level = 8
		self.team_name = team_name
		self.inventory = g_ressources
		self.levelup_prerequisite = g_prerequisites
		self.map_dim = (0,0)
		self.direction = (1 << random.randint(0, 3))
		self.nb_client = 0
		self.unused_connection = 0
		self.vision = init_vision(8)
		self.vision_uptodate = False
		self.cli = Client(ip, port, team_name)
		self.last_op_state = False
		self.character = character

# 	=========================================================================
#	GETTERS
# 	=========================================================================

	def get_prerequisite(self):
		return self.levelup_prerequisite[self.cli.level - 1]

# 	=========================================================================
#	Connecting Client to the Server
# 	=========================================================================
	def connect(self):
		self.cli.connect()

# 	=========================================================================
#	Dying => Disconnect Socket
# 	=========================================================================
	def die(self):
		self.cli.alive = False
		self.cli.connected = False
		self.cli.disconnect()
		print("A {} of the team ".format(self.character) + self.team_name + " has died.\n")

# 	=========================================================================
#	LIVE ====> Receive first messages from server, if c = 0, dying...
# 	=========================================================================
	def read_welcome(self):
		# self.cli.get_message(self.cli.socket)
		self.cli.event_listener()
		message = self.cli.answers.pop(0)
		if (message != "WELCOME" and message != "BIENVENUE"):
			print("Not welcomed")
			self.cli.alive = False
		else:
			self.cli.alive = True


	def read_nb_client(self):
		try:
			# self.cli.get_message(self.cli.socket)
			self.cli.event_listener()
			message = self.cli.answers.pop(0)
			tmp = message
			message = int(message)
			if not message:
				self.cli.alive = False
				return False
			self.nb_client = message
		except Exception as e:
			sys.stderr.write("Nb_client Wrong Format (not integer): |{}|\n".format(tmp))
			self.cli.alive = False
			self.die()
			return False
		return True

	def read_map_dim(self):
		# self.cli.get_message(self.cli.socket)
		os.write(tty2, "coucou map dim\n".encode())
		self.cli.event_listener()
		message = self.cli.answers.pop(0).strip().split(' ')
		if len(message) > 2:
			sys.stderr.write("Map Size Wrong Format (Too many arguments)\n")
			self.die()
			return False
		try:
			x = int(message[0])
			y = int(message[1])
			self.map_dim = (x, y)
		except Exception as e:
			sys.stderr.write("Map Size Wrong Format (not integers)\n")
			self.die()
			return False
		return True

	def live(self):
		message = ''
		x = 0
		y = 0
		if (not self.cli.connected):
			self.die()
			return False
		self.read_welcome()
		if not self.cli.connected or not self.cli.alive or not self.cli.send_message(self.team_name + "\n"):
			self.die()
			return False
		if not self.read_nb_client() or not self.read_map_dim():
			return False
		os.write(tty2, "here\n".encode())
		return (self.cli.connected and self.cli.alive)

	def get_msg(self):

		# Deprecated but should replace self.cli.answers.pop(0)

		try:
			self.cli.get_message(self.cli.socket)
		except Exception as e:
			sys.stderr.write("get message Error {}\n".format(e))
			return False
		return True

# 	=========================================================================
#	Broadcast
# 	=========================================================================
	def broadcast(self, text):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("A {} is broadcasting {}".format(self.character, text))
		if not self.cli.send_message("broadcast " + text):
			sys.stderr.write("Broadcast failed\n")
		self.cli.event_listener()
		self.last_op_state = self.cli.answers.pop(0)

# 	=========================================================================
#	Turn Right // Turn Left
# 	=========================================================================
	def turn_right(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		self.cli.send_message("right\n")
		# self.cli.send_message("droite\n")
		print("A {} is turning right".format(self.character))
		self.cli.last_action = "right"
		self.cli.event_listener()
		self.last_op_state = self.cli.answers.pop(0)
		self.vsion_uptodate = False

	def turn_left(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("A {} is turning left".format(self.character))
		# self.cli.send_message("gauche\n")
		self.cli.send_message("left\n")
		self.cli.last_action = "left"
		self.cli.event_listener()

		self.last_op_state = self.cli.answers.pop(0)
		self.vsion_uptodate = False

# 	=========================================================================
#	Advance
# 	=========================================================================
	def advance(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("A {} advances\n".format(self.character))
		# self.cli.send_message("avance\n")
		self.cli.send_message("advance\n")
		self.cli.last_action = "advance"
		self.cli.event_listener()

		self.last_op_state = self.cli.answers.pop(0)
		self.vision_uptodate = False

# 	=========================================================================
#	Take an Object
# 	=========================================================================
	def pick_up(self, stone):
		sys.stdout.write("Thread numbre [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("Trying to pick up {}".format(stone))
		# self.cli.send_message("prend " + stone + "\n")
		self.cli.send_message("take " + stone + "\n")
		self.cli.last_action = "pickup"
		self.cli.event_listener()

		if self.cli.answers.pop(0) == "ok":
			print("I am picking up Food !")
			self.last_op_state = True
			self.inventory[stone] += 1
		else:
			self.last_op_state = False
			sys.stderr.write("Pick up " + stone + " failed.\n")

# 	=========================================================================
#	Drop an Object
# 	=========================================================================
	def drop(self, stone):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("I drop a {}".format(stone))
		self.cli.send_message("put " + stone + "\n")
		# self.cli.send_message("pose " + stone + "\n")
		self.cli.last_action = "drop"
		self.cli.event_listener()

		if self.cli.answers.pop(0) == "ok":
			self.last_op_state = True
			self.inventory[stone] -= 1
		else:
			self.last_op_state = False
			sys.stderr.write("Pick up " + stone + " failed.\n")


# 	=========================================================================
#	KICK
# 	=========================================================================
	def kick(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("I Kick")
		self.cli.send_message("kick\n")
		self.cli.last_action = "kick"
		self.cli.event_listener()

		if self.cli.answers.pop(0) == "ok":
			self.last_op_state = True
		else:
			self.last_op_state = False

# 	=========================================================================
#	Number of conections possible
# 	=========================================================================
	def connect_nbr(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("Getting unused connection number")
		self.cli.send_message("connect_nbr\n")
		self.cli.last_action = "connect_nbr"
		self.cli.event_listener()
		try:
			self.connect_nbr = int(self.cli.answers.pop(0))
		except Exception as e:
			sys.stderr.write("Getting unused connection number failed : {}\n".format(e))

# 	=========================================================================
#	SEE
# 	=========================================================================

	def see(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("A {} look around dude...".format(self.character))
		# self.cli.send_message("voir\n")
		self.cli.send_message("see\n")
		self.cli.last_action = "see"

		self.cli.event_listener()

		message = self.cli.answers.pop(0).strip("}{").split(',')
		clear_vision(self.vision)
		for i in range(len(message)):
			square = message[i].strip().split(' ')
			for ressources in square:
				ressources = ressources.strip()
				if ressources in self.vision[i]:
					self.vision[i][ressources] += 1
				else:
					self.vision[i][ressources] = 1
		# print(self.vision)
		self.vision_uptodate = True

# 	=========================================================================
#	Get Inventory
# 	=========================================================================
	def peek_inventory(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("A {} is Peeking his inventory".format(self.character))
		self.cli.send_message("inventory\n")
		# self.cli.send_message("inventaire\n")
		self.cli.last_action = "inventory"
		self.cli.event_listener()

		message = self.cli.answers.pop(0)
		message = message.strip("}{").split(',')
		for ressource in message:
			ressource = ressource.strip(' ').split(' ')
			try:
				self.inventory[ressource[0]] = int(ressource[1])
			except Exception as e:
				print(ressource)
				sys.stderr.write("Inventory Error: {}\n".format(e))
				self.inventory[ressource[0]] = 0

# 	=========================================================================
#	Fork (Lay An Egg)
# 	=========================================================================
	def lay_egg(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		sys.stdout.write("Forking ...\n".format(threading.get_ident()))
		self.cli.send_message("fork\n")
		self.cli.last_action = "fork"
		self.cli.event_listener()

		message = self.cli.answers.pop(0)

# 	=========================================================================
#	Start An Incantation
# 	=========================================================================
	def incantation(self):
		sys.stdout.write("Thread number [\033[1;34;40m{}\033[1;0;40m] || ".format(threading.get_ident()))
		print("HOUGA HOUGA HOUGA HOUGA HOUGA")
		print("Level before incantation : {}".format(self.cli.level))
		self.cli.last_action = "incantation"
		self.cli.send_message("incantation\n")
		self.cli.event_listener()
		self.last_op_state = not not self.cli.answers.pop(0)
		self.cli.event_listener()
		print("Level after incantation : {}".format(self.cli.level))
