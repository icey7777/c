#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node
{
    int data;
    struct Node *next;
}Node,*LinkList;
 
struct Node *InitList(LinkList L,Node *node)  //建立顺序表并且排序
{
    struct Node *ptr,*ptr1,*ptr2;
   
    ptr=node;
    ptr2=L;
 
    if(L==NULL)
    {
        L=ptr;
        L->next=NULL;
    }
    else
    {
        while((ptr->data > ptr2->data)&& (ptr2->next!=NULL))
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(ptr->data <= ptr2->data)
 
        {
            if(L==ptr2)
                L=ptr;
            else
                ptr1->next=ptr;
            ptr->next=ptr2;
        }
        else
        {
            ptr2->next=ptr;
            ptr->next=NULL;
        }
    }
    return L;
}
 
void SearchList(LinkList L,int data)  //按值查找
{
    if(L==NULL)
    {
        printf("线性表为空!\n");
        return ;
    }
    int i=0;
    Node *p;
    p=L;
    while((p->data < data) &&(p->next !=NULL))
    {
        p=p->next;
        i++;
    }
    if(p->data == data)
    {
        printf("查找成功，您要查找的是第%d个节点\n",i+1);
        return ;
    }
    if(p->next != NULL)
    {
        printf("线性表中没有此节点\n");
        return ;
    }
 
}
 
 
void InsertList(LinkList L,int data) //插入
{
    if(L==NULL)
    {
        printf("线性表为空!\n");
        return ;
    }
    int i=0;
    Node *p,*ptr,*s;
    s=(Node *)malloc(sizeof(Node));
    s->data=data;
    p=L;
 
    while((p->data < data) &&(p->next !=NULL))
    {
        ptr=p;
        p=p->next;
        i++;
    }
    if(p->data >= data)
    {
        if(p==L)
        {
            s->next=p;
            L->next=s;
        }
        else
        {  
            s->next=p;
            ptr->next=s;
        }
    }
    else
    {
        p->next=s;
        s->next=NULL;
    }
    printf("插入成功!");
 
}
void DeleteList(LinkList L,int data) //删除
{
    if(L==NULL)
    {
        printf("线性表为空!\n");
        return ;
    }
    int i=0;
    Node *p,*ptr,*s;
    s=(Node *)malloc(sizeof(Node));
    s->data=data;
    p=L;
 
    while((p->data < data) &&(p->next !=NULL))
    {
        ptr=p;
        p=p->next;
        i++;
    }
    if(p->data == data)
    {
        if(p==L)
        {
            L=L->next;
            free(p);
        }
        else
        {
            ptr->next=p->next;
            free(p);
        }
    }
    else
        printf("未能找到要删除的节点\n");
    printf("删除成功，您删除了第%d节点",i);
 
}
 
void menu()
{
    printf("*************1、创建**************\n");
    printf("************2、查找***********\n");
    printf("************3、插入***********\n");
    printf("************4、删除***********\n");
    printf("************5、遍历输出**********\n");
    printf("************0、退出***********\n");
 
}
 
int main()
{  
    LinkList L;
    int data;
    Node *node,*ptr;
    node=(Node *)malloc(sizeof(Node));
    L=node=NULL;
   
    menu();
    int num;
    printf("请输入你的选择:\n");
    scanf("%d",&num);
    while(1)
    {
        switch(num)
        {
        case 1:
            printf("建立链表L，请输入数据（用0结尾）:\n");
            scanf("%d",&data);
            while(data!=0)
            {
                node=(Node*)malloc(sizeof(Node));
                node->data=data;
                L=InitList(L,node);
                scanf("%d",&data);
                node=NULL;
            }
            break;
        case 2:
            printf("请输入您要查找的值:\n");
            scanf("%d",&data);
            SearchList(L,data);
            break;
        case 3:
            printf("请输入您要插入的值:\n");
            scanf("%d",&data);
            InsertList(L,data);
            break;
        case 4:
            printf("请输入您要删除的值:\n");
            printf("%d",&data);
            DeleteList(L,data);
            break;
        case 5:
            for(ptr=L;ptr!=NULL;ptr=ptr->next)
                printf("%d",ptr->data);
            printf("\n");
            break;
        case 0:
            return 0;
        }
        printf("请输入你的选择:\n");
        scanf("%d",&num);
    }
    return 0;
}
