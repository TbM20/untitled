#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

Users* userlist;
int LoginSystem(char* username, char* password) {
	

	if (strcmp(username, "admin") == 0) {
		if (strcmp(password, "adminpass") == 0) {
			return 2;
		}

	}
	for (int i = 0; i < userlist[0].totalUsers ;i++) {
		if (strcmp(userlist[i].username,username)==0) {
			if (strcmp(userlist[i].password, password) == 0) {
				return 1;
			}
		}
	}


	return 0;
}