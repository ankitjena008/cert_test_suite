/*
 * @description
 * CERT rules: FIO08-J. Distinguish between characters or bytes read from a stream and -1
 * InputStream.read() and Reader.read() methods are used to read a byte 
 * or character, respectively, from a stream. Both methods return the 32-bit 
 * value -1 (0xffffffff) to indicate that the end of the stream has been reached 
 * and no data is available. Prematurely converting the resulting int to a byte or
 * char before testing for the value −1 makes it impossible to distinguish between 
 * characters read and the end of stream indicator. Programs must check for the end 
 * of stream before narrowing the return value to a byte or char.

 * Noncompliant Code: cast the value returned by the read() method directly to a 
 * value of type byte or char and then compares this value with −1 in an attempt 
 * to detect the end of the stream.
 * Compliant Code: use a variable of type int to capture the return value of the 
 * byte and char input method
 * 
 * */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.io.*;
import java.lang.*;

public class CERT_FIO_08 extends AbstractTestCase {
    /*
     * Noncompliant: cast return value of read() to byte or char before compare with
     * -1
     */
    public void bad() throws Throwable {
        bad1();
        bad2();
    }

    private void bad1() throws Throwable {
        try {
            FileInputStream in = new FileInputStream("C:\\file.txt");
            byte data;
            while ((data = (byte) in.read()) != -1) {
                System.out.print(data);  
            }
            in.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    private void bad2() throws Throwable {
        try {
            FileInputStream in = new FileInputStream("C:\\file.txt");
            char data;
            while ((data = (char) in.read()) != -1) {
                System.out.print(data);  
            }
            in.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public void good() throws Throwable {
        good1();
        good2();
    }

    private void good1() throws Throwable {
        try {
            FileInputStream in = new FileInputStream("C:\\file.txt");
            int inbuff;
            byte data;
            while ((inbuff = in.read()) != -1) {
                data = (byte) inbuff;
                System.out.print(data);  
            }
            in.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    private void good2() throws Throwable {
        try {
            FileInputStream in = new FileInputStream("C:\\file.txt");
            int inbuff;
            char data;
            while ((inbuff = in.read()) != -1) {
                data = (char) inbuff;
                System.out.print(data);  
            }
            in.close();
        } catch (Exception e) {
            System.out.println(e);
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