/* Parser.java */

/* Written by Alexis Malozemoff */

import java.util.*;
import joos.lib.*;

public final class Parser {

	protected JoosIO io;
	/* Whether we are currently parsing a string or not */
	protected boolean isString;
	/* Stores intermediate representations of numbers, 
	 * i.e. in the number 100, tmpNum will store 1, then 10, finally 100 */
	protected StringBuffer tmpNum;
	/* Stores intermediate representation of strings */
	protected StringBuffer tmpStr;
	/* Object used to store and maintain stack */
	protected Performer s;

	/* List of variables */
	protected Vector varList;

	/* Constructor: Initialize parser environment */
	public Parser() 
	{
		super();
		int i;

		io = 		new JoosIO();
		tmpNum =	new StringBuffer();
		tmpStr =	new StringBuffer();
		s =			new Performer();
		isString = 	false;

		/* Initializes vector and creates empty element for 
		 * each 'a' - 'z' */
		varList =	new Vector(26);
		for (i = 0; i < 26; i++)
			varList.addElement(null);
	}

	/* Given an string as input, we parse the string character by
	 * character and calling to necessary operation.  Since the FALSE
	 * language uses single characters exclusively, this option is
	 * feasible */
	public void parse(String line)
	{
		int i;
		char c;				/* char read in from string */
		Object v1, v2, v3;	/* temporary storage for stack items */

		for (i = 0; i <= line.length(); i++) {
			/* if we are done with a string, store EOL as newline */
			if (i == line.length()) {
				c = '\n';
			/* otherwise get next character */
			} else {
				c = line.charAt(i);
			}

			/* Check if character part of string */
			if (isString) {
				if (c == '\"') {				/* end of string */
					s.push(new String(tmpStr.toString()), 
							"Input String: " + tmpStr.toString());
					tmpStr = new StringBuffer();/* empty string buffer */
					isString = false;
				} else {
					tmpStr.append((new Character(c)));
				}
			} else if (c == '\"') {	/* Character is start of new string */
				isString = true;

			/* Character is part of a number */
			} else if (c >= '0' && c <= '9') {
				tmpNum.append((new Character(c)));
			/* Character is not a number */
			} else if ((c < '0' || c > '9') && tmpNum.length() > 0) {
				s.push(new Integer(tmpNum.toString()), 
							"Input Number: " + tmpNum.toString());
				tmpNum = new StringBuffer();
			}

			/* Only do the following if we are not currently parsing
			 * a string */
			if (!isString) {
				/* anything b/w 'a' and 'z' is a variable */
				if (c >= 'a' && c <= 'z') {
					s.push(new Character(c), "Variable: " + c);
				} else if (c == ':') {	/* assignment function */
					v2 = s.pop();
					v1 = s.pop();
					varList.setElementAt(v1, 
							((Character) v2).charValue() - 97);
				} else if (c == ';') {	/* get variable value */
					v1 = s.pop();
					v2 = varList.elementAt(
							((Character) v1).charValue() - 97);
					s.push(v2, "Variable " + v1 + "'s value: " + v2);
				/* Operators */
				} else if (c == '+') {
					v2 = s.pop();
					v1 = s.pop();
					s.push(new Integer(((Integer) v1).intValue() + 
							((Integer) v2).intValue()), v1 + " + " + v2);
				} else if (c == '-') {
					v2 = s.pop();
					v1 = s.pop();
					s.push(new Integer(((Integer) v1).intValue() - 
							((Integer) v2).intValue()), v1 + " - " + v2);
				} else if (c == '*') {
					v2 = s.pop();
					v1 = s.pop();
					s.push(new Integer(((Integer) v1).intValue() * 
							((Integer) v2).intValue()), v1 + " * " + v2);
				} else if (c == '/') {
					v2 = s.pop();
					v1 = s.pop();
					s.push(new Integer(((Integer) v1).intValue() / 
							((Integer) v2).intValue()), v1 + " / " + v2);
				} else if (c == '_') {	/* negate */
					v1 = s.pop();
					s.push(new Integer(0 - ((Integer) v1).intValue()),
							"-" + v1);
				} else if (c == '$') {	/* duplicate */
					v1 = s.peek();
					s.push(v1, "Duplicating " + v1);
				} else if (c == '%') { 	/* delete */
					s.pop();
				} else if (c == '\\') {	/* swap */
					v2 = s.pop();
					v1 = s.pop();
					s.push(v2, "Swapping " + v2);
					s.push(v1, "Swapping " + v1);
				} else if (c == '@') {	/* rotate 3rd item from top */
					v1 = s.pop(); 
					v2 = s.pop();
					v3 = s.pop();
					s.push(v1, "Rotating " + v1);
					s.push(v2, "Rotating " + v2);
					s.push(v3, "Rotating " + v3);
				} else if (c == '.') {	/* output value */
					io.print(s.peek().toString());
				} else if (c == ',') {	/* output ASCII value */
					io.print("" + (char) ((Integer) s.peek()).intValue());
				} else if (c == '`') {	/* output stack */
					s.showStack();
				} else if (c == '#') {	/* print stack trace */
					s.traceStack();
				} else if (c == '!') {	/* clear stack trace */
					s.clearStackTrace();
				} else if (c == ')') {	/* empty stack */
					s.empty();
				}
			}
		}
	}
}

