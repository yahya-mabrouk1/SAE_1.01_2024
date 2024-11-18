#include "fonctions.h"

void consulterOffresStagesDisponiblesSelonDepartement(void)
{
    int reference_stage, departement_stage, statu_stage, nombre_Candidats;
    int tab_numeros_des_candidats[100]; 
    int i; 
    int delet1, delet2, delet3; 
    int departementChoisi; 
    int compteur = 0; 
    int menuQuitter;
    FILE *fichier_Ofrres_De_Stages; 

    fichier_Ofrres_De_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Ofrres_De_Stages == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    printf("Saisissez le département que vous voulez :\n");
    scanf("%d", &departementChoisi);

    printf(">>>>>>>>>>Offres des stages disponibles sur le département '%d':<<<<<<<<<<\n", departementChoisi);
    printf("Reference de stage :\tDepartement :\tNombre des candidats :\tNumeros des candidats :\n");

    
    fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    while (!feof(fichier_Ofrres_De_Stages)) 
    {
        if (statu_stage == 0)
        {
            fscanf(fichier_Ofrres_De_Stages, "%d", &nombre_Candidats);

            if ((nombre_Candidats != 0) && (nombre_Candidats != 3))
            {
                if (departement_stage == departementChoisi)
                {
                    printf("\t%d\t\t\t%d\t\t%d\t\t\t", reference_stage, departement_stage, nombre_Candidats);
                    compteur++;
                }

                i = 0;
                while (i < nombre_Candidats)
                {
                    fscanf(fichier_Ofrres_De_Stages, "%d", &tab_numeros_des_candidats[i]);
                    if (departement_stage == departementChoisi)
                    {
                        printf("%d\t", tab_numeros_des_candidats[i]);
                    }                                
                    i++;
                }

                if (departement_stage == departementChoisi)
                {
                    printf("\n");
                }
            }

            if (nombre_Candidats == 0)
            {
                if (departement_stage == departementChoisi)
                {
                    printf("\t%d\t\t\t%d\t\t%d\n", reference_stage, departement_stage, nombre_Candidats);
                }
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
    {
        printf("Aucune offre de stage dans ce département actuellement.\n");
    }

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}
