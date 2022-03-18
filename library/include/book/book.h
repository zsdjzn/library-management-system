#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//枚举图书状态，借出，未借出（存在），禁止借出
typedef enum {
    LEND, EXIST, PROHIBIT
} Status;

typedef struct Book {
    int id;             //图书编号
    char title[30];     //图书名称
    char author[30];    //图书作者
    double pirce;       //图书价格
    Status status;      //图书状态
} Book;

typedef struct BookList {
    //数据域
    Book data;

    //指针域
    struct BookList* next;
    struct BookList* prev;
} BookList;

typedef struct 

//初始化双向循环链表
BookList* bookListInit(void);
//插入链表节点
void addBookListNode(BookList* head, Book data);
//删除链表节点
void delBookListNode(BookList* head, Book data);
//添加图书到链表
void addBook(BookList* head);
//显示链表所有数据
void showBookLinkList(BookList *head);
//写入文件
void writeBookFile(Book data);
//将文件中的信息获取到链表
void readBookFile(BookList* head);
//添加图书
void addBook(BookList* head);
//修改图书信息
void editTheBook(BookList* head);
//清空文件重新将链表内容写入
void clearWriteBookFile(BookList* head);
//删除图书
void clearBook(BookList* head);
//查找某一本图书
void findTheBook(BookList* head);
//借书
void borrowBooks(BookList* head);
//还书
void returnBook(BookList* head);

#endif