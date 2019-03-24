package certJNI;

import java.security.*;

// Untrusted.java

public class Untrusted {

   private native void nativeOperation();

   public static void main(String[] args) {
      String library = new String("NativeMethodLib");
      Trusted.loadLibrary(library);
      Untrusted obj = new Untrusted();
      obj.nativeOperation(); // invoke the native method
   }
}