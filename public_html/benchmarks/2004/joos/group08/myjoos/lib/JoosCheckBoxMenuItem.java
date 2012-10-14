/*
 * Created on Sep 28, 2004
 *
 * @author Shahla Almasri
 *
 * This class is a wraper around JCheckBoxMenuItem in swing.
 */
package myjoos.lib;

import javax.swing.JCheckBoxMenuItem;

public class JoosCheckBoxMenuItem extends JCheckBoxMenuItem {
	
	/******************************************************************************************
	/* constructor
	 * 
	 * @param str	the checkbox's label
	 */
	public JoosCheckBoxMenuItem(String str) {
		super(str);
	}
	
	/******************************************************************************************
	 * This is a workaround for avoiding using the interface ItemListener, since JOOS does not
	 * support interfaces. 
	 * @param frame		the JoosFrame that is listening to events from this check box
	 */
	public void addItemListener(JoosFrame frame) {
			super.addItemListener(frame);
	}
	
	/******************************************************************************************
	 * 
	 * @return	this instance as a JCheckBoxMenuItem object
	 */
	public JCheckBoxMenuItem getJCheckBoxMenuItem() {
			return ((JCheckBoxMenuItem) this);
	}
}
