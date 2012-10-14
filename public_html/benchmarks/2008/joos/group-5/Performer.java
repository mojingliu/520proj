/* this file is created by Wei Wu */

import java.util.Stack;

import joos.lib.JoosIO;

public class Performer {

	protected JoosIO m_io;
	protected Stack stack;

	// String constants to display the stack
	protected String M_STACK_TOP;
	protected String M_STACK_BOTTOM;
	protected String M_SIDE_LEFT;
	protected String M_SIDE_RIGHT;
	protected String M_EMPTY_SIDE_LEFT;
	protected String M_EMPTY_SIDE_RIGHT;

	protected String M_PISTON_TOP;
	protected String M_PISTON_BOTTON;
	protected String M_PISTON_LEFT;
	protected String M_PISTON_RIGHT;

	protected String M_BOX_CEILING;
	protected String M_BOX_SIDE;
	// /////////////////////////////////

	protected String stackTrace;
	protected String stackStr;

	protected int MAX_LEN;

	public Performer() {
		super();
		m_io = new JoosIO();

		MAX_LEN = 6; // the maximum number of characters that can be displayed
						// in the stack.
		// If a string longer than 6, just display the first 3 characters and an
		// ellipsis.

		stackTrace = new String();
		stackStr = new String();

		stack = new Stack();

		M_STACK_TOP = new String("__________          __________\n");
		M_STACK_BOTTOM = new String("$$$$$$$$$$|__|__|__|$$$$$$$$$$\n");

		M_SIDE_LEFT = new String("$$$$$$$$$$|");
		M_EMPTY_SIDE_LEFT = new String("           ");
		M_SIDE_RIGHT = new String("|$$$$$$$$$$\n");
		M_EMPTY_SIDE_RIGHT = new String("           \n");

		M_PISTON_TOP = new String(" ______ ");
		M_PISTON_BOTTON = new String("|______|");
		M_PISTON_LEFT = new String("  | ");
		M_PISTON_RIGHT = new String(" |  ");

		M_BOX_CEILING = new String("|      |");
		M_BOX_SIDE = new String("|");

		this.empty(); // Create an empty stack

	}

	// Pop an element
	public Object pop() {

		String poppedBox;
		int deletePoint;
		Object poppedObj;

		poppedObj = stack.pop();

		// The poppedBox are displayed above the stack
		poppedBox = this.buildBox(poppedObj.toString(), M_EMPTY_SIDE_LEFT,
				M_EMPTY_SIDE_RIGHT);

		deletePoint = stackStr.indexOf("$", 0);

		// Delete the poppedBox in the stack string, 5 lines of each box.
		stackStr = new StringBuffer(stackStr.substring(0, deletePoint)).append(
				stackStr.substring(5 * deletePoint, stackStr.length()))
				.toString();

		stackTrace = new StringBuffer(stackTrace).append("\n").append(
				"Pop an element: ").append("\n").append(poppedBox).append(
				stackStr).toString();

		return poppedObj;

	}
	
	
	//Push in an element
	public Object push(Object obj, String expression) {
		int insertPoint;

		insertPoint = stackStr.indexOf("$", 0);

		//Insert an box into the stack string.
		stackStr = new StringBuffer(stackStr.substring(0, insertPoint)).append(
				this.buildBox(this.normalizeStr(obj.toString()), M_SIDE_LEFT,
						M_SIDE_RIGHT)).append(
				stackStr.substring(insertPoint, stackStr.length())).toString();

		stackTrace = new StringBuffer(stackTrace).append("\n").append(
				expression).append("\n").append(stackStr).toString();

		return stack.push(obj);

	}

	
	//Empty the stack
	public boolean empty() {

		stackStr = new StringBuffer(this.createEmptyStackStr()).toString();

		stackTrace = new StringBuffer(stackTrace).append(stackStr).toString();

		return stack.empty();

	}

	//Get top element of the stack without pushing it out
	public Object peek() {
		return stack.peek();
	}

	//Display the current stack
	public void showStack() {
		m_io.println("Current stack is:");
		m_io.println(stackStr);
	}

	//Display the change log of the stack
	public void traceStack() {
		m_io.println("The stack change log:");
		m_io.println(stackTrace);
	}

	//Clear the change log of the stack
	public void clearStackTrace() {
		stackTrace = new String("");
	}

	public String buildPiston() {
		return new StringBuffer(M_SIDE_LEFT).append(M_PISTON_TOP).append(
				M_SIDE_RIGHT).append(M_SIDE_LEFT).append(M_PISTON_LEFT).append(
				M_PISTON_RIGHT).append(M_SIDE_RIGHT).toString();

	}

	public String buildBox(String str, String sideLeft, String sideRight) {

		return new StringBuffer(sideLeft).append(M_PISTON_TOP)
				.append(sideRight).append(sideLeft).append(M_BOX_CEILING)
				.append(sideRight).append(sideLeft).append(M_BOX_SIDE).append(
						this.normalizeStr(str)).append(M_BOX_SIDE).append(
						sideRight).append(sideLeft).append(M_PISTON_BOTTON)
				.append(sideRight).toString();

	}

	//If the string of object in stack is longer than 6, cut it, otherwise fill some space.
	public String normalizeStr(String str) {
		int length;
		int i;
		StringBuffer strBuff;

		strBuff = new StringBuffer();

		str = this.filter(str);

		length = str.length();

		if (length <= MAX_LEN) {

			length = MAX_LEN - length;

			for (i = 0; i < length / 2; i++) {
				strBuff.append(" ");

			}

			strBuff.append(str);

			if (length % 2 == 0) {

				for (i = 0; i < length / 2; i++) {
					strBuff.append(" ");

				}

				return strBuff.toString();
			} else {

				for (i = 0; i < (length + 1) / 2; i++) {
					strBuff.append(" ");

				}

				return strBuff.toString();

			}

		}

		// if the string is longer than 6, just display the first 3 characters.
		return strBuff.append(str.substring(0, 3)).append("...").toString();

	}

	//if the element pushed in is a new line, just display as "\n"
	public String filter(String str) {

		if (str.equals("\n")) {
			return "\\n";
		} else {
			return str;
		}

	}
	
	public String createEmptyStackStr() {
		StringBuffer strBuffer;
		strBuffer = new StringBuffer(M_STACK_TOP);

		return strBuffer.append(this.buildPiston()).append(M_STACK_BOTTOM)
				.toString();
	}

}
