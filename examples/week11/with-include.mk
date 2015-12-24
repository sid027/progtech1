include config.mk

paper.pdf : paper.tex figure-1.pdf figure-2.pdf
	${LATEX}  paper.tex

figure-%.pdf : summary-%.dat
	${PYTHON} plot.py $^ $@

summary-%.dat : data-%-*.dat
	${PYTHON}  stats.py $@ $^

data-*-*.dat : stats.py
	touch $@
