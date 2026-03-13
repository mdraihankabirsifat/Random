
import java.time.LocalDate;

class MyDate {
    private int day, month, year;
    MyDate(String str) {
        LocalDate date = LocalDate.parse(str);
        day = date.getDayOfMonth();
        month = date.getMonthValue();
        year = date.getYear();
    }
    MyDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    void showMyDate() {
        System.out.println(day + "/" + month + "/" + year);
    }
    // scope resolution not possible
}

public class Ex9 {

    public static void main(String[] args) {

        MyDate sDate = new MyDate("2024-05-12");
        MyDate iDate = new MyDate(23, 7, 2025);

        sDate.showMyDate();
        iDate.showMyDate();
    }
}
