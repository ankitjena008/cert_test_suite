/*
* @description
* CERT rules: OBJ05-J. Do not return references to private mutable class members
* Returning references to internal mutable members of a class can compromise an 
* application's security, both by breaking encapsulation and by providing the 
* opportunity to corrupt the internal state of the class. Programs must not 
* return references to private mutable classes.
* 
* Noncompliant Code: Return the sole instance of the private object
* Compliant Code: Return a reference to a defensive copy of a mutable internal state
*
* Noncompliant and compliant methods declared in testcases.CERT_Rules.MutableClass
*
* */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.io.*;
import java.lang.*;
import java.util.Date;
import testcases.CERT_Rules.MutableClass;


public class CERT_OBJ_05 extends AbstractTestCase {
    /* Noncompliant: Return the sole instance of the private object */
    public void bad() throws Throwable {
        bad1();
        bad2();
    }

    private void bad1() throws Throwable {
        MutableClass M = new MutableClass();
        Date curr = M.getDate1();
        System.out.println("Current date is " + curr);
    }

    private void bad2() throws Throwable {
        MutableClass M = new MutableClass();
        Date[] currs = M.getArr1();
        for(int i = 0;i < currs.length; i++) {
            System.out.println(i + ":" + currs[i]);
        }
    }

    /* Compliant: Return a reference to a defensive copy of a mutable internal state */
    public void good() throws Throwable {
        good1();
        good2();
    }

    private void good1() throws Throwable {
        MutableClass M = new MutableClass();
        Date curr = M.getDate2();
        System.out.println("Current date is " + curr);
    }

    private void good2() throws Throwable {
        MutableClass M = new MutableClass();
        Date[] currs = M.getArr2();
        for(int i = 0;i < currs.length; i++) {
            System.out.println(i + ":" + currs[i]);
        }
    }

    /*
     * Below is the main(). It is only used when building this testcase on its own
     * for testing or for building a binary to use in testing binary analysis tools.
     * It is not used when compiling all the testcases as one application, which is
     * how source code analysis tools are tested.
     */
    public static void main(String[] args)
            throws ClassNotFoundException, InstantiationException, IllegalAccessException {
        mainFromParent(args);
    }
}
