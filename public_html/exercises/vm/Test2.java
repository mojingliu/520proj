class A {
  int m(Object x, Object y) {
    return 1;
  }
  int m(Object x, String y) {
    return 4;
  }
}
class B extends A {
  int m(Object x, String y) {
    return 2;
  }
}
class C extends B {
  int m(Object x, Object y) {
    return 3;
  }
}
public class Test2 {
  public static void main(String[] args) {
    A a = new C();
    System.out.println(a.m(null,"abc"));
  }
}