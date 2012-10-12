SVG=$(wildcard *.svg)
SVGtoEPS=$(SVG:.svg=.eps)

all: $(SVGtoEPS)

%.eps: %.svg
	inkscape -T -E $@ $<

clean:
	rm -f *~ $(SVGtoEPS)
