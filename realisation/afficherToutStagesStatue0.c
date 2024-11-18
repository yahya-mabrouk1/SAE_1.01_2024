#include "fonctions.h"

void afficherToutStagesStatue0(void)
{
    int reference_stage, departement_stage, statu_stage, nombre_Candidats;
    int tab_numeros_des_candidats[100]; 
    int i; 
    int compteur = 0, menuQuitter; 
    FILE *fichier_Ofrres_De_Stages; 

    fichier_Ofrres_De_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Ofrres_De_Stages == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    printf(">>>>>>>>>> Offres des stages qui ne sont pas pourvus : <<<<<<<<<<\n"); 
    printf("Reference de stage :\tDepartement :\tNombre des candidats :\tNumeros des candidats :\n");

    fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    while (!feof(fichier_Ofrres_De_Stages)) 
    {
        if (statu_stage != 1)
        {
            fscanf(fichier_Ofrres_De_Stages, "%d", &nombre_Candidats);

            printf("\t%d\t\t\t%d\t\t%d\t\t", reference_stage, departement_stage, nombre_Candidats);

            if (nombre_Candidats > 0)
            {
                i = 0; 
                while (i < nombre_Candidats)
                {
                    fscanf(fichier_Ofrres_De_Stages, "%d", &tab_numeros_des_candidats[i]);
                    printf("%d\t", tab_numeros_des_candidats[i]);
                    i++;
                }
                printf("\n");
            }
            else if (nombre_Candidats == 0)
            {
                printf("\n"); 
            }

            compteur++; 
        }


        fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    }

    fclose(fichier_Ofrres_De_Stages);

    if (compteur == 0)
        printf("Aucune offre de stage disponible.\n");

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;

}
