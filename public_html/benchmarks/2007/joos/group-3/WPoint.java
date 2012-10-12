
public class WPoint {
	
	protected int x;
	protected int y;
	
	public WPoint(int xp, int yp) {
		super();
		x = xp;
		y = yp;
	}
	
	public int getX() { return x; }
	public int getY() { return y; }
	public void setPos(int xp, int yp) {
		x = xp;
		y = yp;
	}
	public void setX(int xp) {
		x = xp;
	}
	public void setY(int yp) {
		y = yp;
	}
	
	public String toString() {
		return "WPoint("+x+","+y+")";
	}
	
}
