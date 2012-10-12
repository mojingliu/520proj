import joos.lib.*;
import java.util.*;
import java.lang.*;

public class McMap
{
	public McMap()
	{
		super();
      	}

	public void ComputeDistanceMatrix(Vector lst, Vector tbl)
	{
		int i, j;
		int row, col;
		JoosIO f;

		i = 0;
		row = tbl.size();
		f = new JoosIO();

		while(i < row)
		{
			j = 0;
			col = ((Vector)tbl.elementAt(i)).size();
			
			while(j < col)
			{
				if(((Vector)tbl.elementAt(i)).elementAt(j) == null)
				{
					((Vector)tbl.elementAt(i)).setElementAt(new Integer(-1), j);
				}
				else
				{
					int x1, y1;
					int x2, y2;
					int distance;

					x1 = ((mNode)lst.elementAt(i)).getX();
					y1 = ((mNode)lst.elementAt(i)).getY();
					x2 = ((mNode)lst.elementAt(j)).getX();
					y2 = ((mNode)lst.elementAt(j)).getY();

					distance = this.ComputeDistance(x1,y1,x2,y2);
					((Vector)tbl.elementAt(i)).setElementAt(new Integer(distance), j);
				}
				//f.print(((Vector)tbl.elementAt(i)).elementAt(j).toString() + " ");
				j = j + 1;
			}
			//f.println("\n");
			i = i + 1;
		}
	}
	
	public int ComputeDistance(int x1, int y1, int x2, int y2)
	{
		int dx, dy;
		int distance;

		dx = x2-x1;
		dy = y2-y1;
		distance = this.sqrt(dx*dx + dy*dy);
		if(distance == 0) distance = 1;
		return distance;
	}
  
     	public int sqrt(int x)
	{
		int i, a, e, r;
		int BITS, NN;

		a = 0;                  // accumulator...
		e = 0;                  // trial product...
		r=0;                    // remainder...	
		i=0; 
		BITS = 32;
		NN = 0;  		// range: 0...BITSPERLONG/2
	
		while (i < (BITS/2) + NN)
		{
			r = r * 4;
			r = r + (x / this.pow(2, (BITS - 2)));
			x = x * 4;
			
			a = a * 2;
			e = (a * 2) + 1;
			
			if(r >= e)
			{
				r = r - e;
				a = a + 1;
			}
		
			i = i + 1;
		}
	
		return a;
     	}

	public int pow(int x, int y)
	{
		int i, res;
		i = 0;
		res = 1;

		while(i < y)
		{
			res = res * x;
			i = i + 1;
		}
		
		return res;
	}

	public void ParseMap(Vector lst, Vector dstTable)
	{
		JoosRandomAccessFile io;

		int i, k;
		String str;
		StringTokenizer st;
		int b; // number of buildings
		int c; // number of crossings
		Integer bInt, cInt;
		
		Integer x, y, ie;
		Integer lnk, rec;
		String name;
		boolean ieB;
		Vector dstRow;
		
		io = new JoosRandomAccessFile("map", "r");
		str = io.readLine();

		st = new StringTokenizer(str, " ");
		bInt = new Integer(st.nextToken(" "));
		cInt = new Integer(st.nextToken(" "));
		b = bInt.intValue();
		c = cInt.intValue();
	
		k = 0;
		while(k < b+c)
		{
			dstTable.addElement(null);
			k = k + 1;
		}
	
		i = 0;
		while (i < b+c)
		{
			str = io.readLine();
			st = new StringTokenizer(str, " ");
			
			rec  = new Integer(st.nextToken(" "));
			name = st.nextToken(" ");
			x = new Integer(st.nextToken(" "));
			y = new Integer(st.nextToken(" "));
			ie = new Integer(st.nextToken(" "));
			
			if(ie.intValue() == 1)
				ieB = true;
			else
				ieB = false;
			
			dstRow = new Vector();
				
			k = 0;
			while(k < b+c)
			{
				dstRow.addElement(null);
				k = k + 1;
			}

			while(st.hasMoreTokens())
			{
				lnk = new Integer(st.nextToken(" "));
				dstRow.setElementAt(new Integer(1), lnk.intValue()-1);
			}
			
			if(i < b)
			{
				lst.addElement(new mBuildingNode(name, x.intValue(), y.intValue(), ieB));
			} else
			{
				lst.addElement(new mCrossNode(name, x.intValue(), y.intValue(), ieB));
			}
			
			dstTable.setElementAt(dstRow, i);
			i = i+1;
		}
	}

	public Vector ComputeShortestPath(Vector tbl, int src, int dest)
	{
		Vector route, spTable;
		int i, j, smallNumber;
		int tSize;
		JoosIO f;

		tSize = tbl.size();
                spTable = new Vector();
                {
                        Vector spRow;
                        i = 0;
                        while(i < tSize)
                        {
                                j = 0;
                                spRow = new Vector();

                                while(j < tSize)
                                {
                                        if(i != j)
                                        {
                                                spRow.addElement(new Integer(-1));
                                        }
                                        else
                                        {
                                                spRow.addElement(new Integer(2555));
                                        }

                                        j = j + 1;
                                }

                                spTable.addElement(spRow);
                                i = i + 1;
                        }
		}

		f = new JoosIO();
		route = new Vector();
		
		((Vector)spTable.elementAt(src)).setElementAt(new Integer(0), src);

		//f.println("check before");

		this.SPT(tbl, spTable, src, dest);

				//f.println("check after");

		if (((Integer)((Vector)spTable.elementAt(dest)).elementAt(dest)).intValue() == 2555)
			return null;
		
		//	i = 0;

		//while(i < tSize)
		//{
		//	j = 0;
		//	
		//	while(j < tSize)
		//	{
		//		f.print(((Vector)spTable.elementAt(i)).elementAt(j).toString() + " ");
		//		j = j + 1;
		//	}
		//	f.println("\n");
		//	i = i + 1;
		//}
		
		i = 0;
		route.addElement(new Integer(dest));
		while(dest != src )
		{	boolean b;
			b = true;
			i = 0;
	
			smallNumber = ((Integer)((Vector)spTable.elementAt(dest)).elementAt(dest)).intValue();
			while(i < tSize && b)
			{
				if(((Integer)((Vector)spTable.elementAt(dest)).elementAt(i)).intValue() == smallNumber && i!=dest)
				{
					route.addElement(new Integer(i)); 
					dest = i;
					b = false;
				}
				i = i+1;
			}
		}

		
		//f.println("before return");
		return route;
	}		

	public int SPT(Vector tbl, Vector spTable, int src, int dest)
	{
		JoosIO f;
		int i;
		f = new JoosIO();
		if(src == dest){
			return 1;
		}
		i = 0;
		while(i < tbl.size())
		{		
			int d2NextN;
			d2NextN = ((Integer)((Vector)tbl.elementAt(src)).elementAt(i)).intValue();

			//		f.println("check rec");

			if(d2NextN<0)
			{
				i = i+1; 
			}
			else 
			{  
			//	f.println("check before else");
				int bl, tmpn, tmpc, tmpf;
				bl = 0;	
	
				tmpn = ((Integer)((Vector)spTable.elementAt(i)).elementAt(src)).intValue();
				tmpc = ((Integer)((Vector)spTable.elementAt(src)).elementAt(src)).intValue();
				tmpf = ((Integer)((Vector)spTable.elementAt(i)).elementAt(i)).intValue();
	
				if(tmpn < 0)
				{
					((Vector)spTable.elementAt(i)).setElementAt(new Integer(d2NextN+tmpc), src);
					((Vector)spTable.elementAt(src)).setElementAt(new Integer(d2NextN+tmpc) ,i);
					if ( d2NextN+tmpc < tmpf) 
						((Vector)spTable.elementAt(i)).setElementAt(new Integer(d2NextN+tmpc) ,i);
					this.SPT(tbl, spTable, i, dest);
					i = i+1;
				}
				else if(tmpn<= d2NextN + tmpc) {
					i = i+1;
				}
				else {
					((Vector)spTable.elementAt(i)).setElementAt(new Integer(d2NextN+tmpc), src);
					((Vector)spTable.elementAt(src)).setElementAt(new Integer(d2NextN+tmpc) ,i);
					if (d2NextN+tmpc < tmpf) 
						((Vector)spTable.elementAt(i)).setElementAt(new Integer(d2NextN+tmpc) ,i);
					bl = this.SPT(tbl, spTable, i, dest);
					i = i+1;
				}
				//	f.println("check after else");
			}
		}
		return 0;
	}

	public void printer(Vector route, Vector nodelist, int time)
	{
		int l, i;
		JoosIO f;
		mNode node;

		f = new JoosIO();

		//f.println(route.toString());
		if(route == null) {
			 f.println("Sorry, there is no path between the two destinations.");	
		} else {
			f.println("Please follow the directions: ");
			i= 1;
			l = route.size();
			while (i<=l){
				node = (mNode)(nodelist.elementAt(((Integer)route.elementAt(l-i)).intValue()));
				if (i==1)
				f.println("Now you are at "+ node.getName());	
				else if (i==l)
				f.println("Well done! You are at "+node.getName());
				else
				f.println("Please head for "+node.getName());
				
				i = i + 1;
			}
		}

		f.println("Thank you for using McMap!\n");
	}

	public static void main(String[] args)
  	{
		McMap map;
		JoosIO io;
		Vector lst;
		Vector dstTable;

		map = new McMap();
		io = new JoosIO();
		lst = new Vector();
		dstTable = new Vector();

		map.ParseMap(lst, dstTable);
		map.ComputeDistanceMatrix(lst, dstTable);

		{
			String str;
    			StringTokenizer st;
			int src, dst, i;
			Integer sInt, dInt;
			Vector route;
			mNode node;

			i=0;
			io.println("Please select the buildings from the list:\n");
			while(i < lst.size())
			{
				node = (mNode)(lst.elementAt(i));
				io.println("Number: " + i + " Name: " + node.getName());
				i = i + 1;
			}
			io.println("\nStart\tDestination\n");
			
			str = io.readLine();
			while (str != null)
			{
				st = new StringTokenizer(str, " ");
				sInt = new Integer(st.nextToken(" "));
				dInt = new Integer(st.nextToken(" "));
				
				src = sInt.intValue();
				dst = dInt.intValue();
				
				route = map.ComputeShortestPath(dstTable, src, dst);
				map.printer(route, lst, new Date().getHours());			

				str = io.readLine();
			}
		}
	}
}
