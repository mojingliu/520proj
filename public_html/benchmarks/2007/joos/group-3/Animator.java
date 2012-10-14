

import joos.lib.*;
import java.util.*;

public class Animator {
	
	protected int w;
	protected int h;
	protected int tw;
	protected int th;
	protected JoosIO f;
	
	protected Vector canvas;
	
	// Mac: 90x26
	public Animator(int width, int height, int terminalWidth, int terminalHeight) {
		
		super();

		int i;

		f = new JoosIO();
		w = width;
		h = height;
		tw = terminalWidth;
		th = terminalHeight;
		canvas = this.buildCanvas(w,h,' ');

	}
	
	public WPoint getDim() {
		return new WPoint(w,h);
	}
	
	public void fillCanvas(char bgcolor) {
		canvas = this.buildCanvas(w, h, bgcolor);
	}
	
	
	public Vector buildCanvas(int w, int h, char bgcolor) {
		Vector rows, row;
		int i,j;
		rows = new Vector();
		for(i=0; i < h; i++) {
			row = new Vector();
			for(j=0; j < w; j++) {
				row.addElement(new Integer(bgcolor));
			}
			rows.addElement(row);
		}
		return rows;
	}
	
	
	public void randomizeCanvas() {
		Random r;
		int i;
		r = new Random();
		i = (r.nextInt() % (47-33)) + 33;
		canvas = this.buildCanvas(w,h,(char)i);
	}
	
	public void drawSprite(WPoint spriteTermworld, Vector art, WPoint cameraCenter) {
		// Assumptions: art is a Vector of same-length strings
		// termPoint is in termworld coords
		// cameraCenter is in termworld coords
		int aw,ah,i,j,dx,dy;
		int xcs,ycs;// cartes. scr.
		WPoint spritePointOnTerminal,screenTermworldCoords;
		
		ah = art.size();
		if( ah == 0 ) {
			return;
		}
		aw = ((String)(art.elementAt(0))).length();
		
		// screenTermworldCoords = ();
		// spritePointOnTerminalNormalDir = spriteTermworld - screenTermworldCoords
		// spritePointOnTerminal : flip y


		screenTermworldCoords = new WPoint(cameraCenter.getX() - (w/2), cameraCenter.getY() - (h/2));
		spritePointOnTerminal = new WPoint(spriteTermworld.getX()-screenTermworldCoords.getX(), h+(-1)*(spriteTermworld.getY()-screenTermworldCoords.getY()));
		
		//f.println("spritePointOnTerminal: "+spritePointOnTerminal);

		// handle out of bounds
		
		for(dx=spritePointOnTerminal.getX(); (dx-spritePointOnTerminal.getX() < aw) && (dx < w) && (dx>0); dx++) {
			for(dy=spritePointOnTerminal.getY(); (dy-spritePointOnTerminal.getY() < ah) && (dy < h) && (dy>0); dy++) {
				
				((Vector)canvas.elementAt(dy)).setElementAt(   new Integer(  ((String)art.elementAt(dy-spritePointOnTerminal.getY())).charAt(dx-spritePointOnTerminal.getX())  ), dx);
			}
		}
	}
	
	public void printFrame() {
		Vector row;
		
		int i,j,pl,pr,pt,pb,temp;
		String frame;
		
		
		frame = "";
		
		pl = ((tw-w)/2);
		pr = tw-w-pl;
		
		pt = ((th-h)/2);
		pb = th-h-pt-1;
		
		

		for(temp=0; temp<pt; temp++) { frame = frame + "\n"; }

		for(i=0; i < h; i++) {

			for(temp=0; temp<pl; temp++) { frame = frame + " "; }

			row = (Vector)canvas.elementAt(i);
			for(j=0; j < w; j++) {
				frame = frame + (char)(((Integer)(row.elementAt(j))).intValue());
			}

			for(temp=0; temp<pr; temp++) { frame = frame + " "; }

		frame = frame + "\n";	
		}

		for(temp=0; temp<pb; temp++) { frame = frame + "\n"; }
		
		f.print(frame);
		
		
	}
	
}
