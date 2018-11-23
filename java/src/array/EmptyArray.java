package array;

import java.util.ArrayList;
import java.util.List;


public class EmptyArray {

  public static void emptyArray() {

    List<String> abstractClassList = new ArrayList<>();
    abstractClassList.add("");
    abstractClassList.add("123");

    String[] array = abstractClassList.toArray(new String[abstractClassList.size()]);
  }

  public static void main(String[] args) {
    emptyArray();
  }
}
