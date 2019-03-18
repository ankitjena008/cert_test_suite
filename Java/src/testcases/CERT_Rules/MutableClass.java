/* CERT_OBJ05: MutableClass*/
package testcases.CERT_Rules;

import java.io.*;
import java.lang.*;
import java.util.Date;

public class MutableClass {
    private Date d;
    private Date[] arr;

    public MutableClass() {
        d = new Date();
        arr = new Date[20];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new Date();
        }
    }

    // Noncompliant
    public Date getDate1() {
        return d;
    }
    public Date[] getArr1() {
        return arr;// Or return arr.clone() (shallow copy not work)
    }

    // Compliant
    public Date getDate2() {
        return (Date) d.clone();
    }
    public Date[] getArr2() {
        Date[] arrs = new Date[arr.length];
        for(int i = 0; i < arr.length; i++) {
            arrs[i] = (Date) arr[i].clone();//Deep Copy
        }
        return arrs;
    }
}