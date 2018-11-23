import java.util.TreeMap;

class Dog implements Comparable {
  String color;
  int size;
  Dog(String c) {
    color = c;
  }
  public String toString(){
    return color + " dog";
  }
  @Override
  public int compareTo(Object o) {
    return 1;
  }
}

public class JavaTreeMap {
  public static void main(String[] args) {
    Dog d1 = new Dog("red");
    Dog d2 = new Dog("black");
    D2.
    Dog d3 = new Dog("white");
    Dog d4 = new Dog("white");
    TreeMap treeMap = new TreeMap();
    treeMap.put(d1, 10);
    treeMap.put(d2, 15);
    treeMap.put(d3, 5);
    treeMap.put(d4, 20);
    treeMap.forEach((key, value) -> System.out.println(key + " - " + value));
  }
}