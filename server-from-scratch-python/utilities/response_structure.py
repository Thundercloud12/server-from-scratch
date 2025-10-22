def builder(client_socket, client_address):
    body = "<html>Chal be pract kelie kaun padega??</html>"
    response = (
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        f"Content-Length: {len(body)}\r\n"
        "\r\n"
        f"{body}"
    )

    return response