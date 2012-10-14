/*
 * NEGATIVE TESTING
 * 2. SymInterfaceTypes
 *    1. no such parent class OK
 *    2. type identifier not declared for formal OK
 *    3. type identifier not declared for rettype OK
 */

public class Cons extends Objects /*2.1*/ {
  // Fields 
  protected Object first;
  protected Cons rest;
 
  // Constructor 
  public Cons(Object f, Conse r/*2.2*/)
    { super();
      first = f;
      rest = r; 
    }

  // Methods 
  public void setFirst(Object newfirst)
    { first = newfirst; }

  public boolean member(Object item) 
    { if (first.equals(item))
        return(true);
      else if (rest == null)
        return(false);
      else
        return(rest.member(item));
    }

  public String toString()
    { if (rest == null) 
        return(first.toString());
      else
        return(first + " " + rest);
    }
    
  	public void myfunc(Rage/*2.2*/ y) { ;	}
  	public first/*2.3*/ myfunc2() { return null; }
}