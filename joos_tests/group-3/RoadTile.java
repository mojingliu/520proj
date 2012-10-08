import java.util.Vector;
import joos.lib.*;

public class RoadTile extends SpatialObject {
	
	public RoadTile() {
		super();
	}
	
	public Vector getArt() {
		Vector v;
		v = new Vector();
		v.addElement("#");
		return v;
	}
	
}
