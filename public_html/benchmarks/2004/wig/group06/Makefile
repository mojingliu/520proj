
NAME=wiki

DEST=/var/www/testcgi
WIG10CP=../../utils/wig10-classes-new.jar
#JAVA=/usr/local/j2sdk/1.3/bin/java
JAVA=/usr/lib/fjsdk/bin/java
GCC=gcc-2.95
TARBALL_LIST=Makefile README runwig10.c $(NAME).c $(NAME).wig

all: $(NAME).cgi

$(NAME).c: $(NAME).wig
	$(JAVA) -cp $(WIG10CP) wig10.Compiler $(NAME).wig
	cat $(NAME).c | sed 's/\/home\/user\/hendren\/WIG\/10\///g' \
	    >$(NAME).c.fixed
	mv -f ./$(NAME).c.fixed $(NAME).c

$(NAME).cgi: $(NAME).c runwig10.c
	$(GCC) -o $(NAME).cgi $(NAME).c
	chmod a+rx $(NAME).cgi

install: $(NAME).cgi
	cp -f $(NAME).cgi $(DEST)/$(NAME).cgi
	chmod a+x $(DEST)/$(NAME).cgi

clean:
	rm -f $(NAME).c $(NAME).c.fixed $(NAME).cgi $(NAME).install $(NAME).tar.gz
	rm -f $(NAME)/*
	-rmdir $(NAME)

tarball: $(TARBALL_LIST)
	rm -f $(NAME).tar.gz
	rm -f $(NAME)/*
	-rmdir $(NAME)
	mkdir $(NAME)
	for one in $(TARBALL_LIST); do cp -f $${one} $(NAME)/$${one}; done
	tar zcvf $(NAME).tar.gz $(NAME)
