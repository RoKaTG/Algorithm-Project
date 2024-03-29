
/**************************************************/
/* Partie 3 du Tp en autonomie d'Algorithmique    */
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
#define NTREES 4

typedef enum { FALSE, TRUE} bool;


/*************************************************/
/*                                               */
/*                structure bloc_image           */
/*                                               */
/*************************************************/

typedef struct bloc_image {
  bool toutnoir ;
  struct bloc_image * fils[4];
} bloc_image;
typedef bloc_image *image;


/*************************************************/
/*                                               */
/*                Fonctions demandées            */
/*                                               */
/*************************************************/

/**     1.1]
 Construit une image blanche
 @param non
 @return NULL
*/

image Construit_blanc() {
  return NULL;
}


/**     1.2]
 Construit une image noire
  @param non
  @return image res
*/

image Construit_noir() {
  image res = (image)malloc(sizeof(bloc_image));
  res -> toutnoir = TRUE;
  for (int i = 0; i < NTREES; i++) {
    res -> fils[i] = NULL;
  }
  return res;
}

///////////////////////////////////////////////////////////////////////////////
/** Pour la clarté du code nous créons les constructeurs suivants : */
image iHG(image I) {
  return I->fils[0];
}

image iHD(image I) {
  return I->fils[1];
}

image iBG(image I) {
  return I->fils[2];
}

image iBD(image I) {
  return I->fils[3];
}
///////////////////////////////////////////////////////////////////////////////
bool est_blanche(image I) {
  return I == NULL;
}

bool est_noire(image I) {
  return I->toutnoir;
}

bool est_composee(image I) {
  return !I->toutnoir;
}
///////////////////////////////////////////////////////////////////////////////

/**     1.3]
 Construit une image composées
  @param image ihg
  @param image ihd
  @param image ibg
  @param image ibd
  @return image res
*/

image Construit_composee(image ihg, image ihd, image ibg, image ibd) {
  image res = (image)malloc(sizeof(bloc_image));
  res->toutnoir = false;
  res->fils[0] = ihg; res->fils[1] = ihd;
  res->fils[2] = ibg; res->fils[3] = ibd;
  return res;
}


/**     1.4]
  Affiche une image en 2D
  @param image I
  @return void img
*/

void afficher(image I) {
  void img(image I, int p) {
    if (est_blanche(I)) { printf("B%d", p);
  }
  else if (est_noire(I)) { printf("N%d", p);
  }
  else {
      printf(".%d", p);
      for (int i = 0; i < NTREES; i++) {
        img(sous_image(I, i), p + 1);
      }
    }
  }
  img(I, 0);
}


/**     1.5]
  Verifie si une image est noire
  @param image I
  @return bool res
*/

bool EstNoire(image I) {
  if (est_noire(I)) {
    return true;
  }
  else {
    bool res = true;
    for (int i = 0; i < NTREES && res; i++) {
      res = res && EstNoire(sous_image(I, i));
    }
  }
  else if (est_blanche(I)) {
    return false;
  }
    return res;
  }


  /**     1.5]
    Verifie si une image est blanche
    @param image I
    @return bool res
  */

bool EstBlanche(image I) {
  if (est_blanche(I)) {
    return true;
  }
  else if (est_noire(I)){
    return false;
  }
  else {
    bool res = true;
    for (int i = 0; i < NTREES && res; i++) {
      res = res && EstBlanche(sous_image(I, i));
    }
    return res;
  }
}


/**     1.6]
  Fait une copie de l'image avec la même structure
  @param image I
  @return image construit_composee
*/

image copie(image I) {
  if (est_blanche(I)) {
    return construit_blanc();
  }
  else if (est_noire(I)) {
    return construit_noir();
  }
  else {
    return construit_composee(copie(iHG(I)), copie(iHD(I)),
                              copie(iBG(I)), copie(iBD(I)));
  }
}


/**     1.7]
  Rend le taux de noire
  @param image I
  @return float res
*/

float aire(image I) {
  if (est_blanche(I)) {
    return 0.;
  }
  if (est_noire(I)) {
    return 1.;
  }
  else {
    float res = 0.;
    for (int i = 0; i < NTREES; i++) {
      res += aire(sous_image(I, i)) / 4.;
    }
    return res;
  }
}
