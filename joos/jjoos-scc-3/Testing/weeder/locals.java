public class locals {
	public locals() { super(); int i; }
	public void method1() {
		int j;
		
		j++;
		
		locals k; // bad
	}
	
	public void method2() {
		{
			char c;
			c = 'a';
			char d; // bad
		}
		if (true) {
			int i;
			if (false) {
				char d;
			}
			else 
				boolean j; // bad
		}
		
	}
}