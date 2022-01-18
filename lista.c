#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int val;
    struct Node *next;
};

void listAdd(struct Node **list, int val);
void listPrint(struct Node *pn);
int listLenght(struct Node *list);
int listPosition(struct Node *list, int val);
void listRemoveAt(struct Node **list, int val);

int main(){
    struct Node *list = NULL;
    char input[25] = "";
    while (strcmp(input, "stop") != 0)
    {
        printf("Inserisci un numero per inserirlo nella lista, o \"stop\" per terminare: ");
        scanf("%s", &input);

        if (strcmp(input, "stop") != 0)
        {
            listAdd(&list, atoi(input));
        }
    }
    printf("Lungezza: %d\n", listLenght(list));
    int pos;
    printf("Inserisci un numero da cercare nella lista: ");
    scanf("%d", &pos);
    pos = listPosition(list, pos);
    if (pos != -1)
    {
        printf("valore trovato alla posizione %d\n", pos + 1);
    } else
    {
        printf("valore non presente nella lista\n");
    }
    printf("Lista:\n");
    listPrint(list);
    int rem;
    printf("Inserisci la posizione da rimuovere: ");
    scanf("%d", &rem);
    listRemoveAt(&list, rem - 1);
    printf("Lista con il valore rimosso:\n");
    listPrint(list);
}

void listAdd(struct Node **list, int val) {
    struct Node *p = *list;
    // If the list is not empty the pointer goes on until the last one
    // Else alloc
    if (*list)
    {
        while (p -> next)
        {
            p = p -> next;
        }
        
        p -> next = malloc(sizeof(struct Node));
        p = p -> next;
    } else {
        *list = malloc(sizeof(struct Node));
        p = *list;
    }
    p -> val = val;
    p -> next = NULL;
}

int listLenght(struct Node *list) {
    int l = 0;
    if (list)
    {
        l++;
        while (list -> next)
        {
            l++;
            list = list -> next;
        }
    }
    return l;
}

int listPosition(struct Node *list, int val) {
    int p = 0;
    if (list)
    {
        while (list -> next && list -> val != val)
        {
            p++;
            list = list -> next;
        }
        if (list -> next == NULL && list -> val != val)
        {
            p = -1;
        }
    } else {
        p = -1;
    }
    return p;
}

void listRemoveAt(struct Node **list, int val) {
    struct Node *p = *list;
    if (p)
    {
        for (int i = 0; i < val && p; i++)
        {
            p = p -> next;
        }
        if (p)
        {
            struct Node *p2 = p -> next;
            if (p2)
            {
                if (val == 0)
                {
                    *list = p -> next;
                    free(p);
                } else {
                    p -> next = p2 -> next;
                    free(p2);
                }
            } else {
                p -> next = p2;
            }
        }
    }
}

void listPrint(struct Node *pn) {
    while (pn){
        printf("%d ",pn->val);
        pn = pn -> next;
    }
    printf("\n");
}