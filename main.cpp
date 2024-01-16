#include <iostream>
#include <cstring>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


using namespace std;

struct Person {
    Person *next;
    char lastname[50];
    int age;
    Person *prev;
};

struct List {
    Person *head;
    int size;
};

void showList(Person *head) {
    Person *ptr = head;
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

void addPerson(List *list) {
    Person *temp = (Person *) malloc(sizeof(Person));
    printf("age: ");
    scanf("%d", &(temp->age));
    printf("lastname: ");
    scanf("%s", temp->lastname);

    if (list->head != NULL) { // add new element at the beginning, that is, new list->head
        temp->prev = NULL;
        temp->next = list->head;
        list->head->prev = temp;
        list->head = temp;
    } else { // add first element
        temp->next = NULL;
        temp->prev = NULL;
        list->head = temp;
    }
    list->size++;

    printf("confirmed\n");
}

void removePerson(List *list) {
    char lastname[50];
    printf("lastname to remove: ");
    scanf("%s", lastname);
    for (Person *i = list->head; i != NULL; i = i->next) {
        if (strcmp(lastname, i->lastname) == 0) {
            if (i->prev == NULL && i->next == NULL) {// remove one
                list->head = NULL;
            } else if (i->prev == NULL) { // remove first
                i->next->prev = NULL;
                list->head = i->next;
            } else if (i->prev != NULL && i->next != NULL) {//remove middle
                i->prev->next = i->next;
                i->next->prev = i->prev;
            } else if (i->next == NULL) { // remove last
                i->prev->next = NULL;
            }
            list->size--;
            free(i);
            return;
        }
    }
}

void findPerson(Person *head) {
    char lastname[50];
    printf("lastname to find: ");
    scanf("%s", lastname);
    for (Person *i = head; i != NULL; i = i->next) {
        if (strcmp(lastname, i->lastname) == 0) {
            printf("age is:%d\n", i->age);
            printf("lastname is:%s\n", i->lastname);
            break;
        }
    }
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

//void sorting(Person* head){
//   Person *array = (Person*) malloc(sizeof(Person*) * n);
//
////    for () {
////
////    }
//}

int menu() {
    List list;
    list.head = NULL;
    list.size = 0;

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
                showList(list.head);
                break;
            case 2:
                addPerson(&list);
                break;
            case 3:
                removePerson(&list);
                break;
            case 4:
                findPerson(list.head);
                break;
            case 5:
//                sorting(list->head);
                break;
            case 6:
                printf("see you later\n");
                break;
            default:
                printf("chose something\n");
        }
    }
}

struct Person *addEnd(struct Person *n, int age) {
    struct Person *temp, *tail;
    temp = (Person *) malloc(sizeof(struct Person));
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


















//    Person* HEAD = createPerson(1);
//    Person* node = createPerson(2);
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


