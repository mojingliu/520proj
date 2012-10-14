import java.util.Vector;

public class GraphNode {
  protected Vertex v;
  protected Vector n;

  // constructors
  public GraphNode() {
    super();
    n = new Vector();
  }

  public GraphNode(GraphNode t) {
    super();
    n = new Vector();
    v = new Vertex(t.getVertex());
  }

  public GraphNode(Vertex vv) {
    super();
    n = new Vector();
    v = vv;
  }

  // methods
  public Vertex getVertex() {
    return v;
  }

  public void addNeighbor(GraphNode t) {
    if (!this.isNeighbor(t)) {
      n.addElement(t);
    }
    if (!t.isNeighbor(this)) {
      t.addNeighbor(this);
    }
  }

  public boolean isNeighbor(GraphNode p) {
    boolean neighbor;
    boolean tmp;
    int i;
    Object o;
    neighbor = false;
    tmp = false;
    i = 0;
    while (i < n.size()) {
      o = n.elementAt(i);
      neighbor = p.equals(o) || neighbor;
      i = i + 1;
    }
    return neighbor;
  }

  public Vector getNeighbors() {
    return n;
  }

  public GraphNode getGraphNodeOnly() {
    GraphNode s;
    s = new GraphNode();
    s.setVertex(v);
    return s;
  }

  public void setVertex(Vertex vv) {
    v = vv;
  }



  public boolean equals(Object p) {
    return (v.equals(((GraphNode) p).getVertex()));
  }

  public String toString() {
    return "Vertex: " + v.toString();
  }
}
