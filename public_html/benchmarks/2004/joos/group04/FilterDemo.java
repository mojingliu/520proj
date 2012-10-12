import java.awt.image.BufferedImage;
import imagelib.JoosImageIO;
import joos.lib.JoosFraction;
import joos.lib.JoosString;
import imagelib.JoosSystem2;

public class FilterDemo {
  public FilterDemo() {
    super();
  }
  public static void main(String[] args) {
    int dx, dy;
    BufferedImage image;
    JoosString s;
    JoosImageIO jiio;
    JoosSystem2 js;
    JoosFraction f;
    Filter filter;
    s = new JoosString("ss");
    jiio = new JoosImageIO();
    js = new JoosSystem2();
    image = jiio.read(js.getIn());
    filter = new Filter();
    // crop the central part of the image
    dx = image.getWidth()/5;
    dy = image.getHeight()/5;
    image = filter.crop(image, dx, dy, image.getWidth()-2*dx, image.getHeight()-2*dy);
    // increase the saturation
    f = new JoosFraction(3, 2);
    image = filter.setSaturation(image, f); 
    // increase the brightness
    f = new JoosFraction(4, 3);
    image = filter.setBrightness(image, f); 
    // scale by a factor of 2
    f = new JoosFraction(2,1); 
    image = filter.scale(image, f, f);
    // output
    jiio.writePNGToStandardOut(image);
  }
}
