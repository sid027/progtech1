paper.pdf : paper.tex figure-1.pdf figure-2.pdf
	/usr/local/bin/pdflatex paper.tex

figure-%.pdf : summary-%.dat
	/usr/local/bin/python plot.py $^ $@

summary-%.dat : data-%-*.dat
	/usr/local/bin/python stats.py $@ $^

data-*-*.dat : stats.py
	touch $@
