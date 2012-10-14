import java.util.Vector;
import joos.lib.*;

public class Sign extends SpatialObject {
	
	protected String s;
	
	public Sign(String sp, WPoint p) {
		super();
		s = sp;
		this.setPos(p);
	}
	
	public Vector getArt() {
		Vector v;
		v = new Vector();
		v.addElement(" __ ");
		v.addElement("/  \\");
		v.addElement(s);
		v.addElement("\\__/");
		v.addElement(" || ");
		return v;
	}
	
}
