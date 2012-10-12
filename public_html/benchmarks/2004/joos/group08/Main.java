//*
//* Created on Sep 22, 2004
//*
//* Copied from the book "Java How To Program," Fifth Edition.
//* The code has been modified to fulfill the assignment's requirement and to be 
//* JOOS compatible.
//*
//* Modified by: Shahla Almasri
//*

import java.io.File;
import java.util.StringTokenizer;

import joos.lib.*;
import myjoos.lib.*;

public class Main extends Object {
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Constructor
	//
    public Main() {
		super();   
   }

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// main method: Prompt the user for a text. If the entered text was an existing file, it 
	// opens the file, reads it, and then display its content. If it wasn't a file, it displays the
	// entered text as it is.
	//
    public static void main( String argv[] ) {
   		// declarations
   		String str, token;
		JoosIO io;
		JoosSystem sys;
	  	File file_name;
	  	JoosBufferedReader input;
	  	MyJoosConstants myConst;
		StringTokenizer tokenizer;
		MenuTest application;
		Main mainObj;

		mainObj = new Main();
	  	myConst = new MyJoosConstants();
		sys = new JoosSystem();
	  	io = new JoosIO();
	  	io.println("Please enter a file name or a sample text:");
	  	str = io.readLine();
	  
   	  	if (str.length() > 0) {
   	  		// check whether the flag -n was passed. If it was don't show an x/window
			tokenizer = new StringTokenizer(str);
   	  		token = tokenizer.nextToken(" ");
   	  		if (token.equals("-n")) {
				application = new MenuTest(str, false);
   	  			mainObj.printInitialSelection(application);
   	  			sys.exit(0);	
   	  		}
   	  		
   	  		// check whether the string is a file name or not.
   	  		// If it is, then open it, read it, and let the string be its content
   	  		file_name = new File(str);
   	  		if (file_name.exists()) {
   	  			String tmp;
   	  			tmp = new String();
   	  			str = "";
	  			input = new JoosBufferedReader(new JoosFileReader(file_name));
	  		
				while (tmp != null) {
            		tmp = input.readLine();
                	if (tmp != null) {
                    	str = str.concat(tmp);
                	}
            	}
            	input.close();
   	  		}
   	  	} else { 
   	  		str = "Sample Text";
   	  	}
   	  
      	application = new MenuTest(str, true);
      	application.setDefaultCloseOperation(myConst.EXIT_ON_CLOSE());
      	
      	mainObj.printInitialSelection(application);
   	}
   	
   	public void printInitialSelection(MenuTest app) {
   			String str;
			JoosIO io;
			
			io = new JoosIO();
			 //	Print the current font.
			 str = "Initially, you have chosen the color " + app.getSelectedColor() + 
					 ", the font " + app.getSelectedFont(); 
			 if (app.getSelectedStyle() != "")
				 str = str +  ", and the style " + app.getSelectedStyle();
			 io.println(str);
   	}
} // end class Main

//**************************************************************************
// * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and               *
// * Prentice Hall. All Rights Reserved.                                    *
// *                                                                        *
// * DISCLAIMER: The authors and publisher of this book have used their     *
// * best efforts in preparing the book. These efforts include the          *
// * development, research, and testing of the theories and programs        *
// * to determine their effectiveness. The authors and publisher make       *
// * no warranty of any kind, expressed or implied, with regard to these    *
// * programs or to the documentation contained in these books. The authors *
// * and publisher shall not be liable in any event for incidental or       *
// * consequential damages in connection with, or arising out of, the       *
// * furnishing, performance, or use of these programs.                     *
// *************************************************************************/
