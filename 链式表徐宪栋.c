#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node
{
    int data;
    struct Node *next;
}Node,*LinkList;
 
struct Node *InitList(LinkList L,Node *node)  //����˳���������
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
 
void SearchList(LinkList L,int data)  //��ֵ����
{
    if(L==NULL)
    {
        printf("���Ա�Ϊ��!\n");
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
        printf("���ҳɹ�����Ҫ���ҵ��ǵ�%d���ڵ�\n",i+1);
        return ;
    }
    if(p->next != NULL)
    {
        printf("���Ա���û�д˽ڵ�\n");
        return ;
    }
 
}
 
 
void InsertList(LinkList L,int data) //����
{
    if(L==NULL)
    {
        printf("���Ա�Ϊ��!\n");
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
    printf("����ɹ�!");
 
}
void DeleteList(LinkList L,int data) //ɾ��
{
    if(L==NULL)
    {
        printf("���Ա�Ϊ��!\n");
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
        printf("δ���ҵ�Ҫɾ���Ľڵ�\n");
    printf("ɾ���ɹ�����ɾ���˵�%d�ڵ�",i);
 
}
 
void menu()
{
    printf("*************1������**************\n");
    printf("************2������***********\n");
    printf("************3������***********\n");
    printf("************4��ɾ��***********\n");
    printf("************5���������**********\n");
    printf("************0���˳�***********\n");
 
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
    printf("���������ѡ��:\n");
    scanf("%d",&num);
    while(1)
    {
        switch(num)
        {
        case 1:
            printf("��������L�����������ݣ���0��β��:\n");
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
            printf("��������Ҫ���ҵ�ֵ:\n");
            scanf("%d",&data);
            SearchList(L,data);
            break;
        case 3:
            printf("��������Ҫ�����ֵ:\n");
            scanf("%d",&data);
            InsertList(L,data);
            break;
        case 4:
            printf("��������Ҫɾ����ֵ:\n");
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
        printf("���������ѡ��:\n");
        scanf("%d",&num);
    }
    return 0;
}
