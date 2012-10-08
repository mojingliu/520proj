import joos.lib.*;
import java.util.*;
public class board  {
    protected String summary; // cs520c summary
    protected String delivery; // the coming delivery
    protected String content; // key word of the content in cs520
    protected Vector topics; // hash table for the content
    public board() { super();
       topics = new Vector();

       // the following is just "hardwired" content to the course
       // topics. content is a string which is composed of several
       // pieces. Every piece is in the format : XXY*************.
       // Where XX is the length of the piece, Y is the topic number
       // *********** is the topic key word, e.g., "111boostrap", 
       // the piece is 11 char long, keyword is boostrap and it in 
       // topic 1 of the lecutre. It will go to "b" entry of the hash
       // table .
       content = "151Introduction121Bootstrap101History111Compiler";
       content = content + "092Parser102Scanner082Bison062Lex222Regular expressions";
       content = content + "232Context free grammer132Ll parsing132Lr parsing";
       content = content + "073Joos073Java163Java Bytecode";
       content = content + "234Abstract syntax tree065Wig075Html065Cgi";
       content = content + "156Symbol table167Type checking188Virtual machine";
       content = content + "189Code generation150Optimization";
       content = content + "211Garbage Collection252Native code generation";
       content = content + "203Static collection";}

   // initialize summary
   public void initSummary()
   {   summary = "cs 520: compiler design.";
       summary = summary + "By L. Hendren.";
       summary = summary + "This course has 2 project: JOOS and WIG.";}

   // put content to hash table (vector with 26 entries) topics
   public void initContent()
   {
      // con is a class to hold info. Instances of con will be 
      // put to hash table. con has 3 fields: content, a string 
      // such as "joos" or "virtual machine", topicnum, a int 
      // representing which topic "joos" appears. and next, a con 
      // reference. The objects are hashed according to the order
      // of the first character of content. If you hava 2 objects 
      // with the same first character then they are chained.
      con C;  
      int i,j,k;
      JoosIO f;
      i = 0;
      // initialize hash table
      while (i < 26){
        topics.addElement(null);
        i = i + 1;}
      i=0;
      j=0;
      k=0;
      f = new JoosIO();

      // put all content to hash table
      while (i < content.length())
      { int top;
        String s;
        int index;

        // j is the length of one "piece" content
        j=content.charAt(i)-'0';
        j= j*10 + content.charAt(i+1)-'0';

        // s is the "piece"
        s = content.substring(i, i+j);

        // top is the topic number
        top = s.charAt(2)-'0';

        // when topic ==0, then it means topic number is 10
        if (top==0)
          k++;
        top = k*10 +top;

        // s get rid of length and topic number
        s = s.substring(3, s.length());

        // index is the first char of s, i.e., hash key value.
        index = s.charAt(0)-'A';

        // C is the object to put; notice next of C is the 
        // current topics.elemnentAt(index). If it is null, then next
        // simply is null
        C = new con(top,s,(con)topics.elementAt(index));
        topics.setElementAt(C,index);

        // go to next piece
        i = i + j;
        j=0;
      } }

  // calculate the next deliverable based on the current date
   public void calculateDel()
   {   date d; // a class used to get day and month
       int day, mon;
       day = 0;
       mon = 0;
       d = new date();
       day = d.findDay();
       mon = d.findMonth();
       delivery = "The coming delivery is:";

       // do the calculation according current date
       if (mon==8 && day < 24){
           delivery = delivery + "benchmark";}
       else if (mon <9 ){
           delivery = delivery + "comment and desurging";}
       else if (mon == 9 && day < 15){
           delivery = delivery + "WIG scanner and parser";}
       else if (mon == 9 &&  day < 22){
           delivery = delivery + "WIG symbol tables";}
       else if (mon == 9 && day < 29){
           delivery = delivery + "WIG tye checking";}
       else if ((mon == 10&& day<5) ||( mon == 9 && day >=29)){
           delivery = delivery + "JOOS stack limit";}
       else if (mon == 10 && day < 12){
           delivery = delivery + "JOOS peephole pattern";}
       else if ((mon == 10 && day > 12) || (mon == 11 && day < 3)){
           delivery = delivery + "report";}
   }

   public String getsummary()
   { return summary;}

   public con gettopic(int i)
     {return (con)topics.elementAt(i);}

   public String getdelivery()
   { return delivery;}
     
   public static void main (Integer argv[]){
    JoosIO f;
    int i, count;
    con C;
    board b;
    String s;
    s=new String();
    b= new board();
    f = new JoosIO();
    b.initSummary();
    b.initContent();
    b.calculateDel();
    // interacting with user
    while (s.compareTo("end")!=0)
    {   f.println("");
    	f.println("***********************************************");
        f.println("Welcome to CS520 - Info Program.");
        f.println("Enter 'g' for general info");
	f.println("      'd' to see the delivery");
        f.println("      't' to search for a topic");
	f.println("      'l' to list topics in alphabetical order");
	f.println("      'end' to end the program.");

        s = f.readLine();

        if (s.compareTo("g")==0 || s.compareTo("G")==0)
	   f.println(b.getsummary());

        if (s.compareTo("d")==0 || s.compareTo("D")==0)
           f.println(b.getdelivery());
	
	if (s.compareTo("l")==0 || s.compareTo("L")==0){
           i=0;
           count=0;
           while (i <26){
             C = b.gettopic(i);
             
             if (C != null){

                while (C!=null){

                   f.print(C.getcontent());
                   f.print(" - Topic ");
                   f.println((new Integer(C.gettopnum())).toString());

		   if (count >= 15){
		      count=0;
                      f.println ("Press 'Enter' to continue");
                      s= f.readLine();
                   }
                   count= count +1;
                   C=C.getnext();
                }
 	     }
           i=i+1;
           }
	}
        
        if (s.compareTo("t")==0 || s.compareTo("T")==0){
           f.println("Enter the first letter for your keyword");
           s = f.readLine();
           i=s.charAt(0)-'a';
           if (i < 0 || i > 26) 
		   i = i-'A'+'a';
           C =b.gettopic(i);
           if (C==null)
            f.println("Sorry the topic is not found");
           while (C!=null){
             f.print(C.getcontent());
             f.print(" and the topic is in Topic");
             f.println((new Integer(C.gettopnum())).toString());
             C=C.getnext();
           }
         }
    }    
    }
}