# Programming Techniques for Scientific Simulations, HS 2015
# Exercise 11.0
# gnuplot script

set terminal png
set output "convergence.png"
set logscale xy
set xlabel "N_bins"
set ylabel "Absolute error"
set yrange[:10]
plot "convergence.dat" using 1:2 title "smooth integrand: exp(-x)",\
     "convergence.dat" using 1:3 title "continuous integrand: abs(x-1/pi)",\
     "convergence.dat" using 1:4 title "discontinuous integrand: x < 1/pi ? x^2 : (x-1/pi)"
     
