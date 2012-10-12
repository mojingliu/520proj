#/bin/sh! 

echo This script will compile the JOOS benchmark with JOOSC
rm -f *.class
rm -f *.j


joosc Main.java Arithmetic.java VectorTest.java VectorObject.java queueObject.java simpleQueue.java QueueTest.java

echo 
echo Done...
