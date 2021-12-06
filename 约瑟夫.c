#include <stdio.h>
#include <stdlib.h>
struct list {
    int date;
    struct list* next;//顺时针
    struct list* denext;//逆时针
};
struct list* creatnode(struct list* head);
void outputlist(struct list* head,int n);
int main()
{
    int i = 0;
    printf("请问多少人参与游戏(大于1):");
    scanf("%d", &i);
    struct list* tail = NULL;
    struct list* head = NULL;
    int temp = i;
    while (temp)
    {
        head = creatnode(head);
        temp--;
    }
    tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = head;
    head->denext = tail;
    outputlist(head, i);/*随机head输出*/
    int cnt = rand() % 10 + 1;
    while (cnt)
    {
        head = head->next;
        cnt--;
    }
    outputlist(head, i);/*对比*/
    while(i)
    {
        int Temp = head->date;
            if (Temp  == 1)
            {
                struct list* ne = head->next;
                head->denext->next = head->next;
                head->next->denext = head->denext;
                free(head);
                head = ne;
                i--;
                outputlist(head, i);
            }
            else
            {
                if (i == 2)
                {
                    if (Temp % 2 == 0)
                    {
                        outputlist(head, 1);
                        free(head->next);
                        i--;
                    }
                    else
                    {
                        outputlist(head->next, 1);
                        free(head);
                        i--;
                    }
                }
                else
                {
                    if (Temp % i==0)
                    {
                        struct list* ne = head->denext;
                        head->denext->denext->next= head;
                        head->denext = ne->denext;
                        free(ne);
                        i--;
                        outputlist(head, i);
                    }
                    else
                    {
                    while (Temp % i - 1)
                    {

                        head = head->next;
                        Temp--;
                    }
                    struct list* ne = head->next;
                    head->denext->next = head->next;
                    head->next->denext = head->denext;
                    free(head);
                    head = ne;
                    i--;
                    outputlist(head, i);
                    }
                }
            }
        if (i == 1)
            break;
    }
}
struct list* creatnode(struct list* head)//创建结点
{
    if (head == NULL)
    {
        head = (struct list*)malloc(sizeof(struct list));
        head->date = rand()%10+1;
        //scanf("%d", &head->date);
        head->next = NULL;
        head->denext = NULL;
        return head;
    }
    else
    {
        struct list* node = (struct list*)malloc(sizeof(struct list));
        node->date = rand() % 10+1;
        //scanf("%d", &node->date);
        node->next = head;
        head->denext = node;
        head = node;
        return head;
    }
}
void outputlist(struct list* head,int n)
{
    while (n)
    {
        printf("%d ", head->date);
        head = head->denext;
        n--;
    }
    printf("\n\n");
}
