import java.util.Vector;

// our graph is just a linked list of nodes with weight and extra stuff
public class Graph extends Vector {
  public Graph() {
    super();
  }

  public boolean containsVertex(Vertex v) {
    boolean containsVertex;
    int i;
    containsVertex = false;
    i = 0;
    while (i < super.size()) {
      containsVertex = containsVertex ||
          ( (GraphNode)this.elementAt(i)).getVertex().equals(v);
      i = i + 1;
    }
    return containsVertex;
  }

  public GraphNode getGraphNode(Vertex v) {
    GraphNode n;
    int i;
    n = null;
    i = 0;
    while (i < super.size()) {
      if ( (n = ( (GraphNode)this.elementAt(i))).getVertex().equals(v)) {
        return n;
      }
      i = i + 1;
    }
    return null;
  }
}
