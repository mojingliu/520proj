import java.io.*; 
import joos.lib.*;

public class KnightsTour {   
    
    public KnightsTour(){
	    super();
    }

    public static void main(String[] args) {
	    // find a knights tour in a chess board of the given dimension

	    JoosIO f;
	    int dimension;
	    FindTour tour;

	    f = new JoosIO();
	    f.println("Enter the number of dimensions for the Knight's Tour");
	    dimension = f.readInt();

	    tour = new FindTour();
        tour.go(dimension);

    }
}



