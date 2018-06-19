import sys
import subprocess
import time
import threading
from utils.usage import *
from AI.aiClass import Ai

host = "localhost"
port = None
team_name = None
freq = 1
argc = len(sys.argv)

# 	=========================================================================
#
# 	=========================================================================

if argc < 5:
	usage(sys.argv[0])
	quit()
else:
	argc = len(sys.argv)
	i = 1
	while i < argc:
		if (sys.argv[i] == "-n" and i + 1 < argc):
			i += 1
			team_name = sys.argv[i]
		elif (sys.argv[i] == "-p" and i + 1 < argc):
			i += 1
			try:
				port = int(sys.argv[i])
			except:
				port = 1337
		elif (sys.argv[i] == "-h" and i + 1 < argc):
			i += 1
			host = sys.argv[i]
		elif (sys.argv[i] == "-t" and i + 1 < argc):
			i += 1
			try:
				freq = 1 / int(sys.argv[i])
			except:
				freq = 0.01
		i += 1
if not port or not team_name:
	usage(sys.argv[0])
	sys.exit(0)

# print("{} - {} - {}".format(host,port,team_name))


# 	=========================================================================
#	Main Game Handler
# 	=========================================================================

rolesDict = {
		"mother":			0,
		"stones_seeker":	0,
		"food_seeker":		0,
		"warrior":			0,
		"follower":			0
	}

brainPool = []


# new_ai = Ai(team_name, host, port, "mother")
# new_ai.player.connect()
# new_ai.player.live()
# new_ai.player.advance()
# new_ai.player.turn_right()
# new_ai.player.advance()
# sys.exit(0)

import os

tty = os.open("/dev/ttys000", os.O_RDWR)
# os.write(tty, "++ver")

def invoke_player(brainPool, character):
	os.write(tty ,"[{}]\033[1;35;40mINVOKING PLAYER\033[1;0;40m {}\n".format(threading.get_ident(), character).encode())
	new_ai = Ai(team_name, host, port, character)
	new_ai.player.connect()
	if new_ai.player.cli.connected:
		brainPool.append(new_ai)
		new_ai.start()
		rolesDict[character] += 1
		# new_ai.launch_ai()
		return True
	new_ai.player.die()
	del new_ai
	os.write(tty ,"{} COULD NOT CONNECT".format(character).encode())
	return False

def deads_collector(brainPool):
	deaths = 0
	if len(brainPool) == 0:
		return 0
	for brain in brainPool:
		if not brain.player.cli.alive:
			if rolesDict[brain.character]:
				rolesDict[brain.character] -= 1
			os.write(tty ,"\n Removing body of a {} in {} team\n".format(brain.character, brain.team_name).encode())
			brainPool.remove(brain)
			deaths += 1
	return deaths

try:
	# time.sleep(1)
	invoke_player(brainPool, "mother")

	if deads_collector(brainPool):
		sys.stderr.write("Bad team name or no slot available\n")
		usage(sys.argv[0])
		sys.exit(0)
	os.write(tty ,"brain pool :{}\n".format(len(brainPool)).encode())
	while len(brainPool):
		## try to invoke players
		# time.sleep(freq)
		time.sleep(1)
		os.write(tty, "Looping\n".encode())
		if not rolesDict["mother"]:
			invoke_player(brainPool, "mother")
		elif rolesDict["stones_seeker"] < 5:
			invoke_player(brainPool, "stones_seeker")
		elif rolesDict["food_seeker"] < 5:
			invoke_player(brainPool, "food_seeker")
		else:
			invoke_player(brainPool, "warrior")
		deads_collector(brainPool)
except Exception as e:
	sys.stderr.write("Main Game Handler Error: [{}]\n".format(e))
finally:
	for brain in brainPool:
		brain.join()
	os.write(tty, "\nEnding...\n".encode())
