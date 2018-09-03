#include <gtk/gtk.h>
#include "glade.h"

void create_window(GtkBuilder  **buil, GtkWidget       **win, char fenetre[50])
{
    *buil = gtk_builder_new();
    gtk_builder_add_from_file (*buil,"glade/window_main.glade", NULL);
 
    *win = GTK_WIDGET(gtk_builder_get_object(*buil, fenetre));
    gtk_builder_connect_signals(*buil, NULL);
}



void create_tree_view(GtkWidget       **treeview)
{
GtkCellRenderer     *renderer;


renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (*treeview), -1, "Nom", renderer, "text", COL_NOM, NULL);
    

  renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (*treeview), -1, "Prénom", renderer, "text", COL_PRENOM, NULL);
    

    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (*treeview), -1, "Métier", renderer, "text", COL_JOB, NULL);
    


   renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (*treeview), -1, "Pays", renderer, "text", COL_PAYS, NULL);
    
renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (*treeview), -1, "Salaire", renderer, "text", COL_SALAIRE, NULL);

}

