import java.time.Year;
import java.util.*;
import java.lang.Math;

public class App {
    public static void main(String[] args) throws Exception {

        Year firstYear =  Year.of(2016);
        //System.out.println(firstYear.isLeap());

        double a = 90;
        double b = Math.toRadians(a);
        System.out.println("value " + b);
        System.out.println("Sin value " + Math.sin(b));
        System.out.println("Cos value " + Math.cos(b));
        System.out.println("Tan value " + Math.tan(b));


    }
}
