#define min(x,y) (x < y ? x : y)

int main() {
  int x=1;
  int y=0;
  return min(x++,y++);
}
