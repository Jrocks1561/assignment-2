// Header.h

#pragma once

#include <iostream>
#include <stdexcept>

// Assuming Item_Type is a struct with a 'size' member
struct Item_Type {
    int size;  // You may need to adjust this based on your actual structure
};

class SLinkedL {
private:
    struct Node {
        Item_Type item;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t numItems;

public:
    SLinkedL();
    SLinkedL(Item_Type item);

    void printSingLinkedL();
    void push_front(Item_Type item);
    void push_back(Item_Type item);
    void pop_front();
    void pop_back();
    bool isEmpty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
    Item_Type front() const;
    Item_Type back() const;
    size_t getNumItems() const;
};

