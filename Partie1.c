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
    ackermann_recursive();
    ackermann_iterative();
}

/**         1]
 Calcul d'Eumer avec une expression mathématique
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

/**         3.1]
 Calcul d'Ackermann de manère recursive
 @param int m
 @param longlong n
 @return unsigned long int
*/

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

/**         3.2]
 Calcul d'Ackermann de manère iterative
 @param int m
 @param longlong n
 @return unsigned long int
*/

unsigned long int ackermann_iterative(int m, long long n) {
    while (m == 0) {
        return n + 1;
    }
     while (m > 0 && n == 0) {
        do {
           return ackermann_iterative(m - 1, 1)
        }
    }
     while (m > 0 && n > 0) {
        do {
           return ackermann_ierative(m - 1, ackermann_iterative(m, n - 1));
        }
    }
}

/**         4.1]
 Calcul d'une suite X de manière recursive
 @param unsignedint n
 @return double, x valeur de la suite X(n)
*/

double X_recursive(unsigned int n) {
    if (n == 0) {
        return 1;
    }
    else if (n > 0) {
        double x;
        x = (X_recursive(n- 1 ) + 1) / X_recursive(n - 1);
    }
    return x;
}

/**         4.2]
 Calcul d'une suite X de manière iterative
 @param unsignedint n
 @return double, x valeur de la suite X(n)
*/

double X_iterative(unsigned int n) {
    while (n == 0) {
        return 1;
    }
    while (n > 0) {
        do {
            double x;
            x = (X_iterative(n - 1) + 1) / (X_iterative(n - 1);
        }
    }
    return x;
}
