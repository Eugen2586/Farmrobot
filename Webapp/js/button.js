
let send = 'nop';

document.getElementById("A").onmousedown = function(){
    send = 'A';
}
document.getElementById("A").onmouseup = function(){
  send = 'nop';
}
document.getElementById("D").onmousedown = function(){
  send = 'D';
}
document.getElementById("D").onmouseup = function(){
  send = 'nop';
}
document.getElementById("W").onmousedown = function(){
  send = 'W';
}
document.getElementById("W").onmouseup = function(){
  send = 'nop';
}
document.getElementById("S").onmousedown = function(){
  send = 'S';
}
document.getElementById("S").onmouseup = function(){
  send = 'nop';
}
document.getElementById("Q").onmousedown = function(){
  send = 'Q';
}
document.getElementById("Q").onmouseup = function(){
  send = 'nop';
}
document.getElementById("E").onmousedown = function(){
  send = 'E';
}
document.getElementById("E").onmouseup = function(){
  send = 'nop';
}

function sendingFunction(){
    socket.send(send);
    console.log(send);
}

setInterval(function() {
  sendingFunction()
}, 200);

socket.onclose = function(event) {
  if (event.wasClean) {} else {

  }
};

socket.onerror = function(error) {
  alert(`[error] ${error.message}`);
};
