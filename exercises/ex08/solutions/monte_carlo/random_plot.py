from numpy import *
from matplotlib.pyplot import *

data = loadtxt('random.dat').transpose()
data[0] /= 1e6
plot(data[0],zeros_like(data[0]),'k--')
errorbar(data[0],data[1]-np.pi,data[2],label='drand48')
errorbar(data[0],data[3]-np.pi,data[4],label='mt19937')
legend()
xlabel('million samples')
ylabel('estimate - $\\pi$')
savefig('random.pdf')
