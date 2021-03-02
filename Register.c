#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

Users* userlist;
int RegisterSystem(char* username, char* password, char* name, char* emails,int usernumber) {
	userlist = malloc(sizeof(Users));
	char newEmail[30];
	strcpy_s(newEmail,30,emails);
	 
	while(strstr(newEmail,"@")==NULL) {
		printf("please renter email with the @ symbol: ");
		scanf_s(" %s", &newEmail,30);

	}
	
	strcpy_s(userlist[userlist[0].totalUsers].email, 30,newEmail);
	strcpy_s(userlist[userlist[0].totalUsers].password, 50, password);
	strcpy_s(userlist[userlist[0].totalUsers].name, 50, name);
	strcpy_s(userlist[userlist[0].totalUsers].username, 50,username);
	userlist[0].totalUsers=+1;
	
	
	
	
	
	return 0;
}