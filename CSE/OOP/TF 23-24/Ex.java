
import java.util.*;

class Employee implements Comparable<Employee> {

    int id, age;
    String name;

    Employee(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public int compareTo(Employee o) {
        if (age != o.age) {
            return age - o.age;
        }
        return name.compareTo(o.name);
    }
}

public class Ex {

    public static void main(String[] args) {

        List<Employee> list = new ArrayList<>();

        list.add(new Employee(1, "Rodgers", 10));
        list.add(new Employee(2, "Bradley", 25));
        list.add(new Employee(3, "Chambers", 15));
        list.add(new Employee(4, "Calvin", 10));
        list.add(new Employee(5, "Quinn", 30));
        list.add(new Employee(6, "Mccoy", 15));

        Collections.sort(list);

        for (Employee e : list) {
            System.out.println(e.id + " " + e.name + " " + e.age);
        }
    }
}

/*
Key Notes:

1. Comparable → default sorting
2. Sorting rule:
   - age ascending
   - if same → name ascending
3. Collections.sort() uses compareTo()
*/
