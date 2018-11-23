package multithreading;

public class SequentialThreads {

  public static void main(String[] args) throws InterruptedException {
    Thread thread1 = new Thread(() -> System.out.println("1"));
    Thread thread2 = new Thread(() -> System.out.println("2"));

    thread2.start();
    System.out.println("print");

    thread2.join();
    thread1.start();
    thread1.join();
  }
}
