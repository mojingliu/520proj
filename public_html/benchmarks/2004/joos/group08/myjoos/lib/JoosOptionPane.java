/*
 * Created on Sep 29, 2004
 *
 *	 @author Shahla Almasri
 *
 * This class is a wraper around JOptionPane in swing.
 */
package myjoos.lib;

import java.awt.Component;
import javax.swing.JOptionPane;

public class JoosOptionPane extends JOptionPane {
	
	/***************************************************************************************
	 * Empty constructor
	 *
	 */
	public JoosOptionPane() {
		super();
	}

	/***************************************************************************************
	 * Shows a simple message dialog	
	 * @param parent	the parent of this dialog
	 * @param message	message to display
	 * @param title		the dialog's title
	 * @param messageType	the message type
	 */		
	public void show(Component parent, Object message, String title, int messageType) {
		JOptionPane.showMessageDialog(parent, message, title, messageType);
	}

}
