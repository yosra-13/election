#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Election.h"

int x,s;
void
on_rech2_gest_elec_button_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_rech1_gest_elec_button_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_val_ajou_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 
  GtkWidget *id;
  GtkWidget *nom ;
  GtkWidget *nbrh;
  GtkWidget *nbrc;
  GtkWidget *jdate;
  GtkWidget *mdate;
  GtkWidget *adate;

id=lookup_widget(objet_graphique,"id_ajou_elec_entry");
nom=lookup_widget(objet_graphique,"muni_ajou_elec_entry");
nbrh=lookup_widget(objet_graphique,"nbrh_ajou_elec_entry");
nbrc=lookup_widget(objet_graphique,"nbrc_ajou_elec_entry");
jdate=lookup_widget(objet_graphique,"jdate_ajou_elec_entry");
mdate=lookup_widget(objet_graphique,"mdate_ajou_elec_entry");
adate=lookup_widget(objet_graphique,"adate_ajou_elec_entry");
       
          int ver;
          ver=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
         if(existe(ver,"Election.txt")==1)
{
GtkWidget *la;
la=lookup_widget(objet_graphique,"labelajout");
         gtk_label_set_text(GTK_LABEL(la)," cet identifiant existe");
       }
         else
          {

GtkWidget *la;
la=lookup_widget(objet_graphique,"labelajout");
  Election e;
      e.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
      strcpy(e.nom_municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nom)));
      e.nbr_habitant=atoi(gtk_entry_get_text(GTK_ENTRY(nbrh)));
      e.nbr_conseiller=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbrc));
      e.date_debut.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jdate));
      e.date_debut.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mdate));
      e.date_debut.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(adate));
      
ajouter(e,"Election.txt");
      gtk_label_set_text(GTK_LABEL(la),"ajout avec succes");}


       



}


void
on_ann_ajou_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *la;
la=lookup_widget(objet_graphique,"labelajout");
gtk_label_set_text(GTK_LABEL(la),"vous avez annuler l ajout");

}


void
on_ann_modi_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *lm;
lm=lookup_widget(objet_graphique,"labelmodif");
gtk_label_set_text(GTK_LABEL(lm),"vous avez annuler la modification");

}


void
on_val_modi_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *id;
  GtkWidget *nom ;
  GtkWidget *nbrh;
  GtkWidget *nbrc;
  GtkWidget *jdate;
  GtkWidget *mdate;
  GtkWidget *adate;

id=lookup_widget(objet_graphique,"id_modif_elec_entry");
nom=lookup_widget(objet_graphique,"muni_modi_elec_combobox");
nbrh=lookup_widget(objet_graphique,"muni_modi_elec_entry");
nbrc=lookup_widget(objet_graphique,"nbrc_modi_elec_spin");
jdate=lookup_widget(objet_graphique,"jdate_modi_elec_spin");
mdate=lookup_widget(objet_graphique,"mdate_modi_elec_spin");
adate=lookup_widget(objet_graphique,"adate_modi_elec_spin");

/*if((is_empty(id)==0) || (is_empty(nom)==0) || (is_empty(nbrh)==0) || (is_empty(nbrc)==0)
	 || (is_empty(jdate)==0) || (is_empty(mdate)==0)|| (is_empty(adate)==0))
         {
		GtkWidget *lm;
          lm=lookup_widget(objet_graphique,"labelmodif");
          gtk_label_set_text(GTK_LABEL(lm),"Vous devez remplir tous les champs SVP !!");

        }
else
{*/
           int ver;
           ver=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
	if(existe(ver,"Election.txt")!=1)
         {
         GtkWidget *lm;
         lm=lookup_widget(objet_graphique,"labelmodif");
         gtk_label_set_text(GTK_LABEL(lm),"cet identifiant n existe pas");
         }
         else
         {
         Election e1;
         e1.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(e1.nom_municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nom)));
         e1.nbr_habitant=atoi(gtk_entry_get_text(GTK_ENTRY(nbrh)));
         e1.nbr_conseiller=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbrc));
         e1.date_debut.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jdate));
         e1.date_debut.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mdate));
         e1.date_debut.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(adate));
         modifier(e1, "Election.txt");
         GtkWidget *lm;
         lm=lookup_widget(objet_graphique,"labelmodif");
         gtk_label_set_text(GTK_LABEL(lm),"modification avec succes");
         }


}


void
on_conf_supp_elec_button_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
if(x==1)
{ 

         GtkWidget *id;
         GtkWidget *ls;
id=lookup_widget(objet_graphique,"id_supp_election_entry");
         ls=lookup_widget(objet_graphique,"labelsupp");
         id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
          
         if(existe(id,"Election.txt")!=1)
          {
         gtk_label_set_text(GTK_LABEL(ls),"cet identifiant n existe pas");
         }
         
         
         else
         {

          supprimer( id, "Election.txt");
          gtk_label_set_text(GTK_LABEL(ls),"suppression avec succes");

          }
}
else
if(x==2)
{
GtkWidget *ls;
ls=lookup_widget(objet_graphique,"labelsupp");
gtk_label_set_text(GTK_LABEL(ls),"vous avez annuler la suppression");
}
}


void
on_n_supp_elec_button_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_o_supp_elec_button_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_ajout_gest_elec_button_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gest;
GtkWidget*ajout;
gest=lookup_widget(objet_graphique,"gestion_election");
ajout = lookup_widget(objet_graphique,"ajout_election_");
gtk_widget_destroy(gest);
ajout=create_ajout_election_ ();
gtk_widget_show(ajout);
}


void
on_modif_gest_elec_button_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gest,*modif;
gest=lookup_widget(objet_graphique,"gestion_election");
modif = lookup_widget(objet_graphique,"modif_election_");
gtk_widget_destroy(gest);
modif=create_modif_election_ ();
gtk_widget_show(modif);
}


void
on_supp_gest_elec_button_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gest,*supp;
gest=lookup_widget(objet_graphique,"gestion_election");
supp = lookup_widget(objet_graphique,"supprimer_election_");
gtk_widget_destroy(gest);
supp=create_supprimer_election_ ();
gtk_widget_show(supp);
}


void
on_prcd_modif_elec_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gest,*modif;
gest=lookup_widget(objet_graphique,"gestion_election");
modif = lookup_widget(objet_graphique,"modif_election_");
gtk_widget_destroy(modif);
gest=create_gestion_election ();
gtk_widget_show(gest);

}


void
on_prcd_ajout_elec_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gest,*ajout;
gest=lookup_widget(objet_graphique,"gestion_election");
ajout = lookup_widget(objet_graphique,"ajout_election_");
gtk_widget_destroy(ajout);
gest=create_gestion_election ();
gtk_widget_show(gest);
 
}


void
on_prcd_supp_election_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *supp,*recherche;
supp=lookup_widget(objet_graphique,"supprimer_election_");
recherche = lookup_widget(objet_graphique,"gestion_election");
gtk_widget_destroy(supp);
recherche=create_gestion_election ();
gtk_widget_show(recherche);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter Iter;
	int id;
       
       gchar nom[20];
       int nbrh ;
      int nbrc;
int jelc,aelc,melc;		
	Election e;	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
     GtkWidget *treeview1;
        treeview1=lookup_widget(treeview,"treeview1");
	afficher_election(treeview1);
		
		
	
	
}

