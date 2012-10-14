public class Node {
	
	protected String value;
	
	protected Node next;
	protected Node prev;

	public Node() {
		super();
		value = "";
		next = null;
		prev=  null;
	}
	
	public String toString() {
		return value + " ";
	}

	public void setValue(String v) {
		value = v;
	}
	
	public Node getPrev() {
		return prev;
	}
	
	public void setPrev(Node p) {
		prev = p;
	}

	public Node getNext() {
		return next;
	}
	
	public void setNext(Node n) {
		next = n;
	}
}
