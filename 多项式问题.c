#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct list {
    int date1;//系数
    int date2;//指数
    struct list* next;
};
struct list* creatnode(struct list* head);
void outputlist(struct list* head);
struct list* addition(struct list* head, struct list* headol);
struct list* subtraction(struct list* head, struct list* headol);
struct list* multiplication(struct list* head, struct list* headol);
struct list* Derivation(struct list* head);
struct list* Generationvalue(struct list* head,int x);
int main()
{
    printf("1-多项式加法         2-多项式减法\n");
    printf("3-多项式乘法         4-多项式求导\n");
    printf("             0-带入X求值\n");
    int select = 0;
    scanf("%d", &select);
    system("cls");
    if (select == 1)
    {
        int i = 0;
        printf("请输入第一个多项式项数：");
        scanf("%d", &i);
        struct list* head = NULL;
        while (i)
        {
            head = creatnode(head);
            i--;
        }
        int j = 0;
        printf("请输入第二个多项式项数：");
        scanf("%d", &j);
        struct list* headol = NULL;
        while (j)
        {
            headol = creatnode(headol);
            j--;
        }
        outputlist(head);
        outputlist(headol);
        head = addition(head, headol);
        outputlist(head);
    }
    if (select == 2)
    {
        int i = 0;
        printf("请输入第一个多项式项数：");
        scanf("%d", &i);
        struct list* head = NULL;
        while (i)
        {
            head = creatnode(head);
            i--;
        }
        int j = 0;
        printf("请输入第二个多项式项数：");
        scanf("%d", &j);
        struct list* headol = NULL;
        while (j)
        {
            headol = creatnode(headol);
            j--;
        }
        outputlist(head);
        outputlist(headol);
        head = subtraction(head, headol);
        outputlist(head);
    }
    if (select == 3)
    {
        int i = 0;
        printf("请输入第一个多项式项数：");
        scanf("%d", &i);
        struct list* head = NULL;
        while (i)
        {
            head = creatnode(head);
            i--;
        }
        int j = 0;
        printf("请输入第二个多项式项数：");
        scanf("%d", &j);
        struct list* headol = NULL;
        while (j)
        {
            headol = creatnode(headol);
            j--;
        }
        outputlist(head);
        outputlist(headol);
        head = multiplication(head, headol);
        outputlist(head);
    }
    if (select == 4)
    {
        int i = 0;
        printf("请输入多项式项数：");
        scanf("%d", &i);
        struct list* head = NULL;
        while (i)
        {
            head = creatnode(head);
            i--;
        }
        outputlist(head);
        head = Derivation(head);
        outputlist(head);
    }
    if (select == 0)
    {
        int i = 0,X=0;
        printf("请输入多项式项数：");
        scanf("%d", &i);
        printf("请输入X的代入值：");
        scanf("%d", &X);
        struct list* head = NULL;
        while (i)
        {
            head = creatnode(head);
            i--;
        }
        outputlist(head);
        head = Generationvalue(head,X);
    }
}
struct list* creatnode(struct list* head)//创建结点
{
    if (head == NULL)
    {
        head = (struct list*)malloc(sizeof(struct list));
        printf("请输入系数");
        scanf("%d", &head->date1);
        printf("请输入指数");
        scanf("%d", &head->date2);
        head->next = NULL;
        return head;
    }
    else
    {
        struct list* node = (struct list*)malloc(sizeof(struct list));
        printf("请输入系数");
        scanf("%d", &node->date1);
        printf("请输入指数");
        scanf("%d", &node->date2);
        node->next = head;
        head = node;
        return head;
    }
}
void outputlist(struct list* head)
{
    struct list* la;
    struct list* lb;
    la = head;
    while (la != NULL)
    {
        if (la->date1 == 0)
        {
            lb = la;
            la = la->next;
            free(lb);
            head = la;
        }
        else
        {
            if (la == NULL)
                break;
            if (la->next == NULL)
                break;
            if (la->next->date1 == 0)
            {
                lb = la->next;
                la->next = lb->next;
                free(lb);
            }
        }
        if (la == NULL)
            break;
        if (la->next == NULL)
            break;
        la = la->next;
    }
    if (head == NULL)
    {
        printf("结果为0");
    }
    while (head != NULL)
    {
        printf("%d*X^%d  ", head->date1, head->date2);
        head = head->next;

    }
    printf("\n");
}
struct list* addition(struct list* head, struct list* headol)//加法
{
    struct list* la = head;
    struct list* lb = headol;
    while (la != NULL)
    {
        lb = headol;
        if (lb->date2 == la->date2)
        {
            la->date1 = lb->date1 + la->date1;
            struct list* pre = lb->next;
            free(lb);
            lb = pre;
            headol = lb;
        }
        else
        {
            while (lb->next != NULL)
            {
                if (lb->next->date2 == la->date2)
                {
                    la->date1 = lb->next->date1 + la->date1;
                    struct list* pre = lb->next;
                    lb->next = lb->next->next;
                    free(pre);

                }
                if (lb->next == NULL)
                    break;
                lb = lb->next;
            }
        }
        if (la->next == NULL)
            break;
        la = la->next;
    }
    la->next = headol;
    return head;
}
struct list* subtraction(struct list* head, struct list* headol)//减法
{
    struct list* la = head;
    struct list* lb = headol;
    while (la != NULL)
    {
        lb = headol;
        if (lb->date2 == la->date2)
        {
            la->date1 = lb->date1 - la->date1;
            struct list* pre = lb->next;
            free(lb);
            lb = pre;
            headol = lb;
        }
        else
        {
            while (lb->next != NULL)
            {
                if (lb->next->date2 == la->date2)
                {
                    la->date1 = lb->next->date1 - la->date1;
                    struct list* pre = lb->next;
                    lb->next = lb->next->next;
                    free(pre);

                }
                if (lb->next == NULL)
                    break;
                lb = lb->next;
            }
        }
        if (la->next == NULL)
            break;
        la = la->next;
    }
    lb = headol;
    while (lb != NULL)
    {
        lb->date1 = 0 - lb->date1;
        lb = lb->next;
    }
    la->next = headol;
    return head;
}
struct list* multiplication(struct list* head, struct list* headol)//乘法
{
    struct list* newlist;
    newlist = (struct list*)malloc(sizeof(struct list));
    newlist->next = NULL;
    struct list* la = head;
    struct list* lb = headol;
    while (la != NULL)
    {
        lb = headol;
        while (lb != NULL)
        {
            struct list* node;
            node = (struct list*)malloc(sizeof(struct list));
            node->next = NULL;
            node->date1 = la->date1 * lb->date1;
            node->date2 = la->date2 + lb->date2;
            struct list* temp = newlist->next;
            newlist->next = node;
            node->next = temp;
            lb = lb->next;
        }
        la = la->next;
    }
    return(newlist->next);
}
struct list* Derivation(struct list* head)
{
    struct list* la = head;
    while (la != NULL)
    {
        la->date1 = la->date1 * la->date2;
        la->date2--;
        la = la->next;
    }
    return head;
}
struct list* Generationvalue(struct list* head,int x)
{
    double sum = 0;
    struct list* temp = head;
    while (head != NULL)
    {
        sum = sum+head->date1* pow(x, head->date2);
        head = head->next;
    }
    printf("值为%.0lf", sum);
    return temp;
}
 
