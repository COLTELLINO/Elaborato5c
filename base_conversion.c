#include "base_conversion.h"
#include <math.h>
#include <stdio.h>

static int num_of_digits(unsigned int x, unsigned int y) {
    
    if (x > 0) {
        unsigned int c;
        c = log10(x) / log10(y);    //calcola il numero di cifre
        return ceil(c);             //arrotondo per eccesso
    }
    else
        return 0;                   //se è 0 restituisce 0
}

static void print_digit(unsigned int x, unsigned int base, unsigned int pos) {
    
    unsigned int q = x, r = 0;
    int i;

    for (i = 0; i <= pos; i++) {
        r = q % base;                   //calcola la cifra corrente
        q /= base;                      //passa alla cifra successiva
    }

    if (r < 10) {
        printf("%d", r);                //stampa la cifra corrente in numero se <10
    }
    else {
        printf("%c", r + 55);           //stampa la cifra corrente in lettere se >10
    }
}

void base_conversion_rc(unsigned int n, unsigned int b) {

    if (n != 0) {                                               //controllo che il numero sia diverso da 0
        if (b >= 2 && b <= 16) {                                //controllo che la base sia supportata                      
            
            int resto;                                          //dichiaro la variabile che memorizza il resto
            
            if (n > 0) {                                        //la ricorsione termina raggiunto il caso base n == 0
                base_conversion_rc(n / b, b);                   //passa alla cifra successiva
                resto = n % b;                                  //calcola la cifra corrente
                if (resto < 10) printf("%d", resto);            //stampa la cifra corrente in numero se <10
                else printf("%c", resto + 55);                  //stampa la cifra corrente in lettere se >10
            }
        }
        else {
            return;                                             //termino la funzione
        }
    }

}

void base_conversion_it(unsigned int n, unsigned int b) {
    
    if (n != 0) {                                               //controllo che il numero sia diverso da 0
        if (b >= 2 && b <= 16) {                                //controllo che la base sia supportata
            int num = num_of_digits(n, b);
            int most_significant = num;                         //memorizzo la posizione della cifra più significativa

            while (most_significant >= 0) {
                print_digit(n, b, most_significant);
                n %= (unsigned int)pow(b, most_significant);    //rimuovo la cifra più significativa
                most_significant--;                             //passos alla cifra successiva
            }
        }
        else {
            return;                                             //termino la funzione                        
        }
    }
}