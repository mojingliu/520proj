import java.util.*;

public class State extends Vector {
  protected int weight;

  public State(Vector n, int index) {
    super();
    int i;
    i = 0;
    while (i < n.size()) {
      this.addElement(new Integer( ( (Integer) n.elementAt(i)).intValue()));
      i = i + 1;
    }
    this.addElement(new Integer(index));
  }

  public State(Vector n) {
    super();
    int i;
    i = 0;
    while (i < n.size()) {
      this.addElement(new Integer( ( (Integer) n.elementAt(i)).intValue()));
      i = i + 1;
    }
  }

  public State() {
    super();
  }


  public int getWeight() {
    return weight;
  }

  // see if a state is a child of this state
  public boolean isChild(State s) {
    boolean child;
    int i;
    if (this.size() + 1 != s.size()) {
      return false;
    }
    child = true;
    i = 0;
    while (i < this.size()) {
      child = child && this.elementAt(i).equals(s.elementAt(i));
      i = i + 1;
    }
    return child;
  }

  // now see if its a descendent
  // the only difference between this and isChild is the first line
  // a child node can only have length of size+1
  // a descendent node needs to have longer length
  public boolean isDescendent(State s) {
    boolean desc;
    int i;
    if (this.size() >= s.size()) {
      return false;
    }
    desc = true;
    i = 0;
    while (i < this.size()) {
      desc = desc && this.elementAt(i).equals(s.elementAt(i));
      i = i + 1;
    }
    return desc;
  }

  // comparator
  public int compareWeight(Object o) {
    int w1, w2;
    w1 = weight;
    w2 = ( (State) o).getWeight();
    if (w1 > w2) {
      return 1;
    }
    else if (w1 < w2) {
      return -1;
    }
    else {
      return 0;
    }
  }


  public int calculateWeight(Graph nodes) {
    GraphNode p1, p2;
    int size;
    int i;
    size = this.size();
    weight = 0;
    i = 0;
    while (i < size) {
      p1 = (GraphNode) nodes.elementAt( ( (Integer)this.elementAt(i % size)).intValue());
      p2 = (GraphNode) nodes.elementAt( ( (Integer)this.elementAt((i + 1) % size)).intValue());
      weight = weight + this.dist(p1, p2);
      i = i + 1;
    }
    return weight;
  }

  // swap 2 edges and give a new state
  public State swap(int i, int j) {
    State s;
    Object oi, oj;
    s = new State(this);
    oi = s.elementAt(i);
    oj = s.elementAt(j);
    s.setElementAt(oj, i);
    s.setElementAt(oi, j);
    return s;
  }

  // distance method.. used in weight calculation
  public int dist(GraphNode c1, GraphNode c2) {
    Vertex v1, v2;
    int dx, dy;
    v1 = c1.getVertex();
    v2 = c2.getVertex();
    dx = v1.getX() - v2.getX();
    if (dx<0) { dx = -dx; }
    dy = v1.getY() - v2.getY();
    if (dy<0) { dy = -dy; }
    return dx+dy;
  }
}

