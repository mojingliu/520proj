import junit.framework.TestCase;


public class NaiveMapTest extends TestCase {

	public void testIsEmpty() {
		NaiveMap map = new NaiveMap();
		assertTrue(map.isEmpty());
		map.put("a", "q");
		assertFalse(map.isEmpty());
	}

	public void testPut() {
		NaiveMap map = new NaiveMap();
		assertFalse(map.containsKey("a"));
		assertFalse(map.containsValue(new Integer(13)));
		map.put("a", new Integer(13));
		assertTrue(map.containsKey("a"));
		assertTrue(map.containsValue(new Integer(13)));
	}

	public void testGet() {
		NaiveMap map = new NaiveMap();
		assertFalse(map.containsKey("a"));
		assertNull(map.get("a"));
		map.put("a", new Integer(13));
		assertTrue(map.containsKey("a"));
		assertEquals(map.get("a"), new Integer(13));
	}

	public void testCopy() {
		NaiveMap map1 = new NaiveMap();
		map1.put("a", new Integer(12));
		map1.put("b", new Object());
		NaiveMap map2 = map1.copy();
		map2.put("a", new Integer(0));
		assertEquals(map1.size(), 2);
		assertEquals(map1.get("a"), new Integer(12));
		assertEquals(map2.size(), 2);
		assertEquals(map2.get("a"), new Integer(0));
	}

}
