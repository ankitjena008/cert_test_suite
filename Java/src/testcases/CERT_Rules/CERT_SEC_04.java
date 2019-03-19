/* 
 * @description
 * CERT rules: SEC04-J. Protect sensitive operations with security manager checks
 * Sensitive operations must be protected by security manager checks.
 * 
 * Noncompliant Code: no security manager checks for sensitive operation
 * Compliant Code: install security checks to protect sensitive operation
 * 
 * */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.io.*;
import java.lang.*;
import java.security.*;
import java.util.Hashtable;

public class CERT_SEC_04 extends AbstractTestCase {
    private Hashtable<Integer, String> ht = new Hashtable<Integer, String>();
    
    public void addEntry(Integer key, String s) {
        ht.put(key, s);
    }
    public void removeEntry(Object key) {
        if(ht.containsKey(key)) {
            ht.remove(key);
        }
    }

    private void check(String directive) {
        SecurityManager sm = System.getSecurityManager();
        if (sm != null) {
            sm.checkSecurityAccess(directive);
        }
    }
    /* Noncompliant: no security manager checks for sensitive operation */
    public void bad() throws Throwable {
        addEntry(0, "bad");
        removeEntry(0);
    }
    /* Compliant: install security checks */
    public void good() throws Throwable {
        check("addKeyPermission");
        addEntry(1, "good");
        check("removeKeyPermission");
        removeEntry(1);
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
