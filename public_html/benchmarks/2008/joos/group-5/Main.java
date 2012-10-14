/* Main.java */

/* Coded by Alexis Malozemoff */

import joos.lib.*;

public class Main {

	public Main() { super(); }

	public static void main (String argv[])
	{
		boolean takeInputFile;

		JoosIO io;
		Parser p;
		String line;

		io = new JoosIO();	
		p = new Parser();

		/* CHANGE THIS LINE TO false AND RECOMPILE IF YOU WANT THE 
		 * INTERACTIVE FALSE INTERPRETER */
		takeInputFile = true;

		if (!takeInputFile) {
			io.println("Welcome to the FALSE Interpreter!");
			io.println("Hit CTRL-D to quit.  Enjoy!");
			io.print(" > ");
		}
		while ((line = io.readLine()) != null) {
			p.parse(line);
			if (!takeInputFile)
				io.print(" > ");
		}
	}
}

