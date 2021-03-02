
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include <stdbool.h>


int LoginSystem(const char *username,const char *password) {
    int i;

    if (strcmp(username, "admin") == 0) {
        if (strcmp(password, "adminpass") == 0) {
            return 61;
        }

    }

    for (i = 0; i < userlist[0].totalUsers; i++) {

        if (strcmp(userlist[i].username, username) == 0) {
            if (strcmp(userlist[i].password, password) == 0) {
                return userlist[i].UserId;
            }
        }
    }
    return 60;
}
