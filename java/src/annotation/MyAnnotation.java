package annotation;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;


// @Retention(RetentionPolicy.RUNTIME) means that the annotation can be accessed via reflection at runtime. If you do not set this directive, the annotation will not be preserved at runtime, and thus not available via reflection.
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.TYPE)

public @interface MyAnnotation {
  public String name();

  public String value();
}
