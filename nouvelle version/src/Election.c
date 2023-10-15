#include "Election.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<gtk/gtk.h>

enum
{    
       
          ID,
          NOM,
          NBRH,
          NBRC,
          JELC,
          MELC,
          AELC,
          COLUMNS
};



int ajouter(Election e , char filename [])
{
  
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
 {
        fprintf(f,"%d %s %d %d %d %d %d\n",e.id,e.nom_municipalite,e.nbr_habitant,e.nbr_conseiller,e.date_debut.jj,e.date_debut.mm,e.date_debut.aa);
        fclose(f);
        return 1;
    }

else 
return 0;
  
}



int existe(int idt,char filename[])
 {
FILE *f=fopen(filename,"r");
int find=0;
Election e; 
if(f!=NULL)
{
while (fscanf(f,"%d %s %d %d %d %d %d\n",&e.id,e.nom_municipalite,&e.nbr_habitant,&e.nbr_conseiller,&e.date_debut.jj,&e.date_debut.mm,&e.date_debut.aa)!=EOF)
{
if(e.id==idt)
find=1;
}
}

return find;
}

int is_empty(GtkWidget *entry)
{
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}


int modifier(Election nouv, char * filename)
{
Election e;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else

   {
while(fscanf(f,"%d %s %d %d %d %d %d\n",&e.id,e.nom_municipalite,&e.nbr_habitant,&e.nbr_conseiller,&e.date_debut.jj,&e.date_debut.mm,&e.date_debut.aa)!=EOF)
{
if(e.id!=nouv.id)
        fprintf(f2,"%d %s %d %d %d %d %d\n",e.id,e.nom_municipalite,e.nbr_habitant,e.nbr_conseiller,e.date_debut.jj,e.date_debut.mm,e.date_debut.aa);
else

  fprintf(f2,"%d %s %d %d %d %d %d\n",nouv.id,nouv.nom_municipalite,nouv.nbr_habitant,nouv.nbr_conseiller,nouv.date_debut.jj,nouv.date_debut.mm,nouv.date_debut.aa);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

int supprimer(int id, char * filename)
{
Election e;
int s=0;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %d %d %d %d %d\n",&e.id,e.nom_municipalite,&e.nbr_habitant,&e.nbr_conseiller,&e.date_debut.jj,&e.date_debut.mm,&e.date_debut.aa)!=EOF)
{
if(e.id!=id)
        fprintf(f2,"%d %s %d %d %d %d %d\n",e.id,e.nom_municipalite,e.nbr_habitant,e.nbr_conseiller,e.date_debut.jj,e.date_debut.mm,e.date_debut.aa);
}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
 
        return 1;
    }
}
Election chercher(int id, char * filename)
{
Election e; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %d %d %d %d %d\n",&e.id,e.nom_municipalite,&e.nbr_habitant,&e.nbr_conseiller,&e.date_debut.jj,&e.date_debut.mm,&e.date_debut.aa)!=EOF && tr==0)
{if(e.id==id)
tr=1;
}
}
if(tr==0)
e.id=-1;
return e;
}


Election chercher1(char nom, char * filename)
{
Election e; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %d %d %d %d %d\n",&e.id,e.nom_municipalite,&e.nbr_habitant,&e.nbr_conseiller,&e.date_debut.jj,&e.date_debut.mm,&e.date_debut.aa)!=EOF && tr==0)
{if(strcmp(e.nom_municipalite,nom)==0)
tr=1;
}
}
if(tr==0)
e.nom_municipalite =="-1";
return e;
}

void afficher_election(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Election e ;
Date d;


  int id;
char nom[20];
int nbrh ;
int nbrc;
int jelc,aelc,melc;
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("id ",renderer,"text",ID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom ",renderer,"text",NOM,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

       renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nbrh",renderer,"text",NBRH,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nbrc",renderer,"text",NBRC,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jelc",renderer,"text",JELC,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("melc",renderer,"text",MELC,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("aelc",renderer,"text",AELC,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



    }
store = gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);


   
    f = fopen("Election.txt","r");
if(f == NULL){
        return 0;
    }
else
{

        while(fscanf(f,"%d %s %d %d %d %d %d\n",&id,nom,&nbrh,&nbrc,&jelc,&melc,&aelc))
{
sprintf(id,"%d",e.id);
sprintf(nom,"%s",e.nom_municipalite);
sprintf(nbrh,"%d",e.nbr_habitant);
sprintf(nbrc,"%d",e.nbr_conseiller);
sprintf(jelc,"%d",e.date_debut.jj);
sprintf(melc,"%d",e.date_debut.mm);
sprintf(aelc,"%d",e.date_debut.aa);
}
gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,ID,id,NOM,nom,NBRH,nbrh,NBRC,nbrc,JELC,jelc,MELC,melc,AELC,aelc,-1);
           
      
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
        fclose(f); 



}
}

