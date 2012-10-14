// /* The SieveThread modifies a list by removing all multiples of n.
//  *
//  * Louis Kearns <louis.kearns@cs.mcgill.ca> 
//  * Kacper Wysocki <kwysoc@cs.mcgill.ca>
//  * October 1st, 2004
//  */

import joos.lib.*;

public class SieveThread extends Thread {

	protected LinkedList list;
	protected int num;

	public SieveThread(LinkedList lst, int n) {
		super();
		list = lst;
		num = n;		
	}

	public void run() {
		JoosIO j;
		j = new JoosIO();
		this.deleteMultiple(num, list);
	}
	
	public void deleteMultiple(int n, LinkedList l) {
		int i;
		i = 0;
		while (i < l.getLength()) {
			int element;
			element = l.getAt(i);
			
			if (element == n) {
				;//empty statement;
			}
			else {
				if (element % n == 0) {
					l.remove(element);
				}
			}
			i = i + 1;
		}
	}
}
