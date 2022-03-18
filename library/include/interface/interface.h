#ifndef INTERFACE_H
#define INTERFACE_H

#include "book/book.h"
#include "tools/hint.h"
#include "user/user.h"
#include "menu/menu.h"

//主界面交互
void mainInterface();
//管理员交互
void adminInterface(UserList* user, BookList* book);
void manageUsers(UserList* user);//管理用户
void manageBooks(BookList* book);//管理图书
//用户交互
void userInterface(UserList* user, BookList* book);

#endif