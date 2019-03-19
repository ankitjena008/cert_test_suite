/*
 * @description
 * CERT rules: SEC01-J. Do not allow tainted variables in privileged blocks
 * Do not operate on unvalidated or untrusted data in a privileged block. 
 * 
 * Noncompliant Code: accept a tainted path or file name as an argument 
 * of privilegedMethod
 * Compliant Code: hard codes the name of the file and declares the variable 
 * as static final to prevent it from being modified.
 * 
 * */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.io.*;
import java.lang.*;
import java.security.*;

public class CERT_SEC_01 extends AbstractTestCase {
    /*
     * Noncompliant: accept a tainted path or file name as an argument of
     * privilegedMethod
     */
    private void privilegedMethod1(final String filename) throws FileNotFoundException {
        try {
            FileInputStream fis = (FileInputStream) AccessController.doPrivileged(new PrivilegedExceptionAction() {
                public FileInputStream run() throws FileNotFoundException {
                    return new FileInputStream(filename);
                }
            });
            // Do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // Forward to handler
        }
    }

    /* Compliant: hard codes the name of the file */
    static final String FILEPATH = "C:\\protected.bat";

    private void privilegedMethod2() throws FileNotFoundException {
        try {
            FileInputStream fis = (FileInputStream) AccessController.doPrivileged(new PrivilegedExceptionAction() {
                public FileInputStream run() throws FileNotFoundException {
                    return new FileInputStream(FILEPATH);
                }
            });
            // Do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // Forward to handler and log
        }
    }

    public void bad() throws Throwable {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String name = reader.readLine(); 
        privilegedMethod1(name);
    }

    public void good() throws Throwable {
        privilegedMethod2();
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