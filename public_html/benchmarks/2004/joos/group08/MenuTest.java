// *
// * Created on Sep 22, 2004
// *
// * Copied from the book "Java How To Program," Fifth Edition.
// * The code has been modified to fulfill the assignment's requirement and to be 
// * JOOS compatible.
// *
// * Modified by: Shahla Almasri
// *

// Fig. 14.9: MenuTest.java
// Demonstrating menus

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ItemEvent;
import java.util.Vector;
import javax.swing.*;

import joos.lib.*;
import myjoos.lib.*;

public class MenuTest extends JoosFrame {
	protected JoosMenuItem aboutItem, exitItem;
	protected Vector colorValues, colorItems, fontItems, styleItems;
	protected Vector colorsNames, styleNames, fontNames;
	protected JLabel displayLabel;
	protected ButtonGroup fontGroup, colorGroup;
	protected int style, fontSelected, colorSelected;
	protected JoosConstants joosConst;
	protected MyJoosConstants myConst;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Constructor: set up GUI
	//
	public MenuTest(String display_str, boolean show_window) {
		super("Using JMenus");

		// Decalrations
		JoosIO io;
		JMenuBar bar;
		JMenu fileMenu, fontMenu, colorMenu, formatMenu;
		int count;
		
		// initilization
		io = new JoosIO();
		joosConst = new JoosConstants();
		myConst = new MyJoosConstants();

		//	create Color submenu
		colorsNames = new Vector(4);
		colorsNames.addElement("Black");
		colorsNames.addElement("Blue");
		colorsNames.addElement("Red");
		colorsNames.addElement("Green");
		
		//	create Color submenu
		colorValues = new Vector(4);
		colorValues.addElement(joosConst.black());
		colorValues.addElement(joosConst.blue());
		colorValues.addElement(joosConst.red());
		colorValues.addElement(joosConst.green());

		//	set up style menu items
		styleNames = new Vector(2);
		styleNames.addElement("Bold");
		styleNames.addElement("Italic");

		//	create Font submenu
		fontNames = new Vector(3);
		fontNames.addElement("Serif");
		fontNames.addElement("Monospaced");
		fontNames.addElement("SansSerif");

		fileMenu = new JMenu("File");
		fileMenu.setMnemonic('F');

		// set up About... menu item
		aboutItem = new JoosMenuItem("About...");
		aboutItem.setMnemonic('A');
		aboutItem.addActionListener(this);
		fileMenu.add(aboutItem.getJMenuItem());
		
		// set up Exit menu item
		exitItem = new JoosMenuItem("Exit");
		exitItem.setMnemonic('x');
		exitItem.addActionListener(this);
		fileMenu.add(exitItem.getJMenuItem());

		// create menu bar and attach it to MenuTest window
		bar = new JMenuBar();
		this.setJMenuBar(bar);
		bar.add(fileMenu);

		// create Format menu, its submenus and menu items
		formatMenu = new JMenu("Format");
		formatMenu.setMnemonic('r');

		colorMenu = new JMenu("Color");
		colorMenu.setMnemonic('C');

		colorItems = new Vector(4);
		colorGroup = new ButtonGroup();

		// create color radio button menu items
		count = 0;
		while (count < colorsNames.size()) {
			colorItems.addElement(new JoosRadioButtonMenuItem((String) colorsNames.elementAt(count)));
			((JoosRadioButtonMenuItem) colorItems.elementAt(count)).addActionListener(this);
			colorMenu.add(((JoosRadioButtonMenuItem) colorItems.elementAt(count)).getJRadioButtonMenuItem());
			colorGroup.add(((JoosRadioButtonMenuItem) colorItems.elementAt(count)).getJRadioButtonMenuItem());
			count = count + 1;
		}

		// select first Color menu item
		((JoosRadioButtonMenuItem)colorItems.elementAt(0)).setSelected(true);

		// add format menu to menu bar
		formatMenu.add(colorMenu);
		formatMenu.addSeparator();

		fontMenu = new JMenu("Font");
		fontMenu.setMnemonic('n');

		fontItems = new Vector(3);
		fontGroup = new ButtonGroup();

		// create Font radio button menu items
		count = 0;
		while (count < fontNames.size()) {
			fontItems.addElement(new JoosRadioButtonMenuItem((String) fontNames.elementAt(count)));
			((JoosRadioButtonMenuItem) fontItems.elementAt(count)).addActionListener(this);
			fontMenu.add(((JoosRadioButtonMenuItem)fontItems.elementAt(count)).getJRadioButtonMenuItem());
			fontGroup.add(((JoosRadioButtonMenuItem)fontItems.elementAt(count)).getJRadioButtonMenuItem());
			count = count + 1;
		}

		// select first Font menu item
		((JoosRadioButtonMenuItem) fontItems.elementAt(0)).setSelected(true);

		fontMenu.addSeparator();

		styleItems = new Vector(2);

		// create style checkbox menu items
		count = 0;
		while (count < styleNames.size()) {
			styleItems.addElement(new JoosCheckBoxMenuItem((String) styleNames.elementAt(count)));
			((JoosCheckBoxMenuItem) styleItems.elementAt(count)).addItemListener(this);
			fontMenu.add(((JoosCheckBoxMenuItem) styleItems.elementAt(count)).getJCheckBoxMenuItem());
			count = count + 1;
		}

		// put Font menu in Format menu
		formatMenu.add(fontMenu);

		// add Format menu to menu bar
		bar.add(formatMenu);

		// set up label to display text
		displayLabel = new JLabel(display_str, myConst.SWING_CENTER());
		displayLabel.setForeground(joosConst.black());
		displayLabel.setFont(new Font("Serif", joosConst.PLAIN(), 72));

		this.getContentPane().setBackground(joosConst.cyan());
		this.getContentPane().add(displayLabel);

		if (show_window) {
			this.setSize(500, 200);
			this.setVisible(true);
		}

	} // end constructor
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Callback for ActionListener
	//
	public void actionPerformed(ActionEvent event) { 
		JoosSystem sys;
		Object source;
		int count;
		JoosOptionPane dialog;
		JoosIO io;
		String st;

		sys = new JoosSystem();
		io = new JoosIO();
		source = event.getSource();
		
		if (source == exitItem) {
			st = "Before exiting you have chosen the color " + this.getSelectedColor() + 
				", the font " + this.getSelectedFont(); 
			if (this.getSelectedStyle() != "")
				st = st +  ", and the style " + this.getSelectedStyle();
			io.println(st);
			
			sys.exit(0);
		} else if (source == aboutItem) {
			dialog = new JoosOptionPane();
			dialog.show(null, 
							"This is an example\nof using menus", 
							"About", 
							myConst.PLAIN_MESSAGE());
		} else {
			//	process color selection
			count = 0;
			while (count < colorItems.size()) {
					 if (((JoosRadioButtonMenuItem) colorItems.elementAt(count)).isSelected() ) {
						displayLabel.setForeground(((Color) colorValues.elementAt(count)));
						colorSelected = count;
						count = colorItems.size();  // to get around breaking the loop
					 }
					 count = count + 1;
			}
 
			 // process font selection
			count = 0;
			while(count < fontItems.size()) { 
				  	if ( event.getSource() == fontItems.elementAt(count)) {
						displayLabel.setFont(new Font(((JoosRadioButtonMenuItem) fontItems.elementAt(count)).getText(), style, 72 ) );
						fontSelected = count;
						count = fontItems.size();	// to get around breaking the loop
					}
					count = count + 1;
			}

				  this.repaint();  
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Callback for ItemListener: Updates the label's style based on the new selection.
	//
	public void itemStateChanged(ItemEvent event) {
		style = 0;

		// check for bold selection
		if (((JoosCheckBoxMenuItem) styleItems.elementAt(0)).isSelected() )
			style = style + joosConst.BOLD();

		// check for italic selection
		if (((JoosCheckBoxMenuItem) styleItems.elementAt(1)).isSelected() )
			style = style + joosConst.ITALIC();

		displayLabel.setFont(new Font( displayLabel.getFont().getName(), style, 72 ) );

		this.repaint();	
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Returns the current color selection
	//
	public String getSelectedColor() {
		return ((String) colorsNames.elementAt(colorSelected));
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Returns the current font selection
	//	
	public String getSelectedFont() {
		return ((String) fontNames.elementAt(fontSelected));
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Returns the current style selection
	//	
	public String getSelectedStyle() {
		String st;
		
		st = "";
		if (((JoosCheckBoxMenuItem) styleItems.elementAt(0)).isSelected() )
				st = st + ((String) styleNames.elementAt(0));

		// check for italic selection
		if (((JoosCheckBoxMenuItem) styleItems.elementAt(1)).isSelected() ) {
			if (st != "")
				st = st + " and ";
				
			st = st + ((String) styleNames.elementAt(1));
		}
		
		return st;
	}

} // end class MenuTest

//**************************************************************************
// * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and               *
// * Prentice Hall. All Rights Reserved.                                    *
// *                                                                        *
// * DISCLAIMER: The authors and publisher of this book have used their     *
// * best efforts in preparing the book. These efforts include the          *
// * development, research, and testing of the theories and programs        *
// * to determine their effectiveness. The authors and publisher make       *
// * no warranty of any kind, expressed or implied, with regard to these    *
// * programs or to the documentation contained in these books. The authors *
// * and publisher shall not be liable in any event for incidental or       *
// * consequential damages in connection with, or arising out of, the       *
// * furnishing, performance, or use of these programs.                     *
// *************************************************************************/
