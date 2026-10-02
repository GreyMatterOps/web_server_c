import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect(("127.0.0.1", 9000))

print("Connected")

data = s.recv(1024)
print("Received:", data.decode())

s.close()