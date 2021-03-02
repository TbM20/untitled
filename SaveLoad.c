#define _CRT_SECURE_NO_WARNINGS
#pragma warning(supress 6385)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

Users *userlist;

int load_books(FILE* file) {




    if (file == NULL) {
        return 8;
    }


    Bookcollection.array =(struct Book*) malloc(1 * sizeof(struct Book));
    Bookcollection.array[0].title = (char*)malloc(50);
    Bookcollection.array[0].authors = (char*)malloc(50);

    char d[50];
    char * ptr[500];
    char *year[20];
    char *id[20];
    char *copiess[20];
    char*ptrs;
    fgets((char *)ptr,500,file);

    sscanf((const char*)ptr,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]",d,Bookcollection.array[0].title,Bookcollection.array[0].authors, year, id,
            copiess);
    Bookcollection.length=strtol(d,&ptrs,10);
    Bookcollection.array[0].year=strtol((const char*)year,&ptrs,10);
    Bookcollection.array[0].ID=strtol((const char*)id,&ptrs,10);
    Bookcollection.array[0].copies=strtol((const char*)copiess,&ptrs,10);


    for(unsigned int a = 1; a < Bookcollection.length; a++){
        Bookcollection.array =realloc ( Bookcollection.array,sizeof(struct Book)*Bookcollection.length);
        Bookcollection.array[a].title = (char*)malloc(50);
        Bookcollection.array[a].authors = (char*)malloc(50);

        fgets((char *)ptr,500,file);
        sscanf((const char*)ptr,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]",d,Bookcollection.array[a].title, Bookcollection.array[a].authors,year,
              id,
               copiess);
        Bookcollection.length=strtol(d,&ptrs,10);
        Bookcollection.array[a].year=strtol((const char*)year,&ptrs,10);
        Bookcollection.array[a].ID=strtol((const char*)id,&ptrs,10);
        Bookcollection.array[a].copies=strtol((const char*)copiess,&ptrs,10);


    }
    fclose(file);



return 0;
}
int load_users(FILE* file,FILE*files) {
    int b=0;

    if (file == NULL) {
        return 8;
    }


    userlist =(Users*) malloc(1 * sizeof(Users));
    userlist[0].username = (char*)malloc(50);
    userlist[0].password = (char*)malloc(50);
    userlist[0].email = (char*)malloc(50);
    userlist[0].name = (char*)malloc(50);
    char *ptr[500];
    char *totalr[20];
    char *cb[20];
    char *ui[20];
    char*ptrs;
    fgets((char *)ptr,500,file);

        sscanf((const char*)ptr,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]",totalr,userlist[0].username, userlist[0].password, userlist[0].name,
               userlist[b].email, cb,ui);




    userlist[0].totalUsers=strtol((const char*)totalr,&ptrs,10);
    userlist[0].currentBorrowed=strtol((const char*)cb,&ptrs,10);
    userlist[0].UserId=strtol((const char*)ui,&ptrs,10);



        for(int b=0;b<userlist[0].currentBorrowed;b++){
            fgets(ptr,500,files);
            sscanf(ptr,"%i",&userlist[0].IDheld[b]);
        }







    for (int j=1; j < userlist[0].totalUsers; j++) {

        userlist =realloc(userlist,userlist[0].totalUsers * sizeof(Users));
        userlist[j].username = (char*)malloc(50);
        userlist[j].password = (char*)malloc(50);
        userlist[j].email = (char*)malloc(50);
        userlist[j].name = (char*)malloc(50);
        userlist[j].currentBorrowed = malloc(sizeof(int));
        userlist[j].UserId=malloc(sizeof(int));

        fgets((char *)ptr,500,file);

        sscanf((const char*)ptr,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]",totalr,userlist[j].username, userlist[j].password, userlist[j].name,
               userlist[j].email, cb,ui);
        userlist[j].totalUsers=strtol((const char*)totalr,&ptrs,10);
        userlist[j].currentBorrowed=strtol((const char*)cb,&ptrs,10);
        userlist[j].UserId=strtol((const char*)ui,&ptrs,10);

        for(int b=0;b<userlist[j].currentBorrowed;b++){
            fgets(ptr,500,files);
            sscanf(ptr,"%i",&userlist[j].IDheld[b]);
        }



    }






    fclose(file);

    return 0;
}
int store_books(FILE* file) {

    if (file == NULL) {
        return 1;
    }


    unsigned int l;
    for (l = 0; l < Bookcollection.length; l++) {

        fprintf(file, "%d;%s;%s;%i;%u;%u;\n",Bookcollection.length,Bookcollection.array[l].title, Bookcollection.array[l].authors,Bookcollection.array[l].year,
                Bookcollection.array[l].ID,
                Bookcollection.array[l].copies);

    }


}
int store_users(FILE* files) {

        if (files == NULL) {
            return 1;
        }




        for (int i = 0; i < userlist[0].totalUsers;i++) {
            fprintf(files, "%i;%s;%s;%s;%s;%i;%i;\n",userlist[0].totalUsers, userlist[i].username, userlist[i].password, userlist[i].name, userlist[i].email,
                    userlist[i].currentBorrowed,userlist[i].UserId);
        }



    fclose(files);
    return 0;
}
int store_loans_record(FILE*files){
    if (files == NULL) {
        return 1;
    }
for(int i=0;i<userlist[0].totalUsers;i++){
    for(int j=0;j<userlist[i].currentBorrowed;j++){
        fprintf(files,"%i;\n",userlist[i].IDheld[j]);
    }
}
fclose(files);
return 0;
}
