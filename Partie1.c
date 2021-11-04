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

int main(int argc, char **argv){
    ackermann_Rtest();
    ackermann_Itest();
    X_test();
    assert(egal(e(10), 2.718281, 0.000001));
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

/**       2.1]
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
        for (i = 1; i <= n; n++) {
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
    do {
        return n + 1;
    }
    while (m == 0);
    do {
        return ackermann_iterative(m - 1, 1);
    }
    while (m > 0 && n == 0);
    do {
        return ackermann_ierative(m - 1, ackermann_iterative(m, n - 1));
    }
     while (m > 0 && n > 0);
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
    double x;
    do {
        return 1;
    }
    while (n == 0);
    do {
        x = (X_iterative(n - 1) + 1) / (X_iterative(n - 1);
    }
    while (n > 0);
    return x;
}

/**
 Test de la fonction d'ackermann recursive
 @param int i
 @param int j
 @return char int.
*/

int ackermann_Rtest(int i, int j) {
    for(i=1;i<=2;i++) for(j=1;j<=10;j++) {
            printf("Ackermann recursive(%i,%i)=%i\n",i,j,ackermann_recursive(i,j));
        }
    return 0;
}

/**
 Test de la fonction d'ackermann iterative
 @param int i
 @param int j
 @return char int.
*/

int ackermann_Itest(int i, int j) {
    for(i=1;i<=2;i++) for(j=1;j<=10;j++) {
            printf("Ackermann iterative(%i,%i)=%i\n",i,j,ackermann_iterative(i,j));
        }
    return 0;
}

/**
 Calcul de X(100) de manière recursive
 @param double res1
 @return double
*/

double X_R(double res1) {
    res1 = X_recursive(100);
}

/**
 Calcul de X(100) de manière iterative
 @param double res2
 @return double
*/

double X_I(double res2) {
    res2 = X_iterative(100);
}

/**
 Test qui montre si X(100) iterativement est égal à X(100) recursivement
 @param void
 @return double
 @return char erreur
*/

void X_test(void) {
    if (res1 == res2) {
        return res1;
    }
    else printf("L'une des deux methodes est fausse !")
}

/**
 Test pour verifié l'approximation d'Eleur
 @param float x
 @param float y
 @param float epsilon
 @return float diff
*/

bool egal(float x, float y, float epsilon) {
    float diff = x - y;
    if (diff >= 0.) {
        return diff <= epsilon;
    }
    else {
        return - diff <= epsilon;
    }
}
