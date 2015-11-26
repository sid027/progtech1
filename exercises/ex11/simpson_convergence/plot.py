from numpy import *
import matplotlib
matplotlib.use('pdf')
from matplotlib.pyplot import *

a=loadtxt('convergence.dat')

figure()
loglog(a[:,0],a[:,1], 'gx', label='Exp(-x)')
loglog(a[:,0],a[:,2], 'b+', label='Discontinuous')
loglog(a[:,0],a[:,3], 'ro', label='Non-smooth')
legend(loc='best')
ylabel('Absolute error')
xlabel('N_bins')
savefig('convergence.pdf')
