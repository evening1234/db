#include <iostream>

struct List {
    struct List *next;
    char lastName;
    char name;
    int age;
    char id;
    char sex;
    struct List *prev;
};

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
struct List* addList(List* n,char lastName,char name,int age,char id,char sex){
    List *temp =(List*)malloc(sizeof(List));
    temp->prev = NULL;
    char lastName=lastName;
    char name=name;
    int age=age;
    char id=id;
    char sex=sex;
    temp->next = NULL;
    n = temp;
    return n;
}

struct List* addBeg(List* n,char lastName,char name,int age,char id,char sex){
    List *temp =(List*)malloc(sizeof(List));
    temp->prev = NULL;
    temp->age = age;
    temp->next = NULL;
    temp->next = n;
    n->prev = temp;
    n = temp;
    return n;
}
struct List* addEnd(List* n,int age){
    List *temp,*tail;
    temp=(List*)malloc(sizeof(List));
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
int menu() {
    int a=-1;
    struct List* head = NULL;
    struct List* ptr;


    while(a!=6) {
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

                break;
            case 2:
                head = addList(head,f,f,f,f,f);
                head = addBeg(head, f,f,f,f,f);
                head = addBeg(head, f,f,f,f,f);
                head = addBeg(head, f,f,f,f,f);
                head = addEnd(head, 99);
                ptr = head;
                while (ptr != NULL) {
                    printf("%d\n", ptr->age);
                    ptr = ptr->next;
                }

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
}

int main() {
    menu();
    return 0;

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
    }














