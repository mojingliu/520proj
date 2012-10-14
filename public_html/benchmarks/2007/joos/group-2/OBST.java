///*
// * OBST.java
// *
// * Created on February 21, 2005, 8:25 PM
// * Programmed by Terry Sznober (terry.sznober@unb.ca)
// * and Diana Gheorghiu (i0bb3@unb.ca)
// * CS 3913 Winter 2005
// * Modified October 1, 2007 for COMP 520 to be compatible with JOOS.
// * Diana Gheorghiu and Gina Jeong, Group 2
// */

import java.io.FileReader;
import java.io.BufferedReader;
import java.text.NumberFormat;
import java.util.Vector;
import joos.lib.*;

///**
// *
// * @author Terry
// */
public class OBST
{
//    private String[] s; /** Vector of Strings that holds the OBST keys*/
	protected Vector s; 
	//    private double[] p; /** Vector of Doubles that holds p values*/
	protected Vector p; 
//    private double[] q; /** Vector of Doubles holds q values*/
	protected Vector q; 
//    private double[][] cost; /** Vector of Vectors of Doubles that holds cost memoization table*/
	protected Vector cost; 
//    private int[][] root; /** Vector of Vectors of Integers that holds root node memoization table*/
    protected Vector root; 
    ///** Number of OBST keys*/
    protected int n; 
    ///** IO handler */
    protected  JoosIO f; 
    protected JoosSystem joosys;
    
//    /** Creates a new instance of OBST */
    public OBST()
    {
    	super();
    	f = new JoosIO();
    	joosys = new JoosSystem();
    }
    
    public void run()
    {
        this.loadFile();
//        printInput();
        this.memoizedObst();
//        printTable(cost,"cost");
//        printTable(root,"root");
        f.println("The expected cost of a find on this OBST is " + ((Vector)cost.elementAt(1)).elementAt(n));
        f.print("The root node is ");
        f.println((s.elementAt(((Integer)((Vector)root.elementAt(1)).elementAt(n)).intValue())).toString());
//        f.println("\"");
        this.printObstNode(1,n,((Integer)((Vector)root.elementAt(1)).elementAt(n)).intValue());
    }
    
    public void printInput()
    {
    	int i;
        f.print("n = ");
        f.println(new Integer(n).toString());
        
        i = 0;
        while(i <= n) 
        {
            if(i == 0)
            {
                f.print("q[");
                f.print(new Integer(i).toString());
                f.print("] = ");
                f.println((((Integer)q.elementAt(i)).toString()));
            }
            else
            {
                f.println("s[" + i + "] = " + s.elementAt(i) + ", p[" + i + "] = " + ((Integer)p.elementAt(i)).intValue() + ", q[" + i + "] = " + ((Integer)q.elementAt(i)).intValue());
            }
            i = i + 1;
        }
    }
    
    public void loadFile()
    {
    	int i;
        int j;
        int k;
    
        String temp;
        
        // Get the value of n
        //temp = f.readLine();
        n = f.readInt();
        
        // Allocate memory for s, p, q, cost, root, and w
        s = new Vector(n+1);
        p = new Vector(n+1);
        q = new Vector(n+1);
        cost = new Vector();
        j = 0;
        while(j < n+2)
        {
        	cost.addElement(new Vector(n+1));
        	k = 0;
        	while(k < n+1)
        	{
        		((Vector)cost.elementAt(j)).addElement(new Integer(0));
        		k = k + 1;
        	}
        	j = j + 1;
        }
        root = new Vector();
        j = 0;
        while(j < n+2)
        {
        	root.addElement(new Vector(n+1));
        	k = 0;
        	while(k < n+1)
        	{
        		((Vector)root.elementAt(j)).addElement(new Integer(0));
        		k = k + 1;
        	}
        	j = j + 1;
        }
        
        // Get the value of q[0]
        //temp = f.readLine();
        q.addElement(new Integer(f.readInt()));
        
        // Put phony values in s[0], and p[0]
        s.addElement("");
        p.addElement(new Integer(-1));
        
        i = 1;
        while(i <= n)
        {
            // OBST key
            temp = f.readLine();
            if (temp == null)
            {
            	f.println("Format error in input!!");
            	joosys.exit(1);
            }
            s.addElement(temp);
            
            // p value
            //temp = f.readLine();
            //if (temp == null)
            //{
            //	f.println("Format error in input!!");
            //	joosys.exit(1);
            //}
            p.addElement(new Integer(f.readInt()));
            
            // q value
            //temp = f.readLine();
            //if (temp == null)
            //{
            //	f.println("Format error in input!!");
            //	joosys.exit(1);
            //}		
            q.addElement(new Integer(f.readInt()));
            i = i + 1;
        }
    }
    
    public void memoizedObst()
    {
    	int i;
    	int j;
    	int k;
    	int l;
    	Integer sum;
    	
    	i = n + 1;
        while(i >= 1)
        {
        	j  = i - 1;
            while(j <= n)
            {
                Integer bestCost;
                int bestRoot;
                bestRoot = -1;
                bestCost = new Integer(0);
                
                if(j < i)
                {
                    bestCost = new Integer(0);
                    bestRoot = -1;
                }
                else
                {
                    bestCost = new Integer(2147483647);
                }
                
                k = i;
                while(k <= j)
                {
                    sum = new Integer(((Integer)((Vector)cost.elementAt(i)).elementAt(k-1)).intValue() + ((Integer)((Vector)cost.elementAt(k+1)).elementAt(j)).intValue());
                    
                    l = i;
                    while(l <= j)
                    {
                        sum = new Integer(sum.intValue() + ((Integer)p.elementAt(l)).intValue() + ((Integer)q.elementAt(l)).intValue());
                        l = l + 1;
                    }
                    sum = new Integer(sum.intValue() + ((Integer)q.elementAt(0)).intValue());
                
                    if(sum.intValue() < bestCost.intValue())
                    {
                        bestCost = sum;
                        bestRoot = k;
                    }
                    k = k + 1;
                }
                ((Vector)root.elementAt(i)).setElementAt(new Integer(bestRoot), j);
                ((Vector)cost.elementAt(i)).setElementAt(bestCost, j);
                j = j + 1;
            }
            i = i -1;
        }
        
    }

//    private void printTable(double[][] t, String tableName)
//    {
//        NumberFormat nf = NumberFormat.getInstance();
//        nf.setMaximumFractionDigits(7);
//        nf.setMaximumIntegerDigits(3);
//
//        System.out.println(tableName + " table:");
//        for(int i = 0; i < t.length; i++)
//        {
//            for(int j = 0; j < t[i].length; j++)
//            {
//                System.out.print("[" + i + "," + j + "] = " + nf.format(t[i][j]) + "\t");
//            }
//            System.out.println("");
//        }
//    }
//    
//    private void printTable(int[][] t, String tableName)
//    {
//        System.out.println(tableName + " table:");
//        for(int i = 0; i < t.length; i++)
//        {
//            for(int j = 0; j < t[i].length; j++)
//            {
//                System.out.print("[" + i + "," + j + "] = " + t[i][j] + "\t");
//            }
//            System.out.println("");
//        }
//    }
    
    public synchronized void printObstNode(int left, int right, int parent)
    {
        String str;
        int node;
        int leftChild;
        int rightChild;
        
        node = ((Integer)((Vector)root.elementAt(left)).elementAt(right)).intValue();
        str = "";
        
        if(node < 0)
        {
            return;
        }
        
        leftChild = ((Integer)((Vector)root.elementAt(left)).elementAt(node-1)).intValue();
        rightChild = ((Integer)((Vector)root.elementAt(node+1)).elementAt(right)).intValue();
        
        if(leftChild >= 0 && leftChild <= n)
        {
            f.print((String)s.elementAt(leftChild));
            f.print(" is left child of ");
            f.println((String)s.elementAt(node));
            
            if(left < parent)
            {
                this.printObstNode(left,node-1, node);
            }
            else
            {
                this.printObstNode(parent + 1,node-1, node);
            }
        }
        
        if(rightChild >= 0 && rightChild <= n)
        {
            f.print((String)s.elementAt(rightChild));
            f.print(" is right child of ");
            f.println((String)s.elementAt(node));
            if(right > parent)
            {
                this.printObstNode(node+1,right, node);
            }
            else
            {
                this.printObstNode(node + 1,parent - 1, node);
            }
        }
    }
    
//    /**
//     * @param args the command line arguments
//     */
    public static void main(String[] argv)
    {
    	JoosIO f2;
    	JoosSystem js;
        OBST obst;
        obst = new OBST();
        f2 = new JoosIO();
        js = new JoosSystem();
        
//        if(argv.length == 1)
//        {
            obst.run();
            js.exit(0);
//        }
//        else
//        {
//            f2.println("Usage: java OBST");
//            js.exit(1);
//        }
    }
    
}
