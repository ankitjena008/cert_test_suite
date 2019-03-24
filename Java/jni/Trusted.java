package certJNI;

import java.security.*;

// Trusted.java
public class Trusted {
    public static void loadLibrary(final String library) {
        AccessController.doPrivileged(new PrivilegedAction<Void>() {
            @Override
            public Void run() {
                System.loadLibrary(library);
                return null;
            }
        });
    }
}