import java.util.Objects;


public class ObjectsEqual {

  public static void main(String[] args) {
    String foo = "123";
    String bar = new String("123");

    // true: value comparison
    System.out.println(foo.equals(bar));

    // true: object comparison + value comparison
    System.out.println(Objects.equals(foo, bar));

    // false: object comparison
    System.out.println(foo == bar);
  }
}
