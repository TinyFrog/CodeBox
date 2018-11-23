package com.manning.gia.todo.model;

public class ToDoItem implements Comparable<ToDoItem> {

  private Long id;
  private String name;
  private boolean completed;

  @Override
  public int compareTo(ToDoItem o) {
    return 0;
  }

  public Long getId() {
    return id;
  }

  public void setId(Long id) {
    this.id = id;
  }
}
