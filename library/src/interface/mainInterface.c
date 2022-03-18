#include "interface/interface.h"

void mainInterface()
{
    UserList* user = userListInit();
    BookList* book = bookListInit();
    readUserFile(user);
    readBookFile(book);

    int cmd;
    int ret;
    while (1) {
        mainMenu();
        scanf("%d", &cmd); while(getchar() != '\n');
        switch (cmd) {
        case 1:
            ret = userLogin(user);
            if (ret == 1) {
                adminInterface(user, book);
            } else if (ret == 2) {
                userInterface(user, book);
            }
            break;
        case 2:
            registerUser(user);
            break;
        case 3:
            showUserLinkList(user);
            break;
        case 0:
            exit(1);
        default:
            invalidMessage();
            break;
        }
    }
}
