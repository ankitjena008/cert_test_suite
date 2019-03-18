/*
* @description
* CERT rules: MET00-J. Validate method arguments
* Validate method arguments to ensure that they fall within the bounds of 
* the method's intended design.
* 
* Noncompliant Code: fail to validate arguments.
* Compliant Code: validate method arguments and verify the internal state before use
* */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.util.logging.Level;
import java.io.*;
import java.sql.*;
import java.lang.*;

public class CERT_MET_00 extends AbstractTestCase {
    private String myState = null;

    /* Noncompliant: fail to validate arguments */
    private void setState1(String state) {
        myState = state;
    }

    private void useState1() {
        int num = Integer.parseUnsignedInt(myState);
        System.out.println(num);
    }

    /* Compliant: validate method arguments and verfiy internal state before use */
    private void setState2(String state) {
        if (state == null) {
            // Handle null state
            System.out.println("Invalid State");
        } else {
            myState = state;
        }
    }

    private void useState2() {
        if (myState == null) {
            // Handle null state
            System.out.println("Invalid State");
        } else {
            try {
                // Handle invalid state
                int num = Integer.parseUnsignedInt(myState);
                System.out.println(num);
            } catch (NumberFormatException e) {
                System.out.println("Invalid State: should be integer");
            } catch (Exception e) {
                System.out.println("Exception occurred");
            }
        }
    }

    public void bad() throws Throwable {
        String s1 = null;
        setState1(s1);
        useState1();
        String s2 = "badsink";
        setState2(s2);
        useState1();
    }

    public void good() throws Throwable {
        goodB2G();
        goodG2G();
    }

    private void goodB2G() throws Throwable {
        String s1 = null;
        setState1(s1);
        useState2();
        String s2 = "goodsink";
        setState2(s2);
        useState2();
    }

    private void goodG2G() throws Throwable {
        String s = "12";
        setState2(s);
        useState2();
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