/*

	ARS Driving

ASCII Road Simulation Driving

            or

     The Art of Driving




Version 0.1

*/
import java.util.Vector;
import joos.lib.*;

public class ArsDriving {
	
	public ArsDriving() {
		super();
	}
	public static void main(String argv[]) {
		
		Animator a;
		World w;
		int i;
		String s;
		Vector signs;
		JoosIO f;

		f = new JoosIO();
		
		f.println("Enter four-letter words (each on a new line), then press CTRL-D");
		signs = new Vector();
		s = f.readLine();
		while(s != null) {
			signs.addElement(s);
			s = f.readLine();
		}
		
		a = new Animator(79,19,79,27);
		//a = new Animator(50,30,55,35);
		
		w = new World(120,250, signs);
		w.runWorld(5,15,a);
	}
	
	
	
	
	
	
}
