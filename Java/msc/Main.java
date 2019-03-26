import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws Throwable{
        //MSC_03: CWE-321: Use of Hard-coded Cryptographic Key
        String password;
        password = "";
        Cipher aesCipher = Cipher.getInstance("AES");
        SecretKeySpec secretKeySpec = new SecretKeySpec("ABCDEFGHABCDEFGH".getBytes("UTF-8"), "AES");
        aesCipher.init(Cipher.DECRYPT_MODE, secretKeySpec);
        password = new String(aesCipher.doFinal(password.getBytes("UTF-8")), "UTF-8");
        System.out.println(password);

        //MSC_02: same seed in PRNG
        final byte[] SEED = new byte[] {0x01, 0x02, 0x03, 0x04, 0x05};
        SecureRandom secureRandom = new SecureRandom();
        secureRandom.setSeed(SEED);
        for(int i = 0; i < 5; i++) {
            System.out.println(secureRandom.nextInt());
        }
    }
}
