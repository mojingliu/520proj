import joos.lib.*;

public class Main {

	public Main() {
		super();
	}

	public static void main(String[] args) {

		JoosIO out;
		String expression;
		Lexer lexer;
		Scanner scanner;
		Tree tree;
		
		out = new JoosIO();
		expression = out.readLine();
		
		lexer = new Lexer(expression);
		scanner = new Scanner(lexer);
		
		tree = scanner.parse();
		out.println(""+tree);
		

		//expression = "     3+4567               -               3+5";

		//lexer = new Lexer(expression);
		//scanner = new Scanner(lexer);

		//tree = scanner.parse();
		//System.out.println("The expression was : " + tree);
	}
}
