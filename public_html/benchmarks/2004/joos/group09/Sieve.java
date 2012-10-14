// COMP-520 Compiler Design, Deliverable 2: JOOS benchmark.
// Louis Kearns <louis.kearns@cs.mcgill.ca> 
// Kacper Wysocki <kwysoc@cs.mcgill.ca>
// October 1st, 2004


// This class implements the Sieve of Eratosthenes, but with a little twist:
// we perform the elimination of multiples of two numbers at one time.

// We don't claim our method to be efficient.


import joos.lib.*;
import mylib.*;

public class Sieve {
	
	protected LinkedList mlist;
	
	public Sieve(int n) {
		super();

		int i;
		mlist = new LinkedList();

		i = 2;
		while (i <= n) {
			mlist.append(i);
			i = i + 1;
		}
	}

	public static void main(String[] args) {
		Sieve S;
		int n;
		JoosIO eat;
		
		eat = new JoosIO();
		n = eat.readInt();
		S = new Sieve(n);
		S.primigateafyize();
	}

	public LinkedList getMasterList() {
		return mlist;
	}

	
// 	Returns the intersection of two lists of integers.  Assumes
// 	the integers are sorted in increasing(not non-decreasing!)
// 	order

	public LinkedList intersection(LinkedList a, LinkedList b) {
		int cur_a;
		int cur_b;
		LinkedList list;

		list = new LinkedList();
		cur_a = a.pop();
		cur_b = b.pop();
		while (cur_a != -1 && cur_b != -1) {
			if (cur_a < cur_b) {
				cur_a = a.pop();
			} 
			else if (cur_b < cur_a) {
				cur_b = b.pop();
			} 
			else {
				list.push(cur_a);
				cur_a = a.pop();
				cur_b = b.pop();
			}
		}
		return list;
	}
	
// 	/* This is where all the work gets done - inits threads and merges lists.*/
	public void primigateafyize(){
		JoosIO j;
		int x,y,mul_atx,mul_aty;
		LinkedList L1;
		LinkedList L2;
		UsableThread T1;
		UsableThread T2;
		
		j = new JoosIO();
		x = 0;
		y = 1;
		mul_atx = mlist.getAt(x);
		mul_aty = mlist.getAt(y);

// 		/* until we're out of numbers to sieve... */
		while (mul_atx != -1){

			L1 = mlist.copy();
			L2 = mlist.copy();
			
			T1 = new UsableThread(new SieveThread(L1, mul_atx));
			if (mul_aty != -1){
				T2 = new UsableThread(new SieveThread(L2, mul_aty));
			}
			else{
// 				/* An empty thread just dies... and keeps the compiler happy. */
				T2 = new UsableThread(new Thread());
			}

// 			/* Start the treads and wait for them to finish. */
			T1.start();
			T2.start();
		
			T1.join(0);
			T2.join(0);
			
// 			/* Get the intersection */
		  if (mul_aty != -1){
				mlist = this.intersection(L1, L2);
			}
			else{
				mlist = L1;
			}
			x = x + 2;
			y = y + 2;
			mul_atx = mlist.getAt(x);
			mul_aty = mlist.getAt(y);
		}
		j.print(mlist.toString());
	}

	public void printInt(int i) {
		String s;
		JoosIO p;
	 	p = new JoosIO();
		s = new Integer(i).toString();
		p.println(s);
	}
}
