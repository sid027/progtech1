template <class R, class T, class U>
R  min (T x, U y)
{
  return x< y ? x : y;
}


int main()
{
  std::cout << min<double>(1,3.4);


}
