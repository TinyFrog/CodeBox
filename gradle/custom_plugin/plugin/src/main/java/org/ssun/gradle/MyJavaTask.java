package org.ssun.gradle;

import org.gradle.api.DefaultTask;
import org.gradle.api.file.FileTree;
import org.gradle.api.tasks.TaskAction;
import org.gradle.api.

import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Formatter;
import java.util.regex.Pattern;

public class MyJavaTask extends DefaultTask {
    @TaskAction
    public void howdy() {
        System.out.println("Howdy from java task");
    }


    // Reference: http://groovy.codehaus.org/Calculating+a+SHA1+hash+for+large+files
    private String calculate_sha1(String fileContent) {
        String sha1 = "";
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("SHA1");
            messageDigest.update(fileContent.getBytes("UTF-8"));
            sha1 = byteToHex(messageDigest.digest());
        } catch (NoSuchAlgorithmException noSuchAlgorithmException) {
            noSuchAlgorithmException.printStackTrace();
        } catch (UnsupportedEncodingException unsupportedEncodingException) {
            unsupportedEncodingException.printStackTrace();
        }

        return sha1;
    }


    private static String byteToHex(final byte[] hash)
    {
        Formatter formatter = new Formatter();
        for (byte b : hash)
        {
            formatter.format("%02x", b);
        }
        String result = formatter.toString();
        formatter.close();
        return result;
    }

    private FileTree unzip(File file) {
        // it will be unzipped into ./build/tmp/expandedArchives/
        FileTree fileTree = zipTree("$file").matching {
            // TODO: why this cannot filter subdir?
            include '**.class'
        }
        return fileTree;
    }


    /*
    private void visit_jar(FileTree fileTree, Map results) {
        fileTree.visit { visitor ->
                // getFile() will give the absolute path of the file
                String filePath = visitor.getFile();
            File theFile = file(filePath);

            if (theFile.isFile()) {
                String sha = calculate_sha1(theFile);
                if (!results[sha]) {
                    results[sha] = [];
                }
                // TODO: might be useful to add path of original jar here
                results[sha].add(filePath);
            }
        }
    }


    private void print_summary(Map results) {
        results.each { String key, List fileList ->
            // only interested when it has more than one class included
            if (fileList.size() > 1) {
                println key;
                fileList.each { println it }
                println "";
            }
        }
    }*/
}

