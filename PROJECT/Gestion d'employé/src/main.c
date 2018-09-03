#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "CRUD.h"
#include "glade.h"



FILE* f;
FILE* INFILE; 
FILE* OUTFILE;


GtkWidget   *treeview;
GtkCellRenderer     *renderer;
//widget to login
GtkWidget *g_entry1, *g_entry2, *g_label3;
//widget to ajouter
GtkWidget *g_entry3, *g_entry4, *g_entry5, *g_entry10, *g_entry11, *g_label10;

//widget to mofifier
GtkWidget *g_searchentry1, *g_entry6, *g_entry7, *g_entry8, *g_entry12, *g_entry13, *g_label16, *g_label22;
//widhet to supp
GtkWidget *g_entry9, *g_label19;



GtkBuilder      *builder, *builder1, *builder2; 
GtkWidget       *window, *window1, *window2;

 
int main(int argc, char *argv[])
{
 
    gtk_init(&argc, &argv);
    //first window(login) 
    create_window(&builder,&window,"window_main");
   
    g_entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    g_entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    g_label3 = GTK_WIDGET(gtk_builder_get_object(builder, "label3"));

 
    g_object_unref(builder);
    gtk_widget_show(window);   
 
    //SECOND WINDOW
    create_window(&builder1,&window1,"window1");
        // ajouter
    g_entry3 = GTK_WIDGET(gtk_builder_get_object(builder1, "entry3"));
    g_entry4 = GTK_WIDGET(gtk_builder_get_object(builder1, "entry4"));
    g_entry5 = GTK_WIDGET(gtk_builder_get_object(builder1, "entry5"));
    g_entry10 = GTK_WIDGET(gtk_builder_get_object(builder1, "entry10"));
    g_entry11 = GTK_WIDGET(gtk_builder_get_object(builder1, "entry11"));
    g_label10 = GTK_WIDGET(gtk_builder_get_object(builder1, "label10"));
        // recherche
     g_searchentry1 = GTK_WIDGET(gtk_builder_get_object(builder1, "searchentry1"));
     g_label16 = GTK_WIDGET(gtk_builder_get_object(builder1, "label16"));
        // supprimer
    g_entry9 = GTK_WIDGET(gtk_builder_get_object(builder1, "entry9"));
    g_label19 = GTK_WIDGET(gtk_builder_get_object(builder1, "label19"));
  

  
 treeview =  GTK_WIDGET(gtk_builder_get_object(builder1, "treeview"));
 create_tree_view(&treeview);
   
    g_object_unref(builder1);
    gtk_widget_hide(window1); 



//MODIFIER WINDOW
create_window(&builder2,&window2,"window2");
       // modifier
    g_entry6 = GTK_WIDGET(gtk_builder_get_object(builder2, "entry6"));
    g_entry7 = GTK_WIDGET(gtk_builder_get_object(builder2, "entry7"));
    g_entry8 = GTK_WIDGET(gtk_builder_get_object(builder2, "entry8"));
    g_entry12 = GTK_WIDGET(gtk_builder_get_object(builder2, "entry12"));
    g_entry13 = GTK_WIDGET(gtk_builder_get_object(builder2, "entry13"));
    g_label22 = GTK_WIDGET(gtk_builder_get_object(builder2, "label22"));
  

    
    g_object_unref(builder2);
    gtk_widget_hide(window2);             
   
 gtk_main();
    
 
 
    return 0;
}




// called when button login is clicked
void on_login_clicked()
{
    char user[40], pass[40];
    int i;
    strcpy(user,gtk_entry_get_text(GTK_ENTRY(g_entry1)));
    strcpy(pass,gtk_entry_get_text(GTK_ENTRY(g_entry2)));
    i=loger(user,pass);
    if (i==0){
    gtk_label_set_text(GTK_LABEL(g_label3),"USERNAME or PASSWORD invalide !" );}
    else{
    gtk_widget_show(window1);
    gtk_widget_hide(window);
}

}

// called when button ajouter is clicked
void on_ajouter_clicked()
{

USER u;
char vide[40]={0};

    
    
    strcpy(u.name,gtk_entry_get_text(GTK_ENTRY(g_entry3)));
    strcpy(u.last_name,gtk_entry_get_text(GTK_ENTRY(g_entry4)));
    strcpy(u.job,gtk_entry_get_text(GTK_ENTRY(g_entry5)));
    strcpy(u.pays,gtk_entry_get_text(GTK_ENTRY(g_entry11)));
    strcpy(u.salaire,gtk_entry_get_text(GTK_ENTRY(g_entry10)));
    
    
    strcpy(u.username,u.name);
    strcat(u.username,".");
    strcat(u.username,u.last_name);

    

if (!checker(u.name) || !checker(u.last_name) || !checker(u.job) || !checker(u.pays) || !strcmp(u.salaire,vide) || verif_num(u.salaire)==0 )
{ gtk_label_set_text(GTK_LABEL(g_label10),"Opération échoué !");
    }
  else if (recherche(u.username)==1)
{
       gtk_label_set_text(GTK_LABEL(g_label10),"Cet employé existe dejà  !");}
         
    else{
    ajouter(u);
    
gtk_label_set_text(GTK_LABEL(g_label10),"Données ajoutées");}
  

}


// called when window_main is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

// called when window1 is closed
void on_window1_destroy()
{
    gtk_widget_show(window);
    gtk_widget_hide(window1);
}
// called when window2 is closed
void on_window2_destroy()
{
    gtk_widget_hide(window2);
}





// called when recherche is clicked

void on_RECHERCHER_clicked()
{   
   char username[40];
   USER l;
   strcpy(username,gtk_entry_get_text(GTK_ENTRY(g_searchentry1)));
   if (recherche(username)==0) 
        gtk_label_set_text(GTK_LABEL(g_label16),"Employé n'existe pas !");
   else{
        f=fopen("/home/wassim/Documents/LOGIN/USERS.txt","r");
	while( fscanf(f, "%s %s %s %s %s %s\n",l.name, l.last_name, l.username, l.job, l.pays, l.salaire)!=EOF)
        { if (strcmp(username,l.username)==0)
                break;}
        gtk_widget_show(window2);
        gtk_entry_set_text(GTK_ENTRY(g_entry6),l.name);
        gtk_entry_set_text(GTK_ENTRY(g_entry7),l.last_name);
        gtk_entry_set_text(GTK_ENTRY(g_entry8),l.job);
        gtk_entry_set_text(GTK_ENTRY(g_entry12),l.pays);
        gtk_entry_set_text(GTK_ENTRY(g_entry13),l.salaire);
        
}
}
        
//called when modifier is clicked
void on_MODIFIER_clicked()
{
    USER l;
    char vide[40]={0};
    char username[40];
     strcpy(username,gtk_entry_get_text(GTK_ENTRY(g_searchentry1)));

     strcpy(l.name,gtk_entry_get_text(GTK_ENTRY(g_entry6)));
     strcpy(l.last_name,gtk_entry_get_text(GTK_ENTRY(g_entry7)));
     strcpy(l.job,gtk_entry_get_text(GTK_ENTRY(g_entry8)));
     strcpy(l.pays,gtk_entry_get_text(GTK_ENTRY(g_entry12)));
     strcpy(l.salaire,gtk_entry_get_text(GTK_ENTRY(g_entry13)));

    strcpy(l.username,l.name);
    strcat(l.username,".");
    strcat(l.username,l.last_name);
    DELETE(username);
    
    if (!checker(l.name) || !checker(l.last_name) || !checker(l.job) || !checker(l.pays) || !strcmp(l.salaire,vide) || verif_num(l.salaire)==0 )
{ gtk_label_set_text(GTK_LABEL(g_label22),"Opération échouée !");
    }
  else if (recherche(l.username)==1)
{
       gtk_label_set_text(GTK_LABEL(g_label22),"Cet employé existe déjà !");}
         
    else{
    ajouter(l);
    gtk_widget_hide(window2);
    
    
gtk_label_set_text(GTK_LABEL(g_label16),"Employé modifié");}
  

}
    
    
void on_DELETE_clicked()
{
   char username[40];
   strcpy(username,gtk_entry_get_text(GTK_ENTRY(g_entry9)));
   if ( recherche(username)==1 ){
      DELETE(username);
      gtk_label_set_text(GTK_LABEL(g_label19),"Employé supprimé");}
   else
      gtk_label_set_text(GTK_LABEL(g_label19),"Cet employé n'existe pas !");
}



void on_ACTUALISER_pressed()
{
 
  char ch1[70];
  char ch2[70];
  char ch3[70];
  char ch4[70];
  char ch5[70];
  char ch[70];


  FILE *f;
  

    GtkListStore  *store;
    GtkTreeIter    iter;
    
  
 
store = gtk_list_store_new (NUM_COLS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ) ;

f = fopen("USERS.txt", "r");

   
    while(fscanf(f,"%s %s %s %s %s %s\n",ch1,ch2,ch,ch3,ch4,ch5)!=EOF)
    {
      gtk_list_store_append (store, &iter);
     gtk_list_store_set (store, &iter,COL_PRENOM,ch1,COL_NOM,ch2,COL_JOB,ch3,COL_PAYS,ch4,COL_SALAIRE,ch5,-1);
    }
fclose(f);
    
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
  g_object_unref (store);

}


  
void on_trie_clicked()
{
	int x,max=0;
	USER l,u;
	INFILE=fopen("USERS.txt","r");
	OUTFILE=fopen("USERS_TRIE.txt", "w");
        while(!feof(INFILE))
	{
	while((fscanf(INFILE, "%s %s %s %s %s %s\n",l.name, l.last_name, l.username, l.job, l.pays, l.salaire)!=EOF))
	{
	x=atoi(l.salaire);
	if (x>max)
	{
		strcpy(u.name,l.name);
		strcpy(u.last_name,l.last_name);
		strcpy(u.username,l.username);
		strcpy(u.job,l.job);
		strcpy(u.pays,l.pays);
		strcpy(u.salaire,l.salaire);
		max=x;
		}
	}
		
	    fprintf(OUTFILE, "%s %s %s %s %s %s\n",u.name, u.last_name, u.username, u.job, u.pays, u.salaire);
            fclose(INFILE);
	    DELETE(l.username);
	    INFILE=fopen("USERS.txt","r");
	}
			
		
	
	fclose(INFILE);
	fclose(OUTFILE);
  
  char ch1[70];
  char ch2[70];
  char ch3[70];
  char ch4[70];
  char ch5[70];
  char ch[70];


  

    GtkListStore  *store;
    GtkTreeIter    iter;
    
  
 
store = gtk_list_store_new (NUM_COLS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ) ;

f = fopen("USERS_TRIE.txt", "r");

   
    while(fscanf(f,"%s %s %s %s %s %s\n",ch1,ch2,ch,ch3,ch4,ch5)!=EOF)
    {
      gtk_list_store_append (store, &iter);
     gtk_list_store_set (store, &iter,COL_PRENOM,ch1,COL_NOM,ch2,COL_JOB,ch3,COL_PAYS,ch4,COL_SALAIRE,ch5,-1);
    }
fclose(f);
    
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
  g_object_unref (store);
	
}
     
    
    
     
     
  
	





 
