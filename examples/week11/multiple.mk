all: figure-1.pdf figure-2.pdf

figure-1.pdf : summary-1.dat
	./plot.py summary-1.dat figure-1.pdf

figure-2.pdf : summary-2.dat
	./plot.py summary-2.dat figure-2.pdf

summary-1.dat : data-1-1.dat data-1-2.dat data-1-3.dat
	./stats.py summary-1.dat data-1-1.dat data-1-2.dat data-1-3.dat
