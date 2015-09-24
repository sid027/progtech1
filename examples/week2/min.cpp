// C++ linkage

int min(char x, char y) { return x<y ? x : y;}
int min(int x, int y) { return x<y ? x : y;}
int min(unsigned int x, unsigned int y) { return x<y ? x : y;}
long min(long x, long y) { return x<y ? x : y;}
long min(unsigned long x, unsigned long y) { return x<y ? x : y;}
float min(float x, float y) { return x<y ? x : y;}
double min(double x, double y) { return x<y ? x : y;}

extern "C" {
// C and Fortran linkage
  short min(short x, short y) { return x<y ? x : y;}
}
