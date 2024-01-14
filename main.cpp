#include <iostream>

int menu(int a) {
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
    return 0;
}

//craete node
struct List {
    int age;
    struct List *next;
    struct List *prev;
};

int main() {
    int a;

    List *head;
    List *tail;
    List *n;

    n - new List;
    n->age = 1;
    n->prev = nullptr;
    head = n;
    tail = n;
    printf("%d\n", *n);

    n - new List;
    n->age = 2;
    n->prev = tail;
    tail->next = n;
    tail = n;
    printf("%d\n", *n);

    n - new List;
    n->age = 3;
    n->prev = tail;
    tail->next = n;
    tail = n;
    tail->next = nullptr;
    printf("%d\n", *n);





    //menu(a);

    return 0;
}


