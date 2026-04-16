
import java.util.LinkedList;

public class Ex4_LinkedListDemo {

    public static void main(String args[]) {

        LinkedList<String> ll = new LinkedList<>();

        ll.add("F");
        ll.add("B");
        ll.add("D");
        ll.add("E");
        ll.add("C");

        ll.addLast("Z");
        ll.addFirst("A");
        ll.add(1, "A2");

        System.out.println("Original: " + ll);

        ll.remove("F");
        ll.remove(2);

        System.out.println("After deletion: " + ll);

        ll.removeFirst();
        ll.removeLast();

        System.out.println("After removing ends: " + ll);

        Object val = ll.get(2);
        ll.set(2, val + " Changed");

        System.out.println("After change: " + ll);
    }
}

/*
Key Notes:

1. LinkedList uses doubly linked list.
2. Better for insertion/deletion than ArrayList.
3. addFirst(), addLast() → special operations.
4. removeFirst(), removeLast() → efficient.
5. get() + set() → access and modify elements.
6. Slower random access compared to ArrayList.
*/
