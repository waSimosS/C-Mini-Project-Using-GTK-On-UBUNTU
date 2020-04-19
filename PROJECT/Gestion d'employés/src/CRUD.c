#include "CRUD.h"
#include <stdio.h>
#include<string.h>
#include<ctype.h>



FILE *f;
FILE *INFILE, *OUTFILE;




//verif login and pass
int loger(char user[40], char pass[40])
{
	char login[40],password[40];
	f=fopen("login.txt","r");
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s\n",login,password)!=EOF)
			{
			if ((strcmp(user,login)==0)&& (strcmp(pass,password)==0))
			return 1;
			}
	}
	return 0;
}

void ajouter(USER u)
{
	f=fopen("USERS.txt","a");
	fprintf(f, "%s %s %s %s %s %s\n",u.name, u.last_name, u.username, u.job, u.pays, u.salaire);
	fclose(f);
        

}



int verif_num(char R[4])
{
	int i;
	for(i=0;i<strlen(R);i++)
	{
	if (isdigit(R[i])==0)
	return 0;
	}
return 1;
}

int verif_alpha(char test[50])
{
	int i;
        for(i=0;i<strlen(test);i++)
	{
	if ((isalpha(test[i]))==0)
	return 0;
	}
return 1;
}
int verif_alpha(char*);

int checker(char test1[50])
{
	
	char vide[50]={0};

	if ( (verif_alpha(test1)!=0) && (strcmp(test1,vide)!=0) )
		return 1;
	return 0;
}
	


int recherche(char username[40])
{
        USER l;
        f=fopen("USERS.txt","r");
	while( fscanf(f, "%s %s %s %s %s %s\n",l.name, l.last_name, l.username, l.job, l.pays, l.salaire)!=EOF)
        { if (strcmp(username,l.username)==0)
                {return 1;}
        }
        return 0;
	fclose(f);
}

void DELETE(char username[40])
{
	
        USER l;

	INFILE=fopen("USERS.txt","r");
	OUTFILE=fopen("tempon1.txt", "w");
	while((fscanf(INFILE, "%s %s %s %s %s %s\n",l.name, l.last_name, l.username, l.job, l.pays, l.salaire)!=EOF))
	{
	if (strcmp(username,l.username)!=0)
		{
		if (OUTFILE!=NULL)
			{
			fprintf(OUTFILE, "%s %s %s %s %s %s\n",l.name, l.last_name, l.username, l.job, l.pays, l.salaire);
			}
		}
	}
	fclose(INFILE);
	fclose(OUTFILE);
	remove("USERS.txt");
	rename("tempon1.txt","USERS.txt");
	
}





