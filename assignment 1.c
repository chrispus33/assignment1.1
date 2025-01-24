#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
Node* merge(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    Node* mergedHead = NULL;
    if (list1->data <= list2->data) {
        mergedHead = list1;
        mergedHead->next = merge(list1->next, list2);
    } else {
        mergedHead = list2;
        mergedHead->next = merge(list1, list2->next);
    }
    return mergedHead;
}

// Function to append a node to a linked list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Main function
int main() {
    Node *list1 = NULL, *list2 = NULL;

    // Create first sorted linked list
    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);

    // Create second sorted linked list
    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    Node* mergedList = merge(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
