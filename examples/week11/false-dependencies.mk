paper.pdf : paper.tex figure-1.pdf figure-2.pdf
	pdflatex paper.tex

figure-%.pdf : summary-%.dat
	./plot.py $^ $@

summary-%.dat : data-%-*.dat
	./stats.py $@ $^

data-*-*.dat : stats.py
	touch $@
