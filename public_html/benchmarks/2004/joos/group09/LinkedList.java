// This is a linked list implementation for positive integers
// Louis Kearns <louis.kearns@cs.mcgill.ca> 
// Kacper Wysocki <kwysoc@cs.mcgill.ca>
// October 1st, 2004

import joos.lib.*;

public class LinkedList {
	
	protected ListNode head;
	protected ListNode tail;
	protected int length;
	
	public LinkedList() {
		super();
		length = 0;
	}
	
	public int getHead() {
		if (head != null){
			return head.get();
		}
		else{
			return -1;
		}
	}

	public int getTail() {
		if (tail != null){
			return tail.get();
		}
		else{
			return -1;
		}
	}

	public int getLength() {
		return length;
	}

	public boolean isEmpty(){
		return (head == null);
	}
	
    // Pushes to TAIL
	public void push(int element){
		this.append(element);
	}
	
    // Pops from HEAD 
	public int pop(){
		return this.removeAt(0);
	}

	public void append(int element) {
		ListNode tmp;
		if (length == 0) {
			head = new ListNode(element, null);
			tail = head;
		}
		else {
			tail.setNext(new ListNode(element, null));
			tail = tail.getNext();
		}
		length = length + 1;
	}
	
    // gets element at index n 
	public int getAt(int n) {
		ListNode cur;
		int i;
		if (n >= length){
			return -1;
		}
		
		cur = head;
                i = 0;
		while (i < n) {
			cur = cur.getNext();
			i = i + 1;
		}
		return cur.get();
	}
	
    // returns & removes element at index n
	public int removeAt(int n) {
		ListNode prev, cur; 
		int i;
		prev = head;
		cur = head;
		
		if (n >= length){
			return -1;
		}
		
		// decrement length 
		length = length - 1; 
		
		if (n == 0) {
			head = head.getNext();
			return cur.get();
		}	
		if (length == 1) {
			head = tail = null;
			return cur.get();
		}
                i = 0;
		while (i < n) {
			prev = cur;
			cur = prev.getNext();
			i = i + 1;
		}
		prev.setNext(cur.getNext());
		if (n == length -1) {
			tail = prev;
		}
		return cur.get();
	}

    // finds the first occurence of element and deletes it 
	public int remove(int element) {
		ListNode cur;
		int i;
		cur = head;
		i = 0;
		while (i < length) {
			if (cur.get() == element) {	
				return this.removeAt(i);
			}
			cur = cur.getNext();
			i = i + 1;
		}
		return -1;
	}

	public String toString() {
		int i;
		String s;
		Integer myInt;
		
		s = "List Will Follow:\n";
                i = 0;
		while (i < length) {
			myInt = new Integer(this.getAt(i));
			s = s + myInt.toString() + "\n";
			i = i + 1;
		}
		return s;
	}	
		
    // copies the current list 
	public LinkedList copy(){
		int i;
		LinkedList copy;
		
		copy = new LinkedList();
		i = 0;
		while (i < this.getLength()){
			copy.push(this.getAt(i));
			i = i + 1;
		}
		return copy;
	}
}

