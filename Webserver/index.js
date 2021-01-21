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
    let doneBefore = false;
    console.log(message);
    int++;
    for (let i = 0; i < int; i++) {
      fs.readFile('./' + i.toString() + '.control', function (err, data) {
        if (data.toString().contains(message.toString())) {
          doneBefore = true;
        }
      })
    }
    if (!doneBefore) {
    fs.writeFile(int.toString() + '.control', message.toString(), function (err) {
      if (err) throw err;
    });
  }
  });
});


