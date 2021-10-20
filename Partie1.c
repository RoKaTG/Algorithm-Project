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

int main() {
    e();
    puissance_naive();
    puissance_recursive();
    puissance_iterative();
}

/**         1]
 Calcul d'exponentielle avec une expression mathématique
 @param int limit, pour l'iteration maximale
 @return flottant valeur approximative de e
*/

float e(int limit) {
    float res(int x, int facto, float compteur) {
        if (x > limit) {
            return compteur;
        }
        else {
            if (x > 0) facto = facto * x;
            return res (x + 1, facto, compteur + (1./(float) facto));
        }
    }
    return res(0, 1, 0);
}

/**         2.1]
 Calcul d'une puissance de manère naîve
 @param double x, la base
 @param longlong n, la puissance
 @return floattant res, valeur de x^n
*/

double puissance_naive(double x, long long n) {
    float res = 1.;
    if (n < 0) {
        res = 1./x^(n*(-1));
        n--;
    }
    else if (n == 0 || (n == 0 && x == 0)) {
        res = 1;
    }
    else if (n > 0) {
        res *= x;
        n--;
    }
    return res;
}

/**         2.2]
 Calcul d'une puissance de manère recursive
 @param double x, la base
 @param longlong n, la puissance
 @return floattant res, valeur de x^n
*/

double puissance_recursive(double x, long long n) {
    float res = 1;
    if (n < 0) {
        res = 1./ puissance_recursive(x,n++);
    }
    else if (n == 0 || (n == 0 && x == 0)) {
        res = 1;
    }
    else if (n > 0) {
        res = x * puissance_recursive(x, n--);
    }
    return res;
}

/**         2.3]
 Calcul d'une puissance de manère iterative
 @param double x, la base
 @param longlong n, la puissance
 @return floattant res, valeur de x^n
*/

double puissance_iterative(double x, long long n) {
    float res = 1;
    int i;
    if (n < 0) {
        for (i = 1; i >= n; n--) {
            res = 1. / x ^ (n * (-1));
        }
    }
    else if (n == 0 || (n == 0 && x == 0)) {
        res = 1;
    }
    else if (n > 0) {
        for (i = 1); i <= n; n++) {
            res *= x;
        }
    }
    return res;
}

unsigned long int ackermann_recursive(int m, long long n) {
    if (m == 0) {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return ackermann_recursive(m - 1, 1);
    }
    else if (m > 0 && n > 0) {
        return ackermann_recursive(m - 1, ackermann_recursive(m, n - 1));
    }
}