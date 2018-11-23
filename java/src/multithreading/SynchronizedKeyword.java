package multithreading;

public class SynchronizedKeyword {

  static class SynchronizedBlock {
    public void add() {
      synchronized (this) {

        System.out.println("Feels good");
      }
    }
  }

  public static void main(String[] args) {
new SynchronizedBlock().add();
  }
}
