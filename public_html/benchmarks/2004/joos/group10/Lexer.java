public class Lexer {

	protected String expression;
	protected String parsingExpression;

	public Lexer(String v) {
		super();
		parsingExpression = v.trim();
	}

	public String getNextToken() {
		String token;
		int index;

		index = 0;
		token = new String("");
		parsingExpression = parsingExpression.trim();

		if (parsingExpression.charAt(index) == '+') {
			parsingExpression =
				parsingExpression.substring(1, parsingExpression.length());
			return "+";
		}

		if (parsingExpression.charAt(index) == '-') {
			parsingExpression =
				parsingExpression.substring(1, parsingExpression.length());
			return "-";
		}

		while (index < parsingExpression.length()) {
			if ((parsingExpression.charAt(index) == '-')
				|| (parsingExpression.charAt(index) == '+')
				|| (parsingExpression.charAt(index) == ' ')) {
				token = parsingExpression.substring(0, index);
				parsingExpression =
					parsingExpression.substring(
						index,
						parsingExpression.length());
				return token;
			}

			index = index + 1;
		}

		token = parsingExpression.substring(0, index);
		parsingExpression =
			parsingExpression.substring(index, parsingExpression.length());

		return token;
	}

	public boolean isEmpty() {
		if (parsingExpression.length() == 0)
			return true;
		return false;
	}
}
