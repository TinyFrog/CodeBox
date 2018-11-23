import java.util.HashMap;
import java.util.Map;


public class JavaUtilMap {

  public static void main(String[] args) {
    Map<String, String> map = new HashMap<>();
    map.put("foo", "bar");

    String value = map.remove("foo");
    String valueDoesNotExist = map.remove("keyDoesNotExist");
    System.out.println(value);
    System.out.println(valueDoesNotExist);
    System.out.println(map);
  }
}
