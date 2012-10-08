public class CasterNotId {
	public CasterNotId() {
		super();
	}
	
	public void test() {
		CasterNotId i,j; 
		// a cast
		i = (CasterNotId)new CasterNotId();
		// not a cast
		j = (5+2)new CasterNotId();
	}
}