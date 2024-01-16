#include <iostream>
#include <cstring>

using namespace std;
struct List {
    List *next;
    char lastname[50];
    int age;
    List *prev;
};

void showList(List *head) {
    List *ptr = head;
    if (ptr == NULL) {
        printf("List is empty!\n");
    } else {
        while (ptr != NULL) {
            printf("age is:%d\n", ptr->age);
            printf("lastname is:%s\n", ptr->lastname);
            ptr = ptr->next;
        }
    }
}

List *addPerson(List *head) {
    List *temp = (List *) malloc(sizeof(List));
    printf("age: ");
    scanf("%d", &(temp->age));
    printf("lastname: ");
    scanf("%s", temp->lastname);

    if (head != NULL) { // add new element at the beginning, that is, new head
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    } else { // add first element
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return head;
    }

    printf("confirmed\n");
    return head;
}

List *removePerson(List *head) {
    char lastname[50];
    printf("lastname to remove: ");
    scanf("%s", lastname);
    for (List *i = head; i != NULL; i = i->next) {
        if (strcmp(lastname, i->lastname) == 0) {
            if (i->prev == NULL && i->next == NULL) {// remove one
                head = NULL;
            } else if (i->prev == NULL) { // remove first
                i->next->prev = NULL;
                head = i->next;
            } else if (i->prev != NULL && i->next != NULL) {//remove middle
                i->prev->next = i->next;
                i->next->prev = i->prev;
            } else if (i->next == NULL) { // remove last
                i->prev->next = NULL;
            }
            free(i);
            return head;
        }
    }
}

List *findPerson(List *head) {
    char lastname[50];
    printf("lastname to find: ");
    scanf("%s", lastname);
    for (List *i = head; i != NULL; i = i->next) {
        if (strcmp(lastname, i->lastname) == 0) {
            printf("age is:%d\n", i->age);
            printf("lastname is:%s\n", i->lastname);
            break;
        }
    }
    return head;
}

int options(int a) {
    printf("-||-Hello-||-\n");
    printf("|1|-Show list-\n");
    printf("|2|-Add to list-\n");
    printf("|3|-Remove from list-\n");
    printf("|4|-Find-\n");
    printf("|5|-Sort list-\n");
    printf("|6|-Exit-\n");
    return a;

}

int menu() {
    List *head = NULL;
    int a;
    printf("-||-Hello-||-\n");
    printf("|1|-Show list-\n");
    printf("|2|-Add to list-\n");
    printf("|3|-Remove from list-\n");
    printf("|4|-Find-\n");
    printf("|5|-Sort list-\n");
    printf("|6|-Exit-\n");
    while (a != 6) {

        scanf("%d", &a);
        switch (a) {
            case 1:
                showList(head);
                break;
            case 2:
                head = addPerson(head);
                break;
            case 3:
                head = removePerson(head);
                break;
            case 4:
                head = findPerson(head);
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

struct List *addEnd(struct List *n, int age) {
    struct List *temp, *tail;
    temp = (List *) malloc(sizeof(struct List));
    temp->prev = NULL;
    temp->age = age;
    temp->next = NULL;
    tail = n;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;
    temp->prev = tail;
    return n;
}

int main() {
    menu();


//    head = createList(head,n);

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


