import java.util.Vector;
import joos.lib.*;

public class World {
	
	protected Vector objects;// <SpatialObject>
	protected int microseconds;

	protected int xPerChar;
	protected int yPerChar;
	
	protected WPoint cameraCenter;
	
	protected SpatialObject centerObj;
	
	public World(int xp, int yp, Vector signs) {
		super();
		
		objects = new Vector();
		microseconds = 0;
		
		// idea: 1000 world units per inch
		xPerChar = xp;
		yPerChar = yp;
		
		centerObj = this.defaultWorld(signs);
	}
	
	
	public void runWorld(int worldDurationSeconds, int fps, Animator a) {
		int i,j;
		SpatialObject so;
		int curUs,lastUs;
		JoosIO f;
		
		f = new JoosIO();
		
		curUs = 0;
		lastUs = 0;
		for(i=0; i<worldDurationSeconds*fps; i++) {
			
			curUs = i*1000000/fps;
			
			a.fillCanvas(' ');
			
			
			for(j=0; j < objects.size(); j++) {
				so = (SpatialObject)objects.elementAt(j);
				so.handleTimeChange(curUs, curUs-lastUs);
			}
			
			cameraCenter = centerObj.getCenterOfMass(this);
			
			for(j=0; j < objects.size(); j++) {
				so = (SpatialObject)objects.elementAt(j);
				a.drawSprite(this.worldToTerminal(so.getPos()), so.getArt(), this.worldToTerminal(cameraCenter) );
			}
			
			a.printFrame();
			
			//f.println("Camera: "+cameraCenter+" world, "+this.worldToTerminal(cameraCenter)+" termworld");
			//f.println("Car: "+centerObj.getPos()+" world, "+this.worldToTerminal(centerObj.getPos())+" termworld");
			//f.println("Roadblock: "+((SpatialObject)(objects.elementAt(1))).getPos()+" world, "+this.worldToTerminal(((SpatialObject)(objects.elementAt(1))).getPos())+" termworld");
			
			lastUs = curUs;
			new JoosThread(null).sleep(1000/fps);
		}
	}
	
	
	public WPoint terminalToWorld(WPoint p) {
		return new WPoint(  p.getX()*xPerChar  ,  p.getY()*yPerChar  );
	}
	public WPoint worldToTerminal(WPoint p) {
		return new WPoint(p.getX()/xPerChar,p.getY()/yPerChar);
	}
	
	
	public SpatialObject defaultWorld(Vector signs) {
		
		Car car;
		RoadTile tile;
		int i;
		SpatialObject left,right;
		
		car = new Car();
		car.setPos(new WPoint(0,0));
		objects.addElement(car);
		
		for(i=0; i<200; i++) {
			
			if( i%2 == 1 ) {
				left = new Sign((String)signs.elementAt((2*i+1) % signs.size()),this.terminalToWorld(new WPoint(-13,5+10*i)));
				right = new Sign((String)signs.elementAt((2*i) % signs.size()),this.terminalToWorld(new WPoint(13,0+10*i)));
			}
			else {
				left = new Roadblock('\\',5,this.terminalToWorld(new WPoint(-13,5+10*i)));
				right = new Roadblock('\\',5,this.terminalToWorld(new WPoint(13,0+10*i)));
			}
			
			objects.addElement(left);
			objects.addElement(right);
		}

		for(i=-30; i<3000; i++) {
			tile = new RoadTile();
			tile.setPos(this.terminalToWorld(new WPoint(-18,1*i)));
			objects.addElement(tile);
		}
		for(i=-30; i<3000; i++) {
			tile = new RoadTile();
			tile.setPos(this.terminalToWorld(new WPoint(22,1*i)));
			objects.addElement(tile);
		}
		
		
		return car;
	}
	
	
	
}
