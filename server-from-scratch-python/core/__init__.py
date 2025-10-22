
def __init__(self, client_socket, client_address):
    super().__init__()
    self.client_socket = client_socket
    self.client_address = client_address
