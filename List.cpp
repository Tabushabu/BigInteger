#include "stdio.h"
#include "List.h"


List newList()
{
    List lst = new ListObj;
    lst->length = 0;
    lst->cursor_pos = -1;
    lst->cursor = NULL;
    lst->front = NULL;
    lst->back = NULL;
    return lst;
}

void setListZero(List L)
{
    Node* a = L->front;
    for (int i = 0; i < L->length; i++)
    {
        Node* temp = a;
        a = a->next;
        free(temp);
    }
    L->length = 0;
    L->cursor = NULL;
    L->cursor_pos = -1;
    L->front = NULL;
    L->back = NULL;
}


Node* newNode(long val)
{
    Node a;
    a.value = val;
    a.prev = NULL;
    a.next = NULL;
 
}

void freeList(List* pL)
{
    if (pL == NULL)
    {
        fprintf(stderr, "Error: pointer to list is null in freeList function parameter");
        return;
    }
    Node* a = (*pL)->front;
    for (int i = 0; i < (*pL)->length; i++)
    {
        Node* temp = a;
        a = a->next;
        free(temp);
    }
    free(*pL);
    pL = NULL;
}

void freeNode(Node* a)
{
    if (a != NULL)
    {
        a->prev = NULL;
        a->next = NULL;
        free(a);
        a = NULL;
    }
}

int length(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is undefinded in length function\n");
    }
    return L->length;
}

int indexIt(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is undefinded in indexIt() function\n");
        return -1;
    }
    if (L->cursor_pos == -1)
    {
        return -1;
    }
    return L->cursor_pos;
}

int front(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is undefinded in front() function\n");
        return 0;
    }
    if (L->length > 0)
    {
        return L->front->value;
    }
    else
    {
        fprintf(stderr, "Error: List is empty in front() function\n");
        return 0;
    }
}

int back(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is undefinded in back() function\n");
        return 0;
    }
    if (L->length > 0)
    {
        return L->back->value;
    }
    else
    {
        fprintf(stderr, "Error: List is empty in back() function\n");
        return 0;
    }
}

long get(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is undefinded in get() function\n");
        return 0;
    }
    else if (L->length == 0)
    {
        fprintf(stderr, "Error: list is empty");
        return -1;
    }
    if (L->cursor == NULL)
    {
        return -1;
    }
    return L->cursor->value;
}
void set(List L, long x)
{
    if (L->cursor == NULL)
    {
        printf("Cursor is null in set function\n");
        return;
    }
    L->cursor->value = x;
}

void clear(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is undefinded in clear() function\n");
        return;
    }
    L->cursor_pos = -1;
    L->cursor = NULL;
    L->front = NULL;
    L->back = NULL;
    L->length = 0;
} 

void moveFront(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is NULL in moveFront function");
        return;
    }
    if (L->length == 0)
    {
        return;
    }
    L->cursor_pos = 0;
    L->cursor = L->front;
}


void moveBack(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is NULL in moveBack function");
        return;
    }
    if (L->length == 0)
    {
        return;
    }
    L->cursor_pos = L->length - 1;
    L->cursor = L->back;
}

void movePrev(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is NULL in movePrev function");
        return;
    }
    if (L->cursor_pos <= 0)
    {
       
        L->cursor_pos = -1;
        L->cursor = NULL;
        return;
    }
    L->cursor_pos--;
    L->cursor = L->cursor->prev;
}

void moveNext(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is NULL in moveNext function");
        return;
    }
    if (L->cursor_pos >= L->length - 1)
    {
        L->cursor_pos = -1;
        L->cursor = NULL;
        return;
    }
    L->cursor_pos++;
    L->cursor = L->cursor->next;
}

void prepend(List L, long data)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is Null in prepend parameter");
        return;
    }
    else if (L->length == 0)
    { 
        L->front = newNode(data);
        L->back = L->front;
    }
    else if (L->length == 1)
    {
        L->front = newNode(data);
        L->front->next = L->back;
        L->back->prev = L->front;
    }
    else
    {
        Node* temp = L->front;
        L->front = newNode(data);
        L->front->next = temp;
        temp->prev = L->front;
    }
    L->length++;
    if (L->cursor_pos != -1)
    {
        L->cursor_pos++;
    }
}

void append(List L, long data)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is Null in prepend parameter");
        return;
    }
    else if (L->length == 0)
    { 
        L->front = newNode(data);
        L->back = L->front;
    }
    else if (L->length == 1)
    {
        L->back = newNode(data);
        L->front->next = L->back;
        L->back->prev = L->front;
    }
    else
    {
        Node* temp = L->back;
        Node* a = newNode(data);
        temp->next = a;
        a->prev = temp;
        L->back = a;
    }
    L->length++;
}

void insertBefore(List L, long data)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is Null in insertBefore() parameter");
        return;
    }
    if (L->cursor_pos == -1)
    {
        fprintf(stderr, "Error: cursor is undefinded in insertBefore");
        return;
    }
    if (L->cursor == NULL)
    {
        fprintf(stderr, "Error: cursor is undefinded in insertBefore");
        return;
    }
    Node* insert = newNode(data);
    if (L->cursor_pos == 0 && L->length == 1)
    {
        Node* back = L->back;
        L->front = insert;
        insert->next = back;
        back->prev = insert;
        L->length++;
        return;
    }
    if (L->cursor_pos == 0)
    {
        L->front = insert;
        insert->next = L->cursor;
        L->cursor->prev = insert;
        L->cursor_pos++;
        L->length++;
        return;
    }
    Node* previ = L->cursor->prev;
    insert->prev = previ;
    previ->next = insert;
    insert->next = L->cursor;
    L->cursor->prev = insert;
    L->length++;
    L->cursor_pos++;
}

void insertAfter(List L, long data)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is Null in insertAfter() parameter");
        return;
    }
    if (L->cursor == NULL)
    {
        return;
    }
    Node* insert = newNode(data);
    if (L->length <= 0)
    {
        fprintf(stderr, "Error: List is empty");
        return;
    }
    if (L->cursor_pos < 0)
    {
        fprintf(stderr, "Error: cursor is undefinded in insertAfter");
        return;
    }
    if (L->cursor_pos == 0 && L->length == 1)
    {
        Node* previ = L->front;
        L->back = insert;
        insert->prev = previ;
        previ->next = insert;
        L->length++;
        return;
    }
    if (L->cursor_pos == 0)
    {
        Node* post = L->cursor->next;
        L->cursor->next = insert;
        insert->prev = L->cursor;
        post->prev = insert;
        insert->next = post;
        L->length++;
        return;
    }
    if (L->cursor_pos == L->length - 1)
    {
        L->cursor->next = insert;
        insert->prev = L->cursor;
        L->back = insert;
        L->length++;
        return;
    }

    Node* post = L->cursor->next;
    L->cursor->next = insert;
    insert->prev = L->cursor;
    insert->next = post;
    post->prev = insert;
    L->length++;
    return;
}

void deleteFront(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is Null in deleteFront() parameter");
        return;
    }
    if (L->length <= 0)
    {
        return;
    }
    if (L->cursor_pos == 0)
    {
        L->cursor_pos = -1;
        L->cursor = NULL;
    }
    if (L->length == 1)
    {
        freeNode(L->front);
        L->front = NULL;
        L->back = NULL;
        return;
    }
    if (L->cursor == L->front)
    {
        Node* temp = L->front->next;
        L->front = temp;
        L->front->prev = NULL;
        L->cursor = NULL;
        L->cursor_pos = -1;
        return;
    }
    Node* temp = L->front;
    L->front = L->front->next;
    L->front->prev = NULL;
    freeNode(temp);
    L->length--;
    if (L->cursor_pos != -1)
    {
        L->cursor_pos--;
    }
   
}

void deleteBack(List L)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is Null in deleteBack() parameter");
        return;
    }
    if (L->length <= 0)
    {
        return;
    }
    if (L->cursor_pos == L->length - 1)
    {
        L->cursor_pos = -1;
        L->cursor = NULL;
    }
    if (L->length == 1)
    {
        clear(L);
        return;
    }
    Node* temp = L->back;
    L->back = L->back->prev;
    L->back->next = NULL;
    freeNode(temp);
    L->length--;
}


long valueAt(List L, int pos)
{
    if (L == NULL)
    {
        fprintf(stderr, "Error: List is Null in deleteBack() parameter\n");
        return 0;
    }
    if (L->length < pos)
    {
        fprintf(stderr, "Cannot find value of index in valueAt, list length is %d\n", L->length);
        return 0;
    }
    int curr = 0;
    Node* a = L->front;
    for (int i = 0; i < L->length; i++)
    {
        if (curr == pos)
        {
            return a->value;
        }
        a = a->next;
        curr++;
    }
    return -1;
}

void printList(FILE* out, List L)
{
    Node* a = L->front;
    for (int i = 0; i < L->length; i++)
    {
        if (a != NULL)
        {
            Node* temp = a;
            a = a->next;
            fprintf(out, "%ld", temp->value);
        }
    }
    fprintf(out, "\n");
}

List copyList(List L)
{
    if (L == NULL)
    {
        printf("Error in copyList function: Null list\n");
        return NULL;
    }
    List a = newList();
    moveFront(L);
    while (indexIt(L) != -1)
    {
        append(a, get(L));
        moveNext(L);
    }
    return a;
}

void trimFront(List L)
{
    if (L == NULL)
    {
        return;
    }
    moveFront(L);
    while (indexIt(L) != -1)
    {
        if (length(L) <= 1) {
            break;
        }
        if (get(L) != 0)
        {
            break;
        }
        deleteFront(L);
        moveFront(L);
    }
}

List concatList(List A, List B)
{
    if (A == NULL || B == NULL)
    {
        fprintf(stderr, "Error in concatList function, List provided is null\n");
        return NULL;
    }
    List C = newList();
    Node* current = A->front;
    for (int i = 0; i < A->length; i++)
    {
        append(C, current->value);
        current = current->next;
    }
    current = B->front;
    for (int i = 0; i < B->length; i++)
    {
        append(C, current->value);
        current = current->next;
    }
    return C;
}