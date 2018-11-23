public class JavaThrowable {

  public static void main(String[] args) {

    Throwable throwable = new Throwable();

    Exception exception = new Exception();

    RuntimeException runtimeException = new RuntimeException();

    Error error = new Error();

    // ssb: no exception needed
//    throw error;

    // ssb: no exception needed
//    throw runtimeException;

    // ssb: Need try/catch
    // throw exception;

    // ssb: Need try/catch
    // throw throwable;
  }
}
