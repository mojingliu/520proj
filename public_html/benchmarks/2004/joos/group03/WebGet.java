//WebGet Client by GROUP 3
// This program takes a number of lines as input
// the first line should be a http web address (including the http://)
// subsequent lines can be any of the following:
// -v		will cause verbose output
// -rs or -rd	will restrict harvesting of http links to the Site or Domain
// -d X		will specify the depth of the harvesting, where X is a number
import java.util.*;
import joos.lib.*;

public class WebGet {
	protected JoosIO fIO;	// for input and output
	protected boolean verbose; // whether to have screen output
	protected boolean justThisSite;
	protected boolean justThisDomain;
	protected int MaxDepth; // max depth to log
	protected int MaxLinks; // max links to log per page
	protected String directory; // default "/" directory
	protected String startDirectory; // directory we start in
	protected String host;  		// the original host
	protected String domain;		// the original domain
	protected Vector NeedTo; // Vector of links to visit
	protected Vector Visited;// Vector of links visited

	public WebGet() 
	{
		super();
		fIO = new JoosIO();
		verbose = false; // whether to have screen output
		justThisSite = false;
		justThisDomain = false;
		MaxDepth = 0; // max depth to log
		MaxLinks = 1000; // max links to log per page
		directory = "/"; // default "/" directory
		startDirectory = null;
		host = null;
		domain = null;
		NeedTo = new Vector(); // Vector of links to visit
		Visited = new Vector();// Vector of links visited
	}
 
	public JoosIO getIO() {
		return fIO;
	}

	public static void main(String args[])
        {
       	URLObj start;
       	WebGet wg;
       	int j;
       	int i;
       	boolean endInput;
        String temp;
       	JoosIO f;
        JoosString js;

       	wg = new WebGet();
       	f = wg.getFIO();

       	// Here we read in the inputs from the user
	endInput = false;
        temp = f.readLine();
	while (temp!=null && !endInput) {
		temp = temp.toLowerCase();
	  	// if we are the web address, store the host and domain
		if (temp.indexOf("http://",0)==0) {
			wg.setHost(temp);
			temp = temp.substring(7,temp.length());
			if (temp.indexOf("/",0) > 0) {
			   wg.setDomain(temp.substring(0,temp.indexOf("/",0)));
			} else {
	  		   wg.setDomain(temp);
			}	
		}
         	// specifying depth
		else if (temp.indexOf("-d ",0)==0) {
			temp = temp.substring(3,temp.length());
 			js = new JoosString(temp);
			wg.setMaxDepth(js.string2Int());
		}
		// specify verbose output
		else if (temp.indexOf("-v",0)==0) {
			wg.setVerbose(true);
		}
		// specify restriction to this site
		else if (temp.indexOf("-rs",0)==0) {
			wg.setJustThisSite(true);
		}
		// specify restriction to this domain
		else if (temp.indexOf("-rd",0)==0) {
			wg.setJustThisDomain(true);
		} 
		// input is done if we see "-end"
		else if (temp.indexOf("-end",0)==0) { 
			endInput = true;
		}
		if (!endInput) {
			temp = f.readLine();
		}		 
        }      
	
	// if no host was found in the input, we quit  
       	if (wg.getHost()==null) {
       		f.println("No host.  Quitting");
       		return;	
       	}
              
	// if verbose output, tell the user what we're doing 
	if (wg.isVerbose()) {
       		f.println("URL: "+wg.getHost());
		if(wg.isJustThisSite()) {
			f.println("Visiting just this site");
       		} else if (wg.isJustThisDomain()) {
			f.println("Visiting just this domain");
		}
		f.println("Depth: "+wg.getMaxDepth());
	}
          
       	// set up a new URLObj as the start object
	start = new URLObj();
	start.setURLObj("","","",0,-1);
	start = wg.processLink(start,wg.getHost(),0);
        
	// if, after processing the input address, we don't get a URLObj, quit 
	if (start==null) 
         {
		f.println("Bad request: " + wg.getHost());
		return;
         }
        
	// setup global variables  
	wg.setStartDirectory(start.directory());
        // add the start element to the vector of pages to visit 
	wg.getNeedTo().addElement(start);
         
         f.println("Beginning Harvest...\r\n\r\n");
        
	// call main recursive method to read through all addresses on vector 
         wg.Harvest((URLObj)wg.getNeedTo().firstElement());
            
         f.println("Harvest Complete.");
         
         return;
    } //main 
	
	public void Harvest(URLObj urlObj) {
		String temp;
		String inputBuffer;
        	URLObj newURL;        
        	int count;
        	int itmp;
		JoosURL jurl;
		boolean test;

		test = false;
		
        	newURL = null;
        	count = 0;
       
		// if we've visited this page before or we're only working
		// within our original site or domain and this page isn't
		// in those, the remove it from the vector of pages to visit
		// and ignore it. 
		temp = urlObj.host()+urlObj.directory()+urlObj.file();
		if (Visited.contains(temp) || (justThisSite && urlObj.host().indexOf(domain,0) < 0) || urlObj.directory().indexOf(startDirectory,0) < 0 || (justThisDomain && urlObj.host().indexOf(domain,0) < 0) )
		{
			NeedTo.removeElement(urlObj);
		} 
		// if we exceeded the depth, report the page skipped
		else if (urlObj.depth() > MaxDepth) {
			NeedTo.removeElement(urlObj);
			urlObj.settype(2);
			this.reportURL(urlObj,0);
			Visited.addElement(urlObj.host() + urlObj.directory()
					+ urlObj.file());
			if (verbose) {
				fIO.println("\nToo Deep: skipping " + urlObj.file()
						+ " from " + urlObj.host() + urlObj.directory());
			}
		}
		// if the page isn't a simple HTML type, skip it
		else if (urlObj.type() != 0) {
			NeedTo.removeElement(urlObj);
			urlObj.settype(5);
			this.reportURL(urlObj, 0);
			Visited.addElement(urlObj.host() + urlObj.directory()
					+ urlObj.file());
			if (verbose) {
				fIO.println("\nSkipping " + urlObj.file() + " from "
						+ urlObj.host() + urlObj.directory());
			}
		} 
		// if we are visiting this page, put it in the list of visited
		// pages and process it
		else {
			Visited.addElement(urlObj.host() + urlObj.directory()
					+ urlObj.file());
		
			NeedTo.removeElement(urlObj);

			if (verbose) {
				fIO.println("\nHarvesting " + urlObj.file() + " from "
						+ urlObj.host() + urlObj.directory());
			} // if screen output is needed

			// create a new url for this page
			jurl = new JoosURL(null,"http://"+urlObj.host()+ urlObj.directory() + urlObj.file());

			// if we are able to open the connection
			// let's work with it.  read all input and look for 
			// links of the form <a href="">
			if (urlObj.type() == 0 && jurl.openConnection())
		        { 
					if (jurl.openInputStream())
					{ // input stream opened ok, now read each line and echo
		              while((inputBuffer = jurl.readLine()) != null)
		              {
						if (count < MaxLinks) {
							newURL = this.processLine(inputBuffer, urlObj);
						}
	
						if (newURL != null)
						{
							if (newURL.type() == 0) {
								count = count + 1;
								NeedTo.addElement(newURL);
							} // if not an image, just add
	
							if (verbose) {
								fIO.println("\n\t" + newURL.host()
										+ newURL.directory() + newURL.file());
							}
						} // if we found a link
						inputBuffer = jurl.readLine();
		              } // while the HTML is still coming
		              jurl.closeInputStream();
			    }
			} // if HTML type (0)
			this.reportURL(urlObj, count);
		}

		// if there are still pages to visit, recursively visit them
		if (!NeedTo.isEmpty()) {
			this.Harvest((URLObj) NeedTo.firstElement());
		} // if there are more URL's to be processed
	} // Harvest

	// processLine looks through a line of HTML from a given URLObj
	// and returns a new URLObj if it finds a link in the line 
	public URLObj processLine(String line, URLObj urlObj) {
		URLObj returnUrl;
		int indx;
		int lineIndex;
		String lowerCase;
		returnUrl = null;	
		lowerCase = line.toLowerCase();
		indx = lowerCase.indexOf("href=",0);
	 	if (indx>=0) {
			line = line.substring(indx+5,line.length());
			if (line.charAt(0) == 34) {
				line = line.substring(1,line.length());
				lineIndex = 0;
				while (line.length()>lineIndex && line.charAt(lineIndex) != 34) {
					lineIndex = lineIndex + 1;			
				}
					
				line = line.substring(0, lineIndex);
			} else {
				if (line.indexOf(">",0)>0) {
					line = line.substring(0,line.indexOf(">",0));
				}
			}
			if (line.indexOf(" ",0) > 0) {
				line = line.substring(0,line.indexOf(" ",0));
			}
			if (this.isHTML(line)) {
				returnUrl = this.processLink(urlObj, line, 
0);
			}
		} 

		return returnUrl;
	} // processLine

	// processLink takes a URLObj and a line with the link and a type
	// and creates a new URLObj in return, properly parsed with it's
	// host, directory, filename set
	public URLObj processLink(URLObj urlObj, String line, int type) {
		int firstslash;
		int lastslash;
		URLObj tmp;
		String lowerCase;
		
		tmp = new URLObj();
		lowerCase = line.toLowerCase();
	
		if (lowerCase.indexOf("/",0) < 0) {
			line = urlObj.directory() + line;
		} else if (lowerCase.indexOf("./",0) == 0) {
			line = urlObj.directory() + line.substring(2,line.length());
		} else if (lowerCase.indexOf("././",0) == 0) {
			line = urlObj.directory()
					.substring(
							0,
							(urlObj.directory().substring(0,
									urlObj.directory().length() - 1)
									
.lastIndexOf("/",0)) + 1)
					+ line.substring(4,line.length());
		} else if (lowerCase.indexOf("../",0) == 0) {
			line = urlObj.directory()
					.substring(
							0,
							(urlObj.directory().substring(0,
									urlObj.directory().length() - 1)
									
.lastIndexOf("/",0)) + 1)
					+ line.substring(3,line.length());
		}

		if (line.toLowerCase().indexOf("http://",0) < 0) {
			line = "http://" + urlObj.host() + line;
		}
		line = line.substring(7,line.length());
		firstslash = line.indexOf("/",0);
		if (firstslash<0)
		{
			firstslash=line.length(); 
			lastslash = firstslash;
		} else {
			lastslash = line.lastIndexOf("/",firstslash)+1;
		
			if (lastslash==0) 
			{
				lastslash = line.length();
			}
		}
		tmp.setURLObj(line.substring(0, firstslash), line.substring(
						firstslash, lastslash), line.substring(lastslash,line.length()),
						type, urlObj.depth() + 1);

		return tmp;
	} // processLink

	// isHTML checks if a given line has what appears to be a link to
	// a simple .html file in it
	public boolean isHTML(String line) {
		line = line.toLowerCase();
		if (line.indexOf(".htm",0)>0) {
			return true;
		}

		return false;
	}

	// reportURL tells the user about the given URL
	public void reportURL(URLObj temp, int cnt) {
		String msg;
		String tag;
		
		msg = "";
		tag = "Skipped>";
		
		if (temp != null) {
			if (temp.type() == 0) {
				fIO.print("Page>" + temp.host() + temp.directory()
						+ temp.file() + " (depth:" + temp.depth()
						+ ") harvested (" + cnt + " links)\r\n");
			} else if (temp.type() == 2) {
				if (temp.depth() > MaxDepth) {
					msg = " exceeded depth (" + temp.type() + ")\r\n";
				} else if (cnt > 0) {
					tag = "Page>   ";
					msg = " had errors (" + cnt
							+ " links)\r\n";
				}

				else {
					msg = " failed\r\n";
					tag = "Page>   ";
					msg = " had errors (" + cnt + " links)\r\n";
				}
				fIO.print(tag + temp.host() + temp.directory()
						+ temp.file() + msg);
			}

			else

			{

				fIO.print("Skipped>" + temp.host() + temp.directory()
						+ temp.file() + " uncached (type:" + temp.type()
						+ ")\r\n");
			}
		}
	} // printVector
	
	// GETTERS AND SETTERS FOLLOW FOR GLOBALS IN WEBGET
	public String getDirectory() {
		return directory;
	}
	public void setDirectory(String d) {
		directory = d;
	}
	public String getDomain() {
		return domain;
	}
	public void setDomain(String d) {
		domain = d;
	}
	public JoosIO getFIO() {
		return fIO;
	}
	public void setFIO(JoosIO f) {
		fIO = f;
	}
	public String getHost() {
		return host;
	}
	public void setHost(String h) {
		host = h;
	}
	public boolean isJustThisDomain() {
		return justThisDomain;
	}
	public void setJustThisDomain(boolean j) {
		justThisDomain = j;
	}
	public boolean isJustThisSite() {
		return justThisSite;
	}
	public void setJustThisSite(boolean j) {
		justThisSite = j;
	}
	public int getMaxLinks() {
		return MaxLinks;
	}
	public void setMaxLinks(int m) {
		MaxLinks = m;
	}
	public Vector getNeedTo() {
		return NeedTo;
	}
	public void setNeedTo(Vector n) {
		NeedTo = n;
	}
	public String getStartDirectory() {
		return startDirectory;
	}
	public void setStartDirectory(String s) {
		startDirectory = s;
	}
	public boolean isVerbose() {
		return verbose;
	}
	public void setVerbose(boolean v) {
		verbose = v;
	}
	public Vector getVisited() {
		return Visited;
	}
	public void setVisited(Vector v) {
		Visited = v;
	}
	public int getMaxDepth() {
		return MaxDepth;
	}
	public void setMaxDepth(int d) {
        	MaxDepth = d;
	}
}// class WebGet
