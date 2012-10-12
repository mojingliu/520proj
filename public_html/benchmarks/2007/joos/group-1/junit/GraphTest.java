import java.util.Arrays;
import java.util.Vector;

import junit.framework.TestCase;

public class GraphTest extends TestCase {

	private Graph graph;

	protected void setUp() throws Exception {
		super.setUp();
		graph = new GraphImpl();
	}

	protected void tearDown() throws Exception {
		super.tearDown();
		graph = null;
	}

	public void testAddNode() {
		graph.addNode("a");
		assertTrue(graph.containsNode("a"));
		assertEquals(graph.getNumNodes(), 1);
		graph.addNode("a");
		assertTrue(graph.containsNode("a"));
		assertEquals(graph.getNumNodes(), 1);
		graph.addNode("b");
		assertTrue(graph.containsNode("a"));
		assertTrue(graph.containsNode("b"));
		assertEquals(graph.getNumNodes(), 2);
	}

	public void testAddEdge() {
		graph.addEdge("a", "b");
		assertTrue(graph.containsNode("a"));
		assertTrue(graph.containsNode("b"));
		assertTrue(graph.containsEdge("a", "b"));
		assertFalse(graph.containsEdge("b", "a"));
		assertEquals(graph.getNumNodes(), 2);
		assertEquals(graph.getNumEdges(), 1);

		graph.addEdge("a", "c");
		assertTrue(graph.containsNode("a"));
		assertTrue(graph.containsNode("b"));
		assertTrue(graph.containsNode("c"));
		assertTrue(graph.containsEdge("a", "b"));
		assertTrue(graph.containsEdge("a", "c"));
		assertEquals(graph.getNumNodes(), 3);
		assertEquals(graph.getNumEdges(), 2);
	}

	public void testGetNeighbourSet() {
		graph.addEdge("a", "b");
		graph.addEdge("a", "c");

		NaiveSet aNeighbours = new NaiveSet();
		aNeighbours.add("b");
		aNeighbours.add("c");

		assertEquals(graph.getNeighbourSet("a"), aNeighbours);
		assertEquals(graph.getNeighbourSet("b"), new NaiveSet());
		assertEquals(graph.getNeighbourSet("c"), new NaiveSet());
	}

	public void testGetReverse() {
		graph.addEdge("a", "b");
		graph.addEdge("a", "c");

		{
			Graph reverse1 = graph.getReverse();
			assertTrue(reverse1.containsEdge("b", "a"));
			assertTrue(reverse1.containsEdge("c", "a"));
			assertEquals(reverse1.getNumEdges(), 2);

			Graph reverse2 = reverse1.getReverse();
			assertTrue(reverse2.containsEdge("a", "b"));
			assertTrue(reverse2.containsEdge("a", "c"));
			assertEquals(reverse2.getNumEdges(), 2);
		}

		graph.addEdge("b", "c");
		graph.addEdge("c", "a");

		{
			Graph reverse1 = graph.getReverse();
			assertTrue(reverse1.containsEdge("b", "a"));
			assertTrue(reverse1.containsEdge("c", "a"));
			assertTrue(reverse1.containsEdge("c", "b"));
			assertTrue(reverse1.containsEdge("a", "c"));
			assertEquals(reverse1.getNumEdges(), 4);

			Graph reverse2 = reverse1.getReverse();
			assertTrue(reverse2.containsEdge("a", "b"));
			assertTrue(reverse2.containsEdge("a", "c"));
			assertTrue(reverse2.containsEdge("b", "c"));
			assertTrue(reverse2.containsEdge("c", "a"));
			assertEquals(reverse2.getNumEdges(), 4);
		}
	}

	public void testTopologicalSort() {
		graph.addNode("a");
		graph.addNode("b");
		// this order is not actually required
		assertEquals(graph.topologicalSort(),
				toVector(new Object[] { "b", "a" }));

		graph.addEdge("a", "b");
		assertEquals(graph.topologicalSort(),
				toVector(new Object[] { "a", "b" }));

		graph.addEdge("a", "c");
		graph.addEdge("c", "d");
		graph.addEdge("c", "e");
		graph.addEdge("d", "f");
		graph.addEdge("d", "g");
		// this order is not actually required
		assertEquals(graph.topologicalSort(), toVector(new Object[] { "a", "c",
				"e", "d", "g", "f", "b" }));
	}

	public void testGetStronglyConnectedComponents() {
		graph.addEdge("a", "b");
		graph.addEdge("b", "c");
		graph.addEdge("c", "a");
		graph.addEdge("a", "e");
		graph.addEdge("b", "f");
		graph.addEdge("c", "g");

		graph.addEdge("z", "y");
		graph.addEdge("y", "x");
		graph.addEdge("x", "z");
		graph.addEdge("u", "x");
		graph.addEdge("v", "y");
		graph.addEdge("w", "z");

		assertEquals(graph.getStronglyConnectedComponents(), 
				toVector(new Object[]{
					toVector(new Object[]{"w"}),
					toVector(new Object[]{"v"}),
					toVector(new Object[]{"u"}),
					toVector(new Object[]{"z", "x", "y"}),
					
					toVector(new Object[]{"a", "c", "b"}),
					toVector(new Object[]{"e"}),
					toVector(new Object[]{"f"}),
					toVector(new Object[]{"g"}),
				}));
	}

	private static Vector toVector(Object[] a) {
		return new Vector(Arrays.asList(a));
	}
}
