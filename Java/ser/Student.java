/* CERT_SER01: Noncompliant serialization class */
package certSER;

import java.io.*;
import java.lang.*;

public class Student implements Serializable {
    private static final long serialVersionUID = 1L;
    private String name;
    private int id;

    public Student(String _name, int _id) {
        name = _name;
        id = _id;
    }

    public void writeObject(ObjectOutputStream stream) throws IOException {
        stream.writeObject(name);
        stream.writeObject(id);
    }

    public void readObject(ObjectInputStream stream) throws IOException, ClassNotFoundException {
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