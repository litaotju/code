#include <math.h>
#include <iostream>
using namespace std;
 
class Point
{
 friend double Distance( const Point & p1, const Point & p2 )    /* ① */
 {
 double dx  = p1.x_ - p2.x_;
 double dy  = p1.y_ - p2.y_;
 return(sqrt( dx * dx + dy * dy ) );
 }
 
 
public:
 Point( int x, int y ) : x_( x ), y_( y )                        /* ② */
 {
 }
 
 
private:
 int    x_;
 int    y_;
};
 
 
int main( void )
{
 Point  p1( 3, 4 );
 Point  p2( 6, 9 );
 
 cout << Distance( p1, p2 ) << endl;                      /* ③ */
 return(0);
}