from numpy import *
from matplotlib.pyplot import *
import sys

pop = loadtxt('population.dat')
figure()
plot(pop[:,0],pop[:,1],'x')
xscale('log')
yscale('log')
xlabel('year')
ylabel('population size')
savefig('population.pdf')

figure()
gen = loadtxt('gene_histogram.dat')
plot(gen)
ylim(ymin=0)
xlabel('genome position')
ylabel('bad fraction')
savefig('gene_histogram.pdf')

show()