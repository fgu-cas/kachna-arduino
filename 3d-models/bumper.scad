X = 90;
Y = 2;
Z = 15;

module bumper_half(){
  hull(){
    translate([X/2, 0, 0]) circle(Y, $fn=25);
    translate([X/2+10, -10, 0]) circle(Y, $fn=25);
  }
  hull(){
    translate([X/2, 0, 0]) circle(Y, $fn=25);
    translate([0, 0, 0]) circle(Y, $fn=25);
  }
}

linear_extrude(height=Z)
union(){
  mirror([1,0,0]){
    bumper_half();
  }
  bumper_half();
}
