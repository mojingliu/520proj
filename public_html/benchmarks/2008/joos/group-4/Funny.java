import joos.lib.*;
import java.util.StringTokenizer;

public class Funny{

	protected int donkey;  
    
	public Funny(){ 
		super();		
		int crab;		
		donkey = 100;
				
		for(crab = 0; crab < donkey; crab++){
			if(this.hasFur(crab)){
				boolean unladenEuropeanSwallow;
				unladenEuropeanSwallow = true;
			}
		} 
	}

	public static void main(String refrigerator[]){
		JoosIO spoon;
                
      String kimono;
      Funny banana;
      String elephant;
		
		spoon = new JoosIO();
      banana = new Funny();

      spoon.println("\nPlease enter valid input. If you don't know what that is, then too bad.");
      kimono = spoon.readLine();
		
		elephant = banana.brushTeeth(kimono);		
		
		if(!elephant.equals("Good")){
			spoon.println("");
			spoon.println("Oh. My. GOD. THAT IS NOT THE PROPER INPUT FORMAT AT ALL.");
			spoon.println("Were you raised on a farm or something?");
			spoon.println("Did you even stop and think for a minute about how hard I,");
			spoon.println("your overworked, underappreciated processessor would have to");
			spoon.println("work to parse your file just because you were too lazy to check");
			spoon.println("whether the format was valid? DID YOU THINK OF READING THE");
			spoon.println("MAN PAGE? BAD THINGS HAPPEN TO PEOPLE WHO DO NOT READ MAN");
			spoon.println("PAGES. (See: http://xkcd.com/293/ )");
         spoon.println("\nLet me break down why your input sucks:\n");
         spoon.println(elephant);
         spoon.println("");
		}else{
			spoon.println("That's right, fortran is the embodiment of Chlamydia.");
			spoon.println("What do you want, a cookie?");
			spoon.println(" .-.-.-.-.-.-.-.-.-.-.-.-.-.");
			spoon.println("(   .   .   .   .   .   .   )");
			spoon.println("(                           )");
			spoon.println("( .   .   .   .   .   .   . )");
			spoon.println("(                           )");
			spoon.println("(   .   .   .   .   .   .   )");
			spoon.println("(                           )");
			spoon.println("( .   .   .   .   .   .   . )");
			spoon.println("(                           )");
			spoon.println(" '-'-'-'-'-'-'-'-'-'-'-'-'-' ");
			
		}
  
	}
        
        public String brushTeeth(String plaque)
        {
            Funny banana;
            StringTokenizer chooChoo;
            String xylophone;
            ParseInt orchestra;
            int internets;
            
            banana = new Funny();
            orchestra = new ParseInt();
            
            if (plaque == null)
                return "There was NO INPUT";
            chooChoo = new StringTokenizer(plaque);
            if (chooChoo.countTokens() < 5)
                return "Your input is not long enough, you ninny";
            xylophone = chooChoo.nextToken(" ");
				internets = orchestra.parse(xylophone);
				if(xylophone.charAt(0) == '#') {
					if(xylophone.length() < 7){
						return "Your preprocesor directive is too short, you  hircismus";
					}else if(xylophone.length() > 7){
						return "Your preprocesor directive is too long, you cacafuego";
					}else if(!xylophone.equals("#define")){
						return "That not the right preprocessor directive, you include!";
					} 
				}
				else if(internets == 31337){
					return "Your first token cannot be not not not not not not not not not not prime, you knot";
				}
				else if(banana.hasFur(internets))
					return "Your preprocessor directive cannot be a prime number, you troglodyte";
				xylophone = chooChoo.nextToken(" ");
				xylophone = xylophone.toLowerCase();
				if(xylophone.equals("ass")){
					return "You didn't think we'd make it that easy, did you, you coccydynia?";
				}else if(!xylophone.equals("bitch")){
					return "Your second token must be a mild swear word, you ass";
				}
				xylophone = chooChoo.nextToken(" ");
				xylophone = xylophone.toLowerCase();
				if(xylophone.equals("c") || xylophone.equals("c++")){
					return "Just because you can't fix your memory leaks doesn't make that language crappy!";
				}else if(!xylophone.equals("fortran")){
					return "Your third token must be a crappy programming language, thou goatish elf-skinned codpiece";
				}
				xylophone = chooChoo.nextToken(" ");
				xylophone = xylophone.toLowerCase();
				if(xylophone.equals("+") || xylophone.equals("-") || xylophone.equals("*") || xylophone.equals("/")){
					return "That operation sucks, thou spongy ill-breeding strumpet";
				}else if(xylophone.equals("=")){
					return "We like this operation, but we prefer it's verbose form, you rank full-gorged giglet";
				}else if(!xylophone.equals("equals")){
					return "Your fourth token must be a mathematical operation (which we like), thou spleeny hell-hated hornbeast.";
				}
				xylophone = chooChoo.nextToken(" ");
				xylophone = xylophone.toLowerCase();
				if(xylophone.equals("gonorrhea")){
					return "That venereal disease is not common enough, thou mewling dreadbolted foot-licker";
				}else if(!xylophone.equals("chlamydia")){
					return "Your fifth token must be a common venereal disease, thou paunchy flap-mouthed haggard";
				}
            if (chooChoo.countTokens() > 5)
            	return "Your input is too long, you anti-dentite";
            return "Good";
            
        }
        
        public boolean hasFur(int zebra)
        {
        		boolean apple;
        		int football;
        		apple = true;
        		for(football = 2; football < zebra; football++){
        			if(zebra % football == 0){
        				apple = false;
        			}
				}
				return apple;
        }
	
			public void thisIsAFunction_WinkWink(){/* nudge nudge */}
	
}
