import joos.lib.*;

public class mNode extends Object
{
	protected String NodeName;
	protected int x, y; /*coordination of the node*/
	
	public mNode(){
		super();
	}

	public mNode(String name, int ax, int ay){
		super();
		NodeName = name;
		x = ax;
		y = ay;
	}

	public String getName(){
 		return NodeName;	
	}
	public void setName(String name){
		NodeName = name;
	}

	public int getX(){
		return x;
	}
        public int getY(){
        	return y;
	}
        public void setX(int val){
        	x = val;
	}
        public void setY(int val){
        	y = val;
	}
}
