
/**************************************************/
/* Partie 2 du Tp en autonomie d'Algorithmique    */
/* Etudiant(e) : Yassine MSILINI, Sarah BOUNDAOUI */
/* L3 Informatique Paris-Saclay 2021-2022         */
/**************************************************/


#include <stdio.h>
#include <stdlib.h>

/*************************************************/
/*                                               */
/*                sucre syntaxique               */
/*                                               */
/*************************************************/

#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !
#define then

typedef enum { FALSE, TRUE} bool;

/*************************************************/
/*                                               */
/*          definition type liste                */
/*                                               */
/*************************************************/

typedef struct Bloc
{
    int nombre;
    struct Bloc *suivant;
} Bloc;

typedef Bloc *Liste ;

/*************************************************/
/*                                               */
/*                predeclarations                */
/*                                               */
/*************************************************/

/* initialise une Liste � vide */
void initVide(Liste *L);

/* renvoie 1 si la Liste en parametre est vide, 0 sinon */
bool estVide(Liste l);

/* renvoie le premier element de la Liste en parametre */
int premier(Liste l);

/* renvoie une nouvelle Liste correspondant a celle en parametre, avec l'element x ajoute en haut de la pile */
Liste ajoute(int x, Liste l);

/* modifie la Liste en parametre: x est ajoute comme premier element */
void empile(int x, Liste* L);

/* renvoie une nouvelle Liste correspondant a celle en parametre sans son premier element */
Liste suite(Liste l);

/* modifie la Liste en parametre: le premier element est retire */
void depile(Liste* l);

/* affichage simple en recursif et en iteratif */
void affiche_rec(Liste l);
void affiche_iter(Liste l);

/* longueur en recursif et en iteratif */
int longueur_rec (Liste l);
int longueur_iter (Liste l);

/*  Elimination du dernier element en recursif et en iteratif  */
/*  VD est la sousprocedure utilitaire de la version recursive */
void VD (Liste *L);
void VireDernier_rec (Liste *L);
void VireDernier_iter (Liste *L);


/*************************************************/
/*                                               */
/*                briques de base                */
/*                                               */
/*************************************************/


void initVide( Liste *L)
{
    *L = NULL ;
}

bool estVide(Liste l)
{
    return l == NULL ;
}

int premier(Liste l)
{
    return l->nombre ;
}

Liste ajoute(int x, Liste l)
{
    Liste tmp = (Liste) malloc(sizeof(Bloc)) ;
    tmp->nombre = x ;
    tmp->suivant = l ;
    return tmp ;
}

void empile(int x, Liste *L)
{
      *L = ajoute(x,*L) ;
}

Liste suite(Liste l)
{
    return l->suivant ;
}


void depile(Liste *L)
{
    Liste tmp = *L ;
    *L = suite(*L) ;
    free(tmp) ;
}

/*************************************************/
/*                                               */
/*     Affiche, avec les briques de base         */
/*                                               */
/*************************************************/

void affiche_rec(Liste l)
{
    if(estVide(l))
        printf("\n");
    else
    {
        printf("%d ", premier(l));
        affiche_rec(suite(l));
    }
}


void affiche_iter(Liste l)
{
    Liste L2 = l;
    while(!estVide(L2))
    {
        printf("%d ", premier(L2));
        L2 = suite(L2);
    }
    printf("\n");
}

/*************************************************/
/*                                               */
/*     Longueur, sans les briques de base        */
/*                                               */
/*************************************************/

int longueur_rec (Liste l)
{
    if (l == NULL)
         return 0 ;
    else return (1 + longueur_rec(l->suivant)) ;
}


int longueur_iter (Liste l)
{
    Liste P = l;
    int cpt = 0 ;
    while (P ISNOT NULL)
    {   P = P->suivant ;
        cpt++ ;
    }
    return cpt ;
}

/*************************************************/
/*                                               */
/*       VireDernier,                            */
/*               sans les briques de base,       */
/*               ni le "->"                      */
/*                                               */
/*************************************************/

void VD (Liste *L)
          // *L non NULL ie liste non vide
{
     if ( ((**L).suivant) == NULL )
            depile(L) ;   // moralement : depile(& (*L)) ;
     else VD (& ( (**L).suivant )) ;
}

void VireDernier_rec (Liste *L)
{
     if ( (*L) ISNOT NULL )
          VD(L);        // moralement : VD(& (*L)) ;
}

void VireDernier_iter (Liste *L)
{
    if ( (*L) ISNOT NULL)
    {
        while ( ((**L).suivant) ISNOT NULL )
                 L = & ( (**L).suivant ) ;
        free(*L) ;
        *L = NULL ;
     }
}


/*************************************************/
/*                                               */
/*       Libere la memoire                       */
/*                                               */
/*************************************************/

void VideListe(Liste *L)
{
    if(NOT(estVide(*L)))
    {
        depile(L);
        VideListe(L);
    }

}

/*************************************************/
/*                                               */
/*           Main                                */
/*                                               */
/*************************************************/

void poup (Liste l)
{
        printf("Double Affichage \n") ;
        affiche_rec(l) ;
        affiche_iter(l) ;

        printf("Longueur en double %d %d \n\n",
                           longueur_rec(l),
                           longueur_iter(l)
               ) ;
}

int main(int argc, char** argv)
{
    Liste l ;

        initVide (&l) ;

          poup(l) ;

             empile(4, &l) ;

          poup(l) ;

             empile(5, &l) ;
             empile(6, &l) ;
             empile(7, &l) ;
             empile(8, &l) ;
             empile(9, &l) ;

          poup(l) ;

        VireDernier_rec  (&l) ;
        VireDernier_iter (&l) ;
        depile(& l) ;

          poup(l) ;

    VideListe(&l);
    return 0;
}

/*************************************************/
/*                                               */
/*     Fonctions demandées par l'exercice 2.     */
/*                                               */
/*************************************************/

/**         1]
 Verifie si une liste à un 0 en deuxieme position
 @param liste L
 @return boolean TRUE/FALSE
*/

bool ZeroEnDeuxiemePosition(Liste l) {
  if (estVide(l) == TRUE) {
    return FALSE;
  }
  else if (suite(l) == 0) {
    return TRUE;
  }
  else return FALSE;
}

/**         2]
 Verifie si touts les elements d'une liste sont des 0
 @param liste L
 @return boolean TRUE/FALSE
*/

bool queDesZeros(Liste l) {
  if (l == NULL) {
    return TRUE;
  } else while (l -> nombre == 0) {
    l = l -> suivant;
  }
    return l == NULL;
  }

/**         3.1]
 Compte le nombre de 0 en debut de liste de manière recursive
 @param liste L
 @return int
*/

int Compte0InitiauxRec(Liste l) {
  if (estVide(l) == TRUE || premier(l) != 0) {
    return 0;
  }
  else if (premier(l) == 0) {
    return 1 + Compte0InitiauxRec(suite(l));
  }
}

/**         3.2]
 Compte le nombre de 0 en debut de liste de manière iterative
 @param liste L
 @return int compteur
*/

int Compte0InitiauxIte(Liste l) {
  int compteur = 0;
  while (l != NULL && l -> nombre == 0) {
    l = l -> suivant;
    compteur = compteur + 1;
  }
  return compteur;
}

/**         3.3]
 Compte le nombre de 0 en debut de liste de manière recursive terminale IN
 @param liste L
 @return int compteur
*/

int C_Rec_In(Liste l, int compteur) {
  return 0;
}

int Compte0InitiauxRec2(Liste l) {
  return C_Rec_In(l, 0);
}
/**         3.4]
 Compte le nombre de 0 en debut de liste de manière recursive terminale inOUT
 @param liste L
 @return int compteur
*/

int C_Rec_OUT(Liste l, int compteur) {
  return 0;
}

int Compte0InitiauxRec3(Liste l) {
  return C_Rec_OUT(l, 0);
}

/**         4]
 Concatène deux listes et trie les elements communs au deux listes
 @param liste l1 l2
 @return Liste l
*/

Liste IntersectionTriee(Liste l1, Liste l2) {
  if (estVide(l1) == TRUE || estVide(l2) == TRUE) {
    printf("%s\n","%s Impossible l'une des deux listes est nulle" );
  }
  else {
    int entier = premier(l1);
    if (premier(l1) == premier(l2)) {
      return ajoute(entier, IntersectionTriee(suite(l1), suite(l2)));
    }
    else if (premier(l1) != premier(l2)) {
      return IntersectionTriee(suite(l1), suite(l2));
    }
  }
}

/**         5]
elimine les k premières occurences de x
 @param liste l
 @param int x
 @param int k
 @return void
*/

void ElimineKpremiersX(Liste l, int x, int k) {
}

/**         6]
elimine les k dernières occurences de x
 @param liste l
 @param int x
 @param int k
 @return void
*/

void ElimineKderniersX(Liste l, int x, int k) {
}

/**         7]
 Permutation de manière diviser pour regner
 @param liste l1
 @return ?
*/
                                  //Fonctions toutes issues du cours page 30, problème de type, création de nouveau non faite
/** Liste ATLTP(int x, Liste l) {
  if (estVide(l) == TRUE) {
    return [];
  }
  else {
    return Concat(ATP(x, premier(l)), ATLTP(x, suite(l)));
  }
}

Liste ATP(int x, Liste l) {
  if (estVide(l) == TRUE) {
    return [[x]];
  }
  else {
    return ajoute(ajoute(x,l), AETTL(premier(l), ATP(x, suite(l))));
  }
}

Liste Concat(Liste l1, Liste l2) {
  if (estVide(l1) == TRUE) {
    return l2;
  }
  else {
    return ajoute(premier(l1), Concat(suite(l1), l2));
  }
}

Liste AETTL(int x, Liste l) {
  if (estVide(l) == TRUE) {
    return NULL;
  }
  else {
    return ajoute(ajoute(x, premier(l)), AETTL(x, suite(l)));
  }
}

Liste Permutation(int n) {
  if (n == 0) {
    return [[]];
  }
  else {
    return ATLTP(n, Permutation(n-1));
  }
}
*/
