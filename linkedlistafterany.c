#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAfterAny(struct Node* head, int afterValue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* current = head;
    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found. Data not inserted.\n", afterValue);
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
        printf("Data %d inserted successfully after node with value %d.\n", value, afterValue);
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAfterAny(head, 0, 1);
    insertAfterAny(head, 1, 2);
    insertAfterAny(head, 2, 3);

    displayList(head);

    int afterValue, value;
    printf("Enter the value after which you want to insert: ");
    scanf("%d", &afterValue);
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    insertAfterAny(head, afterValue, value);

    displayList(head);

    return 0;
}
