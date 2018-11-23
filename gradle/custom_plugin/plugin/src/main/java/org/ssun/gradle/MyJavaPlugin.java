package org.ssun.gradle;

import org.gradle.api.Project;
import org.gradle.api.Plugin;

public class MyJavaPlugin implements Plugin<Project> {
    @Override
    public void apply(Project project) {
        project.task("howdy");
    }
}
