class Stats<T extends Number> {
    T[] nums;

    Stats(T[] nums) {
        this.nums = nums;
    }

    double average() {
        double sum = 0;
        for (T n : nums) {
            sum += n.doubleValue();
        }
        return sum / nums.length;
    }

    boolean sameAvgAny(Stats<?> obj) {
        return average() == obj.average();
    }
}

public class Ex7_Wildcard {
    public static void main(String[] args) {
        Integer[] a = {1, 2, 3};
        Double[] b = {1.0, 2.0, 3.0};

        Stats<Integer> s1 = new Stats<>(a);
        Stats<Double> s2 = new Stats<>(b);

        System.out.println(s1.sameAvgAny(s2));
    }
}

/*
Key Notes:

1. Wildcard (?) → unknown type.
2. Allows comparison between different generic types.
3. sameAvgAny() works for any Stats<T>.
4. Without wildcard → incompatible types error.
*/