#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

char input[50];
int year;
struct BookArray Bookcollection;
int add_book(struct Book book) {
	

	Bookcollection.array[Bookcollection.length] = book;
	Bookcollection.length = +1;
	return 0;
}
int remove_book(struct Book book) {
	for (int i = 0; i < Bookcollection.length;i++) {
		if (Bookcollection.array[i].authors==book.authors) {
			if (Bookcollection.array[i].title == book.title) {
				if (Bookcollection.array[i].year == book.year) {
					for (int j = i; j < Bookcollection.length;j++ ) {
						Bookcollection.array[i] = Bookcollection.array[i + 1];
						return 0;
					}
				}
			}
		}
	}
	return 1;
}