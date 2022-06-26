import socket

s = socket.socket()

port = 6666

s.connect(('192.168.56.107', port))

data = s.recv(1024)

s.send(b'Hi, saya client. Terima Kasih!');

print (data)

s.close()
