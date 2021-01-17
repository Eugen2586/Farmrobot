const WebSocket = require('ws');
const fs = require('fs');

const wss = new WebSocket.Server({ port: 9010});
let int = 0;
wss.on('connection', function connection(ws) {
  let plants = " ";
  console.log("New Connection");
  const fs = require('fs');
  //Sendet die Pflanzendaten an das Frontend
  fs.readFile('./pflanzenarten.plant', function read(err, data) {
    if (err) {throw err;}
    plants = data.toString();
    ws.send(plants);
  });
  ws.on('message', function incoming(message) {
    console.log(message);
    int++;
    fs.writeFile( int.toString() + '.control', message, function (err) {
      if (err) throw err;
    });
  });

});


