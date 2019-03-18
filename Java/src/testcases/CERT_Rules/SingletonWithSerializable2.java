/* CERT_SER01: compliant readResovle() method*/
package testcases.CERT_Rules;

import java.io.*;
import java.lang.*;

public class SingletonWithSerializable2 implements Serializable {
    private static final long serialVersionUID = 3L;
    private SingletonWithSerializable2() {};
    private static final SingletonWithSerializable2 INSTANCE = new SingletonWithSerializable2();
    public static SingletonWithSerializable2 getInstance() {
        return INSTANCE;
    }
    protected Object readResolve() {
        return INSTANCE;
    }
}