
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

/**     1.3]
 Construit une image composées
  @param image ihg
  @param image ihd
  @param image ibg
  @param image ibd
  @return image res
*/
