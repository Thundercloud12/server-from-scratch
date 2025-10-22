import socket
from .connection_handler import ConnectionHandler

def run_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("127.0.0.1", 8080))
    server_socket.listen(5)
    print("🚀 Server listening on http://127.0.0.1:8080")

    while True:
        client_socket, client_address = server_socket.accept()
        handler = ConnectionHandler(client_socket, client_address)
        handler.start()


