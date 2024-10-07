#include "graphics.h"
#include <math.h>

// defining function
void drawKochSF(double x1, double y1, double x2, double y2);

int main(void)
{
    // drawing each side of the triangle
    drawKochSF(100.0,225.0,300.0,225.0);
    drawKochSF(300.0,225.0,200.0,25.0);
    drawKochSF(200.0,25.0,100.0,225.0);

    return 0;
}

void drawKochSF(double x1, double y1, double x2, double y2)
{
// Calc the distance between the two points
double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

// Calc one-third of the distance
double r = d / 3.0;

// Calc height for the equi triangle
double h = r * sqrt(3) / 2.0;

// Calc point p1,p2,p3
double p1_x = x1 + r * (x2 - x1) / d; 
double p1_y = y1 + r * (y2 - y1) / d; 

double p2_x = x1 + 2 * r * (x2 - x1) / d; 
double p2_y = y1 + 2 * r * (y2 - y1) / d;

double p3_x = (p1_x + p2_x) / 2 - h * (y2 - y1) / d; 
double p3_y = (p1_y + p2_y) / 2 + h * (x2 - x1) / d; 

if (d > 10){ // accuracy lower means more accurate
    drawKochSF(x1,y1,p1_x,p1_y);
    drawKochSF(p1_x,p1_y,p3_x,p3_y);
    drawKochSF(p3_x,p3_y,p2_x,p2_y);
    drawKochSF(p2_x,p2_y,x2,y2);
}
else{ // last iteration
    drawLine((int)x1,(int)y1,(int)p1_x,(int)p1_y);
    drawLine((int)p1_x,(int)p1_y,(int)p3_x,(int)p3_y);
    drawLine((int)p3_x,(int)p3_y,(int)p2_x,(int)p2_y);
    drawLine((int)p2_x,(int)p2_y,(int)x2,(int)y2);

}
}

