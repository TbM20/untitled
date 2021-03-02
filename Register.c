#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

Users* userlist;
int RegisterSystem(const char *username,const char* password,const char* name,const char* emails,int usernumber) {
    userlist = (Users*)realloc(userlist, usernumber* sizeof(Users));
    userlist[usernumber].username = (char*)malloc(50);
    userlist[usernumber].password = (char*)malloc(50);
    userlist[usernumber].email = (char*)malloc(50);
    userlist[usernumber].name = (char*)malloc(50);



    int new=0;

    for(int i=0;i<30;i++){
        if(emails[i]=='@'){
            new = new+1;
            i=29;
        }
    }
if(new==1){
    strcpy(userlist[usernumber].email,emails);
    strcpy(userlist[usernumber].password,password);
    strcpy(userlist[usernumber].name,name);
    strcpy(userlist[usernumber].username, username);
    userlist[usernumber].UserId=usernumber;
    userlist[usernumber].currentBorrowed=0;



}else {
    return 1;
}
    return 0;
}







