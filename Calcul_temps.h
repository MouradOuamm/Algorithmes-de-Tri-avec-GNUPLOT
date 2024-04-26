#ifndef CALCUL_TEMPS_H_INCLUDED
#define CALCUL_TEMPS_H_INCLUDED



#endif // CALCUL_TEMPS_H_INCLUDED
float time_spent(int (*pf)(int[] , int), int tab[] , int taille){
    clock_t begin = clock();
    (*pf)(tab , taille);
    clock_t end = clock();
    float millis = (float)(end -  begin)/ CLOCKS_PER_SEC;
    return millis;
}

void copierTableau(int *t, int *nvt, int taille) {
    for (int i = 0; i < taille; i++) {
        nvt[i] = t[i];
    }
}
