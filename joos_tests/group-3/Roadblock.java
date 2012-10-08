import java.util.Vector;
import joos.lib.*;

public class Roadblock extends SpatialObject {
	
	protected char top;
	protected int width;

	public Roadblock(char blockTop, int blockWidth, WPoint p) {
		super();
		top = blockTop;
		width = blockWidth;
		this.setPos(p);
	}
	
	public Vector getArt() {
		Vector v;
		int i;
		String s;

		s = "";
		v = new Vector();
		for(i=0;i<width;i++) {
			s = s + top;
		}
		v.addElement(s);
		
		s = "|";
		for(i=0;i<width-2;i++) {
			s = s + " ";
		}
		s = s + "|";
		v.addElement(s);		

		return v;
	}
	
	
	public void handleTimeChange(int totalUs, int deltaUs) {
		

		if( (totalUs % (1200000)) < 600000 ) {
			top = '\\';
		}
		else {
			top = '/';
		}
	}
	
}
