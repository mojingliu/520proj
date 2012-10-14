public class Scanner {

	protected Lexer lexer;

	public Scanner(Lexer l) {
		super();
		lexer = l;
	}

	public Tree parse() {
		Tree tree;
		Node node;

		tree = new Tree();

		while (!lexer.isEmpty()) {
			node = this.getNewNode(lexer.getNextToken());
			tree.addNode(node);
		}

		return tree;
	}

	public Node getNewNode(String value) {
		Node node;
		node = new Node();
		node.setValue(value);
		return node;
	}

}
