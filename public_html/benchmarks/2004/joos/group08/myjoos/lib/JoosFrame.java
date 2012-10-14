/*
 * Created on Sep 28, 2004
 * 
 * @author Shahla Almasri
 *
 * This class is a wraper around JFrame in swing.  For this program's requiements, the class
 * had to implement ActionListener and ItemListener. 
 * 
 */
package myjoos.lib;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.JFrame;

public class JoosFrame extends JFrame implements ActionListener, ItemListener{
	
		/***************************************************************************************
	 	 * Constructor
	 	 * @param title		the frame's title
	 	 */
		public JoosFrame(String title) {
				super(title);
		}
		
		/***************************************************************************************
		 * Callback for ActionListener
		 * @param event	
		 */
		public void actionPerformed(ActionEvent event) {
		}
		
		/***************************************************************************************
	 	 * Callback for ItemListener
	 	 * @param event
	 	 */
		public void itemStateChanged(ItemEvent event) {	
		}	
}
