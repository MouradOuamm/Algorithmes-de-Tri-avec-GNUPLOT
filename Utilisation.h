#ifndef UTILISATION_H_INCLUDED
#define UTILISATION_H_INCLUDED



#endif // UTILISATION_H_INCLUDED
void afficherMenuPrincipal() {
    printf("\n-------------------------------------Menu--------------------------------------\n");
    printf("\n1. Lancer GnuPlot\n");
    printf("2. Afficher les %cl%cments du tableau\n",130,130);
    printf("3. Quitter\n");
}

void afficherMenuGnuplot() {
    printf("\n1. Lancer Gnuplot (avec Lissage)\n");
    printf("2. Retour au menu principal\n");
}
void afficherTableau(int *t, int taille) {
    if (t == NULL) {
        printf("Le tableau n'est pas encore rempli.\n");
    } else {
        printf("Les éléments du tableau sont :");
        for (int i = 0; i < taille; i++) {
            printf("\n %d ", t[i]);
        }
    }
}


