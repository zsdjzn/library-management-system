#include "interface/interface.h"

void userInterface(UserList* user, BookList* book)
{
    int cmd;

    while (1) {
        userMenu();
        scanf("%d", &cmd); while(getchar() != '\n');
        switch (cmd) {
        case 1://查找图书
            findTheBook(book);
            break;
        case 2://借书
            borrowBooks(book);
            break;
        case 3://还书
            returnBook(book);
            break;
        case 4:
            showBookLinkList(book);
            break;
        case 0:
            exit(1);
        default:
            invalidMessage();
            break;
        }
    }
}
