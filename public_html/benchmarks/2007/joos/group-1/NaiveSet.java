import java.util.Vector;

/**
 * A set with linear-time operations (i.e. backed by a list).
 */
public class NaiveSet {

	protected Vector elements;
	
	public NaiveSet() {
		super();
		elements = new Vector();
	}
	
	public void add(Object o) {
		if(!elements.contains(o)) {
			elements.addElement(o);
		}
	}
	
	public void addAll(NaiveSet s) {
		int i;
		Vector v;
		
		v = s.toVector();
		for (i = 0; i < v.size(); i++) {
			this.add(v.elementAt(i));
		}
	}
	
	public boolean contains(Object o) {
		return elements.contains(o);
	}
	
	public int size() {
		return elements.size();
	}
	
	public boolean isEmpty() {
		return elements.isEmpty();
	}
	
	public NaiveSet copy() {
		NaiveSet other;
		int i;
		
		other = new NaiveSet();
		for (i = 0; i < elements.size(); i++) {
			other.add(elements.elementAt(i));
		}
		
		return other;
	}
	
	public Vector toVector() {
		Vector v;
		int i;
		
		v = new Vector();
		for (i = 0; i < elements.size(); i++) {
			v.addElement(elements.elementAt(i));
		}
		
		return v;
	}
	
	public String toString() {
		return "{" + elements + "}";
	}

	public int hashCode() {
//		int h;
//		int i;
//		
//		i = 0;
//		h = 0;
//		while(i < elements.size()) {
//			h = h + elements.elementAt(i).hashCode();
//			i = i + 1;
//		}
//		
//		return h;
		return this.size();
	}

	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		} else if (obj == null) {
			return false;
//		} else if (this.getClass() != obj.getClass()) {
//			return false;
		}
		
		
		{
			NaiveSet other;
			Vector otherElements;
			int i;
			
			other = (NaiveSet) obj;
			otherElements = other.toVector();
			
			for (i = 0; i < elements.size(); i++) {
				if(!other.contains(elements.elementAt(i))) {
					return false;
				}
			}
			
			for (i = 0; i < other.size(); i++) {
				if(!this.contains(otherElements.elementAt(i))) {
					return false;
				}
			}
			
			return true;
		}
	}
	
	
}
