#include <iostream>

struct List {
    struct List *next;
    int age;
    struct List *prev;
};

int menu() {
    int a;
    printf("Hello\n");
    printf("1.Show list\n");
    printf("2.Add to list\n");
    printf("3.Remove from list\n");
    printf("4.Find\n");
    printf("5.List management\n");
    printf("6.Exit\n");
    scanf("%d", &a);
    switch (a) {
        case 1:
            printf("AAA\n");
            break;
        case 2:

            printf("AAA\n");
            break;
        case 3:
            printf("AAA\n");
            break;
        case 4:
            printf("AAA\n");
            break;
        case 5:
            printf("AAA\n");
            break;
        case 6:
            printf("AAA\n");
            break;
    }

}

//void printList(List* head){
//    for (List* node = head; node != NULL; node = node->next) {
//        printf("%d\n", node->age);
//    }
//}
//
//List* createPerson(int age) {
//    List* person = (List*) malloc(sizeof(List));
//    person->age = age;
//    return person;
//}
struct List* addList(struct List* n,int age){
    struct List *temp =(List*)malloc(sizeof(struct List));
    temp->prev = NULL;
    temp->age = age;
    temp->next = NULL;
    n = temp;
    return n;
}
struct List* addBeg(struct List* n,int age){
    struct List *temp =(List*)malloc(sizeof(struct List));
    temp->prev = NULL;
    temp->age = age;
    temp->next = NULL;
    temp->next = n;
    n->prev = temp;
    n = temp;
    return n;
}
struct List* addEnd(struct List* n,int age){
    struct List *temp,*tail;
    temp=(List*)malloc(sizeof(struct List));
    temp->prev = NULL;
    temp->age = age;
    temp->next = NULL;
    tail = n;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next=temp;
    temp->prev=tail;
    return n;
}

int main() {
    menu();
    struct List* head = NULL;
    struct List* ptr;
    head = addList(head,10);
    head = addBeg(head,20);
    head = addBeg(head,30);
    head = addBeg(head,40);
    head = addEnd(head,99);
    ptr = head;
    while(ptr != NULL){
        printf("%d\n",ptr->age);
        ptr = ptr -> next;
    }











//    List* HEAD = createPerson(1);
//    List* node = createPerson(2);
//    HEAD->next = node;
//    node = createPerson(3);
//    HEAD->next->next = node;
//
//    for (int i = 4; i < 100; i++) {
//        node = createPerson(i);
//        HEAD->next = node;
//    }
//
//
//    printList(HEAD);
    return 0;
}


