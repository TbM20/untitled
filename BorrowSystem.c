#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"


char checking;
char strings[30];
int year;
int listsize = 0;
extern struct BookArray Bookcollection;

int id;
int searching() {
	printf("would you like to find the book by title, author or year, (t or a or year):");
	scanf_s(" %c", &checking, 1);
	if (checking == 't') {
		printf("enter the title you want to search by: ");
		scanf_s(" %s", &strings, 30);
		if (find_book_by_title(strings).length == 0) {
			printf("Sorry we dont have that books with that year available");
		}
	}
	else if (checking == 'a') {
		printf("enter the author you want to search by: ");
		scanf_s(" %s", &strings, 30);
		if (find_book_by_author(strings).length == 0) {
			printf("Sorry we dont have that books with that author available");
		}
	}
	else if (checking == 'y') {

		printf("enter the year you want to search by: ");
		scanf_s(" %d", &year);
		if (find_book_by_year(year).length == 0) {
			printf("Sorry we dont have that books with tha year available");
		}

	}
	return 0;
}

int Borrow(Users*a)
{
	

	printf("Please enter the ID of the book you want to Borrow: ");
	scanf_s("%d", &id);
	for (int i = 0; i < 30; i++) {
		if (id == a[i].IDheld[i]) {
			return 1;
		}
	}

	a[0].IDheld[a[0].currentBorrowed] = id;
	a[0].currentBorrowed = a[0].currentBorrowed + 1;

	return 0;
}



int returns(Users* b) {

		printf("enter the title you want to return by: ");
		scanf_s(" %s", &strings, 30);
		struct BookArray a = find_book_by_title(strings);
		if(a.length==1){
			b[0].currentBorrowed = b[0].currentBorrowed - 1;
			for (int i = 0; i <b->currentBorrowed; i++) {
				if (a.array[0].ID == b[i].IDheld[i]) {
					b[i].IDheld[i] = b[i].IDheld[i + 1];
				}
			}
			a.array[0].copies=+1;
		}
		
		printf("Sorry this book is unavailable to return");
		
		return 0;
		
}

struct BookArray find_book_by_year(unsigned int year){
	
	
	struct BookArray yearCheck;


	for (int i = 0; i < Bookcollection.length; i++) {
		yearCheck.array = malloc(sizeof(struct Book));
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
	
	for (int i = 0; i < Bookcollection.length; i++) {
		authorCheck.array = malloc(sizeof(struct Book));
		if (Bookcollection.array[i].authors == author) {
			authorCheck.array[listsize] = Bookcollection.array[i];
			listsize = listsize + 1;
		}
	}
	authorCheck.length = listsize;
	return authorCheck;
}
struct BookArray find_book_by_title(const char* title) {
	struct BookArray titleCheck;

	for (int i = 0; i < 50; i++) {
		titleCheck.array = malloc(sizeof(struct Book));
		if (Bookcollection.array[i].title == title) {
			titleCheck.array[listsize] = Bookcollection.array[i];
			listsize = listsize + 1;
		}


		titleCheck.length = listsize;
		return titleCheck;
	}
}