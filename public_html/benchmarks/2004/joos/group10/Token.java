public class Token {
	
	protected String tokenId;
	protected String token;
	
	public Token(String id, String t) {
		super();
		tokenId = id;
		token = t;
	}
	
	public String getId() {
		return tokenId;
	}
	
	public String getToken() {
		return token;
	}

}
