/* Fuck Stack Node
this is an implementation of a fuck stack Node. The fuck stack is used
to match brackets in brainfuck.
Every instance of fuck stack is a node. one cannot push a value on the
fuck stack. Instead, pushing pushes some integer, and returns an integer.
This integer is unique, i.e. every integer will only be used once
during the life of the fuck stack. Operations

*/


public class FuckStackNode{
    protected int i; //The integer stored at this node
    protected FuckStackNode next; //The node bellow this one on the stack
    public FuckStackNode(int v, FuckStackNode n)
    {
	super();
	i = v;
	next = n;
    }



    public int getId()
    {
	return i;
    }
    public FuckStackNode getNext()
    {
	return next;
    }
}