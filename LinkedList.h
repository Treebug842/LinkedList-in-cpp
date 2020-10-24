#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct node {
    std::string data;
    node *next;
};

class LinkedList {
private:
    node *head, *tail;
    int length_count;
    int write_count;
    int loop_count = 0;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void append(std::string data);
    int length();
    std::string read(int index);
    void write(int index, std::string data);
    void clear();
    void remove(int index);
    std::string pop(int index);
    std::string loop_update();
    bool loop = true;
};

#endif