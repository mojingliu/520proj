// Simple URL Object that holds information about a given page on the www
public class URLObj {
	protected String m_host;
	protected String m_directory;
	protected String m_file;
	protected Integer m_type;
	protected Integer m_depth;

	public URLObj() {
		super();
		m_host = null;
		m_directory = null;
		m_file = null;
		m_type = null;
		m_depth = null;
	}

	public void setURLObj(String h, String di, String f, int t, int de) {
                m_host = h.toLowerCase();
                m_directory = di;
                m_file = f;
                m_type = new Integer(t);
                m_depth = new Integer(de);
	}


	// Get methods

	public String host() {
		return m_host;
	}

	public String directory() {
		return m_directory;
	}

	public String file() {
		return m_file;
	}

	public int type() {
		return m_type.intValue();
	}

	public int depth() {
		return m_depth.intValue();
	}


	// Set methods

	public void sethost(String h) {
		m_host = h.toLowerCase();
	}

	public void setdirectory(String di) {
		m_directory = di;
	}

	public void setfile(String f) {
		m_file = f;
	}

	public void settype(int t) {
		m_type = new Integer(t);
	}

	public void setdepth(int de) {
		m_depth = new Integer(de);
	}
}
