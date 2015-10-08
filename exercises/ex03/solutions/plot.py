import sys
import numpy as np
import matplotlib.pyplot as plt

if len(sys.argv) < 2:
    sys.exit('Please provide a filename!')
    
mat = np.loadtxt(sys.argv[1])

# get step sizes
steps = np.unique(mat[:,1])


plt.figure()
for step in steps:
    m = mat[np.isclose(mat[:,1],step),:]
    plt.semilogx(m[:,0],m[:,2],label=str(int(step))+' bytes')
plt.legend(loc=2)
plt.ylabel('time [s]')
plt.xlabel('array size [kB]')
plt.show()



