/* FuckIO, wrapper of joosIO
When working with JoosIO, we noticed a few deficiencies. This wapper, written for the
brainfuck interpreter, attempts to aleviate them. added functionality
-PrintLine     : print line with better convention
-getc          : getchar
                    - returns '\n' before eof even if there was none (joosIO deficiency)
                    - returns '\0' for eof
-putc          : putchar
-readStdin     : returns all of stdin in one string (adds '\n' at the end)

*/
import joos.lib.*;

public class FuckIO extends JoosIO{
  //private attributes
  protected String line; //used for getc

  //constructor
  public FuckIO(){
    super();
    line = super.readLine();
  }


  //printLine, define
  public void printLine(String string){
    this.println(string);
  }

  //get character, returns '\0' for end of file
  public char getc(){
      char first;
      if (line == null) return ((char) 0); //eof case
      if (line.length() == 0){ //if current line is empty return '\n'
          line = super.readLine();
          return '\n';
      }

    first = line.charAt(0);
    line = line.substring(1,line.length());
    return first;
  }


  //have to overwrite readLine - because
  public String readLine(){
      StringBuffer buffer;
      char c;
      buffer = new StringBuffer("");

      for(c = this.getc();(c!='\n')&&(c!=((char)0));c = this.getc()){
          buffer.append(c+"");
      }
      if ((c == ((char) 0))&&(buffer.length()==0)) return null;
      return buffer.toString();
  }

  //put character
  public void putc(char c){
    this.print(c+"");
  }

  //returns all of std in in one string (will return a string even if stdin is empty)
  public String readStdin(){
      String s;
      StringBuffer buffer;
      buffer = new StringBuffer();
      
      for(s=this.readLine();s!=null;s=this.readLine()){
          buffer.append(s);
      }
      return buffer.toString();
  }
}