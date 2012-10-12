/**
 * A pair of objects.
 */
public class Pair {
	protected Object left;
	protected Object right;
	
	public Pair(Object l, Object r) {
		super();
		left = l;
		right = r;
	}

	public Object getLeft() {
		return left;
	}
	
	public Object getRight() {
		return right;
	}

	public void setLeft(Object l) {
		left = l;
	}

	public void setRight(Object r) {
		right = r;
	}
	
	public String toString() {
		return "(" + left + ", " + right + ")";
	}
}
