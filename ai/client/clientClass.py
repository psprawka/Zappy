# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    clientClass.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 13:58:01 by tle-huu-          #+#    #+#              #
#    Updated: 2018/06/05 13:58:03 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import socket
import sys
import threading
import select
import time
from threading import Thread, Lock
import os

tty = os.open("/dev/ttys005", os.O_RDWR)
tty2 = os.open("/dev/ttys004", os.O_RDWR)

os.dup2(tty2, 2)

g_messages_dict = {
		"nicknick":			-1,
		"coming":			-1,
		"kwame":			-1,
		"enemy":			-1
}

class Client:

	def __init__(self, ip, port, team_name):
		# Thread.__init__(self)
		self.ip = ip
		self.port = port
		self.team_name = team_name
		self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.level = 1
		# self.mutex = Lock()
		self.connected = False
		self.welcomed = False
		self.alive = True
		self.last_action = ''
		self.messages = g_messages_dict
		self.answers = []

	def connect(self):
		# print("Client {} - {} - {} - {}".format(self.ip, self.port, self.team_name, self.socket))
		try:
			self.socket.connect((self.ip, self.port))
			self.connected = True
			# self.send_message("Hi Paulina call me maybe: -->{} <---".format(self.team_name).encode())
			os.write(tty, "Successfully connected\n".encode())
		except Exception as e:
			sys.stderr.write("Connection Error: {}\n".format(e))

	def disconnect(self):
		self.connected = False
		self.alive = False
		try:
			self.socket.close()
			return True
		except Exception as e:
			sys.stderr.write("Disconnect Error: {}\n".format(e))
			return False

	def send_message(self, message):
		print("Sending")
		if self.connected:
			try:
				os.write(tty, "[\033[1;36;40m{}\033[1;0;40m] \033[1;37;40mSending\033[1;0;40m [{}]\n".format(threading.get_ident(), message.strip()).encode())
				self.socket.sendall(message.encode())
			except Exception as e:
				sys.stderr.write("Sending Message Error: {}\n".format(e))
				return False
		else:
			self.disconnect()
			return False
		return True

# 	=========================================================================
#	Get message and Parse it, should be in two functions ... I know
# 	=========================================================================
	def parse_message(self, message):
		try:
			k = message[8:9]
			text = message[10:]
			if text.count("NICK NICK ") and text[len("NICK NICK "):] == self.team_name:
				self.messages["nicknick"] = int(k)
			elif text.count("COMING ") and text[len("COMING "):] == self.team_name:
				self.messages["coming"] = int(k)
			elif text.count("KWAME ") and text[len("KWAME "):] == self.team_name:
				self.messages["kwame"] = int(k)
			else:
				self.messages["enemy"] = int(k)
		except:
			os.write(tty, "Broadcast message broken WHERE YOU THINK YOU GOING BABY".encode())

	def get_message(self, fd):
		message = ''
		try:
			message = fd.recv(1).decode()
			if not message:
				return False
			while message[-1] != "\n":
				message += fd.recv(1).decode()
			message = message.strip()
			if message.strip('\n') in ["ok", "ko"]:
				os.write(tty, "Server said :({}) [\033[1;36;40m{}\033[1;0;40m] [\033[1;35;40m{}\033[1;0;40m]-->\033[1;31;40m{}\033[1;0;40m<--\n".format(self.socket.fileno(), threading.get_ident(), self.last_action, message.strip("\n")).encode());
			else:
				os.write(tty, "Server said :({})[\033[1;36;40m{}\033[1;0;40m] [\033[1;35;40m{}\033[1;0;40m]-->\033[1;32;40m{}\033[1;0;40m<--\n".format(self.socket.fileno(), threading.get_ident(), self.last_action, message.strip("\n")).encode());
			if message == "WELCOME" or message == "BIENVENUE":
				self.welcomed = True
				self.answers.append(message)
			elif message.count("message"):
				self.parse_message(message)
			elif message.count("current level : ") or message.count("niveau actuel : "):
				old = self.level
				self.level = int(message[-1])
				print("New level for team " + self.team_name + ": " + str(old) + " => " + str(self.level) + "\n")
			elif message == "death" or message == "mort":
				os.write(tty, "DEATH\n".encode())
				self.alive = False
				self.disconnect()
			else:
				self.answers.append(message)
			return True
		except Exception as e:
			sys.stderr.write("Client get_message [DYING] Error: {}\n".format(e))
			self.connected = False
			self.alive = False
			return False

# 	=========================================================================
#	Main Event Listener
# 	=========================================================================

	def event_listener(self):
		inputs, output, errors = [self.socket], [], []
		try:
			print("Block here : {} {} {}".format(self.connected, self.alive, len(self.answers)))
			while self.connected and self.alive and not len(self.answers):
				readable, writable, error = select.select(inputs, output, errors)
				if not readable:
					os.write(tty, "-->\033[1;31;40m BIG ERROR BIG ERROR BIG ERROR\033[1;0;40m<--\n".encode());
					return True
				self.get_message(readable[0])
		except Exception as e:
			sys.stderr.write("Event listener (Player Dead): {}\n".format(e))
			self.connected = False
			self.alive = False
		return True
