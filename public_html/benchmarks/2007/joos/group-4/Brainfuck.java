/* Brainfuck
This class represents a brainfuck interpreter. Brainfuck programs
*/

import joos.lib.*;
import java.util.*;


public class Brainfuck{
  protected Memory mem; //memory
  protected FuckIO io;
  protected String program; //holds all the fancy characters of the program


  //constructor
  public Brainfuck(){
    super();
    mem = new Memory();
    io = new FuckIO();
    program = io.readStdin();
  }


  //main
  public static void main(String[] args) {
    Brainfuck brainfucker;
    brainfucker = new Brainfuck();
    brainfucker.fuck();
  }


  //actually starts interpreting brainfuck code coming from stdin
  public void fuck(){
    int n;
    FuckStack stack;
    int id; //used to match brackets
    boolean go; //used in bracket matching
    char c;
    if (program.length() == 0) return;
    for(n=0;n<(program.length());n++){
      c = program.charAt(n);
        //>  increment the pointer (to point to the next cell to the right).
        if (c =='>'){
          mem.next();
        } else
        //<  decrement the pointer (to point to the next cell to the left).
        if (c =='<'){
          mem.prev();
        } else
        //+  increment (increase by one) the byte at the pointer.
        if (c =='+'){
          mem.inc();
        } else
        //-  decrement (decrease by one) the byte at the pointer.
        if (c =='-'){
          mem.dec();
        } else
        //.  output the value of the byte at the pointer.
        if (c =='.'){
          io.print((char)mem.get()+"");
        } else
        //,  accept one byte of input, storing its value in the byte at the pointer.
        if (c ==','){
          mem.set(io.getc());
        } else
        //[  jump forward to the command after the corresponding ] if the byte at the pointer is zero.
        if ((c =='[')&&(mem.get() == 0)){
          stack = new FuckStack();
          id = stack.push();
          go = true;
          while(go){
             n++;
             if (program.charAt(n) == ']'){
               if (stack.pop() == id){
                 go = false;
               }
             } else {
               if (program.charAt(n) == '['){
                 stack.push();
               }
             }
          }
          //n++; //maybe not maybe ... dunno
        } else
        //]  jump back to the command after the corresponding [ if the byte at the pointer is nonzero.
        if ((c ==']')&&(mem.get() != 0)){
          stack = new FuckStack();
          id = stack.push();
          go = true;
          while(go){
            n = n-1;
            if (program.charAt(n) == '['){
              int id2;
              id2 = stack.pop();
              if (id2 == id) go = false;
            } else {
              if (program.charAt(n) == ']'){
                stack.push();
              }
            }
          }
        }
     }
  }
}





