package certOBJ;

import java.io.*;
import java.lang.*;
import java.util.Date;

//OBJ_05
public class Expose {
    private Date d;
    private Date[] arr;

    public Expose() {
        d = new Date();
        arr = new Date[20];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new Date();
        }
    }
    //OBJ_05
    public Date getDate() {
        return d;
    }

    public Date[] getArr() {
        return arr;// Or return arr.clone() (shallow copy not work)
    }
}