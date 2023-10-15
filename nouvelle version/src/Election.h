#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <gtk/gtk.h>

typedef struct
{
int jj,aa,mm;
}Date;
typedef struct
{
int id;
char nom_municipalite[20];
int nbr_habitant ;
int nbr_conseiller;
Date date_debut;
}Election;

int ajouter(Election e , char filename []);
int modifier( Election nouv, char * filename);
int supprimer(int id, char * filename);
Election chercher(int id, char * filename);
Election chercher1(char nom, char * filename);
Election chercher2(Date date, char * filename);

#endif // ELECTION_H_INCLUDED
