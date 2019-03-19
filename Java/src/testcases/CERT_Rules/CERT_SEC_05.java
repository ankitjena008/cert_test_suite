/* 
 * @description
 * CERT rules; SEC05-J. Do not use reflection to increase accessibility of 
 * classes, methods, or fields
 * 
 * */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.io.*;
import java.lang.*;
import java.lang.reflect.*;
import java.security.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class CERT_SEC_05 extends AbstractTestCase {
    /*
     * Noncompliant: Allowing hostile code to pass arbitrary field names to the
     * zeroField() method which might leak by throwing an exception for invalid or
     * inaccessible field namesnformation about field names. Attacker can access and
     * modify private fields by zeroField() since it defined as public
     */
    private int i = 3;
    private int j = 4;

    public String toString() {
        return "Example: i=" + i + ", j=" + j;
    }

    public void zeroI() {
        this.i = 0;
    }

    public void zeroField(String fieldName) {
        try {
            Field f = this.getClass().getDeclaredField(fieldName);
            // Subsequent access to field f passes language access checks
            // because zeroField() could have accessed the field via
            // ordinary field references
            f.setInt(this, 0);
            // Log appropriately or throw sanitized exception; see EXC06-J
        } catch (NoSuchFieldException ex) {
            // Report to handler
        } catch (IllegalAccessException ex) {
            // Report to handler
        }
    }

    public void bad() throws Throwable {
        CERT_SEC_05 fe = new CERT_SEC_05();
        System.out.println(fe.toString());
        String fn = new String(Files.readAllBytes(Paths.get("readMe.txt")), "UTF-8");
        fe.zeroField(fn);
        System.out.println(fe.toString());
    }

    public void good() throws Throwable {
        //change zeroField() from public to private or just nonreflection
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