import java.util.Optional;


public class JavaFunctionalInterfaceImpl implements JavaFunctionalInterface {
  @Override
  public String doSomething(String bar) {
    return null;
  }

  public static void main(String[] args) {
    JavaFunctionalInterface javaFunctionalInterface = new JavaFunctionalInterfaceImpl();
    String value = "";
    Optional<String> optional = Optional.ofNullable(value);

    optional.map(javaFunctionalInterface::doSomething);
  }
}
