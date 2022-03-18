#include "user/user.h"
#include "tools/hint.h"

static int count = 0;
static const char* filePath = "src/data/user.txt";

void clearWriteUserFile(UserList* head)
{
    //打开文件(清空打开)
    FILE* fp = fopen(filePath, "w");
    if (fp == NULL) {
        perror("fopen failed");
        return;
    }

    //将链表数据写入文件
    UserList* pos;
    for (pos = head->next; pos != head; pos = pos->next) {
        //写入文件
        fprintf(fp, "%d %s %s\n", pos->data.id, 
                                pos->data.name, 
                                pos->data.password);
    }

    //关闭文件
    fclose(fp);
}

int DetermineThePassword(UserList* head, const char* passwd)
{
    UserList* pos;//遍历指针

    for (pos = head->next; pos != head; pos = pos->next) {
        //找到了
        if (strcmp(pos->data.password, passwd) == 0) {
            return 2;
        }
    }

    //遍历完没找到
    if (strcmp(pos->data.password, passwd)) {
            return -2;
        }
}

int DetermineUserName(UserList* head, const char* name)
{
    UserList* pos;//遍历指针

    for (pos = head->next; pos != head; pos = pos->next) {
        if (strcmp(pos->data.name, name) == 0) {
            return 1;
        }
    }

    if (strcmp(pos->data.name, name)) {
        return -1;
    }
}

void readUserFile(UserList* head)
{
    //打开文件
    FILE* fp = fopen(filePath, "r");
    if (fp == NULL) {
        perror("fopen failed");
        return;
    }

    User data;

    //读取文件
    while (1) {
        bzero(&data, sizeof(data));
        int ret = fscanf(fp, "%d %s %s\n", &data.id, data.name, data.password);
        if (ret == EOF) {
            break;
        }
        addUserListNode(data, head);
    }

    //关闭文件
    fclose(fp);
}

void writeUserFile(User data)
{
    //打开文件
    FILE* fp = fopen(filePath, "a+");
    if (fp == NULL) {
        perror("fopen failed");
        return;
    }

    //写入文件
    fprintf(fp, "%d %s %s\n", data.id, data.name, data.password);

    //关闭文件
    fclose(fp);
}

int userLogin(UserList* head)
{
    const char* admin_name = "admin";
    const char* admin_passwd = "123456";
    int ret_name, ret_passwd;
    User data;
    bzero(&data, sizeof(data));

    //判断用户是否存在
    printf("输入用户名：");
    scanf("%s", data.name); while(getchar() != '\n');
    ret_name = DetermineUserName(head, data.name);
    printf("输入密码：");
    scanf("%s", data.password); while(getchar() != '\n');
    ret_passwd = DetermineThePassword(head, data.password);

    if (!strcmp(data.name, admin_name) && !strcmp(admin_passwd, data.password)) {
        return 1;
    } else if (ret_name == 1 && ret_passwd == 2) {
        return 2;
    } else if (ret_name == -1) {
        printf("用户名输入错误\n");
    } else if (ret_passwd == -2) {
        printf("密码输入错误\n");
    }
}

void registerUser(UserList* head)
{
    //进行注册
    const char* admin = "admin";
    User data;
    bzero(&data, sizeof(data));
    UserList* pos; //遍历指针
    
    while (1) {
        printf("输入用户名：");
        scanf("%s", data.name); while(getchar() != '\n');
        if (!strcmp(data.name, admin)) {
            printf("admin为管理员不可注册\n");
            return;
        }
        //判断用户是否存在
        for (pos = head->next; pos != head; pos = pos->next) {
            if (!strcmp(pos->data.name, data.name)) {
                printf("用户名已注册！\n");
                return;
            }
        }
        if (strlen(data.name) > 16) {
            printf("用户名不能超过16位！\n");
        } else {
            break;
        } 
    }
    while (1) {    
        printf("请输入密码：");
        scanf("%s", data.password); while(getchar() != '\n');
        if (strlen(data.password) > 16) {
            printf("密码不能超过16位！\n");
        } else {
            break;
        }
    }
    
    //更新id
    readUserFile(head);
    UserList* n;//遍历指针
    for (n = head->next; n != head; n = n->next) {
        count = n->data.id;
    }

    data.id = count + 1;//用户id
    successMessage();
    //添加到链表
    addUserListNode(data, head);
    writeUserFile(data);
}

void showUserLinkList(UserList *head)
{
	UserList *pos;	// 遍历指针

    printf("\n");
    printf("用户ID\t用户名\t用户密码\n");
	for(pos = head->next; pos != head; pos = pos->next) {
        printf("%d\t%s\t%s\n", pos->data.id,
                            pos->data.name,
                            pos->data.password);
    }
	printf("\n");
}

void delUserListNode(User data, UserList* head)
{
    //判断链表是否为空
    if (head->next == head) {
        printf("ERROR: Empty.\n");
        return;
    }

    //遍历链表，寻找节点删除
    UserList* pos;  //遍历指针
    for (pos = head->next; pos != head; pos = pos->next) {
        if (strcmp(pos->data.name, data.name)) {//找到需要删除节点
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

void addUserListNode(User data, UserList* head)
{
    //新节点申请堆空间
    UserList* newNode = userListInit();
    newNode->data = data;

    //修改指向
	    //操作新节点
	newNode->next = head;			//新节点->next = 后节点
	newNode->prev = head->prev;	    //新节点->prev = 前节点
	    //操作前后节点，都指向新节点
	head->prev->next = newNode;	    //前节点->next = 新节点
	head->prev = newNode;			//后节点->prev = 新节点
}

UserList* userListInit(void)
{
    //申请堆空间，并清空
    UserList* head = malloc(sizeof(UserList));
    if(head == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	bzero(head, sizeof(UserList));

    //初始化节点，将头尾指针指向自身
    head->next = head;
    head->prev = head;

    //返回堆空间
    return head;
}
