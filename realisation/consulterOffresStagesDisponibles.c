#include "fonctions.h"


void consulterOffresStagesDisponibles(void)
{
    int reference_stage, departement_stage, statu_stage, nombre_Candidats;
    int tab_numeros_des_candidats[100]; 
    int i; 
    int delet1, delet2, delet3; 
    int compteur = 0; 
    int menuQuitter;
    FILE *fichier_Ofrres_De_Stages; 
    fichier_Ofrres_De_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Ofrres_De_Stages == NULL)
    {
        
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    printf(">>>>>>>>>>Offres des stages disponibles :<<<<<<<<<<\n"); 
    printf("Reference de stage :\tDepartement :\tNombre des candidats :\tNumeros des candidats :\n");

    fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    while (!feof(fichier_Ofrres_De_Stages)) 
    {
        if (statu_stage == 0)
        {
            fscanf(fichier_Ofrres_De_Stages, "%d", &nombre_Candidats);

            if (nombre_Candidats != 3)
            {
                printf("\t%d\t\t\t%d\t\t%d\t\t", reference_stage, departement_stage, nombre_Candidats);
            }

            if (nombre_Candidats > 0 && nombre_Candidats < 3)
            {
                i = 0; 
                while (i < nombre_Candidats)
                {
                    fscanf(fichier_Ofrres_De_Stages, "%d", &tab_numeros_des_candidats[i]);
                    printf("%d\t", tab_numeros_des_candidats[i]);
                    i++;
                    compteur++;
                }
                printf("\n");
            }
            else if (nombre_Candidats == 0)
            {
                printf("\n"); 
            }

            if (nombre_Candidats == 3)
            {
                fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &delet1, &delet2, &delet3);
            }
        }

        fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    }

    fclose(fichier_Ofrres_De_Stages);

    if (compteur == 0)
        printf("Aucune offre de stage dans ce departement actuellement.\n");

}
