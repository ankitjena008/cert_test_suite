package certOBJ;

import java.io.*;
import java.lang.*;

//OBJ_09
public class CompareClassName {
    public static void main(String[] args) {
        certOBJ.CWE486_Compare_Classes_by_Name__Helper helperClassRoot = new certOBJ.CWE486_Compare_Classes_by_Name__Helper();
        certOBJ.HelperClass.CWE486_Compare_Classes_by_Name__Helper helperClass = new certOBJ.HelperClass.CWE486_Compare_Classes_by_Name__Helper();

        if (helperClassRoot.getClass().getSimpleName().equals(helperClass.getClass().getSimpleName())) {
            System.out.println("Classes are the same");
        } else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
            System.out.println("Classes are different");
        }
    }

}