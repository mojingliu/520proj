JOOSC := joosc
JAVA := java
SRC = $(wildcard *.java)
CLASS_FILES = $(SRC:.java=.class)
OUTPUT_FILES = $(SRC:.java=.j) $(CLASS_FILES)

%.class: %.java
	$(JOOSC) $<

.PHONY: clean
.SILENT: test profile

all: classes

classes:
	$(JOOSC) *.java

exec: classes
	@$(JAVA) Quiz
test: classes
	@echo "Executing : Quiz < in1 > output.test"
	@$(JAVA) Quiz < in1 > output.test
	@echo "Result ::"
	@diff -u output.test out1
	@echo "End of results"
	@\rm output.test
clean: 
	\rm -f $(OUTPUT_FILES)
	\rm -f *~

rebuild:clean lib
