import socket
import sys

hote = "localhost"
if sys.argv[1]:
	hote = sys.argv[1]
port = int(sys.argv[2])

print(hote)

connexion_avec_serveur = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
	connexion_avec_serveur.connect((hote, port))
except Exception as e:
	sys.stderr.write("Salut terence {}\n".format(e))
print("Connexion établie avec le serveur sur le port {}".format(port))

msg_a_envoyer = b""
while msg_a_envoyer != b"fin":
    msg_a_envoyer = input("> ")
    # Peut planter si vous tapez des caractères spéciaux
    msg_a_envoyer = msg_a_envoyer.encode()
    # On envoie le message
    connexion_avec_serveur.send(msg_a_envoyer)
    msg_recu = connexion_avec_serveur.recv(1024)
    print(msg_recu.decode()) # Là encore, peut planter s'il y a des accents

print("Fermeture de la connexion")
connexion_avec_serveur.close()
