# Programming Techniques for Scientific Simulations, HS 2014
# Exercise 9.2

from numpy import *
from matplotlib.pyplot import *

a=loadtxt('simpson_benchmark_results.dat',usecols=(0,1,3,4,6,7,9,10,12))

figure()
errorbar(a[:,0],a[:,1],a[:,2], fmt='x', label='hardcoded')
errorbar(a[:,0],a[:,5],a[:,6], fmt='+', label='template function object')
errorbar(a[:,0],a[:,3],a[:,4], fmt='^', label='function pointer')
errorbar(a[:,0],a[:,7],a[:,8], fmt='v', label='abstract function object')
legend(loc='best')
xticks(arange(1,7),['f(x)=0','f(x)=1','f(x)=x','f(x)=x*x','f(x)=sin x','f(x)=sin 5x'])
xlim(.1,6.5)
xlim(.5,6.5)
ylabel('time per integration [s]')
xlabel('integrand')
savefig('simpson_benchmark.pdf')
show()
