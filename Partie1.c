/**************************************************/
/* Partie 1 du Tp en autonomie d'Algorithmique    */
/* Etudiant(e) : Yassine MSILINI, Sarah BOUNDAOUI */
/* L3 Informatique Paris-Saclay 2021-2022         */
/**************************************************/


/* Bibliothéque C et facilitée syntaxique */
#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||
#define then

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

float e(int limit);
double puissance_naive(double x, long long n);
double puissance_recursive(double x, long long n);
double puissance_iterative(double x, long long n);
double puissance1(double x, long long n);
double puissance2(double x, long long n);
double puissance3(double x, long long n);
unsigned long int ackermann_recursive(int m, long long n);
unsigned long int ackermann_iterative(int m, long long n);
double X_recursive(unsigned int n);
double X_iterative(unsigned int n);
int ackermann_Rtest(int i, int j);
int ackermann_Itest(int i, int j);
double X_R(double res1);
double X_I(double res2);
double X_test(double res1, double res2);
bool egal(float x, float y, float epsilon);


int main(int argc, char **argv){
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

/**         2.1]
 Calcul d'une puissance de manère recursive
 @param double x, la base
 @param longlong n, la puissance
 @return floattant res, valeur de x^n
*/

double puissance_recursive(double x, long long n) {
    double res = 1;
    if (n < 0) {
        res = 1./ puissance_recursive(x,-n);
    }
    else if (n == 0 || (n == 0 && x == 0)) {
        res = 1;
    }
    else if (n > 0) {
        res = x * puissance_recursive(x, n-1);
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
    double res = 1;
    int i;
    if (n < 0) {
        for (i = 1; i >= n; n--) {
            res = 1. / puissance_iterative(x,-n);
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

double puissance1(double x, long long n) {  //Fait n appels, la fonction est de complexité n
  if (n < 0) {
    return 1./ puissance1(x,-n);
  }
  if (n == 0) {
    return 1;
  } else {
    return puissance1(x, n-1) * x;
  }
}

double puissance2(double x, long long n) {  //Fait ln2(n) appels, donc de complexité log
  if (n < 0) {
    return 1./ puissance2(x,-n);
  }
  if (n == 0) {
    return 1;
  } else {
    double y = puissance2(x, n / 2);
    if (n%2 == 0) {
      return y * y;
    } else {
      return y * y * x;
    }
  }
}

double puissance3(double x, long long n) { //Il y aenviron ln2(n) iterations.
  double y = x;
  int res = 1;
  while (n != 0) {
    if (n%2 != 0) {
      res = res * y;
      n = n / 2;
      y = y *y;
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
        return ackermann_iterative(m - 1, ackermann_iterative(m, n - 1));
    }
     while (m > 0 && n > 0);
}

/**Pour A(m,0) m de 0 à 6 :
A(1,0) = 1
A(2,0) = 2
A(3,0) = 3
A(4,0) = 5
A(5,0) = 65533
A(6,0) = A(5,1)
*/


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
        return x;
    }
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
        x = (X_iterative(n - 1) + 1) / (X_iterative(n - 1));
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
            printf("Recursive");
            return ackermann_recursive(i,j);
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
            printf("Iterative");
            return ackermann_iterative(i,j);
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
    return res2;
}

/**
 Test qui montre si X(100) iterativement est égal à X(100) recursivement
 @param void
 @return double
 @return char erreur
*/

double X_test(double res1, double res2) {
  X_I(res2);
  X_R(res1);
    if (res1 == res2) {
        return res1;
    }
    else return 0;
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
