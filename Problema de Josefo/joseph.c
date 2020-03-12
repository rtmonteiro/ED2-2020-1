//
// Created by rtfsmonteiro on 10/03/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "joseph.h"

struct node {
    int pos;
    Person* next;
};

Person* enterTheCircle(Person* new, Person* head) {
    Person* aux = head;
    for(Person* p = head->next; p != head; p = p->next) {
        aux = p;
    }
    aux->next = new;
    new->next = head;
    return head;
}

Person* createPerson(int pos) {
    Person* person = (Person *) malloc(sizeof(Person));
    person->pos = pos;
    person->next = person;

    return person;
}

void freePerson(Person *person) {
    free(person);
}

Person *takeOutPerson(Person *person) {

    Person* aux = person;
    for (Person* p = person->next; p != person; p = p->next) {
        aux = p;
    }

    aux->next = person->next;
    person->next = NULL;

    printf("%d ", person->pos);
    freePerson(person);

    return aux->next;
}

void startThePlay(int n, int m) {

    int participants = n;

    printf("E comeca a eleicao...\n");

    Person* head = createPerson(1);
    for (int i = 2; i < n + 1; ++i) {
        Person* p = createPerson(i);
        enterTheCircle(p, head);
    }

    while (participants > 1) {
        Person* p = head;
        for (int i = 1; i < m; ++i) {
            p = p->next;
        }
        head = takeOutPerson(p);
        --participants;
    }

    printf("\n%d eh o lider escolhido", head->pos);
}
