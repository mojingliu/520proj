
import joos.lib.*;
import java.util.*;

public class SimpleQuestion extends Question{
  
  public SimpleQuestion(String question, String answer)
  {
    super(question, answer);
  }
  
  public void showQuestion()
  {
    new JoosIO().println(this.getRealQuestion());
  }
}
