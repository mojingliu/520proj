public class Tree {

	protected Node first;
	protected Node last;

	public Tree() {
		super();
	}

	public String toString() {
		String output;
		Node node;

		node = first;
		output = "";

		while (node != null) {
			output = output + node.toString();
			node = node.getNext();
		}

		return output;
	}

	public void addNode(Node node) {
		if (first == null) {
			node.setPrev(null);
			node.setNext(null);
			first = node;
			last=node;
		}
		else {
			last.setNext(node);
			node.setPrev(last);
			node.setNext(null);
			last = node;
		}
	}
}
