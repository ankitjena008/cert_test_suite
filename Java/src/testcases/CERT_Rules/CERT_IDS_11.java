/*
* @description
* CERT rules: IDS11-J. Perform any string modifications before validation
* Any string modifications must be performed before the string is validated.
*
* Noncompliant Code: validate input before the removal of any noncharacter code points
* Compliant Code: 
*
*/

package testcases.CERT_Rules;

import testcasesupport.*;

import java.util.logging.Level;
import java.io.*;
import java.sql.*;
import java.lang.*;

import java.text.Normalizer;
import java.text.Normalizer.Form;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CERT_IDS_11 extends AbstractTestCase {
    /* Nocompliant: validate input before removing noncharacter code points */
    public void bad() throws Throwable {
        String maliciousInput = "<scr" + "\uFDEF" + "ipt>";
        String s = Normalizer.normalize(maliciousInput, Form.NFKC);

        // Validate input
        Pattern pattern = Pattern.compile("<script>");
        Matcher matcher = pattern.matcher(s);
        if (matcher.find()) {
            throw new IllegalArgumentException("Invalid input");
        }

        // Deletes noncharacter code points
        s = s.replaceAll("[\\p{Cn}]", "");
        System.out.printf("output string: %s", s);
    }

    /* Compliant: replaces unknown character before other sanitization */
    public void good() throws Throwable {
        String maliciousInput = "<scr" + "\uFDEF" + "ipt>";
        String s = Normalizer.normalize(maliciousInput, Form.NFKC);
        // Replaces all noncharacter code points with Unicode U+FFFD
        s = s.replaceAll("[\\p{Cn}]", "\uFFFD");

        // Validate input
        Pattern pattern = Pattern.compile("<script>");
        Matcher matcher = pattern.matcher(s);
        if (matcher.find()) {
            throw new IllegalArgumentException("Invalid input");
        }
        System.out.printf("output string: %s", s);
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