import joos.lib.*;

public class IFSnakeGame
{
    public IFSnakeGame()
        {super();}

    public static void main(String [] args)
    {
        JoosIO sc;
        SnakeHead snake;
        int roomw;
        int roomh;
        Apple apple;
        String cmd;
        boolean printinfo;
        boolean cheat;

        printinfo = true;
        cheat = false;
        sc = new JoosIO();
        sc.println("You are a snake, and you are hungry for apples.");
        roomw = 8;
        roomh = 8;
        snake = new SnakeHead(0, roomh/2);
        apple = new Apple(roomw, roomh, 1);
        while(true)
        {
            if(printinfo)
            {
                sc.println(snake.printInfo(roomw, roomh, apple));
                if(cheat)
                    sc.println(snake.printBoard(roomw, roomh, apple));
            }
            printinfo = true;
            cmd = sc.readLine();
            if(cmd.equalsIgnoreCase("length"))
                sc.println("You are " + snake.getLength() + " feet long.");
            else if(cmd.equalsIgnoreCase("forward"))
            {
                if(snake.move(apple))
                {
                    sc.println("Mmm! You eat the apple.");
                    sc.println("You feel yourself growing longer.");
                    apple.randomize(roomw, roomh);
                }
                else
                    sc.println("You slither forward.");
            }
            else if(cmd.equalsIgnoreCase("left"))
            {
                snake.turnLeft();
                if(snake.move(apple))
                {
                    sc.println("Mmm! There was an apple to your left!");
                    sc.println("You feel yourself growing longer.");
                    apple.randomize(roomw, roomh);
                }
                else
                    sc.println("You turn to your left and slither forward a bit.");
            }
            else if(cmd.equalsIgnoreCase("right"))
            {
                snake.turnRight();
                if(snake.move(apple))
                {
                    sc.println("Mmm! There was an apple to your right!");
                    sc.println("You feel yourself growing longer.");
                    apple.randomize(roomw, roomh);
                }
                else
                    sc.println("You turn to your right and slither forward a bit.");
            }
            else if(cmd.equalsIgnoreCase("cheat"))
            {
                cheat = !cheat;
            }
            else if(cmd.equalsIgnoreCase("quit"))
            {
                sc.println("Goodbye.");
                return;
            }
            else if(cmd.equalsIgnoreCase("help"))
            {
                sc.println("You may choose to go 'forward', 'left', or 'right'.\nAlternatively, you may opt to 'quit' or 'cheat'.");
                printinfo = false;
            }
            else
            {
                sc.println("I don't know that command.");
                printinfo = false;
            }
            if(snake.getX() < 0 || snake.getX() >= roomw || snake.getY() < 0 || snake.getY() >= roomh)
            {
                sc.println("Ouch! You ran headfirst into a wall and died.");
                sc.println("You were " + snake.getLength() + " feet long when you died.");
                return;
            }
            if(snake.bitYourself())
            {
                sc.println("Ouch! You bit your own tail!");
                sc.println("The poison quickly sets in and you die.");
                sc.println("You were " + snake.getLength() + " feet long when you died.");
                return;
            }
        }
    }
}
