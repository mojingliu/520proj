public class CasterIsId {
	public CasterIsId() {
		super();
	}
	
	public void test() {
		CasterNotId i,j; 
		// a cast
		i = (CasterNotId)new CasterIsId();
		// another cast
		j = (CasterNotId)new CasterIsId();
	}
}