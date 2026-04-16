
import java.util.Enumeration;
import java.util.Hashtable;

public class Ex7_HashTableDemo {

    public static void main(String args[]) {

        Hashtable<String, Double> balance = new Hashtable<>();

        balance.put("John Doe", 3434.34);
        balance.put("Tom Smith", 123.22);
        balance.put("Jane Baker", 1378.00);

        Enumeration<String> itr = balance.keys();

        while (itr.hasMoreElements()) {
            String key = itr.nextElement();
            System.out.println(key + ": " + balance.get(key));
        }

        String key = "John Doe";
        double bal = balance.get(key);

        balance.put(key, bal + 1000);

        System.out.println(key + " new balance: " + balance.get(key));
    }
}

/*
Key Notes:

1. Hashtable stores key-value pairs.
2. No null key/value allowed.
3. Synchronized → thread-safe.
4. keys() returns Enumeration (old style iterator).
5. put(), get() → main operations.
*/
