#include "dico.h"

char lireCaractere() 
{ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}

void lireLigne(char* mot)
{	
	int i=0;
	
	while ((mot[i]=getchar()) != '\n')
	{
		toupper(mot[i]);
		i++;
	}
	mot[i]='\0';	
}

int main()
{
	int  i, taille;
	char motCache[TAILLE_MAX];
	int coupsRestants, coups;
	char carLu;
	
	printf("\nBienvenue dans le jeu du pendu !\n\n");
	printf("Tapez 1 si vous voulez le mode 1 joueur et 2 si vous voulez le mode 2 joueurs\n");
	
	carLu = lireCaractere();
	
	if (carLu == '2')	
	{
		printf("\nMode 2 joueurs : tapez le mot caché\n");
		lireLigne(motCache);
	}
		
	else choixMot(motCache);
	
	taille=strlen(motCache);
		
	char motActuel[TAILLE_MAX];
	for (i=0;i<taille;i++)
	{
		motActuel[i] = '*';
	}
	motActuel[taille]='\0';
	
	char dif[TAILLE_MAX];
	printf("\nDifficulté (tapez le nombre de coups pour trouver le mot)\n");
	lireLigne(dif);
	
	coupsRestants= strtol(dif, NULL, 10);
	coups = coupsRestants;

	printf("\n\n\nNombre de coups : %d \n\n", coupsRestants);
	
	while (coupsRestants > 0)
	{
	
		printf("\nQuel est le mot secret ? %s\n", motActuel);
		printf("Il vous reste %d coups a jouer\n", coupsRestants);

		printf("\nProposez une lettre : (ou appuyez sur 1 pour quitter)\n");
		
		carLu=lireCaractere();
		
		if (carLu != '1')
		{		
			for (i=0; i<strlen(motCache);i++)
			{

				if (motCache[i] == carLu)
				{
					motActuel[i] = carLu;
				}
			}				

			coupsRestants--;
			
			if (strcmp(motActuel,motCache)==0)
			{
				printf("\n%s\nBravo, vous avez gagné en %d coups!\n\n",motCache,coups-coupsRestants);
				coupsRestants = 0;			
			}
			
			else if (coupsRestants==0) printf("\n\nVous avez perdu!\nLe mot était %s\n\n",motCache);
		}
		
		else coupsRestants=0;
		
	}
	
	return 0;
}
