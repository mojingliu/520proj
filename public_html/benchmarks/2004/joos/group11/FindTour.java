import java.io.*; 
import joos.lib.*;
import java.util.*;

public class FindTour {
   
    protected TwoDVector graph; // stores all vertices and their needed 
                                // information
    protected TwoDVector tour;  // stores a knights tour if one exists
    protected BitMap inTour;    // tracks whether a Vertex has been used - 
                                // no repeats are allowed 
    protected int tourLength;   // length of the tour is dependent on 
                                // dimension parameter
 
    public FindTour() {
       super();
    }

    public void go(int dimension ){
        int startSquare, i;
        Vertex root;
        JoosIO io;

        io = new JoosIO();
       
        tourLength = dimension*dimension - 1;
        // find the startSquare to start the tour from
        startSquare = this.findStartSquare(dimension); 

        // create graph
        this.createGraph(dimension);
        // build graph vertices and pointers
        this.buildGraph(dimension, startSquare);
 
        // create a tour to hold the found tour 
        tour = new TwoDVector();
        tour.create(dimension*dimension, 2);
       
        // create a BitMap to track if square already in tour
        inTour = new BitMap(dimension);

        // set the starting Vertex
        root = (Vertex)graph.getElem(startSquare, startSquare);

        // output result
        if (this.findTour(root, dimension*dimension)) {
	        io.println("A Knights Tour exists and is as follows");
	        //output tour
            i = 0;
            while (i < dimension*dimension){
	            io.println(((Integer)tour.getElem(i, 0)).toString()+","+((Integer)tour.getElem(i, 1)).toString());
                i = i + 1;
	        }
        }
        else {
	        io.println("A Knights Tour does not exist");
        }
         
    }

    // allows the start square to be close to center as possible
    public int findStartSquare(int dimension) {
	    return dimension/2;
    }
    
    // create space for all the vertices in the chess board
    public void createGraph(int dimension) {
        int i, j;
        JoosIO io;
        graph = new TwoDVector();
        graph.create(dimension, dimension);
        i = 0;
        io = new JoosIO();
        while (i < dimension){
            j = 0;
            while (j < dimension) {
		        graph.setElem(i, j, new Vertex());
	            j = j + 1;
            }
            i = i + 1;
	    }
    }

    // build graph by setting any needed info and building each 
    // vertices adjacency list
    // and then sort each vertices adjacency list
    public void buildGraph(int dimension, int startSquare) {
	    int index, i, j;
        JoosIO io;
        io = new JoosIO();
        index = 0;
        i = 0;
        while (i < dimension){
            j = 0;
	        while(j < dimension) {
		        ((Vertex)graph.getElem(i, j)).setRow(i);
		        ((Vertex)graph.getElem(i, j)).setCol(j);
		        ((Vertex)graph.getElem(i, j)).setInfo(dimension, startSquare);
		        j = j + 1;
	        }
            i = i + 1;
	    }
        i = 0;
        while (i < dimension) {
	        j = 0;
            while (j < dimension) {
		        ((Vertex)graph.getElem(i, j)).initAdjList(graph);
	            j = j + 1;
            }
            i = i + 1;
	    }    
        i = 0;
        while(i < dimension) {
            j = 0;
	        while(j < dimension) {
		        ((Vertex)graph.getElem(i, j)).sortAdjList();
	        
                j = j + 1;
            }
            i = i + 1;
	    }    
   
    }

    // when a new Vertex is looked at use this method to update the tour
    public void updateTour(int numLevel, int row, int column) {
	
        tour.setElem(numLevel, 0, new Integer(row));
	    tour.setElem(numLevel, 1, new Integer(column));
    }

    // function called recursively for each level of the tour 
    public boolean findTour(Vertex next, int numLevels){
	
	    Vertex nextNode;
	    boolean result;
        int i;
        
        result = false;

	    // if index already in tour return false - no repeats
	    if (inTour.check(next.getRowNum(), next.getColNum())) {
	        return false;
	    }

        // mark index as used and add to tour
        inTour.mark(next.getRowNum(), next.getColNum());
	    this.updateTour((numLevels-1),next.getRowNum(),next.getColNum());

	    // if we are at the bottom check if a cycle
	    // if yes return true otherwise clear bits and return false
	    if (numLevels == 1) {
	        if (this.startInAdjList(next)) {
		        return true;
	        }
	        else {
                inTour.clear(next.getRowNum(), next.getColNum());
		        return false;
	        }
	    }
	    // if not at bottom recursively call findTour on all subtrees
	    // until a cycle is found
	    else {
            i = 0;
	        while(i < next.getNumMoves() && !result) {
		        result =  this.findTour(next.getIthNode(i), (numLevels - 1));
                i = i + 1;
	        }
	        if (!result) {
	            inTour.clear(next.getRowNum(), next.getColNum());
	        }
	        return result;
	    }
    }
    
    // determine whether the startSquare is in the adjacency list 
    // of the last node 
    public boolean startInAdjList(Vertex next) {
        int j;
        j = 0;
        while(j < next.getNumMoves()) {
	        if (((Vertex)((Vector)next.getAdjList()).elementAt(j)).getRowNum() == ((Integer)tour.getElem(tourLength, 0)).intValue() && 
	            ((Vertex)((Vector)next.getAdjList()).elementAt(j)).getColNum() == ((Integer)tour.getElem(tourLength, 1)).intValue()) {
	            return true;
	        }
            j = j + 1;
        }
        return false;
    }

}

