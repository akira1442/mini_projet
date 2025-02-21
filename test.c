#include "entreeSortieLC.h"

int main(){

    BiblioH* B;
    B = charger_n_entrees("GdeBiblio.txt", 10);

    inserer_en_tete(B, 42, "LA_VIE", "Richard_ENG");
    inserer_en_tete(B, 56, "LA_VIE", "Richard_ENG");
    inserer_en_tete(B, 77, "TETRIS_POUR_LES_NULLS", "Richard_ENG");
    inserer_en_tete(B, 123, "LA_VIE", "Richard_ENG");
    inserer_en_tete(B, 983, "TETRIS_POUR_LES_NULLS", "Richard_ENG");

    afficher_biblio(B);

    Biblio* B2 = creer_biblio();
    B2->L = recherche_ouvrage(B);

    afficher_biblio(B2);

    liberer_biblio(B);
    liberer_biblio(B2);
 

    return 0;
}