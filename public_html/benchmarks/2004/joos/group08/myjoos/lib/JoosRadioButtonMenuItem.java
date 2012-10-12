/*
 * Created on Sep 28, 2004
 *
 * @author Shahla Almasri
 *
 * This class is a wraper around JRadioButtonMenuItem in swing.
 */
package myjoos.lib;

import javax.swing.JRadioButtonMenuItem;

public class JoosRadioButtonMenuItem extends JRadioButtonMenuItem {
	
	/***************************************************************************************
	 * Constructor
	 * @param str
	 */
	public JoosRadioButtonMenuItem(String str) {
		super(str);
	}

	/***************************************************************************************
	 * This is a workaround for avoiding using the interface ActionListener, since JOOS does not
	 * support interfaces. 
	 * @param frame
	 */
	public void addActionListener(JoosFrame frame) {
			super.addActionListener(frame);
	}
	
	/***************************************************************************************
	 * 
	 * @return	this instance as a JRadioButtonMenuItem object
	 */
	public JRadioButtonMenuItem getJRadioButtonMenuItem() {
			return ((JRadioButtonMenuItem) this);
	}

}
