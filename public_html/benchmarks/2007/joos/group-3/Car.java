import java.util.Vector;
import joos.lib.*;

public class Car extends Vehicle {
	
	public Car() {
		super();
	}
	
	public Vector getArt() {
		Vector v;
		v = new Vector();
		v.addElement(" ___ ");
		v.addElement(")___(");
		v.addElement("|   |");
		v.addElement("|   |");
		v.addElement(")___(");
		return v;
	}
	
	public void handleTimeChange(int totalUs, int deltaUs) {
		this.setPos(new WPoint(this.getPos().getX(), 5*4*(17*totalUs)/100000 ));
	}
	
	public WPoint getCenterOfMass(World w) {
		WPoint del;
		del = w.terminalToWorld(new WPoint(2,-2));
		return new WPoint(p.getX()+del.getX(), p.getY()+del.getY());
	}
}
