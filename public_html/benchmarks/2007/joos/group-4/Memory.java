/* the memory container
This class holds the memory, which is a doubly infinite tape memory. There is a pointer
to memory. Every position in memory is a byte long (even if actual integers are used
internally). Operations are:
-previous : moves pointer up
-next     : moves pointer down
-get      : returns value at current position as integer
-inc      : increases value at current position, wraps
-dec      : decreases value at current position, wraps
-set      : sets byte at current position
-get      : gets byte at current position
*/
import joos.lib.*;


public class Memory {
  protected IntList current; //current node in the integer list

  //constructor - creates a list that is empty
  public Memory(){
     super();
     current = new IntList(0, null, null);
  }

  public void prev() { // <
    current = current.getPrev();
  }

  public void next() { // >
    current = current.getNext();
  }

  public void inc()  { // +
    current.set(current.get()+1);
  }

  public void dec()  { // -
    current.set(current.get()-1);
  }

  public void set(int value) {
    current.set(value % 256);
  }

  public int get() {
    return current.get();
  }
}
