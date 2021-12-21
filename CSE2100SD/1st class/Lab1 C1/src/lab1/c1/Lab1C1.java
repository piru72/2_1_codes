/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1.c1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author Medul
 */
public class Lab1C1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
//        ArrayList<Integer> list = new ArrayList<Integer>();
        LinkedList<Integer> list=new LinkedList<Integer>();
//        HashSet<String> list=new HashSet<String>();
        
        while(sc.hasNext())
        {
            //System.out.println(sc.nextInt());
            list.add(sc.nextInt());
        }
        
        for(int i=0; i<list.size(); i++)
        {
            System.out.println(list.get(i));

        }
        sc.close();
        
        //adjecency list
        
        System.out.println("Adjecency List");
        sc = new Scanner(new File("input.txt"));
        LinkedList<LinkedList<Integer>> list2 = new LinkedList<LinkedList<Integer>>();
        
        for(int i=0; i<6; i++)
            list2.add(new LinkedList<Integer>());
        
        while(sc.hasNext()){
            int first = sc.nextInt();
            int second = sc.nextInt();
            
            list2.get(first).add(second);
        }

        System.out.println(list2);
    }
    
}
