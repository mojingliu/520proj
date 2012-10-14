/*
 * Created on Sep 25, 2004
 * 
 * @author Shahla Almasri
 * 
 * This class is a wraper around some constants in swing.
 */
package myjoos.lib;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;

public class MyJoosConstants extends Object {
	/***************************************************************************************
	 * Constructor
	 */
	public MyJoosConstants() { super();	}
	
	/***************************************************************************************
	 * 
	 * @return	SwingConstants.CENTER
	 */
	public int SWING_CENTER()        { return SwingConstants.CENTER;       }
	
	/***************************************************************************************
	 * 
	 * @return	JFrame.EXIT_ON_CLOSE
	 */
	public int EXIT_ON_CLOSE()		 { return JFrame.EXIT_ON_CLOSE; } 
	
	/***************************************************************************************
	 * 
	 * @return	JOptionPane.PLAIN_MESSAGE
	 */
	public int PLAIN_MESSAGE()		{ return JOptionPane.PLAIN_MESSAGE; }

}
