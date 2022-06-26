import socket
import sys

# Lets catch the 1st argument as server ip
if (len(sys.argv) > 1):
    ServerIp = sys.argv[1]
else:
    print("\nRun like \n python3 clientStore.py < server ip address > \n\n")
    exit(1)


# Now we can create socket object
s = socket.socket()

# Lets choose one port and connect to that port
PORT = 9898

# Lets connect to that port where server may be running
s.connect((ServerIp, PORT))

# We can send any file by typing its name including the extension (example: boi.c)
filetosend = input('\nEnter the file name to be stored in server: ')
s.send(filetosend.encode())
file = open(filetosend, "rb")

SendData = file.read(99999)

while SendData:
    # Now we can receive data from server
    print("\n>Message received from the server:", s.recv(1024).decode("utf-8"))
    #Now send the content of the file to server
    s.send(SendData)
    SendData = file.read(99999)
    print(">" + filetosend + " has been copied successfully to the server for storage.\n")

# Close the connection from client side
s.close()
