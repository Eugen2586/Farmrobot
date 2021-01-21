let bufferA = false;
let i = 0;
document.getElementById("A").onmouseup = function(){
  bufferA  = false;
}
document.getElementById("A").onmousedown = function(){
  bufferA = true;
  while(bufferA) {
    i++;
    socket.send("A"+i.toString());
  }
}
document.getElementById("D").onclick = function() {
 socket.send("D");
}
document.getElementById("W").onclick = function() {
  socket.send("W");
}
document.getElementById("S").onclick = function(){
  socket.send("S");
}
document.getElementById("Q").onclick = function(){
  socket.send("Q");
}
document.getElementById("E").onclick = function(){
  socket.send("E");
}
