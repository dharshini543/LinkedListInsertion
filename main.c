#include <stdio.h>
#include <stdlib.h>

#define Success 1
#define Failure 0

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(struct node *head)
{
    struct node *newnode, *temp;
    int choice,count = 0;
    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return Failure;
        }
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != 0)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        ++count;
        printf("Want to continue... press 1 else 0\n");
        scanf("%d",&choice);
    }
    return head;
}

int displayList(struct node *head)
{
    struct node *temp = head;
    if(temp == 0)
    {
        printf("List is empty\n");
        return Failure;
    }
    else
    {
        while(temp != 0)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        return Success;
    }
}

struct node* insertAtBegginning(struct node* head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return Failure;
    }
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    newnode->next = head;
    head = newnode;
    return head;
}

struct node* insertAtEnd(struct node* head)
{
    struct node*temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return Failure;
    }
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    while(temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node* insertAtPosition(struct node* head,int pos)
{
    int i = 1;
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return Failure;
    }
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node* insertAfterASpecificNode(struct node *head,int pos)
{
    int i = 1;
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return Failure;
    }
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

int main()
{
    struct node *head = 0;
    int option,True = 1;
    while(True)
    {
    printf("Enter\n1.Create Node\n2.Display List\n3.Insert at Beggining\n4.Insert at End\n5.Insert at a specific position\n6.Insert after a specific node\n");
    scanf("%d",&option);
    switch(option)
    {
        int pos;
    case 1:
        head = createNode(head);
        break;
    case 2:
        displayList(head);
        printf("List displayed\n");
        break;
    case 3:
        head = insertAtBegginning(head);
        break;
    case 4:
        head = insertAtEnd(head);
        break;
    case 5:
        printf("Enter position to insert\n");
        scanf("%d",&pos);
        head = insertAtPosition(head,pos);
        break;
    case 6:
        printf("Enter after which node you want to insert\n");
        scanf("%d",&pos);
        head = insertAfterASpecificNode(head,pos);
    }
    }
}
