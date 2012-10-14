import joos.lib.*;

public class mBuildingNode extends mNode {
	protected boolean isIDReq;

	public mBuildingNode(String name, int x, int y, boolean id){
		super(name, x, y);
		isIDReq = id;
	}

	public boolean getIsIDReq(){
		return isIDReq;
	}
	public void setIsIDReq(boolean b){
		isIDReq = b;
	}
}