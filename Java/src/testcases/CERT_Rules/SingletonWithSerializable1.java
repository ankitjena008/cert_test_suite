/* CERT_SER01: noncompliant readResovle() method*/
package testcases.CERT_Rules;

import java.io.*;
import java.lang.*;

public class SingletonWithSerializable1 implements Serializable {
    private static final long serialVersionUID = 2L;
    private SingletonWithSerializable1() {};
    private static final SingletonWithSerializable1 INSTANCE = new SingletonWithSerializable1();
    public static SingletonWithSerializable1 getInstance() {
        return INSTANCE;
    }
    private Object readResolve() {
        return INSTANCE;
    }
}