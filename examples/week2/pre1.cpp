#define SCALE 10.
#define MIN(X,Y) ( X < Y ? X : Y)

doube scale (double x)
{
  return MIN ( SCALE * x, 0.);
}
