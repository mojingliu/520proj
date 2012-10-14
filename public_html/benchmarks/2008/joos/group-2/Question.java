
import joos.lib.*;
import java.util.*;

/* 
 * Basic class used for question handling
 */
public abstract class Question {
  protected String _question;
  protected String _answer;
  
  public Question(String question, String answer)
  {
    super();
    _question = question;
    _answer = answer;
  }
  
  public String getRealQuestion()
  {
    return _question;
  }

  public String getAnswer()
  {
    return _answer;
  }
  
  public abstract void showQuestion();
}
