#include "menu/menu.h"

void mainMenu()
{
    printf("1.登录 2.注册 0.退出\n");
}

void adminMenu()
{
    printf("1.管理用户 2.管理图书 0.退出\n");
}

void adminUser()
{
    printf("1.增加用户 2.删除用户 3.修改用户密码 4.显示所有用户 5.返回\n");
}

void adminBook()
{
    printf("1.增加图书 2.删除图书 3.修改图书信息 4.显示所有图书 5.返回\n");
}

void userMenu()
{
    printf("1.查找图书 2.借书 3.还书 4.显示所有图书 0.退出\n");
}
