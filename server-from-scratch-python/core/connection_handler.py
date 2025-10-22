import socket
import threading
from utilities.response_structure import builder

class ConnectionHandler(threading.Thread):
    def __init__(self, client_socket, client_address):
        super().__init__()
        self.client_socket = client_socket
        self.client_address = client_address

    def run(self):
        try:
            request_data = self.client_socket.recv(1024).decode("utf-8")
            print(f"Received request from {self.client_address}: \n {request_data}")
            response = builder(self.client_socket, self.client_address)
            self.client_socket.sendall(response.encode("utf-8"))
        except Exception as e:
            print(f"{e}")
        finally:
            self.client_socket.close()