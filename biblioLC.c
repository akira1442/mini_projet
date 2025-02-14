#include "biblioLC.h" 


Livre* creer_livre(int num,char* titre,char* auteur){

	Livre* nouv = (Livre*)malloc(sizeof(Livre));

	nouv->num=num;
	nouv->titre=strdup(titre);
	nouv->auteur=strdup(auteur);
	nouv->suiv = NULL;

	return nouv;
}

void liberer_livre(Livre* l){
	free(l->titre);
	free(l->auteur);
	free(l);
}

Biblio* creer_biblio(){
	Biblio* b = (Biblio*)malloc(sizeof(Biblio));
	b->L = NULL;
	return b;
}

void liberer_biblio(Biblio* b){
	
	Livre* tmp = b->L;

	while(tmp){
		b->L = b->L->suiv;
		liberer_livre(tmp);
		tmp = b->L;
	}
	free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){

	Livre* new_livre = creer_livre(num, titre, auteur);
	
	if (b->L == NULL){
		b->L=new_livre;
	}else{
		new_livre->suiv = b->L;
		b->L = new_livre;
	}
}

void affiche_livre(Livre* l){

	Livre* liste = l;

	while (liste != NULL){
		printf("%d %s %s\n", liste->num, liste->auteur, liste->titre);
		liste = liste->suiv;
	}
}

void fusion(Biblio** b1, Biblio* b2){

	Livre* tmp = b2->L;

	// Ajout de b2 en tête de b1 
	// b2 est ajouté a l'en vers
	while (tmp){
		inserer_en_tete(*b1, tmp->num, tmp->titre, tmp->auteur);
		tmp = tmp->suiv;
	}

	liberer_biblio(b2);
	//return b1;
}

Livre* recherche_doublons(Biblio* b){

	Livre* liste = b->L;
	Livre* res_L = NULL;
	Livre* doublon = NULL;

	while (liste){
		doublon = recherche_Livre_auteur(b, liste->auteur)->L;
		while (doublon){
			res_L = (Livre*)malloc(sizeof(Livre));
			if (strcmp(liste->titre, doublon->titre) && strcmp(liste->auteur, doublon->auteur)){
				res_L->titre = strdup(doublon->titre);
				res_L->auteur = strdub(doublon->auteur);
				res_L->num = doublon->num;
				res_L->suiv = NULL;
				res_L = res_L->suiv;
			}	
		}
	}

}
