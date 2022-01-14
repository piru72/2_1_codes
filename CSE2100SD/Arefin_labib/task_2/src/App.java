import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        // create a scanner object that will take two string as input
        Scanner scanner = new Scanner(System.in);

        // create a string variable to store the first string
        String firstString = scanner.nextLine();
        // create a string variable to store the second string
        String secondString = scanner.nextLine();


        //print the length of the first string
        System.out.println(firstString.length());
        //print the length of the second string
        System.out.println(secondString.length());

        //replace all the sapces of first string with underscores
        firstString = firstString.replace(" ", "_");
        System.out.println(firstString);
        //print the first character of the first string
        System.out.println(firstString.charAt(0));

        //compare both string and print "Equal" if they are equal or "Not Equal" if they are not equal
        if (firstString.equals(secondString)) {
            System.out.println("Equal");
        } else {
            System.out.println("Not Equal");
        }

        // find the first occurrence of the letter "a" in the first string and print the index of the first occurrence
        int index = firstString.indexOf("a");
        System.out.println("First occurance at position " + (index+1));

        //if firststring is a substring of second string print a text or if second string is a substring of first string print a text
        if (secondString.contains(firstString)) {
            System.out.println("First String is a Substring of Second String");
        } else if (firstString.contains(secondString)) {
            System.out.println("Second String is a Substring of First String");
        }
        else {
            System.out.println("Not a Substring");
        }

        //covert the first string to lower case and print the result

        firstString = firstString.toLowerCase();
        System.out.println(firstString);

        //cover the second string to upper case and print the result
        secondString = secondString.toUpperCase();
        System.out.println(secondString);

        //save the first string to a character array and print the result
        char[] firstStringArray = firstString.toCharArray();
        System.out.println(firstStringArray);

        
    }
}

//! Trim function 
//The trim() method in Java String is a built-in function that eliminates leading and trailing spaces. The Unicode value of space character is ‘\u0020’. The trim() method in java checks this Unicode value before and after the string, if it exists then removes the spaces and returns the omitted string. The trim() method also helps in trimming the characters in Java. 

//Return Type: The return type of trim() method is String. It returns the omitted string with no leading and trailing spaces.



//! Difference Between == and .equals() Method in Java
/*

Both equals() method and the == operator are used to compare two objects in Java. == is an operator and equals() is method. But == operator compares reference or memory location of objects in a heap, whether they point to the same location or not.

Whenever we create an object using the operator new, it will create a new memory location for that object. So we use the == operator to check memory location or address of two objects are the same or not.

In general, both equals() and “==” operators in Java are used to compare objects to check equality, but here are some of the differences between the two: 

1 . The main difference between the .equals() method and == operator is that one is a method, and the other is the operator.
2. We can use == operators for reference comparison (address comparison) and .equals() method for content comparison. In simple words, == checks if both objects point to the same memory location whereas .equals() evaluates to the comparison of values in the objects.
3. If a class does not override the equals method, then by default, it uses the equals(Object o) method of the closest parent class that has overridden this method. See Why to Override equals(Object) and hashCode() method ? in detail.

*/

