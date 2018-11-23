import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;


public class Main {

  static String[] no;

  static Integer foo;

  public static class Result {
  }

  public static List<Result> getList(List<Result> input) {
    return input;
  }

  public static void varargs(String... foo) {
    System.out.println(foo);
  }

  public static boolean isPalindrome(int x) {
    List<Integer> l = new ArrayList<>();

    int y = x;
    while (y != 0) {
      int remainder = y % 10;
      l.add(remainder);

      y = y / 10;
    }

    int i = 0;
    int j = l.size() - 1;
    while (i<j) {
      if (l.get(i) != l.get(j)) {
        return false;
      }

      i++;
      j--;

    }

    return true;

  }

  public static void main(String[] args) {
    int a = -2147447412;
    System.out.println(Integer.MIN_VALUE);
    System.out.println(isPalindrome(-2147447412));

  }



  private static void foo() {

    try {
      bar();
    } catch(NullPointerException e) {
      System.out.println("NPE!!");
    }
  }

  private static void bar() throws NullPointerException{
//    throw new NullPointerException();
  }

  private static void groupBy() {
    //3 apple, 2 banana, others 1
    List<String> items =
        Arrays.asList("apple", "apple", "banana",
            "apple", "orange", "banana", "papaya");

    Map<String, Long> result =
        items.stream().collect(
            Collectors.groupingBy(
                Function.identity(), Collectors.counting()
            )
        );

    System.out.println(result);

  }
}
