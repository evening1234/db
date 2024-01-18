#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Person {
    Person *next;
    char lastname[50];
    char name[50];
    int age;
    char id[50];
    char sex[50];
    Person *prev;
};

struct List {
    Person *head;
    Person *tail;
    int size;
};

void printPerson(Person *ptr) {
    printf("lastname is:%s\n", ptr->lastname);
    printf("name:%s\n", ptr->name);
    printf("age is:%d\n", ptr->age);
    printf("ID is:%s\n", ptr->id);
    printf("sex is:%s\n", ptr->sex);
}

void showList(Person *head) {
    Person *ptr = head;
    if (ptr == NULL) {
        printf("List is empty!\n");
    } else {
        while (ptr != NULL) {
            printPerson(ptr);
            ptr = ptr->next;
        }
    }
}

void addPerson(List *list, Person *person) {
    if (list->head != NULL) { // add new element at the end
        person->prev = list->tail;
        list->tail->next = person;
        list->tail = person;
        person->next = NULL;
    } else { // add first element
        person->next = NULL;
        person->prev = NULL;
        list->head = person;
        list->tail = person;
    }
}

Person *scanPerson() {
    Person *person = (Person *) malloc(sizeof(Person));
    printf("lastname: ");
    scanf("%s", person->lastname);
    printf("name: ");
    scanf("%s", person->name);
    printf("age: ");
    scanf("%d", &(person->age));
    printf("id: ");
    scanf("%s", person->id);
    printf("sex: ");
    scanf("%s", person->sex);
    return person;
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
            printPerson(i);
            break;
        }
    }
}

void options() {
    printf("-||-Hello-||-\n");
    printf("|1|-Show list-\n");
    printf("|2|-Add to list-\n");
    printf("|3|-Remove from list-\n");
    printf("|4|-Find-\n");
    printf("|5|-Sort list-\n");
    printf("|6|-Exit-\n");
}

List sortList(List *list, char ascending) {
    Person **arr = (Person **) malloc(sizeof(Person *) * list->size);

    int idx = 0;
    for (Person *i = list->head; i != NULL; i = i->next) {
        arr[idx++] = i;
    }

    for (int i = 0; i < list->size; i++) {
        for (int j = 0; j < list->size - i - 1; j++) { // > ascending, < descending
            if (ascending == 'n') {
                if (strcmp(arr[j]->lastname, arr[j + 1]->lastname) < 1) {
                    Person *temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else {
                if (strcmp(arr[j]->lastname, arr[j + 1]->lastname) > 1) {
                    Person *temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    List sortedList;
    sortedList.head = NULL;
    sortedList.tail = NULL;
    for (int i = 0; i < list->size; i++) {
        addPerson(&sortedList, arr[i]);
    }

    sortedList.size = list->size;
    free(arr);
    return sortedList;
}

void freeList(List *list) {
    if (list->head == NULL) {
        return;
    }

    for(Person *i = list->head->next; i != NULL; i = i->next) {
        free(i->prev);
    }

    free(list->tail);
}

void menu() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    int a = -1;
    options();
    while (a != 6) {

        scanf("%d", &a);
        switch (a) {
            case 1:
                showList(list.head);
                break;
            case 2: {
                Person *person = scanPerson();
                addPerson(&list, person);
                list.size++;
                printf("confirmed\n");
                break;
            }
            case 3:
                removePerson(&list);
                break;
            case 4:
                findPerson(list.head);
                break;
            case 5: {
                char ascending;
                printf("Ascending? Y/n\n");
                scanf(" %c", &ascending);

                list = sortList(&list, ascending);
                printf("Done\n");
                break;
            }
            case 6:
                printf("see you later\n");
                break;
            default:
                printf("chose something\n");
        }
    }

    freeList(&list);
}

int main() {
    menu();

    return 0;
}
