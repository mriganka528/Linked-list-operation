#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void create_ll(struct Node **head)
{
    struct Node *temp, *ptr;
    int num;
    printf("Creating the linked list.......");
    printf("\nEnter -1 to end.");
    printf("\nEnter the number :");
    scanf("%d", &num);
    while (num != -1)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = num;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            ptr = *head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        printf("\nEnter the number :");
        scanf("%d", &num);
    }
}
void print_ll(struct Node *head)
{
    printf("\nPrinting the linked list : ");
    if (head == NULL)
    {
        printf("Nothing to print.");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insert_at_head(struct Node **head)
{
    printf("\nInserting element at the begining.......");
    int data;
    printf("\nEnter the data :");
    scanf("%d", &data);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}
void insert_at_end(struct Node **head)
{
    printf("\nInserting element at the end.......");
    int data;
    printf("Enter the data :");
    scanf("%d", &data);
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void insert_before(struct Node **head)
{
    printf("\nInserting element before a given element......");
    int data, data2;
    struct Node *temp, *ptr1, *pre_node;
    printf("\nEnter the data :");
    scanf("%d", &data);
    printf("\nEnter the  value before which the data has to be inserted :");
    scanf("%d", &data2);
    temp = (struct Node *)malloc(sizeof(struct Node));
    pre_node = NULL;
    temp->data = data;
    ptr1 = *head;
    while (ptr1->data != data2)
    {
        pre_node = ptr1;
        ptr1 = ptr1->next;
    }
    if (pre_node == NULL)
    {
        temp->next = ptr1;
        *head = ptr1;
        return;
    }
    pre_node->next = temp;
    temp->next = ptr1;
}
void insert_after(struct Node **head)
{
    printf("\nInserting a node after a given value......");
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    int data, num;
    printf("\nEnter the data :");
    scanf("%d", &data);
    printf("Enter the value after which the data to be inserted :");
    scanf("%d", &num);
    temp->data = data;
    temp->next = NULL;
    ptr = *head;
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void delete_head(struct Node **head)
{
    printf("\nDeleting 1st node.....\n");
    struct Node *ptr = *head;
    *head = ptr->next;
    free(ptr);
}
void delete_end(struct Node **head)
{
    printf("\nDeleting last node......\n");
    struct Node *ptr, *pre_ptr;
    ptr = *head;
    while (ptr->next != NULL)
    {
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    pre_ptr->next = NULL;
    free(ptr);
}
void delete_node(struct Node **head)
{
    printf("\nDeleting a given node.....\n");
    struct Node *ptr, *pre_ptr;
    int data;
    ptr = *head;
    pre_ptr = NULL;
    printf("Enter the value of the node which you want to delete :");
    scanf("%d", &data);
    while (ptr->data != data)
    {
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    if (pre_ptr == NULL)
    {
        *head = ptr->next;
        free(ptr);
        return;
    }
    pre_ptr->next = ptr->next;
    free(ptr);
}
void delete_after(struct Node **head)
{
    printf("\nDeleting the next node of a given value.....\n");
    struct Node *ptr, *pre_ptr;
    int data;
    printf("Enter the value after which the node has to be deleted :");
    scanf("%d", &data);
    ptr = *head;
    pre_ptr = NULL;
    while (ptr->data != data)
    {
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    if (pre_ptr == NULL)
    {

        pre_ptr = ptr->next;
        ptr->next = ptr->next->next;
        free(pre_ptr);
        return;
    }
    pre_ptr = ptr->next;
    ptr->next = ptr->next->next;
    free(pre_ptr);
}
void delete_list(struct Node **head)
{
    struct Node *ptr = *head;
    struct Node *temp;
    while (ptr != NULL)
    {
        printf("\nData to be deleted :%d", ptr->data);
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    *head = ptr;
}
void swapp(int *n1, int *n2)
{
    int n = *n1;
    *n1 = *n2;
    *n2 = n;
}
void sorting_linked_list(struct Node **head)
{
    printf("\nSorting the linked list......\n");
    struct Node *ptr1, *ptr2;
    ptr1 = *head;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr2->data < ptr1->data)
            {
                swapp(&ptr1->data, &ptr2->data);
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void searching(struct Node **head)
{

    struct Node *ptr = *head;
    int data;
    printf("Enter the value you want to search :");
    scanf("%d", &data);
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("%d is present in the linked list.", data);
            return;
        }
        ptr = ptr->next;
    }
    printf("%d isn't present in the linked list.", data);
}
int main()
{
    struct Node *head = NULL;
    int ch;
    do
    {
        printf("\n___MENU___");
        printf("\n1)Create the linked list.\n2) Insert at head.\n3)Insert at end.\n4)Insert before a node.\n5)Insert after a node.\n6)Delete head node.\n7)Delete end node.\n8)Delete a given node.\n9)Delete a node after a given node.\n10)Delete entire list.\n10)Sort the list.\n11)Searching in the list.\n13)Print the list.\n14)Exit");
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_ll(&head);
            break;
        case 2:
            insert_at_head(&head);
            break;
        case 3:
            insert_at_end(&head);
            break;
        case 4:
            insert_before(&head);
            break;
        case 5:
            insert_after(&head);
            break;
        case 6:
            delete_head(&head);
            break;
        case 7:
            delete_end(&head);
            break;
        case 8:
            delete_node(&head);
            break;
        case 9:
            delete_after(&head);
            break;
        case 10:
            delete_list(&head);
            break;
        case 11:
            sorting_linked_list(&head);
            break;
        case 12:
            searching(&head);
            break;
        case 13:
            print_ll(head);
            break;
        case 14:
            break;
        }

    } while (ch != 14);

    return 0;
}