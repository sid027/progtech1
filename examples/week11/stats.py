#! /usr/bin/env python

import sys
import re
import math

results = []

# read all the input files and calculate mean and standard deviation
for fn in sys.argv[2:]:
  f = file(fn)
  txt = f.read()
  f.close()
  data = [float(x) for x in re.findall('[-+]?\d+', txt)]
  mean = sum(data)/len(data)
  stddev= math.sqrt(sum([x*x-mean*mean for x in data])/len(data))
  results.append([mean,stddev])

# write the output
f = file(sys.argv[1],'w')
f.write(str(results))
f.close()


