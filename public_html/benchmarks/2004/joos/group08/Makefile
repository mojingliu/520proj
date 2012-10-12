# --------------- Pick one of these compilers,  
JAVAC = javac 
JOOSC = joosc 

# ---------------  Pick one of these flag settings.
#FLAGS = 
FLAGS = -O

# ---------------  Pick one of these java commands.
#JAVA = jjava
JAVA = java

#-------------------------------------------------------------------------
# Build extern joos classes
JoosLibs: ./myjoos/lib/*.java
	$(JAVAC) $(FLAGS)  ./myjoos/lib/*.java	

# -----------------------------------------------------------------------
# Building with Java
# NOTE: For some reason the compiler is re-compiling JoosConstants.java
# in the Joos/Libs directory. Since this directory is owned by Laurie
# the compilation was failing because of writing permissions. To get around
# this problem I had to use the -d flag. 
MainJava.class : JoosLibs Main.java MenuTest.java
	$(JAVAC) $(FLAGS) -d . Main.java MenuTest.java

# How to run it.
MainJava : MainJava.class
	$(JAVA) Main


# -----------------------------------------------------------------------
# Building with JOOS 
MainJoos.class : JoosLibs Main.java MenuTest.java iolib.joos swinglib.joos
	$(JOOSC) $(FLAGS)  Main.java MenuTest.java iolib.joos swinglib.joos

# How to run it.
MainJoos : MainJoos.class
	$(JAVA) Main

# -----------------------------------------------------------------------
clean	:  
	rm *.class *.j ./myjoos/lib/*.class  
