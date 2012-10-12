////////////////////////////////////////////////////////////////////////
// VSMore - (Very Simple) Matching Of Regular Expressions.                //
////////////////////////////////////////////////////////////////////////
// Work completed for course COMP520, Group no. 6, by                 //
// * Grzegorz B. PROKOPSKI                                            //
// * Jorge RESSIA                                                     //
// * Jacques Le NORMAND                                               //
////////////////////////////////////////////////////////////////////////

import joos.lib.*;

public class VSMore {

  public VSMore() {
    super();
  }

  public boolean isNormalChar(char c) {
    if ( ((c >= 'a') && (c <= 'z')) ||
         ((c >= 'A') && (c <= 'Z')) ||
         ((c >= '0') && (c <= '9')) )
      return true;
    else
      return false;
  }
  
  public char getRepetitions(String s, int idx, int len) {
    char c;
    
    if (idx < len) {// we're not at the last char yet?
      c = s.charAt(idx);
      if ((c == '*') || (c == '+') || (c == '?'))
        return s.charAt(idx);
    }
    return '1';
  }

  public boolean matchToASet(char c, String s) {
    int len;
    int pos;
    
    pos = 0;
    len = s.length();
    
    while (pos < len)
      if (s.charAt(pos) == c)
        return true;
      else
        pos = pos + 1;
    
    return false;
  }

  public int match(String exp, String str) {
    int result, position, expLen, strLen, expPos, strPos;
    String matchSet;

    // '?' - optional single match
    // '+' - one or more matches
    // '*' - any number of matches
    // '1' - exactly one single match
    char matchAmount;
    
    result = 1; // initially assume "match"
    matchSet = "";
    expPos = 0;
    strPos = 0;
    strLen = str.length();
    expLen = exp.length();
    
    while (((expPos < expLen) || (strPos < strLen)) && result > 0) {
      char expChar;

      expChar = exp.charAt(expPos);
      matchAmount = '1';
    
      // find the set of chars that can be matched with next
      // element of regular expression
      if (expChar == '[') {
        int endPos;
	
	endPos = exp.indexOf("]", expPos + 1);

	if (endPos == -1)
	  result = -expPos;
	else {
	  int pos;

	  // ensure all matching chars are from allowed range
	  pos = expPos + 1;
	  while (pos <= endPos - 1)
	    if (!this.isNormalChar(exp.charAt(pos))) {
	      result = -expPos;
	      pos = endPos;
	    } else
	    pos = pos + 1;

	  if (result > 0) {
	    // all right - copy the string from inside of '[' ']'
	    matchSet = exp.substring(expPos + 1, endPos);
	    matchAmount = this.getRepetitions(exp, endPos + 1, expLen);
	    if (matchAmount == '1')
	      expPos = endPos + 1;
	    else
	      expPos = endPos + 2;  // accont for repetition char
	  }
	}
      } else

      if (this.isNormalChar(expChar)) {
        matchSet = exp.substring(expPos, expPos + 1);
	matchAmount = this.getRepetitions(exp, expPos + 1, expLen);
	if (matchAmount == '1')
	  expPos = expPos + 1;
	else
	  expPos = expPos + 2;  // account for repetition char
      } else

      {
        result = -expPos - 1;  // expPos might be 0 so we substract 1
      }
      
      // match as many characters from input string as possible while
      // paying attention to how many you may and/or have to match
      if (result > 0) {
        char strChar;

        // if there's no more "string", is it allowed by the regexp?
	if (((strPos >= strLen) &&
	    ((matchAmount == '1') || matchAmount == '+' ))) {
	  result = 0; // sorry, no match
	} else {
	  strChar = str.charAt(strPos);
          // match the first char specially...
	  if (!this.matchToASet(strChar, matchSet)) {
	    if ((matchAmount == '1') || (matchAmount == '+'))
	      result = 0;
	  } else {
	    strPos = strPos + 1;

	    if ((matchAmount != '1') && (matchAmount != '?')) {
	      // try to match more for '*' and '+'
	       while ((strPos < strLen) &&
	             (this.matchToASet(str.charAt(strPos), matchSet)))
	        strPos = strPos + 1;
	    }
	  }
	}
	
	// if we hit end of regexp but not end of string - no match
	if ((expPos >= expLen) && (strPos < strLen))
	  result = 0;
      }

    }

    return result;
  }

  public static void main(String argv[]) {
    VSMore regExp;
    String expression, string;
    JoosIO joosIO;
    int result;

    joosIO = new JoosIO();
    expression = joosIO.readLine();
    string = joosIO.readLine();

    regExp = new VSMore();
    result = regExp.match(expression, string);
    
    if (result == 1) {
      joosIO.print("The string: '");
      joosIO.print(string);
      joosIO.print("' matches regular expression: '");
      joosIO.print(expression);
      joosIO.println("'");
    } else
    if (result == 0) {
      joosIO.print("The string: '");
      joosIO.print(string);
      joosIO.print("' does not match regular expression: '");
      joosIO.print(expression);
      joosIO.println("'");
    } else
    if (result < 0) {
      joosIO.print("This is not a valid regular expression: '");
      joosIO.print(expression);
      joosIO.println("'");
    }
  }
}
