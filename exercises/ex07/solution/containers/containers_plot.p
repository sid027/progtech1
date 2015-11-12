set key top left; 
set term png; 
set output 'containers.png'; 
set log xy; 
set grid; 
set xlabel 'N'; 
set ylabel 'time[s]'; 
set title 'container benchmarks'; 
plot 'containers.dat' u 1:2 w lp ti 'vector', 'containers.dat' u 1:3 w lp ti 'list', 'containers.dat' u 1:4 w lp ti 'set';
