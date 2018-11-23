package annotation;

import java.util.Arrays;


public class Main {

  public static void main(String[] args) {
    ClassThatMightUseAnnotation classDoesNotUseAnnotation = new ClassDoesNotUseAnnotation();
    ClassThatMightUseAnnotation classUsesAnnotation = new ClassUsesAnnotation();

    Class classDoesNotUseAnnotationClass = classDoesNotUseAnnotation.getClass();
    Class classUsesAnnotationClass = classUsesAnnotation.getClass();

    System.out.println(classDoesNotUseAnnotationClass.getAnnotations().length);
    System.out.println(classUsesAnnotationClass.getAnnotations().length);

    Arrays.stream(classUsesAnnotationClass.getAnnotations()).forEach(annotation -> {
      if (annotation instanceof MyAnnotation) {
        MyAnnotation myAnnotation = (MyAnnotation) annotation;
        System.out.println(myAnnotation.name());
        System.out.println(myAnnotation.value());
      }
    });
  }
}
