#include<stdio.h>
#include<stdlib.h>

struct linkedlist {
    int info;
    struct linkedlist *link;
};

void insertionatbeg(struct linkedlist **startnode, int x) {
    struct linkedlist *node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    node->info = x;
    node->link = *startnode;
    *startnode = node;

    printf("Data inserted at the beginning.\n");
}

void insertatend(struct linkedlist **startnode, int x) {
    struct linkedlist *node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    node->info = x;
    node->link = NULL;

    if (*startnode == NULL) {
        *startnode = node;
    } else {
        struct linkedlist *temp = *startnode;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = node;
    }

    printf("Data inserted at the end.\n");
}

void insertafterany(struct linkedlist *startnode, int afterValue, int x) {
    struct linkedlist *node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    node->info = x;

    struct linkedlist *current = startnode;
    while (current != NULL && current->info != afterValue) {
        current = current->link;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", afterValue);
        free(node);
    } else {
        node->link = current->link;
        current->link = node;
        printf("Data inserted after node with value %d.\n", afterValue);
    }
}

void displayList(struct linkedlist *startnode) {
    struct linkedlist *current = startnode;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->link;
    }
    printf("NULL\n");
}

int main() {
    struct linkedlist *startnode = NULL;
    int x;

    printf("Enter the value: ");
    scanf("%d", &x);

    insertionatbeg(&startnode, x);
    insertatend(&startnode, x);

    printf("Enter the value after which you want to insert: ");
    scanf("%d", &x);

    insertafterany(startnode, x, 2);

    displayList(startnode);

    return 0;
}
