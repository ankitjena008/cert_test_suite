package certSER;

import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws Throwable {
        // SER_01: define public readObject() and writeObject() methods
        Student s = new Student("Alice", 10);
        try {
            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(args[0]));
            out.writeObject(s);
            out.close();
        } catch (Exception e) {
            //handle exception
        }

        //SER_01:  declares readResolve() and writeReplace() methods as private/static
        SingletonWithSerializable p = SingletonWithSerializable.getInstance();
        SingletonWithSerializable p1 = null;
        try {
            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(args[1]));
            out.writeObject(p);
            out.close();

            ObjectInputStream in = new ObjectInputStream(new FileInputStream(args[1]));
            p1 = (SingletonWithSerializable) in.readObject();

            if(p == p1) {
                System.out.println("equal");
            }
            else {
                System.out.println("not equal");
            }
        } catch (Exception e) {
            //handle exception
        }
        
        //SER_12 
        RandomAccessFile f = new RandomAccessFile(args[2], "r");
        byte[] b = new byte[(int) f.length()];
        f.readFully(b);
        deserializeBeforeValidate d = new deserializeBeforeValidate();
        Object r = d.deserialize(b);
    }
}
