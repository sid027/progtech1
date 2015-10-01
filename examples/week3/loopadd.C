void sum(double* a, const double* b, const double* c)
{
  for (int i=0;i<10240;++i)
    a[i]=b[i]+c[i];
}
