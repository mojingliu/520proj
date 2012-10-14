import java.util.Vector;

/**
 * A directed graph (adjacency list representation).
 */
public class GraphImpl extends Graph {
	
	protected NaiveSet nodes;
	protected NaiveMap edgeMap; //NaiveMap<Object, NaiveSet>
	
	public GraphImpl() {
		super();
		nodes = new NaiveSet();
		edgeMap = new NaiveMap();
	}
	
	public void addNode(Object n) {
		if(n == null) {
			return;
			//throw new NullPointerException("Graph may not contain null nodes.");
		}
		nodes.add(n);
	}
	
	public void addEdge(Object source, Object dest) {
		NaiveSet neighbours;
		
		if(source == null || dest == null) {
			return;
			//throw new NullPointerException("Graph may not contain null nodes.");
		}
		
		nodes.add(source);
		nodes.add(dest);
		
		neighbours = (NaiveSet) edgeMap.get(source);
		if(neighbours == null) {
			neighbours = new NaiveSet();
			edgeMap.put(source, neighbours);
		}
		neighbours.add(dest);
	}
	
	public boolean containsNode(Object node) {
		return nodes.contains(node);
	}
	
	public boolean containsEdge(Object source, Object dest) {
		return 	nodes.contains(source) &&
				nodes.contains(dest) && 
				edgeMap.containsKey(source) && 
				((NaiveSet) edgeMap.get(source)).contains(dest);
	}
	
	public NaiveSet getNodes() {
		return nodes.copy();
	}
	
	public int getNumNodes() {
		return nodes.size();
	}
	
	public int getNumEdges() {
		int i;
		int size;
		Vector nodesV;
		
		nodesV = nodes.toVector();
		size = 0;
		for (i = 0; i < nodesV.size(); i++) {
			size = size + this.getNeighbourSet(nodesV.elementAt(i)).size();
		}
		return size;
	}
	
	public NaiveSet getNeighbourSet(Object n) {
		NaiveSet neighbours;
		
		if(n == null) {
			return null;
			//throw new NullPointerException("Graph may not contain null nodes.");
		} else if(!nodes.contains(n)) {
			return null;
			//throw new IllegalArgumentException("Node is not in graph: " + n);
		}
		
		neighbours = (NaiveSet) edgeMap.get(n);
		if (neighbours == null) {
			neighbours = new NaiveSet();
		}
		return neighbours;
	}
	
	public GraphImpl getReverse() {
		int i;
		GraphImpl reversed;
		Vector nodeVector;
		
		reversed = new GraphImpl();
		nodeVector = nodes.toVector();
		for (i = 0; i < nodeVector.size(); i++) {
			Object node;
			Vector neighbours;
			int j;
			
			node = nodeVector.elementAt(i);
			reversed.addNode(node);
			
			neighbours = this.getNeighbourSet(node).toVector();
			for (j = 0; j < neighbours.size(); j++) {
				reversed.addEdge(neighbours.elementAt(j), node);
			}
		}
		
		return reversed;
	}
	
	//adapted from p550 of CLRS
	public Vector topologicalSort() {
		DFS dfsHelper;
		Vector nodeVector;
		int i;

		dfsHelper = new DFS(this);
		nodeVector = nodes.toVector();
		for (i = 0; i < nodeVector.size(); i++) {
			dfsHelper.dfs(nodeVector.elementAt(i));
		}
		
		return dfsHelper.getReverseFinished();
	}
}
