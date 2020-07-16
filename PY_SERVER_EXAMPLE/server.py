from http.server import BaseHTTPRequestHandler, HTTPServer
import time

_SERVER = "localhost"
_PORT = 4242

class MyServer(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(bytes("<html><head><title>WEB SERVER IN PYTHON</title></head>", "utf-8"))
        self.wfile.write(bytes("<body>", "utf-8"))
        self.wfile.write(bytes("<p> WELCOME TO THE WEB SERVER! </p>", "utf-8"))
        self.wfile.write(bytes("</body></html>", "utf-8"))

if __name__ == "__main__":        
    W_Server = HTTPServer((_SERVER, _PORT), MyServer)
    print("SERVER ATTIVO:  http://%s:%s" % (_SERVER, _PORT))

    try:
        W_Server.serve_forever()
    except KeyboardInterrupt:
        pass

    W_Server.server_close()
    print("SERVER NON ATTIVO.")



