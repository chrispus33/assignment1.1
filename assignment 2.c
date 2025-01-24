#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

Node* addLists(Node* head1, Node* head2) {
    Node *result = NULL;
    Node *tail1 = head1, *tail2 = head2;
    int carry = 0;

    while (tail1 && tail1->next != NULL) tail1 = tail1->next;
    while (tail2 && tail2->next != NULL) tail2 = tail2->next;

    while (tail1 || tail2 || carry) {
        int sum = carry;
        if (tail1) {
            sum += tail1->data;
            tail1 = tail1->prev;
        }
        if (tail2) {
            sum += tail2->data;
            tail2 = tail2->prev;
        }
        carry = sum / 10;
        appendNode(&result, sum % 10);
    }

    Node* prev = NULL, *current = result, *next;
    while (current) {
        next = current->next;
        current->next = prev;
        if (prev) prev->prev = current;
        prev = current;
        current = next;
    }
    if (prev) prev->prev = NULL;
    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next)
            printf(", ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *list1 = NULL, *list2 = NULL;

    appendNode(&list1, 2);
    appendNode(&list1, 5);
    appendNode(&list1, 9);

    appendNode(&list2, 3);
    appendNode(&list2, 8);
    appendNode(&list2, 1);

    printf("Doubly linked list one: ");
    printList(list1);
    printf("Doubly linked list two: ");
    printList(list2);

    Node* result = addLists(list1, list2);

    printf("Result (sum stored in a doubly linked list): ");
    printList(result);

    return 0;
}