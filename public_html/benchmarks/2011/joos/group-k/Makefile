all: clean
	joosa- BacktrackSolver.java SudokuSolver.java Benchmark.java
	jasmin BacktrackSolver.j
	jasmin SudokuSolver.j
	jasmin Benchmark.j

java:
	javac BacktrackSolver.java SudokuSolver.java Benchmark.java

clean:	
	rm -rf *.class *.j *~

run:
	java Benchmark < in1
