import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Stream;

public class JavaMap {

  public static void main(String[] args) {
    Map<Integer, Integer> m = new HashMap<>();
    m.put(2, 3);
    m.put(5, 3);
    // Set<Key>
    m.keySet();
    // Set<Entry<Key, Value>>
    m.entrySet();
    // Collection<Value>, have duplicates
    Collection<Integer> values = m.values();

    System.out.println(values);

    Stream<Integer> s = m.keySet().stream();
  }
}
