import java.awt.image.BufferedImage;
import java.awt.Color;
import imagelib.BufferedImageConsts;
import joos.lib.JoosFraction;

public class Filter {
  public Filter() {
    super();
  }
  // clamp a color component to its minimum or maximum value.
  public int clamp(int comp){
    if (comp > 255){
      return 255;
    }
    else if (comp < 0){
      return 0;
    }
    else { 
      return comp;
    }
  }
  // Interpolates between a black image (f == 0)
  // and the source image (f == 1).
  public BufferedImage setBrightness(BufferedImage src, JoosFraction f){
    BufferedImage dest;
    int width, height, type, x, y, r, g, b;
    Color c;
    width = src.getWidth();
    height = src.getHeight(); 
    type = (new BufferedImageConsts()).getINT_RGB();
    dest = new BufferedImage(width, height, type);
    y = 0;
    while (y < height){
      x = 0;
      while (x < width){
        c = new Color(src.getRGB(x, y));
        r = c.getRed();
        g = c.getGreen();
        b = c.getBlue();
        r = (r*f.top())/f.bot();
        g = (g*f.top())/f.bot();
        b = (b*f.top())/f.bot();
        c = new Color(this.clamp(r),this.clamp(g),this.clamp(b));
        dest.setRGB(x, y, c.getRGB()); 
        x = x + 1;
      }
      y = y + 1;
    }
    return dest;
  }
  // Interpolates between a grey scale version of the image (f == 0)
  // and the source image (f == 1).
  public BufferedImage setSaturation(BufferedImage src, JoosFraction f){
    BufferedImage dest;
    int width, height, type, x, y, lum, r, g, b;
    Color c;
    width = src.getWidth();
    height = src.getHeight(); 
    type = (new BufferedImageConsts()).getINT_RGB();
    dest = new BufferedImage(width, height, type);
    y = 0;
    while (y < height){
      x = 0;
      while (x < width){
        c = new Color(src.getRGB(x, y));
        r = c.getRed();
        g = c.getGreen();
        b = c.getBlue();
        lum = (r*76 + g*150 + b*29)/255;
        r = (r*f.top() + lum*(f.bot() - f.top()))/f.bot();
        g = (g*f.top() + lum*(f.bot() - f.top()))/f.bot();
        b = (b*f.top() + lum*(f.bot() - f.top()))/f.bot();
        c = new Color(this.clamp(r),this.clamp(g),this.clamp(b));
        dest.setRGB(x, y, c.getRGB()); 
        x = x + 1;
      }
      y = y + 1;
    }
    return dest;
  }
  // Crops a part of the image.
  public BufferedImage crop(BufferedImage src, int x, int y, int w, int h){
    BufferedImage dest;
    int type, srcX, srcY;
    type = (new BufferedImageConsts()).getINT_RGB();
    dest = new BufferedImage(w, h, type);
    srcY = y;
    while (srcY < y + h){
      srcX = x;
      while (srcX < x + w){
        dest.setRGB(srcX - x, srcY - y, src.getRGB(srcX, srcY)); 
        srcX = srcX + 1;
      }
      srcY = srcY + 1;
    }
    return dest;
  }
   // Scales the image by a factor of fx horizontally and fy vertically.
  public BufferedImage scale(BufferedImage src, JoosFraction fx, JoosFraction fy){
    BufferedImage dest;
    int type, x, y, w, h;
    type = (new BufferedImageConsts()).getINT_RGB();
    w = src.getWidth()*fx.top()/fx.bot();
    h = src.getHeight()*fy.top()/fy.bot();
    dest = new BufferedImage(w, h, type);
    y = 0;
    while (y < h){
      x = 0;
      while (x < w){
        dest.setRGB(x, y, src.getRGB(x*fx.bot()/fx.top(), y*fy.bot()/fy.top())); 
        x = x + 1;
      }
      y = y + 1;
    }
    return dest;
  }
} 
