#include "fonctions.h"


int menuResponsable(void)
{
    int choixMenuResponsable;

    printf(">>>>>>>>>>MENU RESPONSABLE :<<<<<<<<<<\n");
    printf("\t1- Supprimer un étudiant.\n");
    printf("\t2- Ajouter une offre de stage.\n");
    printf("\t3- Supprimer une offre de stage.\n");
    printf("\t4- Affecter un stage à un étudiant.\n");
    printf("\t5- Donner trois notes à un étudiant.\n");
    printf("\t6- Afficher les notes des étudiants par ordre décroissant.\n");
    printf("\t7- Afficher les stages pourvus avec les étudiants affectés à ces stages.\n");
    printf("\t8- Afficher les stages non pourvus.\n");
    printf("\t9- Afficher les étudiants n’ayant pas de stages.\n");
    printf("\t10- Afficher les informations sur un stage donné.\n");
    printf("\t11- Chercher un stage selon le numéro de l'étudiant accépté.\n");
    printf("\t12- Chercher des stages selon le département.\n");

    scanf("%d", &choixMenuResponsable);

    while (choixMenuResponsable < 1 || choixMenuResponsable > 12)
    {
        printf("Erreur, choisissez un numéro entre 1 et 12.\n");
        scanf("%d", &choixMenuResponsable);
    }

    return choixMenuResponsable;
}
