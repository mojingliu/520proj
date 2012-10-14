
import joos.lib.*;
import java.util.*;

public class MCQuestion extends Question{
  protected Vector _choices;
  public MCQuestion(String question, String answer, Vector choices)
  {
    super(question, answer);
    _choices = choices;
  }
  
  public void showQuestion()
  {
    JoosIO io;
    int index;
    io = new JoosIO();
    io.println(this.getRealQuestion());
    
    for(index = 0; index < _choices.size(); index++)
    {
      String currentChoice;
      currentChoice = (String)_choices.elementAt(index);
      io.println((char)('a' + index) + ") " + currentChoice);
    }
  }
}
