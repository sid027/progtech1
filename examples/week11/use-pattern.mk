paper.pdf : paper.tex figure-1.pdf figure-2.pdf
	pdflatex paper.tex

figure-%.pdf : summary-%.dat
	./plot.py $^ $@

summary-1.dat : data-1-*.dat
	./stats.py $@ $^

summary-2.dat : data-2-*.dat
	./stats.py $@ $^

summary-1.dat : stats.py
summary-2.dat : stats.py
