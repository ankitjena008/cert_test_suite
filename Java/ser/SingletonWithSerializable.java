/* CERT_SER01: noncompliant readResovle() method*/
package certSER;

import java.io.*;
import java.lang.*;

public class SingletonWithSerializable implements Serializable {
    private static final long serialVersionUID = 2L;
    private SingletonWithSerializable() {};
    private static final SingletonWithSerializable  INSTANCE = new SingletonWithSerializable();
    public static SingletonWithSerializable getInstance() {
        return INSTANCE;
    }
    private Object readResolve() {
        return INSTANCE;
    }
}