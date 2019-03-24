import java.io.*;
import java.lang.*;

public class Cert_Fio {
    //FIO_08
    public void f1(String file) {
        try {
            FileInputStream in = new FileInputStream(file);
            char data;
            while ((data = (char) in.read()) != -1) {
                System.out.print(data);  
            }
            in.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        Cert_Fio obj = new Cert_Fio();
        obj.f1(args[0]);
    }
}