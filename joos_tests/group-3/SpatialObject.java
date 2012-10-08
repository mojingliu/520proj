import java.util.Vector;
import joos.lib.*;

public class SpatialObject {
	
	protected WPoint p;

	public SpatialObject() {
		super();
	}
	
	
	public void setPos(WPoint pp) {
		p = pp;
	}
	
	public WPoint getPos() {
		return p;
	}
	
	public Vector getArt() {
		Vector v;
		v = new Vector();
		v.addElement("?");
		return v;
	}
	
	public void handleTimeChange(int totalUs, int deltaUs) {
		
	}
	
	public WPoint getCenterOfMass(World w) {
		return p;
	}
}
