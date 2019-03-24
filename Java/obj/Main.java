package certOBJ;

import java.util.Date;

public class Main {
    public static void main(String[] args) {
        Expose obj = new Expose();
        Date d = obj.getDate();
        System.out.println(d);

        Date[] arr = obj.getArr();
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}