/*
 * NEGATIVE TESTING:
 * 3. SymImplementation
 *    1. field name taken OK
 *    2. formal name taken OK
 *    3. local name taken OK
 *    4. identifier not declared OK (FIXED)
 *    5. identifier from superclass not a variable as expected OK
 *    6. not a variable as expected OK
 *    7. illegal static refernce to a field OK
 *    8. class identifier not declared OK
 *    9. identifier not a class as expected OK
 *   10. field type not declared OK
 *   11. local type found but not a class (in main method) OK
 *   12. local type found but not a class (in a block) OK
 *   13. local type not declared OK
 */
 
public class SyncBox extends JoosConstants {
  protected Object boxContents;
  protected Object boxContents; /*3.1*/
  protected Objective tox; /*3.10*/

  public SyncBox() { 
  	super(); 
  	black++;/*3.5*/
  }

  public synchronized Object get()
    { Object contents;
      char contents; /*3.3*/
      contents = doIExist; /*3.4*/
      put = contents; /*3.6*/
      if (contents instanceof Toto)
      	contents = (Toto)contents; /*3.8*/
      contents = new boxContents(); /*3.9*/
      contents = boxContents;
      boxContents = null;
      return contents;
     }
     
  public synchronized boolean put (Object contents,int contents /*3.2*/)
    { if (boxContents != null)
        return false;
      boxContents = contents;
      if (true)
      {
      	indy whoKnows;/*3.13*/
      	boxContents whatIAmDoing;
      	whatIAmDoing = null;/*3.12*/
      }
      
      return true;
    }
   
   
  public static void main(String args[]) {
   boxContents mybox;/*3.11*/
   
  	boxContents = null;/*3.7*/
  } 
}