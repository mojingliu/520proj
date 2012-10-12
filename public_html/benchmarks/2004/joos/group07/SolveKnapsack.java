
// Group 07 - Artem Khassanov, Roman Dolgov
// 0-1 Knapsack Problem Solver Implementation
// Algorithm presented here:
// http://www-cse.uta.edu/~holder/courses/cse2320/lectures/l15/node12.html


import joos.lib.*;
import java.lang.*;
import java.util.*;

public class SolveKnapsack {
  // Table used in dynamic programming solution
  protected Vector dynProgram;
  // Names of items
  protected Vector names;
  // Weights of items
  protected Vector weights;
  // Values of items
  protected Vector values;
  // Maximum weight knapsack can carry
  protected Integer maxWeight;
  // Which items should be taken

  public SolveKnapsack() {
    super();
    dynProgram = null;
    weights = new Vector();
    values = new Vector();
    names = new Vector();
    // Since algorithm assumes indexing starts at 1, and uses dummy
    // Item at index 0, add it in constructor
    names.addElement("No items");
    weights.addElement(new Integer(0));
    values.addElement(new Integer(0));
  }

  // This method reads input data
  // The format of data is as follows:
  // MaxWeight
  // Item0 Name
  // Item0 Weight
  // Item0 Value
  // Item1 Name
  // ...
  public boolean readInput(JoosIO io) {
    // Last line in stdin
    String curLine;
    // last line converted to integer
    Integer weight, value;
    int i;
    weight = null;
    value = null;
    // read max weight
    io.println("Enter maximum weight: ");
    curLine = io.readLine();
    if (curLine != null) {
      maxWeight = new Integer(curLine);
      // Confirm entered value (usefull for redirected stdin)
      io.print("Maximum weight is set to ");
      io.println(maxWeight.toString());
    }
    else
      return false;
    // read first item name
    io.println("Enter item name: ");
    curLine = io.readLine();
    // read item values in a loop until EOF or empty string is entered
    i = 0;
    while ((curLine != null) && (!curLine.equals(""))) {
      if ( (i % 3) == 0) {
        names.addElement(curLine);
        io.println("Enter item weight: ");
      }
      else {
        if ( (i % 3) == 1) {
          weight = new Integer(curLine);
          weights.addElement(weight);
          io.println("Enter item value: ");
        }
        else {
          value = new Integer(curLine);
          values.addElement(value);
          // Print confirmation of the entered item
          io.print((String) names.elementAt((i / 3) + 1));
          io.print(" was added to the inventory with weight ");
          io.print(weight.toString());
          io.print(" and value ");
          io.println(value.toString());
          // Prompt for next item
          io.println("Enter item name (press Enter or Ctrl-D to solve): ");
        }
      }
      i = i + 1;
      curLine = io.readLine();
    }
    // if user abruptly exits without finishing typing data for the last item,
    // or if no items has been entered - exit.
    if ((weights.size() != values.size()) || (weights.size() == 0)) {
      io.println("Not all information is entered.");
      return false;
    }
    else {
      // Otherwise init dynamic programming table. It'll have 0..ItemCount
      // rows and 0..MaxWeight columns
      dynProgram = new Vector(weights.size() * (maxWeight.intValue() + 1));
      i = 0;
      while (i < dynProgram.capacity()) {
        dynProgram.addElement(new Integer(0));
        i = i + 1;
      }
      return true;
    }
  }

  // This method actually prints the solution on the screen
  // Name of the variables are as they appear in the algorithm of the URL above
  public void getSolution() {
    int i, n, w, W, temp;
    Integer Wi, Vi, Cprev, Cthis;
    JoosIO io;
    io = new JoosIO();
    // Get number of rows
    n = weights.size();
    // Get number of columns
    W = maxWeight.intValue() + 1;
    // For each row
    i = 1;
    while (i < n) {
	// Go through each column
        w = 1;
	while (w < W) {
	    // Get parameters of the item in the current row
	    Wi = (Integer) weights.elementAt(i);
	    Vi = (Integer) values.elementAt(i);
	    // Get max that we could put by not taking current item
	    Cthis = (Integer) dynProgram.elementAt( (i - 1) * W + w);
	    // If there is enough space in the bag
	    if (Wi.intValue() <= w) {
		// Get max that we can put in the bag if we take current item
		Cprev = (Integer) dynProgram.elementAt( (i - 1) * W +
							(w - Wi.intValue()));
		// Calculate the total value we would have by taking the item
		temp = Vi.intValue() + Cprev.intValue();
		// If it's bigger than what we have by not putting this
		// item in the bag, we take this item
		if (temp > Cthis.intValue()) {
		    dynProgram.setElementAt(new Integer(temp), i * W + w);
		}
		else {
		    // Otherwise we stay where we are
		    dynProgram.setElementAt(Cthis, i * W + w);
		}
	    }
	    else {
		dynProgram.setElementAt(Cthis, i * W + w);
	    }
	    w = w + 1;
	}
	i = i + 1;
    }
    // Get the value in the last cell fo the table, that's our biggest value
    Cthis = (Integer) dynProgram.elementAt(dynProgram.size() - 1);
    io.print("The maximum value of goods you can take is ");
    io.println(Cthis.toString());
    io.println("You will receive these items in the next version ;)");
  }
}

