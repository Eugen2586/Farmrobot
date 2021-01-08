const WebSocket = require('ws');
const fs = require('fs');

const wss = new WebSocket.Server({ port: 9010});
var int = 0;
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
    console.log('received: %s', message);
    var obj = JSON.parse(message)
    fs.writeFile( int + 'form.dat', message, function (err) {
      if (err) throw err;
    });
    fs.writeFile( obj.Firma + obj.Ansprechpartner + ".res", message, function (err) {
      if (err) throw err;
    });
  });

});


