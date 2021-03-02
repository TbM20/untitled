#define _CRT_SECURE_NO_WARNINGS
#pragma warning(supress 6385) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

Users *userlist;
extern struct BookArray Bookcollection;
int load_books(FILE* file) {
	
	
	
	FILE* fp = fopen("Users.txt", "r");
	if (file == NULL) {
		return 8;
	}
	
	
	char onehundred[500];
	char* str;
	
	int totald = 0;
	int i = 0;
	int l = 0;
	int b = 0;;
	fscanf(file,"%d", &Bookcollection.length);
	fscanf(fp, "%d", &b);
	
	Bookcollection.array =(struct Book*) malloc(Bookcollection.length * sizeof(struct BookArray));
	
    
	
	
	
	userlist =(Users*) malloc(b * sizeof(Users));
	userlist[0].totalUsers = b;

	for (int j=0; j < b; j++) {
		userlist[j].username = (char*)malloc(50);
		userlist[j].password = (char*)malloc(50);
		userlist[j].email = (char*)malloc(50);
		userlist[j].name = (char*)malloc(50);

		fscanf(fp, "%s %s %s %s %d", userlist[i].username, userlist[i].password, userlist[i].name, userlist[i].email, &userlist[i].currentBorrowed);

		i = i + 1;
	}


	for(unsigned int a = 0; a < Bookcollection.length; a++){
		Bookcollection.array[a].title = (char*)malloc(50);
		Bookcollection.array[a].authors = (char*)malloc(50);

		fscanf(file, " %s %s %d %d %d", Bookcollection.array[l].title, Bookcollection.array[l].authors, &Bookcollection.array[l].ID, &Bookcollection.array[l].copies, &Bookcollection.array[l].year);
		
		l = l + 1;
	}
	

	fclose(file);
	fclose(fp);
	return 0;
		

	


	
}
int store_books(FILE* file) {
	
	if (file == NULL) {
		return 1;
	}
	
	fprintf(file, "%d", userlist[0].totalUsers);
	unsigned int l;
	for (l = 0; l < Bookcollection.length; l++) {

		fprintf(file, "%d;%d;%s;%s;%d;%d\n", Bookcollection.length,Bookcollection.array[l].title, Bookcollection.array[l].authors, Bookcollection.array[l].ID, Bookcollection.array[l].copies, Bookcollection.array[l].year);

	}
	for (int i = 0; i <userlist[0].totalUsers;i++) {
		int borrowed = userlist[i].currentBorrowed;
		fprintf(file, "%d;%s;%s;%s;%s;%d\n", userlist[0].totalUsers, userlist[i].username, userlist[i].password, userlist[i].name, userlist[i].email, userlist[i].currentBorrowed);
		for (int h = 0; h < borrowed-1; h++) {
			fprintf(file,"%d;",userlist[i].IDheld[h]);
		}
		fprintf(file, "%d;\n",userlist[i].IDheld[borrowed-1]);
	}
	

	
	
	fclose(file);
	return 0;
}