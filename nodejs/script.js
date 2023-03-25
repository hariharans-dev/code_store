const http = require('http');
http.createServer(function (req, res) {
  res.write("<h1>welcome to this beautiful world</h1>")
  res.end("<br>thanks")
}).listen(8000);