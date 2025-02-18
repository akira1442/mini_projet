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
	printf("%d %s %s\n", l->num, l->auteur, l->titre);	
	
}

void afficher_biblio(Biblio* b){	
	Livre* temp = b ->L;
	while (temp){
		affiche_livre(temp);
		temp=temp->suiv;
	}
}

Livre* recherche_Livre_num(Biblio* b, int num){
	Livre* temp = li;
	while (temp){
		if(temp->num == num){return temp;}
		temp=temp->suiv;
	}
	return NULL;
}

Livre* recherche_Livre_titre(Biblio* b, char titre){
	Livre* temp = li;
	while (temp){
		if(strcmp(temp->titre, &titre)){return temp;}
		temp=temp->suiv;
	}
	return NULL;
}

Biblio* recherche_Livre_auteur(Biblio* b, char* auteur){
	Livre* temp = b -> L;
	Biblio* biblio_aut=creer_biblio();
	while(temp){
		if (strcmp(temp->auteur, auteur)){
			inserer_en_tete(biblio_aut, temp->num, temp->titre, temp->auteur);
		}
		temp=temp->suiv;
	}
	return biblio_aut;
}

void supprime_Livre(Biblio* b, int num, char* auteur, char* titre){
	Livre* temp = b -> L;
	Livre* temp2 = b->L->suiv;
	while(temp){
		if (temp2->num == num && temp2->auteur == auteur && temp2->titre == titre){
			temp->suiv = temp2->suiv;
			liberer_livre(temp2);
			break;
		}
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
}

/*Livre* recherche_doublons(Biblio* b){

	Livre* liste = b->L;
	Livre* res_L = NULL;
	Livre* doublon = NULL;

	while (liste){
		doublon = recherche_Livre_auteur(b, liste->auteur)->L;
		while (doublon){
			res_L = (Livre*)malloc(sizeof(Livre));
			if (strcmp(liste->titre, doublon->titre) && strcmp(liste->auteur, doublon->auteur)){
				res_L->titre = strdup(doublon->titre);
				res_L->auteur = strdup(doublon->auteur);
				res_L->num = doublon->num;
				res_L->suiv = NULL;
				res_L = res_L->suiv;
			}	
		}
	}
	return NULL;
}*/

