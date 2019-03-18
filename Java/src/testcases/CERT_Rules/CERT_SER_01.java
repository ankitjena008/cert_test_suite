/*
 * @description
 * CERT rules: SER01-J. Do not deviate from the proper signatures of serialization methods
 * Classes that require special handling during object serialization and 
 * deserialization must implement special methods with exactly the following 
 * signatures: 
 * private void writeObject(java.io.ObjectOutputStream out)
    throws IOException;
 * private void readObject(java.io.ObjectInputStream in)
    throws IOException, ClassNotFoundException;
 * private void readObjectNoData()
    throws ObjectStreamException;
 *
 * Serializable classes may also implement the readResolve() and writeReplace() methods. 
 * It is possible to add any access-specifier to the readResolve() and writeReplace() methods. 
 * However, if these methods are declared private, extending classes cannot invoke or override 
 * them. If these methods are declared static, extending classes cannot override these methods; 
 * they can only hide them. 
 * 
 * Noncompliant Code: define public readObject() and writeObject() methods;
 * declare readResolve() and writeReplace() methods as private; declares the 
 * readResolve() and writeReplace() methods as static
 * Compliant Code: declares the readObject() and writeObject() methods private 
 * and nonstatic to limit their accessibility; declare the readResolve() and 
 * writeReplace() methods protected while eliminating the static keyword so 
 * that subclasses can inherit them
 * 
 * Noncompliant and compliant code declared in testcases.CERT_Rules.Student1(Noncompliant), 
 * testcases.CERT_Rules.Student2(Compliant), 
 *
 * */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.io.*;
import java.lang.*;


import testcases.CERT_Rules.Student1;
import testcases.CERT_Rules.Student2;
import testcases.CERT_Rules.SingletonWithSerializable1;
import testcases.CERT_Rules.SingletonWithSerializable2;

public class CERT_SER_01 extends AbstractTestCase {
    /*
     * Noncompliant: define public readObject() and writeObject() methods declares
     * the readResolve() and writeReplace() methods as private/static
     */
    public void bad() throws Throwable {
        bad1();
        bad2();
    }

    private void bad1() throws Throwable {
        Student1 s1 = new Student1("Alice", 10);
        try {
            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("C:\\a.txt"));
            out.writeObject(s1);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void bad2() throws Throwable {
        SingletonWithSerializable1 s = SingletonWithSerializable1.getInstance();
        SingletonWithSerializable1 s1 = null;
        try {
            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("C:\\b.txt"));
            out.writeObject(s);
            out.close();

            ObjectInputStream in = new ObjectInputStream(new FileInputStream("C:\\b.txt"));
            s1 = (SingletonWithSerializable1) in.readObject();

            if(s == s1) {
                System.out.println("equal");
            }
            else {
                System.out.println("not equal");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /*
     * Compliant: declares the readObject() and writeObject() methods private and
     * nonstatic declare the readResolve() and writeReplace() methods protected
     * without static keyword
     */

    public void good() throws Throwable {
        good1();
        good2();
    }

    private void good1() throws Throwable {
        Student2 s2 = new Student2("Alice", 10);
        try {
            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("C:\\a.txt"));
            out.writeObject(s2);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void good2() throws Throwable {
        SingletonWithSerializable2 s = SingletonWithSerializable2.getInstance();
        SingletonWithSerializable2 s2 = null;
        try {
            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("C:\\b.txt"));
            out.writeObject(s);
            out.close();

            ObjectInputStream in = new ObjectInputStream(new FileInputStream("C:\\b.txt"));
            s2 = (SingletonWithSerializable2) in.readObject();

            if(s == s2) {
                System.out.println("equal");
            }
            else {
                System.out.println("not equal");
            }
        } catch (Exception e) {
            e.printStackTrace();
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