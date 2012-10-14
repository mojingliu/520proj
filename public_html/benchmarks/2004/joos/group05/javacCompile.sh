#/bin/sh! 

echo This script will compile the JOOS benchmark with JAVAC

rm -f *.class 

rm -f *.j 
javac Main.java Arithmetic.java VectorTest.java VectorObject.java queueObject.java simpleQueue.java QueueTest.java

echo 
echo Done...
