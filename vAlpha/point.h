#ifndef _POINT_H_
#define _POINT_H_

// libraries
#include <cmath>

class Point {
   public:
      Point();
      Point( double x, double y );
      bool isnan();
      bool operator==( Point other );
      bool operator!=( Point other );

      double x;
      double y;
};

#endif

