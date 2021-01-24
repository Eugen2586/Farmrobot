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
  let nopcounter = 1;
  ws.on('message', function incoming(message) {
    if(message == 'nop'){
      console.log(nopcounter);
      nopcounter++;
      return;
    }
    console.log(message);
    int++;
    console.log(new Date().toJSON().toString());
    fs.writeFile(int.toString() + '.control', message.toString(), function (err) {
    if (err) throw err;
    });
  });
});


