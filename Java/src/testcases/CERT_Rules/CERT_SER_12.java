/*
 * @description
 * CERT rules: SER12-J. Prevent deserialization of untrusted data
 * Deserializing untrusted data can cause Java to create an object of an arbitrary 
 * attacker-specified class, provided that the class is available on the classpath 
 * specified for the JVM. 
 * 
 * NonCompliant Code: deserialize a byte array without first validating what classes 
 * will be created, if the object being deserialized belongs to a class with a lax 
 * readObject() method, this could result in remote code execution.
 * 
 * */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.io.*;
import java.lang.*;

public class CERT_SER_12 extends AbstractTestCase {
    public static Object deserialize(byte[] buffer) throws IOException, ClassNotFoundException {
        Object ret = null;
        try (ByteArrayInputStream bais = new ByteArrayInputStream(buffer)) {
            try (ObjectInputStream ois = new ObjectInputStream(bais)) {
                ret = ois.readObject();
            }
        }
        return ret;
    }
    /*
     * Noncompliant: deserialize byte array without validating what classes will be
     * created
     */
    public void bad() throws Throwable {
        RandomAccessFile f = new RandomAccessFile("C:\\file.txt", "r");
        byte[] b = new byte[(int) f.length()];
        f.readFully(b);
        Object r = deserialize(b);
    }

    public void good() throws Throwable {
        
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