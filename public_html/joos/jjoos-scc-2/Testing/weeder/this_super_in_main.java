public class this_super_in_main {
	public this_super_in_main() { super(); }
	
	public static void main(String args[]) {
		this_super_in_main test;
		test = this;
		
		super.clone();
	}
}