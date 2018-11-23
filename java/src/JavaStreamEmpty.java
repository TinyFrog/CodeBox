import java.util.stream.Stream;


public class JavaStreamEmpty {

  public static void main(String[] args) {
    Stream<String> foo = Stream.empty();

    foo.forEach(bar -> {
      System.out.println("yeah yeah");
      System.out.println(bar);
    });
  }
}
