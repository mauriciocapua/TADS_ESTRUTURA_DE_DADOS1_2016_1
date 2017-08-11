/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author Mauricio Capua
 */
public class JavaApplication1 {

    public static int i = 5;

    public static void funcao() {
        int i = 10;
        System.out.println("na funcao"+i);
    }

    /**
     *
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println(i);
        funcao();
        System.out.println(i);
        
        
    }

}
