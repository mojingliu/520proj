/*
 * Created on Sep 27, 2004
 *
 *	@author Shahla Almasri
 *
 * This class is a wraper around BufferedReader in java.io.  Since JOOS does not support 
 * exceptions, we had to take care of them here instead of raising them up to the application's
 * level.
 */
package myjoos.lib;

import java.io.BufferedReader;
import java.io.IOException;

public class JoosBufferedReader extends BufferedReader{
	
	/******************************************************************************************
	 * Constructor 
	 * @param reader	The JoosFileReader to buffer
	 */
	public JoosBufferedReader(JoosFileReader reader) {
		super(reader.getFileReader());
	}

	/******************************************************************************************
	 * Catch the exception and return the read line.
	 * @return a line from the file
	 */
	public String readLine() {
		try {
				return super.readLine();
		} catch (IOException e) {
				return null;
		}
	}
	
	/******************************************************************************************
	 * Catch the exception and close the file.
	 */
	public void close() {
		try {
				super.close();
		} catch (IOException e) {
				e.printStackTrace();
		}
	}
}
