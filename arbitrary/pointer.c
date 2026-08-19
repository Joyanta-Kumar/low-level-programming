#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printNode(const Node* node) {
    printf("[ \e[31;1m%d\e[0m | \e[34;1m%p\e[0m ]\n", node->data, node->next);
}

typedef struct {
    Node* head;
    int size;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void printList(const List* list) {

}

void append(List* list, Node* node) {
    if (list->head == NULL) {
        list->head = node;
    }
    else {
        Node* tail = list->head->next;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = node;
    }
    list->size += 1;
}

int main() {    
    List* list = createList();

    append(list, createNode(1));
    append(list, createNode(2));
    append(list, createNode(3));

    printf("%d", list->size);
    printf("\n");
}
