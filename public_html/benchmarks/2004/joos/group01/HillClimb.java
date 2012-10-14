import joos.lib.*;
import java.util.*;

public class HillClimb {
  protected Graph G;

  public HillClimb() {
    super();
    G = new Graph();
  }

  public Graph hillClimb(Graph nodes) {
    // implementation of the hill climb
    // or initial state
    State parentState;
    State minState, newState;
    GraphNode p1, p2;
    Graph cycle;
    boolean finish;
    int i, j, index, size;
    int oldWeight, newWeight;
    parentState = new State();
    // generate intial state - basically if we have 4 vertices
    // the initial state will be [0, 1, 2, 3]
    i = 0;
    while (i < nodes.size()) {
      parentState.addElement(new Integer(i));
      i = i + 1;
    }
    // calculate the weight
    parentState.calculateWeight(nodes);

    finish = false;

    // minimal state (ie. best state)
    minState = parentState;
    while (!finish) {
      // define a neighbor as a state with only 2 edges different
      // for ever neighbor
      i = 1;
      while (i < nodes.size()) {
        j = i;
        while (j < nodes.size()) {
          // generate the neighbor state by swapping 2 points
          newState = parentState.swap(i - 1, j);
          // calculate its weight
          newState.calculateWeight(nodes);
          // if smaller then minimum, set it to minimum
          if (newState.getWeight() < minState.getWeight()) {
            minState = newState;
          }
          j = j + 1;
        }
        i = i + 1;
      }

      // get the weights
      newWeight = minState.getWeight();
      oldWeight = parentState.getWeight();
      // if new state is no better then the old one, terminate - reached the local minimum
      if (oldWeight <= newWeight) {
        finish = true;
      }
      parentState = new State(minState);
      parentState.calculateWeight(nodes);
      //System.out.println(parentState.toString());
    }

    // so now make a graph out of our state. same way as in aStar
    cycle = new Graph();
    size = parentState.size();
    i = 0;
    while (i < size) {
      index = ( (Integer) parentState.elementAt(i)).intValue();
      cycle.addElement( ( (GraphNode) nodes.elementAt(index)).getGraphNodeOnly());
      i = i + 1;
    }
    i = 0;
    while (i < size) {
      p1 = (GraphNode) cycle.elementAt(i % size);
      p2 = (GraphNode) cycle.elementAt( (i + 1) % size);
      p1.addNeighbor(p2);
      i = i + 1;
    }

    return cycle;
  }

  public Graph readGraph() {
    Graph g;
    GraphNode p, q;
    Vertex v;
    JoosIO f;
    Vector nums;
    Vector nodes;
    String num;
    String input;
    StringTokenizer tokens;
    int i, j;
    Integer n;
    Character C;
    int x, y;
    char c;
    num = "";
    C = new Character('0');
    n = new Integer(0);
    nums = new Vector();
    nodes = new Vector();
    g = new Graph();
    f = new JoosIO();

    // format of the file is
    //    i   x   y   n1   n2   n3 ....
    // where i is the number of the node
    // x and y are coordinates (must be positive!)
    // n1 n2 n3 and so on are the indices of neighbor nodes for this node

    // read each line
    while ( (input = f.readLine()) != null) {
      tokens = new StringTokenizer(input);
      while (tokens.hasMoreElements()) {
        nums.addElement(new Integer((String) tokens.nextElement()));
      }

      // turn the vector of numbers into a new node
      // first number is the # of the node
      i = ( (Integer) nums.elementAt(0)).intValue();
      // second and third are x and y coordiantes
      x = ( (Integer) nums.elementAt(1)).intValue();
      y = ( (Integer) nums.elementAt(2)).intValue();
      // make a new vertex corresponding to the coordinates
      v = new Vertex(x, y);
      // make a new node at that vertex.. right now its a node with no neighbors
      p = new GraphNode(v);
      // add the vector of numbers to our vector of nodes, so we can link nodes later
      nodes.addElement(nums);
      g.addElement(p);

      nums = new Vector();
    }

    // now we need to link the graph nodes together
    i = 0;
    while (i < g.size()) {
      p = (GraphNode) g.elementAt(i);
      nums = (Vector) nodes.elementAt(i);
      // in our vector of integers we read, the numbers after 3rd number are neighbors
      j = 3;
      while (j < nums.size()) {
        // and now we add neighbors
        x = ( (Integer) nums.elementAt(j)).intValue();
        p.addNeighbor( (GraphNode) g.elementAt(x));
        j = j + 1;
      }
      i = i + 1;
    }
    return g;
  }

  public void outputGraph(Graph g) {
    int i, j, index;
    JoosIO f;
    GraphNode p;
    Vertex v;
    Vector neighbors;
    i = 0;
    f = new JoosIO();
    // scan through the graph and print a line for each node
    while (i < g.size()) {
      // get the node
      p = (GraphNode) g.elementAt(i);
      // get the vertex
      v = p.getVertex();
      // print first 3 numers
      f.print(i + "\t" + v.getX() + "\t" + v.getY());
      // get the neighbors
      neighbors = p.getNeighbors();
      j = 0;
      // now print the neighbors
      while (j < neighbors.size()) {
        // get the index of the neighbor so we can print it
        index = g.indexOf( ( (GraphNode) neighbors.elementAt(j)));
        f.print("\t" + index);
        j = j + 1;
      }
      f.print("\n");
      i = i + 1;
    }
  }

  public static void main(String[] args) {
    HillClimb h;
    Graph g;
    Graph solution;
    h = new HillClimb();
    g = h.readGraph();
    solution = h.hillClimb(g);
    h.outputGraph(solution);
  }
}
