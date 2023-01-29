#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// função para inicializar uma lista vazia
struct Node *initList()
{
    return NULL;
}

// função para inserir um novo nó no início da lista
struct Node *push(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// função para inserir um novo nó no final da lista
struct Node *append(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// função para remover um nó específico da lista
struct Node *removeNode(struct Node *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == data)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *current = head;
    while (current->next != NULL)
    {
        if (current->next->data == data)
        {
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        }
        current = current->next;
    }
    return head;
}