import java.io.*;
import java.lang.*;
import java.lang.reflect.*;
import java.security.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Cert_Sec {
    //SEC_01
    private void privilegedMethod(final String filename) throws FileNotFoundException {
        try {
            FileInputStream fis = (FileInputStream) AccessController.doPrivileged(new PrivilegedExceptionAction() {
                @Override
                public FileInputStream run() throws FileNotFoundException {
                    return new FileInputStream(filename);
                }
            });
            // Do something with the file and then close it
        } catch (PrivilegedActionException e) {
            // Forward to handler
        } catch(Exception e) {
            // Forward to handler
        }
    }
    
    //SEC_05
    private int i = 3;
    private int j = 4;
    
    @Override
    public String toString() {
        return "Example: i=" + i + ", j=" + j;
    }

    public void zeroI() {
        this.i = 0;
    }
    public void zeroField(String fieldName) {
        try {
            Field f = this.getClass().getDeclaredField(fieldName);
            // Subsequent access to field f passes language access checks
            // because zeroField() could have accessed the field via
            // ordinary field references
            f.setInt(this, 0);
            // Log appropriately or throw sanitized exception; see EXC06-J
        } catch (NoSuchFieldException ex) {
            // Report to handler
        } catch (IllegalAccessException ex) {
            // Report to handler
        }
    }

    public static void main(String[] args) {
        Cert_Sec obj = new Cert_Sec();
        try{
            obj.privilegedMethod(args[0]);
        } catch (FileNotFoundException e) {
            //handle exception here
        }
        System.out.println(obj.toString());
        obj.zeroField(args[1]);
        System.out.println(obj.toString());
    }
}