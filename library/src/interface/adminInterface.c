#include "interface/interface.h"

void adminInterface(UserList* user, BookList* book)
{
    int cmd;
    while (1) {
        adminMenu();
        scanf("%d", &cmd); while(getchar() != '\n');
        switch (cmd) {
        case 1:
            manageUsers(user);
            break;
        case 2:
            manageBooks(book);
            break;
        case 0:
            exit(1);
        default:
            invalidMessage();
            break;
        }
    }
}

void manageUsers(UserList* user)
{
    int cmd;
    while (1) {
        adminUser();
        scanf("%d", &cmd); while(getchar() != '\n');
        switch (cmd) {
        case 1://增
            break;
        case 2://删
            break;
        case 3://改
            break;
        case 4://显示
            break;
        case 5://返回
            return;
        default:
            invalidMessage();
            break;
        }
    }
}

void manageBooks(BookList* book)
{
    int cmd;
    while (1) {
        adminBook();
        scanf("%d", &cmd); while(getchar() != '\n');
        switch (cmd) {
        case 1://增
            addBook(book);
            break;
        case 2://删
            clearBook(book);
            break;
        case 3://改
            editTheBook(book);
            break;
        case 4://显示
            showBookLinkList(book);
            break;
        case 5://返回
            return;
        default:
            invalidMessage();
            break;
        }
    }
}
