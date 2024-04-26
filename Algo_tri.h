#ifndef ALGORITHMES_H_INCLUDED
#define ALGORITHMES_H_INCLUDED



#endif // ALGORITHMES_H_INCLUDED

void triBulle(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                echanger(&tableau[j], &tableau[j + 1]);
            }
        }
    }
}
void fusion(int tableau[], int gauche, int milieu, int droite) {
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = tableau[gauche + i];
    for (int j = 0; j < n2; j++)
        R[j] = tableau[milieu + 1 + j];

    int i = 0, j = 0, k = gauche;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tableau[k] = L[i];
            i++;
        } else {
            tableau[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tableau[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        tableau[k] = R[j];
        j++;
        k++;
    }
}

void triFusion(int tableau[], int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;

        triFusion(tableau, gauche, milieu);
        triFusion(tableau, milieu + 1, droite);

        fusion(tableau, gauche, milieu, droite);
    }
}

void triInsertion(int tableau[], int taille) {
    for (int i = 1; i < taille; i++) {
        int cle = tableau[i];
        int j = i - 1;

        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j--;
        }

        tableau[j + 1] = cle;
    }
}

void triSelection(int tableau[], int taille) {
    int i, j, min, temp;
    for (i = 0; i < taille - 1; i++) {
        min = i;
        for (j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[min]) {
                min = j;
            }
        }
        // Échanger les éléments min et i
        temp = tableau[i];
        tableau[i] = tableau[min];
        tableau[min] = temp;
    }
}

void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void tamiser(int tableau[], int taille, int racine) {
    int plus_grand = racine;
    int gauche = 2 * racine + 1;
    int droite = 2 * racine + 2;

    if (gauche < taille && tableau[gauche] > tableau[plus_grand]) {
        plus_grand = gauche;
    }

    if (droite < taille && tableau[droite] > tableau[plus_grand]) {
        plus_grand = droite;
    }

    if (plus_grand != racine) {
        echanger(&tableau[racine], &tableau[plus_grand]);
        tamiser(tableau, taille, plus_grand);
    }
}

// Fonction pour trier un tableau en utilisant le tri par tas
void triTas(int tableau[], int taille) {
    // Construire le tas max
    for (int i = taille / 2 - 1; i >= 0; i--) {
        tamiser(tableau, taille, i);
    }

    // Extraire les éléments un par un du tas
    for (int i = taille - 1; i > 0; i--) {
        echanger(&tableau[0], &tableau[i]);
        tamiser(tableau, i, 0);
    }
}
