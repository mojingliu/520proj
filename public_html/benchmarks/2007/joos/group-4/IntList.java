/* integer List
Implements a simple integer list, where the list object is
actually a node of the list. No checks etc are performed
with the following operations
-next        : gets next element in list, null if last
-setnext     : sets next element w/o checks
-prev        : gets previous element in list, null if first
-setprev     : sets previous element w/o checks
-get         : sets value
-set         : gets getsvalue
*/

public class IntList {
  //private locals
  protected int val; //value
  protected IntList prev, next; //pointers next previous

  //constructor, taking value and two pointers
  public IntList(int value, IntList Prev, IntList Next){
    super();
    val = value;
    prev = Prev;
    next = Next;
  }

  //getnext
  public IntList getNext(){
    if(next == null) {
        next = new IntList(0,this,null);
    }
    return next;
  }
	
  //setnext
  public void setNext(IntList Next){
    next = Next;
  }
	
  //getprev
  public IntList getPrev(){
    if(prev == null) {
        prev = new IntList(0,null,this);
    }
    return prev;
  }
	
  //setprev
  public void setPrev(IntList Prev){
    prev = Prev;
  }
	
  //get value
  public int get(){
    return val;
  }
	
  //set value
  public void set(int value){
    val = value;
  }
}
