interface foo {
  void hey(String message);
}

interface bar {
  void hey(String message);

  void hey(String message, String additionalMessage);
}


public class MultipleInterface implements foo, bar {
  @Override
  public void hey(String message) {
    System.out.println(message);
  }

  @Override
  public void hey(String message, String additionalMessage) {

  }
}
