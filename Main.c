#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include <stdbool.h>

Users* userlist;

int  main(int argc, char* argv[])
{
    FILE* file; FILE* files;FILE* filess;
    file= fopen("../libraries.txt","r");
    load_books(file);
    files= fopen("../Users.txt","r");
    filess= fopen("../loans.txt","r");
    load_users(files,filess);






    char usr_input;
    char  username[30];
    char password[30];
    char  name[30];
    char emailAddress[30];
    char* buffer=malloc(50);
    bool exits = false;
    bool log_out = false;
    while (exits==false) {
        log_out = false;
        printf("1.Do you want to Login\n");
        printf("2.Do you want to Register\n");
        printf("3.Do you want to search for books\n");
        printf("4.Do you want to display all books\n");
        printf("5.Quit\n");
        scanf("%c",&usr_input);
        if (usr_input == '1') {
            printf("Please enter a username:");
            getchar();
            fgets(buffer,50,stdin);
            buffer[strcspn(buffer,"\n")]=0;
            sscanf(buffer,"%s",username);
            printf("Please enter a password:");
            fgets(buffer,50,stdin);
            buffer[strcspn(buffer,"\n")]=0;
            sscanf(buffer,"%s",password);
            int a=LoginSystem(username, password);
            if (a == 60) {
                printf("You are not registered you need to register!\n");
                }
            else if (a == 61) {
                while(log_out==false){
                    printf("hello librarian what would you like to do?(remove or add books or log out)(r/a/any character): ");
                    scanf(" %c", &usr_input);

                    if (usr_input == 'a') {

                        struct Book abook;
                        int years;
                        int id;
                        int copies;
                        char correctinput[30];
                        char titleinput[30];
                        bool unique = false;
                        abook.title = malloc(50);
                        abook.authors = malloc(50);
                        printf("please enter the title of book you would like to add:\n");
                        getchar();
                        fgets(buffer,50,stdin);
                        buffer[strcspn(buffer,"\n")]=0;
                        strcpy(titleinput,buffer);
                        abook.title = titleinput;
                        printf("please enter the author of book you would like to add:\n");

                        fgets(buffer,50,stdin);
                        buffer[strcspn(buffer,"\n")]=0;
                        strcpy(correctinput,buffer);
                        abook.authors = correctinput;
                        printf("please enter the year of book you would like to add:\n");
                        scanf("%d", &years);
                        abook.year = years;

                        printf("please enter the ID of book you would like to add:\n");
                        scanf("%d", &id);

                        while(unique==false){
                            int g=0;
                            for(int k=0;k<Bookcollection.length;k++){
                                if(id==Bookcollection.array[k].ID){

                                    g=1;
                                }

                            }

                            if(g!=1){

                                break;
                            }
                            printf("please enter the ID of book you would like to add:\n");
                            scanf("%d", &id);
                        }
                        abook.ID = id;
                        printf("please enter the copies of book you would like to add:\n");
                        scanf("%d", &copies);
                        abook.copies = copies;
                        if(add_book(abook)==0){
                            printf("You have added a book!\n");
                        }

                    }
                    else if(usr_input == 'r') {

                        int id = 0;
                        struct Book rbook;
                        rbook.title = malloc(1 * sizeof(struct Book));
                        rbook.authors = malloc(1 * sizeof(struct Book));

                        printf("please enter the Id of teh book you are trying to remove\n");
                        getchar();
                        fgets(buffer,50,stdin);
                        buffer[strcspn(buffer,"\n")]=0;
                        sscanf(buffer,"%d",&id);
                        for(int i=0;i<Bookcollection.length;i++){
                            if(Bookcollection.array[i].ID==id){
                                rbook.ID=Bookcollection.array[i].ID;
                                rbook.title=Bookcollection.array[i].title;
                                rbook.authors=Bookcollection.array[i].authors;
                                rbook.year=Bookcollection.array[i].year;
                                if(remove_book(rbook)==0){
                                    printf("You have removed a book!\n");
                                }

                            }
                        }



                    }
                    else{
                        log_out=true;
                        getchar();
                    }


                }


            }
            else  {
                printf("Welcome back to the library: %s\n",username);
                while (log_out==false) {
                    printf("1.Borrow a book\n");
                    printf("2.Return a book\n");
                    printf("3.Do you want to search for books\n");
                    printf("4.Do you want to display all books\n");
                    printf("5.Log out\n");

                    scanf(" %c", &usr_input);
                    if (usr_input == '1') {
                        if(Borrow(a)==1) {
                        }

                    }
                    else if (usr_input=='2') {
                        if(returns(a)==1){
                        }
                    }
                    else if (usr_input == '3') {
                        searching();
                    }
                    else if (usr_input == '4') {


                        printf("ID Title                    Author         Copies Year\n");
                        for (int i = 0; i < Bookcollection.length; i++) {
                            printf("%-3d%-30s%-15s%-7d%d\n", Bookcollection.array[i].ID, Bookcollection.array[i].title,
                                   Bookcollection.array[i].authors, Bookcollection.array[i].copies,
                                   Bookcollection.array[i].year);

                        }
                        printf("\n");
                    }


                    else if (usr_input == '5') {
                        printf("Goodbye, %s ! see you next time!\n",username);
                        printf("\n");
                        log_out = true;
                        getchar();


                    }

                }

            }


        }
        else if (usr_input == '2') {

            printf("Please enter a username:");
            getchar();
            fgets(buffer,50,stdin);
            buffer[strcspn(buffer,"\n")]=0;
            sscanf(buffer,"%s",username);
            printf("Please enter a password:");

            fgets(buffer,50,stdin);
            buffer[strcspn(buffer,"\n")]=0;
            sscanf(buffer,"%s",password);
            printf("Please enter a name:");
            getchar();
            fgets(buffer,50,stdin);
            buffer[strcspn(buffer,"\n")]=0;
            sscanf(buffer,"%s",name);
            printf("Please enter a emailaddress:");
            fgets(buffer,50,stdin);
            buffer[strcspn(buffer,"\n")]=0;
            sscanf(buffer,"%s",emailAddress);
            if(RegisterSystem(username, password, name, emailAddress, userlist[0].totalUsers)==0) {
                printf("Thank you for joining:%s!\n", userlist[userlist[0].totalUsers].username);
                userlist[0].totalUsers = userlist[0].totalUsers + 1;
            }


        }
        else if (usr_input == '3') {
            searching();
            getchar();
        }
        else if (usr_input == '4') {



                printf("ID Title          Author         Copies Year\n");
            for(int i=0;i<Bookcollection.length;i++){
                printf("%-3d%-30s%-15s%-7d%d\n",Bookcollection.array[i].ID,Bookcollection.array[i].title,Bookcollection.array[i].authors,Bookcollection.array[i].copies,Bookcollection.array[i].year);

            }
            printf("\n");
            getchar();

        }

        else if (usr_input == '5') {
            FILE* file;
            file= fopen("../libraries.txt","w");
            store_books(file);
            FILE* files;
            files= fopen("../Users.txt","w");
            store_users(files);
            FILE* filess;
            filess= fopen("../loans.txt","w");
            store_loans_record(filess);
            exits = true;

        }
        else {
            printf("Sorry could you please enter another option\n");
        }
    }
}



