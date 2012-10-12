import joos.lib.*;
import java.lang.*;

public class Knapsack {
  public Knapsack() {
    super();
  }
  public static void main(String[] args) {
    JoosIO io;
    SolveKnapsack solver;
    solver = new SolveKnapsack();
    io = new JoosIO();
    if (solver.readInput(io)) {
      solver.getSolution();
    }
  }
}
