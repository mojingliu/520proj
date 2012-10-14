
import joos.lib.*;
import java.util.*;

public class QuestionReader {
  protected Vector _questions;
  protected JoosURL _url;
  protected JoosIO io;
  protected boolean valid;
  
  public QuestionReader(String urlString)
  {
    super();
    valid = false;
    _questions = new Vector();
    io = new JoosIO();
    io.print("Accessing question Db at location : " + urlString);
    _url = new JoosURL(null, urlString);
		if (_url.openConnection()) { 
			if (_url.openInputStream()) { 
			  io.println("     ==> Session opened !");
			  valid = true;
			}
			else
			{
  			io.println("     ==> Session error ... could not access InputStream");
			}
	  }
	  else
	  {
	    io.println("     ==> Session error ... could not open connection");
	  }
  }
  
  public boolean isValid()
  {
    return valid;
  }
  public Vector getQuestions()
  {
    return _questions;
  }
  public void terminate()
  {
    if(valid) {
      _url.closeInputStream();
    }
  }
  
  public void showErrors()
  {
    if(valid) return;
		if (_url.getErrorLog() != null) { 
		
			io.println("***** Errors in this session were: ");
			io.println(_url.getErrorLog());
		}
  }
  
  public void readAllQuestions()
  {
    String inputLine;
		String question, answer;
		Integer numQuestions, qType;
		int i;
		
		io.print("Reading questions ...");
		
		inputLine = _url.readLine();
		i=0;
		
		while (inputLine != null) {
		  io.print(".");
			
			qType = new Integer(inputLine);
			
			// regular question
			if (qType.intValue() == 1) {

				question = _url.readLine();	
				answer = _url.readLine();
				_questions.addElement(new SimpleQuestion(question,answer));
			} else if (qType.intValue() == 2) {
				Vector choices;
				choices = new Vector();
				
				question = _url.readLine();
				
				/* Read 4 choices ... */
				choices.addElement(_url.readLine());
				choices.addElement(_url.readLine());
				choices.addElement(_url.readLine());
				choices.addElement(_url.readLine());

				answer = _url.readLine();
			  _questions.addElement(new MCQuestion(question,answer,choices));
			}
		  inputLine = _url.readLine();
			i = i+1;
		}
		io.println(" => Found " + i + " questions.");
  }
}
