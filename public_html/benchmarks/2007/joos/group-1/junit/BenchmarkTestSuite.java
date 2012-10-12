import junit.framework.Test;
import junit.framework.TestSuite;

public class BenchmarkTestSuite {

	public static Test suite() {
		TestSuite suite = new TestSuite("Tests for JOOS benchmark.");
		suite.addTestSuite(NaiveSetTest.class);
		suite.addTestSuite(NaiveMapTest.class);
		suite.addTestSuite(DFSTest.class);
		suite.addTestSuite(GraphTest.class);
		return suite;
	}

}
