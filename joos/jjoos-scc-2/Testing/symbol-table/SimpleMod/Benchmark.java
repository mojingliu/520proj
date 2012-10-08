/*
 * NEGATIVE TESTING
 * 1. SymInterface:
 *    1. class name taken OK
 *    2. cons name diff from class name OK
 *    3. method name taken OK
 */
 
import joos.lib.*;

public abstract class Benchmark /*1.1 JoosString*/ {

  protected JoosSystem s;

  public Benchmarks/*1.2*/() { 
    super(); 
    s = new JoosSystem(); 
  } 

  public abstract void benchmark();

  public int myrepeat(int count)
  { int start; 
    int i;

    start = s.currentTimeMillis();
    i = 0;
    while (i < count)
      { this.benchmark();
        i = i + 1;
      }
    return(s.currentTimeMillis() - start);
  }
  
  public void s() {;} /*1.3*/

}