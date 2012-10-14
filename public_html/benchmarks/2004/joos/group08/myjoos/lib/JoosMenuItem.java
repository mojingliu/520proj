/*
 * Created on Sep 28, 2004
 *
 * @author Shahla Almasri
 *
 * This class is a wraper around JMenuItem in swing.
 */
package myjoos.lib;

import javax.swing.JMenuItem;

public class JoosMenuItem extends JMenuItem {
	
	/***************************************************************************************
	 * Constructor
	 * @param str	the label of the item
	 */
	public JoosMenuItem(String str) {
		super(str);
	}
	
	/***************************************************************************************
	 * This is a workaround for avoiding using the interface ActionListener, since JOOS does not
	 * support interfaces. 
	 * @param frame	the JoosFrame listening to actions from this menu item.
	 */
	public void addActionListener(JoosFrame frame) {
		super.addActionListener(frame);
	}
	
	/***************************************************************************************
	 * 
	 * @return this instance as a JMenuItem object
	 */
	public JMenuItem getJMenuItem() {
		return ((JMenuItem) this);
	}

}
