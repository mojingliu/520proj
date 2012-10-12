
// Louis Kearns <louis.kearns@cs.mcgill.ca> 
// Kacper Wysocki <kwysoc@cs.mcgill.ca>
// October 1st, 2004

import joos.lib.*;

public class ListNode { 

	protected int element;
	protected ListNode next;

	public ListNode(int e, ListNode n) {
	 super();
	 element = e;
	 next = n;
	}

	public void set(int e) {
		element = e;
	}
	
	public void setNext(ListNode n) {
		next = n;
	}

	public int get() {
		return element;
	}

	public ListNode getNext() {
		return next;
	}
}
