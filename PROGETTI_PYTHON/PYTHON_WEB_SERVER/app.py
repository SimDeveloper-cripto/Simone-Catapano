from http.server import HTTPServer, BaseHTTPRequestHandler

_PORT = 8080

class Serv(BaseHTTPRequestHandler):

    def do_GET(self):
        _PORT = 8080

        # ALLA CONNESSIONE VERRA' MOSTRATA LA PAGINA PRINCIPALE 'index.html'
        if self.path == '/':
            self.path = '/index.html'
                  
        try:
            file_to_open = open(self.path[1:]).read()
            self.send_response(200)
        except: 
            file_to_open = "FILE NON TROVATO!"
            self.send_response(404)
        self.end_headers()
        self.wfile.write(bytes(file_to_open, 'utf-8'))

httpd = HTTPServer(('localhost',8080), Serv)
print("SERVER LOCALE ATTIVO SULLA PORTA:  http://%s:%s" % ("127.0.0.1",_PORT))
httpd.serve_forever()