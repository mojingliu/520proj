package imagelib;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import javax.imageio.ImageIO;

public class JoosImageIO {
  public JoosImageIO(){}
  public BufferedImage read(InputStream input) {
    try {
      return ImageIO.read(input);
    } catch (IOException e) {
      return null;
    }
  }
  
  public boolean writePNGToStandardOut(BufferedImage im) {
    try {
      return ImageIO.write(im, "PNG", System.out);
    } catch (IOException e) {
      return false;
    }
  }
}
