public class FuckOptimizer
{

    public FuckOptimizer()
    {
	super();
    }

    public FuckNode simplify(FuckNode n)
    {
	FuckNode N;
	ValueNode v; //will hold the ValueNode when folding ValueNodes
	PointerNode p;
	p = null;
	v = null;
	N = n;
	for(N = n;n!=null;n=n.getNext()){
	    //simplify value nodes
	    if( n instanceof ValueNode ){
		if( v == null )
		    v = (ValueNode)n;
		else{
		    v.setAmount(v.getAmount()+((ValueNode)n).getAmount());
		    v.setNext(n.getNext());
		}
	    }
	    else{
		if( v != null ){
		    v = null;
		}
	    }
	    //simplify pointer nodes
	    if( n instanceof PointerNode ){
		if( p == null )
		    p = (PointerNode)n;
		else{
		    p.setAmount(p.getAmount()+((PointerNode)n).getAmount());
		    p.setNext(n.getNext());
		}
	    }
	    else{
		if( p != null ){
		    p = null;
		}
	    }

	}
	return N;
    }
}
