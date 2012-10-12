import joos.lib.*;

public class mCrossNode extends mNode {
	protected boolean isEntrance;

	public mCrossNode(String name, int x, int y, boolean e){
		super(name, x, y);
		isEntrance = e;	
	}

	public boolean getIsEntrance(){
		return isEntrance;
	}
	public void setIsEntrance(boolean b){
		isEntrance = b;
	}
}
