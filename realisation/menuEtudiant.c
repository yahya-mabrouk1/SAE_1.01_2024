#include "fonctions.h"


int menuEtudiant(void)
{
    int choixMenuEtudiant; 

    printf(">>>>>>>>>>MENU :<<<<<<<<<<\n");
    printf("\t1- Consulter la liste des offres de stages disponibles.\n");
    printf("\t2- Afficher mes candidatures.\n"); 
    printf("\t3- Consulter la liste des offres de stages disponibles selon le numero du departement.\n"); 
    printf("\t4- Candidater sur un stage.\n"); 

    scanf("%d", &choixMenuEtudiant);

    while ((choixMenuEtudiant != 1) && (choixMenuEtudiant != 2) &&
           (choixMenuEtudiant != 3) && (choixMenuEtudiant != 4))
    {
        printf("Erreur, choisi parmi 1, 2, 3 ou 4.\n");
        scanf("%d", &choixMenuEtudiant);
    }

    return choixMenuEtudiant;
}
