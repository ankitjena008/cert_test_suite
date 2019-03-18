/* Compliant serialization class */
package testcases.CERT_Rules;

import java.io.*;
import java.lang.*;

public class Student2 implements Serializable {
    private static final long serialVersionUID = 4L;
    private String name;
    private int id;

    public Student2(String _name, int _id) {
        name = _name;
        id = _id;
    }

    private void writeObject(ObjectOutputStream stream) throws IOException {
        stream.writeObject(name);
        stream.writeObject(id);
    }

    private void readObject(ObjectInputStream stream) throws IOException, ClassNotFoundException {
        name = (String) stream.readObject();
        id = stream.readInt();
    }

    public String getName () {
        String s = name;
        return s;
    }

    public int getID() {
        int n = id;
        return n;
    }
}