#!/bin/bash

TIME=1600
M=1
T=3
R=7
P=1.0
NMAX=200000
N0=$((NMAX/10))
NMEAS=$TIME
M1=1000
M2=1200
r1=0.17
a1=0
r2=0.22
a2=0

DATFILE=population.dat

echo "Running with TIME=$TIME M=$M T=$T R=$R P=$P NMAX=$NMAX, N0=$N0, M1=$M1, r1=$r1, a1=$a1, M2=$M2, r2=$r2, a2=$a2..."
./penna_sim $TIME $M $T $R $P $NMAX $N0 $NMEAS $M1 $r1 $a1 $M2 $r2 $a2 > $DATFILE
