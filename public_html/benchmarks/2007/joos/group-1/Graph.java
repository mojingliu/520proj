import java.util.Vector;

/**
 * A pointless abstract superclass for the real directed graph class.
 */
public abstract class Graph {

	public Graph() {
		super();
	}

	public abstract Vector topologicalSort();

	public abstract GraphImpl getReverse();

	public abstract NaiveSet getNeighbourSet(Object n);

	public abstract int getNumEdges();

	public abstract int getNumNodes();

	public abstract NaiveSet getNodes();

	public abstract boolean containsEdge(Object source, Object dest);

	public abstract boolean containsNode(Object node);

	public abstract void addEdge(Object source, Object dest);

	public abstract void addNode(Object n);

	public Vector getStronglyConnectedComponents() {
		Vector sorted;
		GraphImpl reversedGraph;
		Vector components;
		NaiveSet allVisited;
		int i;
		
		sorted = this.topologicalSort();
		reversedGraph = this.getReverse();
		
		allVisited = new NaiveSet();
		components = new Vector();
		for (i = 0; i < sorted.size(); i++) {
			Object node;
			node = sorted.elementAt(i);
			if(!allVisited.contains(node)) {
				DFS componentDFS;
				componentDFS = new DFS(reversedGraph, allVisited);
				componentDFS.dfs(node);
				allVisited.addAll(componentDFS.getVisited());
				components.addElement(componentDFS.getReverseFinished());
			}
			
		}
		
		return components;
	}

}