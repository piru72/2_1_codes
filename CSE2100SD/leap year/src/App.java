import java.time.Year;
import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {

        Year firstYear =  Year.of(2016);
        System.out.println(firstYear.isLeap());
    }
}
