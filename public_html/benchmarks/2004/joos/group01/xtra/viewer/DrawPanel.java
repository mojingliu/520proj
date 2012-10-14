import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class DrawPanel
    extends JPanel {

  // two images to hold all we want to draw - so on repaint just redraw the images
  // when we draw something onto the image - like graphs and grid
  // image for the graph
  private BufferedImage buffer = null;
  // image for the background (i.e. the grid)
  private BufferedImage bg = null;
  int w;
  int h;
  private Color c;

  public DrawPanel() {
    h = 350;
    w = 350;
    setPreferredSize(new Dimension(h + 20, w + 20));
    buffer = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
    bg = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);

    // make the grid
    Graphics2D g = (Graphics2D) bg.createGraphics();
    // fill it with gray color
    g.setColor(new Color(128, 128, 128));
    g.fillRect(0, 0, w, h);
    // draw some gridlines on it
    g.setColor(new Color(0,0,0,64));
    for (int i = 1; i < w / 10; i++) {
      g.drawLine(i*(w/10), 0, i*(w/10), h);
    }
    for (int i = 1; i < h / 10; i++) {
      g.drawLine(0, i*(h/10), w, i*(h/10));
    }
    try {
      jbInit();
    }
    catch (Exception ex) {
      ex.printStackTrace();
    }
  }

  public void paintComponent(Graphics g) {
    // what gets called when we call a repaint() paint() update() or whatever
    super.paintComponent(g);
    g.setColor(Color.black);
    g.drawRect(9, 9, buffer.getWidth() + 1, buffer.getHeight() + 1);
    g.drawImage(bg, 10, 10, null);
    g.drawImage(buffer, 10, 10, null);
  }

  // all methods below are self explanatory
  public void drawPoint(int x, int y) {
    Graphics2D g = (Graphics2D) buffer.getGraphics();
    g.setColor(c);
    g.fillRect( (int) (this.w * x)/100 - 3, (int) (this.h * y)/100 - 3, 5, 5);
  }

  public void drawEdge(int x1, int y1, int x2, int y2) {
    Graphics2D g = (Graphics2D) buffer.getGraphics();
    g.setColor(c);
    g.drawLine( (int) ((w * x1)/100), (int) ((h * y1)/100), (int) ((w * x2)/100), (int) ((h * y2)/100));
  }

  public void drawString(String s) {
    Graphics2D g = (Graphics2D) buffer.getGraphics();
    g.setColor(new Color(255,255,255,192));
    g.drawString(s,50, h/2);
    this.repaint();
  }

  public void clear() {
    Graphics2D g = (Graphics2D) buffer.getGraphics();
    g.setComposite(AlphaComposite.Src);
    g.setColor(new Color(0, 0, 0, 0));
    g.fillRect(0, 0, w, h);
  }

  public void setColor(Color c) {
    this.c = c;
  }

  private void jbInit() throws Exception {
  }
}

