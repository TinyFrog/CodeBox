import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;


public class JavaStreamFilter {

  public static void main(String[] args) {

    List<String> list = new ArrayList<>();
    list.add("123");
    list.add("456");

    list.stream().filter(entity -> {
      System.out.println("first filter");
      System.out.println(entity);
      return true;
    }).filter(entity -> {
      System.out.println("second filter");
      System.out.println(entity);
      return true;
    }).collect(Collectors.toList());
  }
}
