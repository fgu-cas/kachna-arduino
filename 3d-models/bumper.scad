X = 90;
Y = 2.5;
Z = 15;

module bumper_half(){
  polygon([[0,0],
           [X/2,0],
           [X/2,Y],
           [0,Y]]);
  translate([X/2, -15])
    intersection(){
      difference(){
        circle(15+Y, $fn=70);
        circle(15, $fn=70);
      }
      polygon([[0,0],
               [30,0],
               [30,30],
               [0,30]]);
    }

}

linear_extrude(height=Z)
union(){
  mirror([1,0,0]){
    bumper_half();
  }
  bumper_half();
}
