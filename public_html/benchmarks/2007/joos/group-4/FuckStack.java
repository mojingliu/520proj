/* Fuck Stack
this is an implementation of a fuck stack. The fuck stack is used
to match brackets in brainfuck.
one cannot push a value on the
fuck stack. Instead, pushing pushes some integer, and returns an integer.
This integer is unique, i.e. every integer will only be used once
during the life of the fuck stack. Operations

int push   : pushes a unique integer on stack
int pop    : pops current integer from stack
int size   : returns size of stack
*/
import joos.lib.*;


public class FuckStack
{
    //protected Vector vc;
  
    protected int nextUID; //next unique id used in this stack
    protected FuckStackNode top; //top of the stack
    protected int s; //size of stack

    public FuckStack()
    {
	super();
	nextUID = 0;
	s = 0;
	top = null;
    }

    public int push()
    {
	top = new FuckStackNode(nextUID,top);
	nextUID++;
	s++;
	return nextUID-1;
    }
    public int pop()
    {
	//Will throw exception when stack is empty
	int i;
	i = top.getId();
	top = top.getNext();
	s = s-1;
	return i;
    }
    public int peek()
    {
	return top.getId();
    }

    public int size()
    {
	return s;
    }

//  public push
//  public pop
//  public size
  
  
  
}
