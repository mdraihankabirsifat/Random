
import java.util.*;
import java.util.stream.*;

// Employee class
class Employee {

    private int id;
    private String name;
    private int age;

    // Constructor
    Employee(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    // Getters
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return id + " " + name + " " + age;
    }
}

public class Ex12 {

    public static void main(String[] args) {

        // (i) Create list and add employees
        List<Employee> list = new ArrayList<>();

        list.add(new Employee(1, "Rodgers", 10));
        list.add(new Employee(2, "Bradley", 25));
        list.add(new Employee(3, "Chambers", 15));
        list.add(new Employee(4, "Calvin", 10));
        list.add(new Employee(5, "Quinn", 30));
        list.add(new Employee(6, "Mccoy", 15));

        // (ii) Using Stream
        // Extract names
        List<String> names = list.stream()
                .map(e -> e.getName())
                .collect(Collectors.toList());

        // Employees with age <= 20
        List<Employee> employees = list.stream()
                .filter(e -> e.getAge() <= 20)
                .collect(Collectors.toList());

        // Print results
        System.out.println(names);
        System.out.println(employees);

        // (iii) Sorting
        list.sort(
                Comparator.comparing(Employee::getAge)
                        .thenComparing(Employee::getName)
        );

        // Print sorted list
        for (Employee e : list) {
            System.out.println(e);
        }
    }
}

/*
Key Notes:

1. (i) ArrayList:
   - stores Employee objects
   - add() used to insert elements

2. Stream API:
   - stream() → convert list to stream

3. map():
   - transforms data
   - here: Employee → String (name)

4. filter():
   - selects elements based on condition
   - here: age <= 20

5. collect():
   - converts stream back to list

6. Sorting:
   - Comparator.comparing(Employee::getAge)
   - thenComparing(Employee::getName)

7. Sorting rule:
   - first by age (ascending)
   - if same age → by name (ascending)

8. No custom sorting logic used
   - only built-in Comparator

9. Method reference:
   - Employee::getAge
   - cleaner than lambda

10. Output order after sorting:
   Age 10 → Calvin, Rodgers
   Age 15 → Chambers, Mccoy
   Age 25 → Bradley
   Age 30 → Quinn
*/
