import joos.lib.*;
import java.util.*;
import java.awt.*;
import java.applet.Applet;

public final class TestFor {

  public TestFor() { super(); }

  public static void main(String argv[])
   { Object o1, o2;
     int i1;
     boolean b1, b2, b3;
     String s;
     JoosIO f;
     int i;

     f = new JoosIO();
     i = 0;
     i++;
     f.println("Wowie++!!! " + (i++) + " == 1");
     i += 50;
     f.println("Kazowie+=!!! " + (i+=50) + " == 102");
    }
} 
