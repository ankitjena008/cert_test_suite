import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws Throwable{
        String password;
        password = "";
        Cipher aesCipher = Cipher.getInstance("AES");
        SecretKeySpec secretKeySpec = new SecretKeySpec("ABCDEFGHABCDEFGH".getBytes("UTF-8"), "AES");
        aesCipher.init(Cipher.DECRYPT_MODE, secretKeySpec);
        password = new String(aesCipher.doFinal(password.getBytes("UTF-8")), "UTF-8");
        System.out.println(password);
    }
}