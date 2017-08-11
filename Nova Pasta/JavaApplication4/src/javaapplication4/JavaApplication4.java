/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication4;

/**
 *
 * @author Mauricio Capua
 */
public class JavaApplication4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int[] vet = {8, 9, 3, 5, 1};
        int aux = 0;
        int i = 0;

        System.out.println("Vetor desordenado: ");
        mostrar(i, vet);
        for (i = 0; i < 5; i++) {
            mostrar(i, vet);
            for (int j = 0; j < 4; j++) {
                if (vet[j] > vet[j + 1]) {
                    aux = vet[j];
                    vet[j] = vet[j + 1];
                    vet[j + 1] = aux;
                }
            }
        }
        System.out.println("Vetor organizado:");
        for (i = 0; i < 5; i++) {
            System.out.println(" " + vet[i]);
        }
    }

    static void mostrar(int i, int[] vet) {
        for (i = 0; i < 5; i++) {
            System.out.println(" " + vet[i]);
        }
        System.out.println(" ");
    }
}
