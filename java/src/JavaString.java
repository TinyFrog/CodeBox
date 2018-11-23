import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class JavaString {
  public static void main(String[] args) {
    String input = "How the dare you";
    String[] splits = input.split(" ");

    System.out.println(splits[1].length());

    StringBuilder stringBuilder = new StringBuilder(input);
    stringBuilder.setCharAt(4, 'F');
    System.out.println(stringBuilder.toString());

    List<char[]> chars = Arrays.asList(input.toCharArray());
    Set<Character> set = new HashSet(chars);
    System.out.println(set);
  }
}
