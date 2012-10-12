import joos.lib.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class A
{
      public A()
      {
	 super();
      }
      public Vector augmentingPath(Vector graph, int source, int sink)
      {
	 Vector path;
	 Vector queue;
	 int q_end;
	 int q_begin;
	 Vector visited;
	 Vector pred;
	 int i;
	 int current;
	 boolean done;

	 pred = new Vector();

	 queue = new Vector();
	 q_end = 0;
	 q_begin = 0;

	 visited = new Vector();

	 i = 0;
	 while (i < graph.size())
	 {
	    queue.addElement(null);
	    i = i+1;
	 }

	 i = 0;
	 while (i < graph.size())
	 {
	    pred.addElement(null);
	    i = i+1;
	 }

	 i = 0;
	 while (i < graph.size())
	 {
	    visited.addElement(new Boolean(false));
	    i = i+1;
	 }

	 queue.setElementAt(new Integer(source), q_end);
	 q_end = q_end + 1;
	 if (q_end >= queue.size())
	 {
	    q_end = q_end - queue.size();
	 }

	 while (q_begin != q_end)
	 {
	    current = ((Integer)queue.elementAt(q_begin)).intValue();
	    q_begin = q_begin + 1;
	    if(q_begin >= graph.size())
	    {
	       q_begin = q_begin - graph.size();
	    }

	    if (!((Boolean) visited.elementAt(current)).booleanValue() == true)
	    {
	       visited.setElementAt (new Boolean(true), current);

	       i = 0;
	       while (i<graph.size())
	       {
		  Vector v;
		  v = ((Vector)graph.elementAt(current));
		  if (((Integer) v.elementAt(i)).intValue() == 1 && ((Boolean) visited.elementAt(i)).booleanValue() == false)
		  {
		     queue.setElementAt(new Integer(i), q_end);
		     q_end = q_end + 1;
		     if (q_end >= queue.size())
		     {
			q_end = q_end - queue.size();
		     }
		     pred.setElementAt(new Integer(current), i);
		  }
		  i = i+1;
	       }
	    }
	 }
	 path = new Vector();
	 current = sink;
	 path.insertElementAt(new Integer(current), 0);
	 if ((pred.elementAt(current) != null))
	 {
	    current = ((Integer)pred.elementAt(current)).intValue();
	    if (current == sink)
	    {
	       path = null;
	       done = true;
	    }
	    else
	    {
	       path.insertElementAt(new Integer(current), 0);
	       done = false;
	    }
	 }
	 else
	 {
	    path = null;
	    done = true;
	 }
	 while (!done)
	 {
	    if (pred.elementAt(current) != null)
	    {
	       current = ((Integer)pred.elementAt(current)).intValue();
	       path.insertElementAt(new Integer(current), 0);
	       if (current == sink)
	       {
		  path = null;
		  done = true;
	       }
	       else if (current == source)
	       {
		  done = true;
	       }
	    }
	    else 
	    {
	       done = true;
	    }
	 }

	 if (path != null && path.size() == 1)
	 {
	    return path = null;
	 }
	 return path;
      }

      public int flow (Vector graph, int source, int sink)
      {
	 Vector queue;
	 Vector path;
	 int count;

	 count = 0;
	 path = new Vector();
	 while(path != null)
	 {
	    int i;
	    path = this.augmentingPath(graph, source, sink);
	    if (path != null)
	    {
	       count = count +1;
	       i = 1;
	       while (i < path.size())
	       {
		  int start; 
		  int end;
		  start = ((Integer)path.elementAt(i-1)).intValue();
		  end = ((Integer)path.elementAt(i)).intValue();

		  ((Vector) graph.elementAt(start)).setElementAt(new Integer(0), end);
		  ((Vector) graph.elementAt(end)).setElementAt(new Integer(1), start);

		  i = i+1;
	       }
	    }
	 }
	 return count;
      }

public BigDecimal distanceSquared(BigDecimal x1, BigDecimal y1, BigDecimal x2, BigDecimal y2)
  {
    BigDecimal retVal;
    BigDecimal retVal2;
    retVal = x1.subtract(x2).abs();
    retVal = retVal.multiply(retVal);
    retVal2 = y1.subtract(y2).abs();
    retVal2 = retVal2.multiply(retVal2);
    return retVal.add(retVal2);
  }
  public static void main(String[] args)
  {
    A thisA;
    JoosIO io;
    int i;
    int j;
    String str;
    StringTokenizer st;
    String delim;
    int matching;

    thisA = new A();
    delim = " ";
    io = new JoosIO();
    str = io.readLine();
    while (str != null)
    {
      int n; // number of gophers
      int m; // number of holes
      Integer nInt;
      Integer mInt;
      BigDecimal seconds;
      BigDecimal velocity;
      BigDecimal maxDistanceSquared;

      Vector gopherX;
      Vector gopherY;
      Vector holeX;
      Vector holeY;
      Vector graph;

      int numVulnerable;

      //
      // Parsing the input;
      //
      st = new StringTokenizer(str, " ");
      nInt = new Integer(st.nextToken(" "));
      mInt = new Integer(st.nextToken(" "));
      seconds = new BigDecimal(st.nextToken(" "));
      velocity = new BigDecimal(st.nextToken(" "));
      maxDistanceSquared = seconds.multiply(velocity);
      maxDistanceSquared = maxDistanceSquared.multiply(maxDistanceSquared);
      n = nInt.intValue();
      m = mInt.intValue();
      gopherX = new Vector();
      gopherY = new Vector();
      holeX = new Vector();
      holeY = new Vector();


//
      // Reading the coordinates of the gophers
      //
      i = 0;
      while (i < n)
      {
        BigDecimal x;
        BigDecimal y;
        str = io.readLine();
        st = new StringTokenizer(str, " ");
        x = new BigDecimal(st.nextToken(" "));
        y = new BigDecimal(st.nextToken(" "));

        gopherX.addElement(x);
        gopherY.addElement(y);

        i = i+1;

      }
      //
      // Reading the coordinates of the holes
      //
      i = 0;
      while (i < m)
      {
        BigDecimal x;
        BigDecimal y;
        str = io.readLine();
        st = new StringTokenizer(str, " ");
        x = new BigDecimal(st.nextToken(" "));
        y = new BigDecimal(st.nextToken(" "));

        holeX.addElement(x);
        holeY.addElement(y);

        i = i+1;
      }

      // Initializind the graph
      graph = new Vector();
      i = 0 ;
      while ( i < n+m+2)
      {
        graph.insertElementAt(new Vector(), i);
        j = 0;
        while (j< n+m+2)
        {
          ((Vector) graph.elementAt(i)).insertElementAt(new Integer(0), j);
          j = j+1;
        }
        i = i + 1;
      }

//
      // Comput Valid edges
      // 0 is the source 1 is the sink
      //
      i = 0;
      while ( i < n )
      {
        BigDecimal gx;
        BigDecimal gy;
        ((Vector) graph.elementAt(0)).setElementAt(new Integer(1),i+2);

        gx = (BigDecimal) gopherX.elementAt(i);
        gy = (BigDecimal) gopherY.elementAt(i);

        j = 0;
        while ( j < m )
        {
          BigDecimal hx;
          BigDecimal hy;
          BigDecimal dist;

          hx = (BigDecimal) holeX.elementAt(j);
          hy = (BigDecimal) holeY.elementAt(j);

          dist = thisA.distanceSquared(gx,gy,hx,hy);
          //io.println ("found distance " + dist);
          if (dist.compareTo(maxDistanceSquared) <= 0)
          {
            //io.println ("smaller that " + maxDistanceSquared);
            ((Vector) graph.elementAt(i+2)).setElementAt(new Integer(1),n+j+2);
          }
          j = j+1;
        }
        i = i+1;
      }
      j = 0;
      while (j < m)
      {
        ((Vector)graph.elementAt(n+j+2)).setElementAt(new Integer(1), 1);
        j = j+1;
      }
      //thisA.printGraph(graph);

      matching = thisA.flow(graph, 0, 1);

      matching = 0;
      i = 0;
      while (i < graph.size())
      {
	 Vector v;
	 int val;
	 v = (Vector)graph.elementAt(0);
	 val = ((Integer)v.elementAt(i)).intValue();
	 if (val == 1)
	 {
	    matching = matching +1;
	 }
	 i = i+1;
      }

      numVulnerable = matching;
      io.println("" + numVulnerable);
      str = io.readLine();
    }
  }
}

