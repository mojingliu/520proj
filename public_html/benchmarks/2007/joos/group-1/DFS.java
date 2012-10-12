import java.util.Vector;

/**
// * A helper for performing depth-first traversals of a graph.
// * 
// * adapted from p541 of CLRS
// */
public class DFS {

	protected NaiveSet visited; //visited nodes
	protected Vector finished;  //nodes with all descendents finished
	protected Graph graph;      //graph being traversed
	
	/**
	 * Start a new DFS, with no nodes considered visited.
	 */
	public DFS(Graph g) {
		super();
		
		visited = new NaiveSet();
		finished = new Vector();
		graph = g;
	}

	/**
	 * Start a new DFS with some nodes considered visited.  Nodes that begin as
	 * visited will never be marked as finished.
	 */
	public DFS(Graph g, NaiveSet v) {
		super();
		
		visited = v.copy();
		finished = new Vector();
		graph = g;
	}

	/**
	 * Perform a DFS of unvisited nodes reachable from root.
	 */
	public void dfs(Object root) {
		Vector children;
		int i;
		
		if(graph.getNodes().contains(root) && !visited.contains(root)) {
			visited.add(root);
			children = graph.getNeighbourSet(root).toVector();
			
			for (i = 0; i < children.size(); i++) {
				Object child;
				child = children.elementAt(i);
				this.dfs(child);
			}
			
			finished.addElement(root);
		}
	}

	public NaiveSet getVisited() {
		return visited.copy();
	}

	public Vector getFinished() {
		Vector v;
		int i;
		
		v = new Vector();
		for (i = 0; i < finished.size(); i++) {
			v.addElement(finished.elementAt(i));
		}
		return v;
	}

	public Vector getReverseFinished() {
		Vector v;
		int i;
		
		v = new Vector();
		for (i = finished.size() - 1; i >= 0; i = i - 1) {
			v.addElement(finished.elementAt(i));
		}
		return v;
	}
}
