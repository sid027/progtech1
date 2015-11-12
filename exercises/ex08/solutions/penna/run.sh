#!/bin/bash

TIME=$((32*1024))
M=2
T=2
R=7
NMAX=100000
N0=$((NMAX/10))
NMEAS=$TIME

DATFILE=population.dat

echo "Running with TIME=$TIME M=$M T=$T R=$R NMAX=$NMAX, N0=$N0..."
./penna_sim $TIME $M $T $R $NMAX $N0 $NMEAS > $DATFILE
