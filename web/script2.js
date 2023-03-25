const http = require('http');
const path =require('path');
var fs=require('fs');
http.createServer(function(req,res){
    res.write("<h1>hello world</h1>");
    res.write("Welcome<br>");
    res.write("good bye<br>");
    res.end("thanks");
}).listen(8000);