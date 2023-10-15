#include <gtk/gtk.h>

#include "Election.h"

void
on_ajou_gest_elec_button_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rech2_gest_elec_button_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rech1_gest_elec_button_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_val_ajou_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ann_ajou_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ann_modi_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_val_modi_elec_button_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_conf_supp_elec_button_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_n_supp_elec_button_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_o_supp_elec_button_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajout_gest_elec_button_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modif_gest_elec_button_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_gest_elec_button_clicked       (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_prcd_modif_elec_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_prcd_ajout_elec_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_prcd_supp_election_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
