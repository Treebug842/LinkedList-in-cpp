#include "LinkedList.h"

using namespace std;

void LinkedList::append(std::string data) {
    node *tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    if (head == NULL) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tail = tail->next;
    }
}

int LinkedList::length() {
    node *tmp = new node;
    if (head == NULL)
        return 0;
    tmp->next = head->next;
    if (tmp->next == NULL)
        return 1;
    length_count = 1;
    while (tmp->next != NULL) {
        tmp->next = tmp->next->next;
        length_count++;
    }
    delete tmp;
    return length_count;
}

std::string LinkedList::read(int index) {
    node *tmp = new node;
    tmp->data = head->data;
    tmp->next = head->next;
    for (int x = 0; x < index; x++) {
        tmp->data = tmp->next->data;
        tmp->next = tmp->next->next;
    }
    return tmp->data;
}

void LinkedList::write(int index, std::string data) {
    node *tmp = new node;
    if (index == 0) {
        head->data = data;
    }
    else {
        tmp->next = head->next;
        std::string *place = &head->data;
        write_count = 0;
        do {
            place = &tmp->next->data;
            tmp->next = tmp->next->next;
            write_count++;
        } while (write_count != index);
        *place = data;
    }
    delete tmp;
}

void LinkedList::clear() {
    delete head;
    head = NULL;
}

void LinkedList::remove(int index) {
    node *tmp = new node;
    node *hold = new node;
    tmp = head;
    for (int x = 0; x < index; x++) {
        tmp = tmp->next;
    }
    hold = tmp;
    while (tmp->next != NULL) {
        tmp->data = hold->next->data;
        tmp->next = hold->next->next;
        hold = hold->next;
    }
    delete tmp;
    delete hold;
}

std::string LinkedList::pop(int index) {
    node *tmp = new node;
    node *hold = new node;
    tmp = head;
    for (int x = 0; x < index; x++) {
        tmp = tmp->next;
    }
    hold = tmp;
    std::string popValue = tmp->data;
    while (tmp->next != NULL) {
        tmp->data = hold->next->data;
        tmp->next = hold->next->next;
        hold = hold->next;
    }
    delete tmp;
    delete hold;
    return popValue;
}

std::string LinkedList::loop_update() {
    if (loop == false)
        loop = true;
    if (loop_count == 0) {
        loop_count++;
        return head->data;
    }
    node *tmp = new node;
    tmp = head;
    for (int x = 0; x < loop_count; x++) {
        tmp = tmp->next;
    }
    if (tmp->next == NULL)
        loop = false;
    loop_count++;
    return tmp->data;
}


