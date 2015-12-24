#! /usr/bin/env python

import sys
import numpy as np
import matplotlib.pyplot as plt


# read and parse the file
f = file(sys.argv[1])
data = np.array(eval(f.read()))

# split into values and errors
means = data[:,0]
errors = data[:,1]

#prepare the plot
N = len(data)
ind = np.arange(N)  # the x locations for the groups
width = 0.35       # the width of the bars

plt.bar(np.arange(N),means, 0.35, yerr=errors)
plt.savefig(sys.argv[2])


