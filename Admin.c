#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

Users*userlist;
struct BookArray Bookcollection;
int add_book(struct Book book) {
Bookcollection.array =realloc ( Bookcollection.array,sizeof(struct Book)*(Bookcollection.length+1));

    Bookcollection.array[Bookcollection.length] = book;
    Bookcollection.length = Bookcollection.length+1;
    return 0;
}
int remove_book(struct Book book) {

    for (int i = 0; i < Bookcollection.length;i++) {
        if (strcmp(Bookcollection.array[i].authors,book.authors)==0) {
            if (strcmp(Bookcollection.array[i].title,book.title)==0) {
                if (Bookcollection.array[i].year == book.year) {
                    for (int j = i; j < Bookcollection.length;j++ ) {
                        Bookcollection.array[j] = Bookcollection.array[j + 1];
                    }
                    Bookcollection.array =realloc ( Bookcollection.array,sizeof(struct Book)*(Bookcollection.length-1));
                    Bookcollection.length=Bookcollection.length-1;


                    for(int l=0;l<userlist[0].totalUsers;l++){
                        for(int c=0;c<userlist[l].currentBorrowed;c++){
                            if(book.ID==userlist[l].IDheld[c]){
                                for(int r=c;r<userlist[l].currentBorrowed;r++){
                                    userlist[l].IDheld[r]=userlist[l].IDheld[r+1];
                                }
                                userlist[l].currentBorrowed=userlist[l].currentBorrowed-1;
                            }
                        }

                    }

                    return 0;
                }
            }
        }
    }
    return 1;
}
