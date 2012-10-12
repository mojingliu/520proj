import java.awt.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class Viewer {

  public Viewer() {
    try {
      jbInit();
    }
    catch (Exception ex) {
      ex.printStackTrace();
    }
  }

  // our graphs
  Graph problemGraph = null;
  Graph mstGraph = null;
  Graph aStarGraph = null;
  Graph hillClimbGraph = null;
  Graph geneticGraph = null;
  JFileChooser fc = new JFileChooser();

  private void jbInit() throws Exception {
    fc.setCurrentDirectory(new File(System.getProperty("user.dir")));
    Panel1.setPreferredSize(new Dimension(158, 30));
    Panel2.setPreferredSize(new Dimension(550, 600));
    problemGenerate.setFont(new java.awt.Font("SansSerif", Font.PLAIN, 9));
    problemGenerate.setPreferredSize(new Dimension(100, 23));
    problemGenerate.setMargin(new Insets(3, 10, 2, 10));
    problemGenerate.setText("Graph 1");
    problemGenerate.addActionListener(new Viewer_problemGenerate_actionAdapter(this));
    mstGenerate.setFont(new java.awt.Font("SansSerif", Font.PLAIN, 9));
    mstGenerate.setPreferredSize(new Dimension(100, 23));
    mstGenerate.setMargin(new Insets(3, 10, 2, 10));
    mstGenerate.setText("Graph 2");
    mstGenerate.addActionListener(new Viewer_mstGenerate_actionAdapter(this));
    generateGraph.setFont(new java.awt.Font("SansSerif", Font.PLAIN, 9));
    generateGraph.setPreferredSize(new Dimension(100, 23));
    generateGraph.setText("Generate");
    generateGraph.addActionListener(new Viewer_generateGraph_actionAdapter(this));
    jTextField1.setPreferredSize(new Dimension(50, 20));
    jTextField1.setText("100");
    jTextField1.setHorizontalAlignment(SwingConstants.CENTER);
    jTextField1.setScrollOffset(0);
    jLabel1.setText("Vertices:");
    Panel2.add(problemPanel);
    Panel2.add(solutionPanel);
    jFrame1.getContentPane().add(Panel1, java.awt.BorderLayout.NORTH);
    Panel1.add(jLabel1);
    Panel1.add(jTextField1);
    Panel1.add(generateGraph);
    Panel1.add(problemGenerate);
    Panel1.add(mstGenerate);
    jFrame1.getContentPane().add(Panel2, java.awt.BorderLayout.CENTER);
    jFilePicker.getContentPane().add(jFileChooser1,
                                     java.awt.BorderLayout.CENTER);
    jFilePicker.setSize(500, 400);
    jFrame1.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    jFrame1.setSize(760, 430);
    jFrame1.setTitle("graphViewer");
    jFrame1.setVisible(true);
  }

  // more GUI Swing stuff
  JFrame jFrame1 = new JFrame();
  JFrame jFilePicker = new JFrame();
  Graph nodes = new Graph();
  int numVertex = 0;
  DrawPanel problemPanel = new DrawPanel();
  DrawPanel solutionPanel = new DrawPanel();
  JPanel Panel2 = new JPanel();
  JPanel Panel1 = new JPanel();
  JButton problemGenerate = new JButton();
  JButton mstGenerate = new JButton();
  JFileChooser jFileChooser1 = new JFileChooser();
  JButton generateGraph = new JButton();
  JTextField jTextField1 = new JTextField();
  JLabel jLabel1 = new JLabel();
  public void generateGraph(File file, int size) throws IOException {
    FileWriter in = new FileWriter(file, false);
    BufferedWriter f = new BufferedWriter(in);

    String ln;
    int x, y;
    for (int i=0; i<size; i++) {
      ln = "";
      // nice printing
      if (i<10) {
        ln += i + "   ";
      }
      else if (i<100) {
        ln += i + "  ";
      }
      else {
        ln += i + " ";
      }

      x = (int) Math.round(Math.random()*100);
      y = (int) Math.round(Math.random()*100);
      if (x>10) {
        if (y>10) {
          ln += x + " " + y + " ";
        }
        else {
          ln += x + " " + y + "  ";
        }
      }
      else {
        if (y > 10) {
          ln += x + "  " + y + " ";
        }
        else {
          ln += x + "  " + y + "  ";
        }
      }

      ln +="\t";

      for (int j=0; j<size; j++) {
        if (j==i) {
          ln += "   ";
        }
        else {
          ln += j + " ";
        }
      }
      ln +="\n";
      f.write(ln);
    }
    f.close();
  }


  public Graph readGraph(File file) throws IOException {
    Graph g;
    GraphNode p;
    Vertex v;
    Vector nums;
    Vector nodes;
    String input;
    StringTokenizer tokens;
    int i, j;
    int x, y;
    nums = new Vector();
    nodes = new Vector();
    g = new Graph();
    FileReader in = new FileReader(file);
    BufferedReader f = new BufferedReader(in);

    // format of the file is
    //    i   x   y   n1   n2   n3 ....
    // where i is the number of the node
    // x and y are coordinates (must be positive!)
    // n1 n2 n3 and so on are the indices of neighbor nodes for this node

    // read each line
    while ( (input = f.readLine()) != null) {
      tokens = new StringTokenizer(input);
      while (tokens.hasMoreElements()) {
        nums.addElement(new Integer( (String) tokens.nextElement()));
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
    f.close();
    return g;
  }

  public void drawProblem(DrawPanel panel, Graph nodes, Color c,
                          boolean drawWeight) {
    // real deal
    Vertex s, t;
    GraphNode p;
    GraphNode q;
    // set the color
    panel.setColor(c);
    for (int i = 0; i < nodes.size(); i++) {
      // get the vertex from the node
      p = (GraphNode) nodes.get(i);
      s = p.getVertex();
      // draw the vertex
      panel.drawPoint(s.getX(), s.getY());
      for (int j = 0; j < p.getNeighbors().size(); j++) {
        // get the neighbor vertex
        q = (GraphNode) p.getNeighbors().get(j);
        t = q.getVertex();
        // every edge gets draw twice, but dont really care
        panel.drawEdge(s.getX(), s.getY(), t.getX(), t.getY());
      }
    }
    if (drawWeight) {
      // and finally draw the weight - if we want to
      // panel.drawString("weight~=" + ((double) Math.round(100*nodes.getWeight())/100.0));
    }
    panel.repaint();
  }

  // simple, isnt it?
  public static void main(String[] args) {
    new Viewer();
  }

  /* everything below is stuff to make the buttons work */
  public void drawGraph1_actionPerformed(ActionEvent e) {
    int returnVal = fc.showOpenDialog(this.fc);
    if (returnVal == JFileChooser.APPROVE_OPTION) {
      File file = fc.getSelectedFile();
      try {
        this.problemGraph = this.readGraph(file);
        this.problemPanel.clear();
        this.drawProblem(problemPanel, problemGraph, Color.BLUE, false);
      }
      catch (IOException E) {
        E.printStackTrace();
      }
    }
  }

  public void drawGraph2_actionPerformed(ActionEvent e) {
    int returnVal = fc.showOpenDialog(this.fc);
    if (returnVal == JFileChooser.APPROVE_OPTION) {
      File file = fc.getSelectedFile();
      try {
        Graph solutionGraph = this.readGraph(file);
        this.solutionPanel.clear();
        this.drawProblem(solutionPanel, solutionGraph, Color.yellow, false);
      }
      catch (IOException E) {
        E.printStackTrace();
      }
    }
  }

  class Viewer_problemGenerate_actionAdapter
      implements ActionListener {
    private Viewer adaptee;
    Viewer_problemGenerate_actionAdapter(Viewer adaptee) {
      this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {
      adaptee.drawGraph1_actionPerformed(e);
    }
  }

  class Viewer_mstGenerate_actionAdapter
      implements ActionListener {
    private Viewer adaptee;
    Viewer_mstGenerate_actionAdapter(Viewer adaptee) {
      this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {
      adaptee.drawGraph2_actionPerformed(e);
    }
  }

  public void generateGraph_actionPerformed(ActionEvent e) {
    int returnVal = fc.showOpenDialog(this.fc);
    if (returnVal == JFileChooser.APPROVE_OPTION) {
      File file = fc.getSelectedFile();
      try {
        this.generateGraph(file, Integer.parseInt(jTextField1.getText()));
      }
      catch (IOException E) {
        E.printStackTrace();
      }
    }
  }
}

class Viewer_generateGraph_actionAdapter
    implements ActionListener {
  private Viewer adaptee;
  Viewer_generateGraph_actionAdapter(Viewer adaptee) {
    this.adaptee = adaptee;
  }

  public void actionPerformed(ActionEvent e) {
    adaptee.generateGraph_actionPerformed(e);
  }
}
