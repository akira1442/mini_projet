#include "biblioH.h"

int fonctionClef(char* auteur){
	int sum = 0;	
	int i = 0;
	while (auteur[i] != '\0') {
        	sum+=auteur[i];
        	i++;
        }
    return sum;
}

LivreH* creer_livre(int num, char* titre, char* auteur){



}










void main(){
	char* nom= "A";
	printf("CLE = %d\n",fonctionClef(nom) );
}
