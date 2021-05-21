for(let x = 0; x < 16; x ++){
  for(let y = 0; y < 6; y ++){
   document.getElementById("-"+ x.toString() +"," + y.toString() +"-").onmousedown = function(){
     document.getElementById("-"+ x.toString() +"," + y.toString() +"-").style.fill = 'Red';
      //for(let x_2 = 0; x < 16; x ++) {
        //for (let y_2 = 0; y < 6; y++) {
          //if(x === x_2 && y === y_2){
          //  continue;
          //}else {
           //<!-- document.getElementById("-" + x.toString() + "," + y.toString() + "-").style.fill = 'sandybrown'; -->
         // }
       // }
      }
    }
}
