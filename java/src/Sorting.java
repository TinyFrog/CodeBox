import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Sorting {

  public static void main(String[] args) {
    int[] i = new int[]{1, 2, 4, 3};

//    Arrays.sort(i);
    List l = Arrays.asList(i);
//    Collections.sort(l, (a, b) -> {return a,b;});

    System.out.println(l);
    mapSortByValue();
  }

  private static void mapSortByValue() {
    Map<Integer, Integer> m = new HashMap<>();
    String s = "";
    m.put(3, 8);
    m.put(2, 2);
    m.put(4, 5);

    Map<Integer, Integer> sortedMapDescending = m.entrySet().stream().sorted(Map.Entry.comparingByValue(Comparator.reverseOrder())).limit(1).collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    List<Integer> sortedMapAscending = m.entrySet().stream().sorted(Map.Entry.comparingByValue()).limit(1).map(e -> e.getKey()).collect(Collectors.toList());
    System.out.println(sortedMapAscending);
    System.out.println(sortedMapDescending);
    for (int i = 0; i<3; ) {
      System.out.println(i);
    }
  }

  private static void twoDimensionsArraySort() {
    int[][] j = new int[][]{
      {2, 3},
      {5, 0},
      {8, 0},
      {2, 0},
      {4, 1}
    };

    Arrays.sort(j, (a, b) -> {
      int compare = Integer.compare(a[1], b[1]);

      if (compare == 0) {
        return Integer.compare(a[0], b[0]);
      }

      return compare;
    });

    int l1 = 3;

    System.out.println(j.length);
    System.out.println(j[0].length);
    System.out.println();
  }
}
