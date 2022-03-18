#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct User {
    int id;        //用户ID
    char name[16];      //用户名
    char password[16];  //用户密码
} User;

typedef struct UserList {
    //数据域
    User data;

    //指针域
    struct UserList* next;
    struct UserList* prev;
} UserList;

//初始化双向循环链表
UserList* userListInit(void);
//插入链表节点
void addUserListNode(User data, UserList* head);
//删除链表节点
void delUserListNode(User data, UserList* head);
//显示链表数据
void showUserLinkList(UserList *head);
//注册用户
void registerUser(UserList* head);
//用户登录
int userLogin(UserList* head);
//写入文件内容
void writeUserFile(User data);
//读取文件内容
void readUserFile(UserList* head);
//判断用户名
int DetermineUserName(UserList* head, const char* name);
//判断密码
int DetermineThePassword(UserList* head, const char* passwd);
//清空写入
void clearWriteUserFile(UserList* head);

#endif