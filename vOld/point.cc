#include "point.h"

Point::Point() {
   x = 0.0;
   y = 0.0;
}

Point::Point( double x, double y ) {
   this->x = x;
   this->y = y;
}

bool Point::isnan() {
   if ( std::isnan(x) ) return true;
   if ( std::isnan(y) ) return true;
   return false;
}

bool Point::operator==( Point other ) {
   if ( x != other.x ) return false;
   if ( y != other.y ) return false;
   return true;
}

bool Point::operator!=( Point other ) {
   return !operator==(other);
}

