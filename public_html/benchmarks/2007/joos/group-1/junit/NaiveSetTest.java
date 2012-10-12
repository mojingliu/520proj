import junit.framework.TestCase;

public class NaiveSetTest extends TestCase {

	public void testAdd() {
		NaiveSet set = new NaiveSet();
		set.add("a");
		assertTrue(set.contains("a"));
		assertEquals(set.size(), 1);
		set.add("a");
		assertTrue(set.contains("a"));
		assertEquals(set.size(), 1);
		set.add("b");
		assertTrue(set.contains("a"));
		assertTrue(set.contains("b"));
		assertEquals(set.size(), 2);
	}

	public void testAddAll() {
		NaiveSet set1 = new NaiveSet();
		set1.add("a");
		set1.add("b");
		set1.add("c");
		set1.add("d");
		NaiveSet set2 = new NaiveSet();
		set2.add("a");
		set2.add("b");
		set2.addAll(set1);
		assertTrue(set2.contains("a"));
		assertTrue(set2.contains("b"));
		assertTrue(set2.contains("c"));
		assertTrue(set2.contains("d"));
		assertEquals(set2.size(), 4);
	}

	public void testIsEmpty() {
		NaiveSet set = new NaiveSet();
		assertTrue(set.isEmpty());
		set.add("a");
		assertFalse(set.isEmpty());
	}

	public void testCopy() {
		NaiveSet set1 = new NaiveSet();
		set1.add("a");
		set1.add("b");
		NaiveSet set2 = set1.copy();
		set2.add("c");
		assertEquals(set1.size(), 2);
		assertEquals(set2.size(), 3);
	}

	public void testEquals() {
		NaiveSet set1 = new NaiveSet();
		set1.add("a");
		set1.add("b");
		set1.add("c");
		NaiveSet set2 = new NaiveSet();
		set2.add("b");
		assertFalse(set1.equals(set2));
		assertFalse(set2.equals(set1));
		set2.add("a");
		assertFalse(set1.equals(set2));
		assertFalse(set2.equals(set1));
		set2.add("c");
		assertTrue(set1.equals(set2));
		assertTrue(set2.equals(set1));
		
	}
}
