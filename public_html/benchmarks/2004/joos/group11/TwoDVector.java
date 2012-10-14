import joos.lib.*;
import java.util.*;

public class TwoDVector {

    protected Vector vect;

    public TwoDVector(){
        super();
    }
    
    public void create(int dim1, int dim2){
        int i, j;
        Vector temp;
        
        i = 0;
        vect = new Vector();
        while (i < dim1){
            temp = new Vector();
            j = 0;
            while (j < dim2){
                temp.insertElementAt(new Object(), j);
                j = j + 1;
            }
            vect.insertElementAt(temp ,i);
            i = i + 1;
        }
    }
    
    public void setElem(int x, int y, Object obj){
        Vector v;
        v = (Vector)vect.elementAt(x);
        v.setElementAt(obj, y);
    }

    public Object getElem(int x, int y){
        Vector v;
        v = (Vector)vect.elementAt(x);
        return v.elementAt(y);
    }
}
