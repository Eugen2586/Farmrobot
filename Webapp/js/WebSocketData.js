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
      if(obj.type.toString() == "plantDat"){
        var li = document.createElement("li");
        li.appendChild(document.createTextNode(obj.Name));
        let z = document.getElementById("plantdat");
        li.setAttribute("id", obj.Name);
        li.setAttribute("style", "list-style: none");
        pflanzendaten.push(obj);
        li.onclick = function(){
          //hier den Code einsetzen um allgemeine Daten zur Pflanze anzuzeigen.
          document.getElementById("pflanzeeins").innerHTML = obj.Sorte
          document.getElementById("pflanzezwei").innerHTML = obj.Bodenbeschaffenheit;
          document.getElementById("pflanzevier").innerHTML = obj.Aussaatzeitpunkt_von + "//" + obj.Aussaatzeitpunkt_bis;
          document.getElementById("pflanzedrei").innerHTML = obj.Wachstumsdauer_min + "//" + obj.Wachstumsdauer_max;
        };
        z.appendChild(li);
        console.log("Pflanzendaten empfangen");
      }else{

      }

    }catch (e) {
      found = false;
    }
  }
};


