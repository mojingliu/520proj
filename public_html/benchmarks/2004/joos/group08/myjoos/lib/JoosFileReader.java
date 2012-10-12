/*
 * Created on Sep 27, 2004
 * 
 * @author Shahla Almasri
 *
 * This class is a wraper around FileReader in java.io.  Since JOOS does not support 
 * exceptions, we had to take care of them here instead of raising them up to the application's
 * level.
 */
package myjoos.lib;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class JoosFileReader {
	private FileReader _reader;
	
	/******************************************************************************************
	 * Catch the exception and instantiate the FileReader object.
	 * @param file	the file object to create a reader for
	 */
	public JoosFileReader(File file) {
		try {
				_reader = new FileReader(file);
		} catch (FileNotFoundException e) {
				_reader = null;
		}
	}
	
	/******************************************************************************************
	 * 
	 * @return	this instance as a FileReader object
	 */
	public FileReader getFileReader(){
		return _reader;
	}

}
