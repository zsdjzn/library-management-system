#include "book/book.h"

static const char* lend = "借出";
static const char* exist = "存在";
static const char* prohibit = "禁止借出";
static int count = 0;
static const char* filePath = "src/data/book.txt";


void returnBook(BookList* head)
{
    Book data;
    bzero(&data, sizeof(data));
    
    printf("输入你要归还的书：\n");
    scanf("%s", data.title); while(getchar() != '\n');

    BookList* pos;
    for (pos = head->next; pos != head; pos = pos->next) {
        if (strcmp(pos->data.title, data.title) == 0) {
            //还书
        }
    }
}

void borrowBooks(BookList* head)
{
    Book data;
    bzero(&data, sizeof(data));
    
    printf("输入你要借的书：\n");
    scanf("%s", data.title); while(getchar() != '\n');

    BookList* pos;
    for (pos = head->next; pos != head; pos = pos->next) {
        if (strcmp(pos->data.title, data.title) == 0) {
            //借书
            if (pos->data.status == 0) {
                printf("已借出\n");
                break;
            } else if (pos->data.status == 1) {
                printf("可以借\n");
                break;
            } else if (pos->data.status == 2) {
                printf("本书禁止借出\n");
                break;
            }
        }
    }
}

void findTheBook(BookList* head)
{
    Book data;
    bzero(&data, sizeof(data));

    //输入你要找的书名
    printf("请输入你要查找的图书的书名：\n");
    scanf("%s", data.title); while(getchar() != '\n');

    //查找图书
        //遍历指针
    BookList* pos;
    for (pos = head->next; pos != head; pos = pos->next) {
        if (strcmp(pos->data.title, data.title) == 0) {//找到了
            printf("\n");
            printf("编号\t书名\t作者\t价格\t状态\n");
            if (pos->data.status == 0) {
                printf("%d\t%s\t%s\t%.2lf\t%s\n", pos->data.id,
                                                pos->data.title,
                                                pos->data.author,
                                                pos->data.pirce,
                                                lend);
                printf("\n");
                break;
            } else if (pos->data.status == 1) {
                printf("%d\t%s\t%s\t%.2lf\t%s\n", pos->data.id,
                                                pos->data.title,
                                                pos->data.author,
                                                pos->data.pirce,
                                                exist);
                printf("\n");
                break;
            } else if (pos->data.status == 2) {
                printf("%d\t%s\t%s\t%.2lf\t%s\n", pos->data.id,
                                                pos->data.title,
                                                pos->data.author,
                                                pos->data.pirce,
                                                prohibit);
                printf("\n");
                break;
            }
        }
    }
    if (strcmp(pos->data.title, data.title)) {
        printf("没找到这本书\n");
        return;
    }
}

void clearBook(BookList* head)
{
    Book data;
    bzero(&data, sizeof(data));
    
    printf("输入你需要删除的书籍的名称：\n");
    scanf("%s", data.title); while(getchar() != '\n');
    
    delBookListNode(head, data);
    clearWriteBookFile(head);
    //需不需要做个判断？(￣_,￣ )
    printf("删除成功！\n");
}

void clearWriteBookFile(BookList* head)
{
    //打开文件(清空打开)
    FILE* fp = fopen(filePath, "w");
    if (fp == NULL) {
        perror("fopen failed");
        return;
    }

    //将链表数据写入文件
    BookList* pos;
    for (pos = head->next; pos != head; pos = pos->next) {
        //写入文件
        fprintf(fp, "%d %s %s %lf %d\n", pos->data.id, 
                                        pos->data.title, 
                                        pos->data.author, 
                                        pos->data.pirce, 
                                        pos->data.status);
    }

    //关闭文件
    fclose(fp);
}

void editTheBook(BookList* head)
{
    Book data;
    bzero(&data, sizeof(data));

    //输入你要找的书名
    printf("请输入你要修改的图书的书名：\n");
    scanf("%s", data.title); while(getchar() != '\n');

    //查找图书
        //遍历指针
    BookList* pos;
    for (pos = head->next; pos != head; pos = pos->next) {
        if (strcmp(pos->data.title, data.title) == 0) {//找到了
            printf("编号\t书名\t作者\t价格\t状态\n");
            if (pos->data.status == 0) {
                printf("%d\t%s\t%s\t%.2lf\t%s\n", pos->data.id,
                                                pos->data.title,
                                                pos->data.author,
                                                pos->data.pirce,
                                                lend);
                break;
            } else if (pos->data.status == 1) {
                printf("%d\t%s\t%s\t%.2lf\t%s\n", pos->data.id,
                                                pos->data.title,
                                                pos->data.author,
                                                pos->data.pirce,
                                                exist);
                break;
            } else if (pos->data.status == 2) {
                printf("%d\t%s\t%s\t%.2lf\t%s\n", pos->data.id,
                                                pos->data.title,
                                                pos->data.author,
                                                pos->data.pirce,
                                                prohibit);
                break;
            }
        }
    }
    if (strcmp(pos->data.title, data.title)) {
        printf("没找到这本书\n");
        return;
    }

    int cmd;
    printf("选择需要修改的信息(1.修改书名 2.修改作者 3.修改价格)：\n");
    scanf("%d", &cmd); while(getchar() != '\n');
    if (cmd == 1) {
        printf("输入新的书名：");
        scanf("%s", pos->data.title); while(getchar() != '\n');
        clearWriteBookFile(head);
        printf("修改成功！\n");
    } else if (cmd == 2) {
        printf("输入新的作者：");
        scanf("%s", pos->data.author); while(getchar() != '\n');
        clearWriteBookFile(head);
        printf("修改成功！\n");
    } else if (cmd == 3) {
        printf("输入新的价格：");
        scanf("%lf", &pos->data.pirce); while(getchar() != '\n');
        clearWriteBookFile(head);
        printf("修改成功！\n");
    }
}

void addBook(BookList* head)
{
    Book data;
    bzero(&data, sizeof(data));
    
    printf("请输入书名: ");
    scanf("%s", data.title);
    printf("请输入作者: ");
    scanf("%s", data.author);
    printf("请输入价格: ");
    scanf("%lf", &data.pirce);
    data.status = EXIST;

    BookList* pos;//遍历指针
    for (pos = head->next; pos != head; pos = pos->next) {
        //获取文件中储存的书籍id
        count = pos->data.id;
    }
    data.id = count + 1;
    addBookListNode(head, data);//插入链表
    writeBookFile(data);//写入文件
}

void readBookFile(BookList* head)
{
    //打开文件
    FILE* fp = fopen(filePath, "r");
    if (fp == NULL) {
        perror("fopen failed");
        return;
    }

    Book data;

    //读取文件
    while (1) {
        bzero(&data, sizeof(data));
        int ret = fscanf(fp, "%d %s %s %lf %u\n", &data.id, data.title, data.author, &data.pirce, &data.status);
        if (ret == EOF) {
            break;
        }
        addBookListNode(head, data);
    }

    //关闭文件
    fclose(fp);
}

void writeBookFile(Book data)
{
    //打开文件
    FILE* fp = fopen(filePath, "a+");
    if (fp == NULL) {
        perror("fopen failed");
        return;
    }

    //写入文件
    fprintf(fp, "%d %s %s %lf %d\n", data.id, data.title, data.author, data.pirce, data.status);

    //关闭文件
    fclose(fp);
}

void showBookLinkList(BookList *head)
{
	BookList *pos;	// 遍历指针

    printf("\n");
    printf("=================INFO=================\n");
    printf("id\tname\tauthor\tpirce\tstatus\n");
	for(pos=head->next; pos!=head; pos=pos->next) {
		if (pos->data.status == 0) {
            printf("%d\t%s\t%s\t%.2lf\t%s\t\n", pos->data.id,
                                        pos->data.title,
                                        pos->data.author,
                                        pos->data.pirce,
                                        lend);
        } else if (pos->data.status == 1) {
            printf("%d\t%s\t%s\t%.2lf\t%s\t\n", pos->data.id,
                                        pos->data.title,
                                        pos->data.author,
                                        pos->data.pirce,
                                        exist);
        } else if (pos->data.status == 2) {
            printf("%d\t%s\t%s\t%.2lf\t%s\t\n", pos->data.id,
                                        pos->data.title,
                                        pos->data.author,
                                        pos->data.pirce,
                                        prohibit);
        }
    }
    printf("======================================\n");
	printf("\n");
}

void delBookListNode(BookList* head, Book data)
{
    //判断链表是否为空
    if (head->next == head) {
        printf("ERROR: Empty.\n");
        return;
    }

    //遍历链表，寻找节点删除
    BookList* pos;  //遍历指针
    for (pos = head->next; pos != head; pos = pos->next) {
        if (!strcmp(pos->data.title, data.title)) {
            //找到需要删除节点
            pos->prev->next = pos->next;    //前节点->next = 后节点
            pos->next->prev = pos->prev;    //后节点->prev = 前节点
            break;
        }
    }

    if (pos == head) {
        printf("ERROR: Not Found.\n");
        return;
    }

    //释放pos堆空间
    free(pos);
}

void addBookListNode(BookList* head, Book data)
{
    //新节点申请堆空间
    BookList* newNode = bookListInit();
    newNode->data = data;

    //修改节点指向
    newNode->next = head;
    newNode->prev = head->prev;

    head->prev->next = newNode;
    head->prev = newNode;
}

BookList* bookListInit(void)
{
    //申请堆空间并清空
    BookList* head = malloc(sizeof(BookList));
    if (head == NULL) {
        perror("malloc failed");
        return NULL;
    }
    bzero(head, sizeof(BookList));

    //初始化节点
    head->next = head;
    head->prev = head;

    //返回堆空间
    return head;
}