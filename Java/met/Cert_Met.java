public class Cert_Met{
    private String myState = null;

    /* Noncompliant: fail to validate arguments */
    private void setState1(String state) {
        myState = state;
    }

    private void useState1() {
        int num = Integer.parseUnsignedInt(myState);
        System.out.println(num);
    }

    /* Compliant: validate method arguments and verfiy internal state before use */
    private void setState2(String state) {
        if (state == null) {
            // Handle null state
            System.out.println("Invalid State");
        } else {
            myState = state;
        }
    }
    //MET_00
    public void f1() {
        String s1 = null;
        setState1(s1);
        useState1();
        String s2 = "badsink";
        setState2(s2);
        useState1();
    }
}