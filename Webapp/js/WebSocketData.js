let pflanzendaten = [];

var msg = {
  type: "befehl"
};

let socket = new WebSocket("ws://localhost:9010");
socket.onopen = function(e) {

};

socket.onmessage = function(event) {
  var str = "";
  str = event.data;
  let found = true;
  while(found){
    try {
      let braket1 = str.indexOf("{", 0);
      let braket2 = str.indexOf("}", 0);
      let strline = str.substr(braket1, braket2 + 1);
      str = str.substr(braket2 + 1, str.length);
      let obj = JSON.parse(strline);
      if(obj.type.toString() === "plantDat"){
        var li = document.createElement("li");
        li.appendChild(document.createTextNode(obj.Sorte));
        let z = document.getElementById("plantdat");
        li.setAttribute("id", obj.Sorte);
        li.setAttribute("style", "list-style: none");
        li.setAttribute("background", "grey");
        pflanzendaten.push(obj);
        li.onclick = function(){
          //hier den Code einsetzen um allgemeine Daten zur Pflanze anzuzeigen.
          document.getElementById("pflanzeeins").innerHTML = obj.Sorte
          document.getElementById("pflanzezwei").innerHTML = obj.Bodenbeschaffenheit;
          document.getElementById("pflanzevier").innerHTML = obj.Aussaatzeitpunkt_von + "//" + obj.Aussaatzeitpunkt_bis;
          document.getElementById("pflanzedrei").innerHTML = obj.Wachstumsdauer_min + "//" + obj.Wachstumsdauer_max;
          document.getElementById("frucht").setAttribute("value", this.innerText);
        };
        z.appendChild(li);
        console.log("Pflanzendaten empfangen");
      }else if(obj.type.toString() === "robot_pos"){
        console.log("Positionsdaten empfangen");
          let position_y =  obj.y;
          let position_x =  obj.x;
          document.getElementById("-" + position_x.toString() + "," + position_y.toString() + "-").style.stroke = 'black';
          document.getElementById("-" + position_x.toString() + "," + position_y.toString() + "-").style.strokeWidth = '3px';
          for (let x_2 = 0; x_2 < 16; x_2++) {
            for (let y_2 = 0; y_2 < 6; y_2++) {
              if ( "-" + x_2 + "," + y_2 + "-" === "-" + obj.x + "," + obj.y + "-") {
                console.log('ich werde erreicht!');
              } else {
                document.getElementById("-" + x_2.toString() + "," + y_2.toString() + "-").style.stroke = 'rosybrown';
                document.getElementById("-" + x_2.toString() + "," + y_2.toString() + "-").style.strokeWidth = '1px';
            }
          }
        }
      }else{

      }

    }catch (e) {
      found = false;
    }
  }
};


