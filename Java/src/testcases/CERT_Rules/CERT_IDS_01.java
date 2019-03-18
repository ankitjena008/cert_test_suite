/*
* @description
* CERT rules: IDS01-J. Normalize strings before validating them
* Applications that accept untrusted input should normalize the 
* input before validating it. Normalization is important because 
* in Unicode, the same string can have many different representations. 
*
* Noncompliant Code: validate the String before performing normalization
* Compliant Code: Normalizes the string before validating it
*
* */

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

public class CERT_IDS_01 extends AbstractTestCase {
    /* Noncomplinat: validate the String before performing normalization */
    public void bad() throws Throwable {
        String data = "\uFE64" + "script" + "\uFE65";

        // Validate
        Pattern pattern = Pattern.compile("[<>]"); // Check for angle brackets
        Matcher matcher = pattern.matcher(data);

        if (matcher.find()) {
            // Found black listed tag
            throw new IllegalStateException();
        } else {
            data = Normalizer.normalize(data, Form.NFKC);
            System.out.printf("output string: %s", data);
        }
    }

    /* Compliant: Normalizes the string before validating it */
    public void good() throws Throwable {
        String data = "\uFE64" + "script" + "\uFE65";

        // Normalize
        data = Normalizer.normalize(data, Form.NFKC);
        // Validate
        Pattern pattern = Pattern.compile("[<>]");
        Matcher matcher = pattern.matcher(data);
        if (matcher.find()) {
            // Found blacklisted tag
            throw new IllegalStateException();
        } else {
            System.out.printf("output string: %s", data);
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
