import joos.lib.*;
import java.util.*;
/**
 * A simple quiz application
 * reads in a database of questions that is 
 * stored online
 */
public class Quiz {

	public Quiz() { super(); }

	public static void main(String argv[]) { 
    QuestionReader reader;
    String urlString;
    JoosIO io;
    int rightAnswers, wrongAnswers;
    
    io = new JoosIO();
    rightAnswers = wrongAnswers = 0;

		io.println("Welcome to the quiz application!");

		io.println("Enter url for database: ");
		urlString = io.readLine();
    reader = new QuestionReader(urlString);
    
    if(reader.isValid()){
      Vector questions;
      int i;
      
      reader.readAllQuestions();
      
      questions = reader.getQuestions();
      for(i=0;i<questions.size();i++){
        Question currentQuestion;
        String userAnswer;
        
        currentQuestion = (Question)questions.elementAt(i);
        io.println("Question #" + (i+1) + "\n----------------");
        currentQuestion.showQuestion();
        
				io.print("\nYour answer is ?? ");
				userAnswer = io.readLine();
				
				if (userAnswer.equals(currentQuestion.getAnswer())) {
					io.println ("Right on!\n\n");
					rightAnswers++;
				} else {
					io.println ("Wrong :(\n\n");
					wrongAnswers++;
				}
      }
      
      io.println("***************** ");
      io.println("* Number of questions: " + (rightAnswers + wrongAnswers));
      io.println("* Right answers: " + rightAnswers);
      io.println("* Wrong answers: " + wrongAnswers);
      io.println("*****************");
    }
    else
    {
      reader.showErrors();
    }
    
    reader.terminate();    
	}
}

