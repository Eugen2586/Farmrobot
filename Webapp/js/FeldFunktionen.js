window.addEventListener("load", function () {
  for (let x = 0; x < 16; x++) {
    for (let y = 0; y < 6; y++) {
      document.getElementById("-" + x.toString() + "," + y.toString() + "-").onmousedown = function () {
        document.getElementById(this.id).style.fill = 'Red';
        for (let x_2 = 0; x_2 < 16; x_2++) {
          for (let y_2 = 0; y_2 < 6; y_2++) {
            if ( "-" + x_2 + "," + y_2 + "-" === this.id) {
              console.log('ich werde erreicht!');
            } else {
              document.getElementById("-" + x_2.toString() + "," + y_2.toString() + "-").style.fill = 'sandybrown';
            }
          }
        }
      }
    }
  }
});
