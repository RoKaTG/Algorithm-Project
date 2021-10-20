/**************************************************/
/* Partie 1 du Tp en autonomie d'Algorithmique    */
/* Etudiant(e) : Yassine MSILINI, Sarah BOUNDAOUI */
/* L3 Informatique Paris-Saclay 2021-2022         */
/**************************************************/


/* Bibliothéque C et facilité syntaxique */
#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||
#define then

type def enum {false, true} bool;

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/**         1]
 Caclul d'exponentielle avec une expression mathématique
 @param entier pour l'iteration maximale
 @return flottant valeur approximative de e
*//

float e(int limit) {
    float e_value(int x, int facto, float acc) {
        if (x > limit) {
            return acc;
        }
        else {
            if (x > 0) facto = facto * x;
            return e_value (x + 1, facto, acc + (1./(float) facto));
        }
    }
    return e_value(0, 1, 0);
}

double puissance_naive(double x, long long n) {
    int res = 1;
    if (n < 0) {
        res = 1./x^(n*(-1));
        n--;
    }
    else if (n == 0) {
        res = 1;
    }
    else if (n > 0) {
        res *= x;
        n--;
    }
    return res;
}

double puissance_recursive(double x, long long n) {
    res = 1;
    if (n < 0) {
        res = 1./ puissance_recursive(x,n++);
    }
    else if (n == 0) {
        res = 1:
    }
    else if (n > 0) {
        res = x * puissance_recursive(x, n--);
    }
    return res;
}