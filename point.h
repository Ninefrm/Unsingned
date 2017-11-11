#ifndef _POINT_H_
#define _POINT_H_

// Por default, todo es público
struct Point {
   // Ejemplos de uso:
   // Point center(0.5,0.6);
   //
   // center = Point(10.0,15.0);
   // center.x = 12.3;
   // center.y = -0.5e-12
   Point() {
      x = 0.0;
      y = 0.0;
   }
   Point( double x, double y) {
      this->x = x;
      this->y = y;
   }
   double x;
   double y;
};

#endif

