TEX=$(wildcard *.tex)
DVI=$(TEX:.tex=.dvi)
PS=$(TEX:.tex=.ps)
4PS=$(TEX:.tex=-4.ps)
4PDF=$(TEX:.tex=-4.pdf)
PDF=$(TEX:.tex=.pdf)

all: $(4PDF) $(PDF) $(DVI) $(PS) $(4PS)

%.pdf: %.ps
	ps2pdf -dMaxSubsetPct=100 -dSubsetFonts=true -dEmbedAllFonts=true $< $@

%-4.pdf: %-4.ps
	ps2pdf -dMaxSubsetPct=100 -dSubsetFonts=true -dEmbedAllFonts=true $< $@

%-4.ps: %.ps
	psnup -4 -pletter $<  > $@

%.ps: %.dvi
	dvips -o $@ -Ppdf -G0 -t letter $<

%.dvi: %.tex
	latex $<
	latex $<

figs:
	$(MAKE) -C figs

clean:
	rm -f *~
	rm -f *.aux *.bbl *.blg *.log *.dvi *.rai *.rao

svnclean: clean
	rm -f *.pdf *.ps *.dvi
