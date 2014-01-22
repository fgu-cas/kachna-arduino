X = 90;
Y = 2;
Z = 15;

linear_extrude(height=Z)
union(){
  hull(){
    translate([X/2, 0, 0]) circle(Y, $fn=25);
    translate([X/2+10, -10, 0]) circle(Y, $fn=25);
  }
  hull(){
    translate([X/2, 0, 0]) circle(Y, $fn=25);
    translate([-X/2, 0, 0]) circle(Y, $fn=25);
  }
  hull(){
    translate([-X/2, 0, 0]) circle(Y, $fn=25);
    translate([-X/2-10, -10, 0]) circle(Y, $fn=25);
  }
}
