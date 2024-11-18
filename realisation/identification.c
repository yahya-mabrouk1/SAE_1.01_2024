#include "fonctions.h"


int identification(void)
{
    int choixIdentification; 
    printf(">>>>>>>>>>Identifiez vous :<<<<<<<<<<\n");
    printf("\t1- Etudiant\n"); 
    printf("\t2- Responsable de stages\n"); 
    scanf("%d", &choixIdentification);

    while ((choixIdentification != 1) && (choixIdentification != 2))
    {
        printf("Erreur, choisi 1 ou 2\n");
        scanf("%d", &choixIdentification);
    }

    return choixIdentification;
}
