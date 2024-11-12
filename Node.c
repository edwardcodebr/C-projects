#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int dados;
    struct Node* ante;
    struct Node* prox;
}Node;

Node* criarNode(int dados)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->dados = dados;
    newnode->ante = NULL;
    newnode->prox = NULL;
    return newnode;
}

void ordenado(Node** cabeca, int dados)
{
    Node* newnode = criarNode(dados);
    if(*cabeca == NULL)
    {
        *cabeca = newnode;
    }else if (dados < (*cabeca)->dados)
    {
        newnode->prox = *cabeca;
        (*cabeca)->ante = newnode;
        *cabeca = newnode;
    } else{
        Node* temp = *cabeca;
        while (temp->prox != NULL && temp->prox->dados < dados)
        {
            temp = temp->prox;
        }
        newnode->prox = temp->prox;
        if (temp->prox != NULL)
        {
            newnode->prox->ante = newnode;
        }
        temp->prox = newnode;
        newnode->ante = temp;
    }
}

void deletar(Node** cabeca, int dados)
{
    Node* temp = *cabeca;
    while (temp != NULL && temp->dados != dados)
    {
        temp = temp->prox;
    }
    if (temp == NULL)
    {
        return;
    }
    if (temp->ante != NULL)
    {
        temp->ante->prox = temp->prox;
    }else {
        *cabeca = temp->prox;
    }
    if (temp->prox != NULL)
    {
        temp->prox->ante = temp->ante;
    }
    free(temp);
}

void imprimir(Node* cabeca)
{
    Node* temp = cabeca;
    while (temp != NULL)
    {
        printf("%d", temp->dados);
        temp = temp->prox;
    }
    printf("\n");
}

int main()
{
    Node* cabeca = NULL;

    printf("lista inicial:\n");
    ordenado(&cabeca,1);
    printf("\n");
    ordenado(&cabeca,3);
    printf("\n");
    ordenado(&cabeca,6);
    printf("\n");
    ordenado(&cabeca,8);
    printf("\n");
    ordenado(&cabeca,10);
    printf("\n");
    imprimir(cabeca);
    printf("\n");

    ordenado(&cabeca, 5);
    printf("apos adicionar 5:");
    criarNode(5);
    imprimir(cabeca);
    printf("\n");

    printf("apos excluir 8:");
    deletar(&cabeca, 8);
    imprimir(cabeca);
    printf("\n");


    return 0;                                                                                                                                                             
}