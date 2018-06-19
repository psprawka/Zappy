
import Player.player as pl
import sys
import time
import signal

host = "localhost"
option_n = False
n_value = ""
option_p = False
p_value = 4242
option_g = False
freq = 0.001

if (len(sys.argv) < 5):
    sys.stderr.write("Usage: " + sys.argv[0] + " -p PORT -n TEAM_NAME [ -h HOST ]\n")
    sys.exit(1)
else:
    i = 1
    while (i < len(sys.argv)):
        if (sys.argv[i] == "-n" and i + 1 < len(sys.argv)):
            option_n = True
            i += 1
            n_value = sys.argv[i]
        elif (sys.argv[i] == "-p" and i + 1 < len(sys.argv)):
            option_p = True
            i += 1
            try:
                p_value = int(sys.argv[i])
            except:
                p_value = 4242
        elif (sys.argv[i] == "-h" and i + 1 < len(sys.argv)):
            i += 1
            host = sys.argv[i]
        elif (sys.argv[i] == "-t" and i + 1 < len(sys.argv)):
            i += 1
            try:
                freq = float(sys.argv[i])
            except:
                freq = 0.001
        elif (sys.argv[i] == "-g" or sys.argv[i] == "-graphic"):
            option_g = True
        i += 1
                
if (option_p == False or option_n == False):
    sys.stderr.write ("Usage: " + sys.argv[0] + " -p PORT -n TEAM_NAME [ -h HOST ]\n")
    sys.exit(1)

playerList = []
playerList.append(pl.Player(n_value, host, p_value, option_g, freq, "pilierRadar"))

# Ne pas changer option_g
option_g = False

def count_role(playerList, role):
    nb = 0
    for player in playerList:
        if (player.role == role and player.dead != True):
            nb += 1
    return (nb)

def invoque(playerList, role):
    new_player = pl.Player(n_value, host, p_value, option_g, freq, role)
    new_player.start()
    time.sleep(0.2)
    if (new_player.cli.connected):
        playerList.append(new_player)
        return (True)
    else:
        del new_player
        return (False)

try:
    AnyAlive = True
    playerList[0].start()
    time.sleep(1)
    if (playerList[0].dead == True):
        sys.stderr.write("Bad team name or no slot available\n")
        sys.exit(0)
    playerList[0].egg_fork()
    size = playerList[0].max_x * playerList[0].max_y
    
    print ("size: " + str(size))
    while (AnyAlive):
        AnyAlive = False
        for player in playerList:
            if (player.cli.dead == False):
                AnyAlive = True
            else:
                player.dead = True
                player.cli.close_connect()
                playerList.remove(player)
                
        if (count_role(playerList, "pilierRadar") == 0):
            invoque(playerList, "pilierRadar")
        elif (count_role(playerList, "muleNourriture") < (1 + (size / 20))):
            invoque(playerList, "muleNourriture")
        elif (count_role(playerList, "mulePierre") < 1 + (size / 10)):
            invoque(playerList, "mulePierre")
        elif (count_role(playerList, "superSaiyan") < 12):
            invoque(playerList, "superSaiyan")
        elif (count_role(playerList, "guerrier") < (1 + (size / 100))):
            invoque(playerList, "guerrier")
        else:
            invoque(playerList, "haricotMagique")
        if (AnyAlive == False):
            if (invoque(playerList, "pilierRadar") == True):
                AnyAlive = True
            
except KeyboardInterrupt:
    pass
finally:
    try:
        if (playerList[0].graphic == True):
            playerList[0].wind.initState = False
            playerList[0].wind.join()
    except:
        pass
    for player in playerList:
        try:
            player.dead = True
            player.cli.close_connect()
        except:
            pass
    for player in playerList:
        player.join()

