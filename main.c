#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "Algo_tri.h"
#include "Calcul_temps.h"
#include "Utilisation.h"
#include "Gauss_lissage.h"
#define TRUE 1
#define FALSE 0

int main()
{
    int num , taille,i, *t,*nvt ,option,n=6,k=0;
      float tab[91][n+1],temps;


    printf("***********************************************************************\n");
    printf("*                    ENSET-M 2023/2024                                *\n");
    printf("*                    Module : Algo & C                                *\n");
    printf("*                    Mini-projet N: 1                                 *\n");
    printf("*   Etude expérimentale des algorithmes de recherche et de tri        *\n");
    printf("*   R%calis%c par : \n\t\t MOURAD OUAMMOU   \n \t\t ABDERAZAK HADDANI   \n\t\t YOUSSEF OUBEN SAID \n\t\t MOHAMED BOURHYM \n",130,130);
    printf("*   Travail r%calis%c sur une machine de processeur : i5 CPU @ 2.4GHZ \n",130,130);
    printf("***********************************************************************\n");

while(1)
    {
afficherMenuPrincipal();

do{
printf("\nVeuillez saisir votre choix dans le menu: ");
scanf("%d",&num);
if((num>3)||(num<1)) printf("\n(!) Ce num%cro ne figure pas dans la liste !\n",130);}
while((num>3)||(num<1));
       {
           if(num ==1) {
                       do
            {
            afficherMenuGnuplot();
            printf("\nVeuillez saisir votre choix : ");
            scanf("%d", &option);

                switch (option)
                {
                    case 1:
                        printf("\nLancement de Gnuplot sans lissage\n");
                        printf("\nAttendre Quelque Secondes !");
                                 FILE *datafile = fopen("data.txt", "w");
        if (datafile == NULL) {
            perror("Erreur lors de l'ouverture du fichier de données");
            return 1;
        }

        for ( taille = 1000; taille <= 20000; taille += 500) {
            fprintf(datafile, "%d\t", taille);
             t = (int *)calloc(taille, sizeof(int));
             nvt = (int *)calloc(taille, sizeof(int));

            for (int i = 0; i < taille; i++) {
                t[i] = (rand() % 10) + 1;
            }

            copierTableau(t, nvt, taille);
            fprintf(datafile, "%f\t", time_spent(&triInsertion, t, taille));
            copierTableau(nvt, t, taille);
            fprintf(datafile, "%f\t", time_spent(&triSelection, nvt, taille));
            copierTableau(t, nvt, taille);
            fprintf(datafile, "%f\t", time_spent(&triTas, t, taille));
            copierTableau(nvt, t, taille);
            fprintf(datafile, "%f\t", time_spent(&triBulle, nvt, taille));
            // Appel à la fonction de tri par fusion (triFusion) ici :
            copierTableau(t, nvt, taille);
            fprintf(datafile, "%f\t", time_spent(&triFusion, t, taille));
            copierTableau(t, nvt, taille);
            fprintf(datafile, "%f\n", time_spent(&triFusion, t, taille));


            free(t);
            free(nvt);
        }
 fclose(datafile);

        FILE *gnuplotScript = fopen("plot_script.plt", "w");
        if (gnuplotScript == NULL) {
            perror("Erreur lors de l'ouverture du script Gnuplot");
            return 1;
        }

        fprintf(gnuplotScript, "set title 'Graphe des algorithmes de tri'\n");
        fprintf(gnuplotScript, "plot 'data.txt' using 1:2 with lines title 'tri par insertion', \
            'data.txt' using 1:3 with lines title 'tri par selection', \
            'data.txt' using 1:4 with lines title 'tri par Tas', \
            'data.txt' using 1:5 with lines title 'tri par bulle', \
            'data.txt' using 1:6 with lines title 'tri par fusion'\n");

        fclose(gnuplotScript);

        FILE *gnuplot = popen("gnuplot -persist", "w");
        if (gnuplot == NULL) {
            perror("Erreur lors de l'ouverture de Gnuplot");
            return 1;
        }

        fprintf(gnuplot, "load 'plot_script.plt'\n");

        pclose(gnuplot);

         printf("\nAppuyer sur n'importe quelle touche pour continuer\n");
         getch();
                        break;

                    case 2:
                        printf("\nRetour au menu principal\n");
                        break;

                    default:
                        printf("\n(!) Ce num%cro ne figure pas dans la liste !\n", 130);
                        break;
                }
            } while (option != 2);
           }


        }
    if(num==2)
{
            afficherTableau(t,taille);
            printf("\nAppuyer sur n'importe quelle touche pour continuer\n");
            getch();
            }
             if(num ==3) {
    exit(0);
 }

  system("PAUSE");
 }


    return 0;
}
