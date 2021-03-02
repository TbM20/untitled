#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include <stdbool.h>

Users* userlist;
extern struct BookArray Bookcollection;
int  main(int argc, char* argv[])
{
	FILE* fp;
	fp= fopen("libraries.txt","r");
	int a=load_books(fp);
	
	int counter = 0;
	char usr_input;
	char  username[30];
	char password[30];
	char  name[30];
	char emailAddress[30];
	bool exits = false;
	bool log_out = false;
	while (exits==false) {
		printf("1.Do you want to Login\n");
		printf("2.Do you want to Register\n");
		printf("3.Do you want to search for books\n");
		printf("4.Do you want to display all books\n");
		printf("5.Quit\n");
		scanf_s(" %c", &usr_input, 30);
		if (usr_input == '1') {
			printf("Please enter a username and password:(seperated by a comma) :");
			scanf_s(" %s , %s", &username, 30, &password, 30);
			if (LoginSystem(username, password) == 0) {
				printf("You are not registered you need to register");
				printf("Please enter a username, password,name and email address:(seperated by a comma) :");
				scanf_s("%s, %s, %s, %s", &username, 30, &password, 30, &name, 30, &emailAddress, 30);

				RegisterSystem(username, password, name, emailAddress, counter);
				counter = counter + 1;

			}
			else if (LoginSystem(username, password) == 1) {
				Users* currentuser = malloc(1*sizeof(Users));
				
				while (log_out==false) {
					printf("Welcome back to the library: %s/n",username);
					printf("1.Borrow a book\n");
					printf("2.Return a book\n");
					printf("3.Do you want to search for books\n");
					printf("4.Do you want to display all books\n");
					printf("5.Log out\n");
					
					scanf_s(" %c", &usr_input, 30);
					if (usr_input == '1') {
						if(Borrow(currentuser)==1)
						{
							printf("Sorry you already have a copy of this book you cannot borrow another one");
						}
					}
					else if (usr_input=='2') {
						returns(currentuser);
					}
					else if (usr_input == '3') {
						searching();
					}
					else if (usr_input == '4') {
						
					}
					else if (usr_input == '5') {
						log_out = true;
						FILE* fs=fopen("libraries.txt","w");
						store_books(fs);
					}

				}
				
			}
			else if (LoginSystem(username, password) == 2) {
				while(log_out==false){
					printf("hello librarian what would you like to do?(remove or add books)(r/a): ");
					scanf_s(" %c", &usr_input, 30);
					
					if (usr_input == 'a') {
						
						struct Book abook ;
						int years;
						char correctinput[30];
						abook.title = malloc(1 * sizeof(struct Book));
						abook.title = malloc(1 * sizeof(struct Book));
						printf("please enter the title of book you would like to add\n");
						scanf_s(" %s", correctinput, 30);
						abook.title = correctinput;
						printf("\nplease enter the author of book you would like to add\n");
						scanf_s(" %s", correctinput, 30);

						abook.authors = correctinput;
						printf("\nplease enter the year of book you would like to addn");
						scanf_s(" %d", &years);
						abook.year = years;

						add_book(abook);
						
					}
					else {
						char correctinput[30];
						int years = 0;
						struct Book rbook;
						rbook.title = malloc(1 * sizeof(struct Book));
						rbook.authors = malloc(1 * sizeof(struct Book));
						printf("please enter the title of book you would like to remove\n");
						scanf_s(" %s", correctinput, 30);
						rbook.title = correctinput;
						printf("\nplease enter the author of book you would like to remove\n");
						scanf_s(" %s", correctinput, 30);

						rbook.authors = correctinput;
						printf("\nplease enter the year of book you would like to remove\n");
						scanf_s(" %d", &years);
						rbook.year = years;
						remove_book(rbook);
						
					}
				
				
				}
				

			}

		}
		else if (usr_input == '2') {
			printf("Please enter a username, password,name and email address:(seperated by a comma) :");
			scanf_s("%s, %s, %s, %s", &username, 30, &password, 30, &name, 30, &emailAddress, 30);

			RegisterSystem(username, password, name, emailAddress, counter);
			counter = counter + 1;
		}
		else if (usr_input == '3') {
			searching();
		}
		else if (usr_input == '4') {
		
		}
		else if (usr_input == '5') {
			exits = true;
		}
		else {
			printf("Sorry could you please enter another option");
		}
	}
}

	
	
	