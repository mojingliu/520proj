
import java.util.*;
import joos.lib.*;

public class Vertex {
  
    protected int MAX_OPTIONS;  // any vertex has a max of 8 options to move
    protected Vector adjList;   // list of options to move to
    protected int dimension;    // size of the board
    protected int numMoves;     // number of moves a vertex actually has
    protected int maxDim;       // used as boundary
    protected int rowNum;       // row number
    protected int colNum;       // column number 
    protected int distance;     // distance of vertex from start square

    // vertex constructor
    public Vertex() {
        super();
        MAX_OPTIONS = 8;
        dimension = 0;
        numMoves = 0;
        maxDim = 0;
        rowNum = 0;
        colNum = 0;
        distance = 0;
    }
    
    // set the row number
    public void setRow(int i) {
	    rowNum = i;
    }
    // set the column number
    public void setCol(int j) {
	    colNum = j;
    }
    // set other info - specifically the dimension of the board, 
    // and startSquare
    // find the distance of the vertex given the starting square
    public void setInfo(int dim, int startSquare) {
        int tempRow, tempCol;
	    dimension = dim;
        maxDim = dimension - 1;
        tempRow = rowNum - startSquare;
        if (tempRow < 0){
            tempRow = 0 - tempRow;
        }
        tempCol = colNum - startSquare;
        if (tempCol < 0){
            tempCol = 0 - tempCol;
        }
	    distance = tempRow + tempCol;
    }
    
    // determine for a vertex where it can move - it cannot go 
    // beyond boundaries
    public void initAdjList(TwoDVector graph) {
        int i;
        JoosIO io;
        
        i = 0;
        adjList = new Vector(MAX_OPTIONS);
        while (i < MAX_OPTIONS){
            adjList.insertElementAt(new Vertex(), i);
            i = i + 1;
        }
        io = new JoosIO();
        
	    // build adjList with possible moves, max eight
        if (rowNum-2 >= 0 && colNum-1 >= 0) {
            adjList.setElementAt(graph.getElem(rowNum - 2, colNum - 1), numMoves);
	        numMoves = numMoves + 1;
	    }
	    if (rowNum-1 >= 0 && colNum-2 >= 0) {
            adjList.setElementAt(graph.getElem(rowNum-1, colNum-2), numMoves);
	        numMoves = numMoves + 1;
	    }	
	    if (rowNum+1 <= maxDim && colNum-2 >= 0) {
            adjList.setElementAt(graph.getElem(rowNum+1, colNum-2), numMoves);
	        numMoves = numMoves + 1;
	    }
	    if (rowNum+2 <= maxDim && colNum-1 >= 0) {
            adjList.setElementAt(graph.getElem(rowNum+2, colNum-1), numMoves);
	        numMoves = numMoves + 1;
	    }
	    if (rowNum+2 <= maxDim && colNum+1 <= maxDim) {
            adjList.setElementAt(graph.getElem(rowNum+2, colNum+1), numMoves);
	        numMoves = numMoves + 1;
	    }
	    if (rowNum+1 <= maxDim && colNum+2 <= maxDim) {
            adjList.setElementAt(graph.getElem(rowNum+1, colNum+2), numMoves);
	        numMoves = numMoves + 1;
	    }
	    if (rowNum-1 >= 0 && colNum+2 <= maxDim) {
            adjList.setElementAt(graph.getElem(rowNum-1, colNum+2), numMoves);
	        numMoves = numMoves + 1;
	    }
	    if (rowNum-2 >= 0 && colNum+1 <= maxDim) {
            adjList.setElementAt(graph.getElem(rowNum-2, colNum+1), numMoves);
	        numMoves = numMoves + 1;
	    }

    }
    
    // sort adjList from nodes with least options to most 
    // for ties pick node farthest from startNode 
    // simple insertion sort
    public void sortAdjList() {
        Vertex key; 
        int i, j;
        boolean result;
        JoosIO io;

        io = new JoosIO();
        j = 1;
        while (j < numMoves){
	        key = (Vertex)adjList.elementAt(j);
            i = j - 1;
            result = this.betterVertex((Vertex)adjList.elementAt(i), key);
            while (i >= 0 && result) {
		        adjList.setElementAt(adjList.elementAt(i), i + 1);
		        i = i - 1;
            }
	        j = j + 1;
	        adjList.setElementAt(key, i + 1);
        }
	}

    // return true if v2 is a better vertex to use then v1 - ie: if v2 
    // has less options or
    // is further from the startSquare
    public boolean betterVertex(Vertex v1, Vertex v2){
        int i, j;
        i = v1.getNumMoves();
        j = v2.getNumMoves();
        if (i > j) {
	        return true;
        }
        else if (i == j) {
	        if (v1.getDistance() < v2.getDistance()) {
	            return true;
	        }
	        else {
	            return false;
	        }
        }
        else {
	        return false;
        }
      
    }
    // return the ith node from the vertices adjacency list
    public Vertex getIthNode(int i) {
        if (i < MAX_OPTIONS) {
	        return (Vertex)adjList.elementAt(i);
	    }
	    else {
	        return null;
	    }
    }

    public int getRowNum(){
        return rowNum;
    }

    public int getColNum(){
        return colNum;
    }
    
    public int getNumMoves(){
        return numMoves;
    }

    public int getDistance(){
        return distance;
    }

    public Vector getAdjList(){
        return adjList;
    }
    
    public String toString() {
        return "numMoves: "+numMoves+" row: "+rowNum+" col: "+colNum+" distance: "+distance;
    }
}






