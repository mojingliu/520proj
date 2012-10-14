import java.util.Vector;

/**
 * A map with linear-time operations (i.e. backed by a list). 
 */
public class NaiveMap {

	protected Vector entries; //Vector<Pair>
	
	public NaiveMap() {
		super();
		entries = new Vector();
	}
	
	public int size() {
		return entries.size();
	}
	
	public boolean isEmpty() {
		return entries.isEmpty();
	}
	
	public void put(Object key, Object value) {
		int i;
		
		for (i = 0; i < entries.size(); i++) {
			Pair entry;
			entry = (Pair) entries.elementAt(i);
			if(entry.getLeft().equals(key)) {
				entry.setRight(value);
				return;
			}
		}

		entries.addElement(new Pair(key, value));
	}
	
	public Object get(Object key) {
		int i;
		
		for (i = 0; i < entries.size(); i++) {
			Pair entry;
			entry = (Pair) entries.elementAt(i);
			if(entry.getLeft().equals(key)) {
				return entry.getRight();
			}
		}
		
		return null;
	}
	
	public boolean containsKey(Object key) {
		int i;
		
		for (i = 0; i < entries.size(); i++) {
			Pair entry;
			entry = (Pair) entries.elementAt(i);
			if(entry.getLeft().equals(key)) {
				return true;
			}
		}
		
		return false;
	}
	
	public boolean containsValue(Object value) {
		int i;
		
		for (i = 0; i < entries.size(); i++) {
			Pair entry;
			entry = (Pair) entries.elementAt(i);
			if(entry.getRight().equals(value)) {
				return true;
			}
		}
		
		return false;
	}
	
	public NaiveMap copy() {
		int i;
		NaiveMap other;
		
		other = new NaiveMap();
		for (i = 0; i < entries.size(); i++) {
			Pair entry;
			entry = (Pair) entries.elementAt(i);
			other.put(entry.getLeft(), entry.getRight());
		}
		
		return other;
	}
	
	public String toString() {
		return entries.toString();
	}
}
