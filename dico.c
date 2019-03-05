#include "dico.h"

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}


int choixMot(char* motCache)
{
	int nbMots=0, nbAlea;
	char carLu;
	
	FILE* fichier = NULL;
	
	fichier = fopen("dictionnaire.txt", "r");
	
	while (carLu != EOF)
	{
		carLu = fgetc(fichier);
		if (carLu == '\n') nbMots++;
	}
	
	nbAlea=nombreAleatoire(nbMots);
	
	rewind(fichier);
	
	while(nbAlea>0)
	{
		carLu = fgetc(fichier);
		if (carLu == '\n') nbAlea--;

	}
		
	if (fichier != NULL)
    {
		fgets(motCache,TAILLE_MAX,fichier);

        fclose(fichier); // On ferme le fichier qui a été ouvert
    }
	motCache[strlen(motCache)-1]='\0';

	return 0;
}
