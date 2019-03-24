import java.io.*;
import java.lang.*;

import java.text.Normalizer;
import java.text.Normalizer.Form;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import java.io.BufferedOutputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

public class Cert_Ids {
    //IDS_01
    public void f1() {
        String data = "\uFE64" + "script" + "\uFE65";

        // Validate
        Pattern pattern = Pattern.compile("[<>]"); // Check for angle brackets
        Matcher matcher = pattern.matcher(data);

        if (matcher.find()) {
            // Found black listed tag
            throw new IllegalStateException();
        } else {
            data = Normalizer.normalize(data, Form.NFKC);
            System.out.printf("output string: %s", data);
        }
    }
    
    //IDS_11
    public void f2() {
        String maliciousInput = "<scr" + "\uFDEF" + "ipt>";
        String s = Normalizer.normalize(maliciousInput, Form.NFKC);
        
        // Validate input
        Pattern pattern = Pattern.compile("<script>");
        Matcher matcher = pattern.matcher(s);
        if (matcher.find()) {
            throw new IllegalArgumentException("Invalid input");
        }

        // Deletes noncharacter code points
        s = s.replaceAll("[\\p{Cn}]", "");
        System.out.printf("output string: %s", s);
    }

    //IDS_16
    public void f3(BufferedOutputStream outStream) {
        String quantity = "1</quantity><price>1.0</price><quantity>1";
        String xmlString = "<item>\n<description>Widget</description>\n" + "<price>500</price>\n" + "<quantity>"
                + quantity + "</quantity></item>";

        try {
            outStream.write(xmlString.getBytes("UTF_8"));
            outStream.flush();
        } catch(Exception e) {
            //handle exception here
        } 
    }

    public static void main(String[] args) {
        Cert_Ids obj = new Cert_Ids();
        obj.f1();
        obj.f2();
        try {
            File f = new File(args[0]);
            FileOutputStream fos = new FileOutputStream(f);
            BufferedOutputStream os = new BufferedOutputStream(fos);
            obj.f3(os);
        } catch(Exception e) {
            //handle exception here
        }
    }

}