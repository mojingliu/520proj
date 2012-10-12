public class Vertex {
  protected int x;
  protected int y;

  public Vertex() {
    super();
    x = 0;
    y = 0;
  }

  public Vertex(int xx, int yy) {
    super();
    x = xx;
    y = yy;
  }

  public Vertex(Vertex v) {
    super();
    x = v.getX();
    y = v.getY();
  }

  public int getX() {
    return x;
  }

  public int getY() {
    return y;
  }

  public String toString() {
    return "Point";
  }

  public boolean equals(Object p) {
    return (y == ((Vertex) p).getY()) && (x == ((Vertex) p).getX());
  }
}
