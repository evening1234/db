#include <iostream>
struct List {
    struct List *next;
    int age;
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
int menu() {
    struct List* head = NULL;
    struct List* ptr;
    int a;
    printf("-||-Hello-||-\n");
    printf("|1|-Show list-\n");
    printf("|2|-Add to list-\n");
    printf("|3|-Remove from list-\n");
    printf("|4|-Find-\n");
    printf("|5|-List management-\n");
    printf("|6|-Exit-\n");
    //head = addList(head, 5);
    while(a!=6) {
        scanf("%d", &a);
        switch (a) {
            case 1:
                ptr = head;
                if(ptr==NULL){
                    printf("List is empty!");
                }else{
                    while(ptr != NULL){
                        printf("age is:%d\n",ptr->age);
                        ptr = ptr -> next;
                    }
                }

                break;
            case 2:
                int n;
                printf("add age:");
                scanf("%d",&n);
                if(head!=NULL){
                    head = addBeg(head,n);
                }else{
                    head = addList(head, n);
                }
                printf("confirmed\n");
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
                printf("see you later\n");
                break;
            default:
                printf("chose something\n");
        }
    }
}
//struct List* addEnd(struct List* n,int age){
//    struct List *temp,*tail;
//    temp=(List*)malloc(sizeof(struct List));
//    temp->prev = NULL;
//    temp->age = age;
//    temp->next = NULL;
//    tail = n;
//    while(tail->next != NULL) {
//        tail = tail->next;
//    }
//    tail->next=temp;
//    temp->prev=tail;
//    return n;
//}

int main() {

    menu();


//    head = addList(head,n);

//    head = addEnd(head,99);












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


