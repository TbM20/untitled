#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"


char checking;
char strings[30];
int years;


int id;
int searching() {
    char* buffer=malloc(50);

    printf("would you like to find the book by title, author or year, (t or a or year):");
    getchar();
    fgets(buffer,50,stdin);
    buffer[strcspn(buffer,"\n")]=0;
    sscanf(buffer,"%c",&checking);


    if (checking == 't') {
        printf("enter the title you want to search by:");

        fgets(buffer,50,stdin);
        buffer[strcspn(buffer,"\n")]=0;
        sscanf(buffer,"%s",strings);

        struct BookArray a=find_book_by_title(strings);
        if (a.length == 0) {
            printf("\nSorry we dont have that books with that title available\n");
        }
        else{
            for(int i=0;i<a.length;i++){
                printf("Author: %s\n",a.array[i].authors);
                printf("Title: %s\n",a.array[i].title);
                printf("ID: %d\n",a.array[i].ID);
                printf("copies: %d\n",a.array[i].copies);
                printf("year: %d\n",a.array[i].year);
            }

        }
    }
    else if (checking == 'a') {
        struct BookArray b;
        printf("enter the author you want to search by:");
        fgets(buffer,50,stdin);
        buffer[strcspn(buffer,"\n")]=0;
        sscanf(buffer,"%s",strings);
        b=find_book_by_author(strings);
        if (b.length == 0) {
            printf("Sorry we dont have that books with that author available\n");
        }
        else{
            for(int i=0;i<b.length;i++){
                printf("Author: %s\n",b.array[i].authors);
                printf("Title: %s\n",b.array[i].title);
                printf("ID: %d\n",b.array[i].ID);
                printf("copies: %d\n",b.array[i].copies);
                printf("year: %d\n",b.array[i].year);
            }

        }
    }
    else if (checking == 'y') {
        struct BookArray c;
        printf("enter the year you want to search by: ");
        scanf("%d", &years);
        c=find_book_by_year(years);
        if (c.length == 0) {
            printf("Sorry we dont have that books with tha year available");
        }
        else{
            for(int i=0;i<c.length;i++){
                printf("\nAuthor: %s",c.array[i].authors);
                printf("\nTitle: %s",c.array[i].title);
                printf("\nID: %d",c.array[i].ID);
                printf("\ncopies: %d",c.array[i].copies);
                printf("\nyear: %d\n",c.array[i].year);
            }

        }

    }
    return 0;
}

 int Borrow(int a)
{

int f=0;
int bookindex=0;
    printf("Please enter the ID of the book you want to Borrow:");
    scanf("%d", &id);

    for(int j=0;j<Bookcollection.length;j++){

        if(id==Bookcollection.array[j].ID){
            bookindex=j;
            f=1;
        }

    }

    if(f==1){
        for (int i = 0; i < userlist[a].currentBorrowed; i++) {
            if (id == userlist[a].IDheld[i]) {
                printf("You already have this book on loan\n");
                return 1;
            }
        }


        if(Bookcollection.array[bookindex].copies>0){
            userlist[a].IDheld[userlist[a].currentBorrowed]= id;
            userlist[a].currentBorrowed = userlist[a].currentBorrowed + 1;
            Bookcollection.array[bookindex].copies=Bookcollection.array[bookindex].copies-1;
            printf("You have borrowed Book of ID:%d\n",id);
        }
        else{
            return 1;
        }
    }
    else {
        printf("Book ID does not exist\n");
        return 1;
    }





    return 0;
}



int returns(int a) {

    printf("enter the id of the book you want to return :");
    scanf("%d", &id);
    int l=0;
    int bookindex=0;
    int userindex=0;
    for(int j=0;j<Bookcollection.length;j++){
        if(id==Bookcollection.array[j].ID){
            bookindex=j;
            l=1;
        }

    }
    for (int i = 0; i < userlist[a].currentBorrowed; i++) {
        if (id == userlist[a].IDheld[i]) {
            userindex = i;
        }
    }
    if(l==1){


            for (int f = userindex; f < userlist[a].currentBorrowed; f++) {
                userlist[a].IDheld[f] = userlist[a].IDheld[f + 1];

            }

            Bookcollection.array[bookindex].copies = Bookcollection.array[bookindex].copies + 1;
            userlist[a].currentBorrowed = userlist[a].currentBorrowed -1;
            printf("Thank you for returning the Book of ID:%d\n",id);


    }
    else {
        printf("This ID doesn't exist or you are not loaning this book ID\n");
        return 1;

    }

    return 0;



}

struct BookArray find_book_by_year(unsigned int year){


    struct BookArray yearCheck;

    int listsize = 0;

    yearCheck.array = (struct Book*) malloc(Bookcollection.length * sizeof(struct Book));

    for (int i = 0; i < Bookcollection.length; i++) {

        if (Bookcollection.array[i].year == year) {
            yearCheck.array[listsize] = Bookcollection.array[i];
            listsize = listsize + 1;
        }
    }
    yearCheck.length = listsize;
    return yearCheck;

}
struct BookArray find_book_by_author(const char* author) {
    struct BookArray authorCheck;
    authorCheck.array = (struct Book*) malloc(Bookcollection.length * sizeof(struct Book));
    int listsize = 0;
    for (int i = 0; i < Bookcollection.length; i++) {

        if (strcmp(Bookcollection.array[i].authors,author)==0) {
            authorCheck.array[listsize] = Bookcollection.array[i];
            listsize = listsize + 1;
        }
    }
    authorCheck.length = listsize;
    return authorCheck;
}
struct BookArray find_book_by_title(const char* title) {


    struct BookArray titleCheck;


    titleCheck.array =(struct Book*) malloc(Bookcollection.length * sizeof(struct Book));
    int listsize = 0;


    for (int i = 0 ;i < Bookcollection.length; i++) {
        printf("%s\n",Bookcollection.array[i].title);
        if (strcmp(Bookcollection.array[i].title, title)==0) {
            titleCheck.array[listsize] = Bookcollection.array[i];
            listsize = listsize + 1;
        }
    }
    titleCheck.length = listsize;
    return titleCheck;
}
