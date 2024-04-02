// Functions.cpp

#include "Header.h"

SLinkedL::SLinkedL() : head(nullptr), tail(nullptr), numItems(0) {}

SLinkedL::SLinkedL(Item_Type item) {
    Node* tempPtr = new Node;
    tempPtr->item = item;
    tempPtr->next = nullptr;
    head = tempPtr;
    tail = tempPtr;
    numItems = 1;
}

void SLinkedL::printSingLinkedL() {
    Node* tempPtr = head;
    while (tempPtr != nullptr) {
        std::cout << " " << tempPtr->item.size;
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}

void SLinkedL::push_front(Item_Type item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = head;
    numItems++;
    head = newNode;
}

void SLinkedL::push_back(Item_Type item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;
    numItems++;

    if (isEmpty()) {
        // If the list is empty, set both head and tail to the new node
        head = tail = newNode;
    }
    else {
        // If the list is not empty, add the new node to the end and update tail
        tail->next = newNode;
        tail = newNode;
    }
}

void SLinkedL::pop_front() {
    if (!isEmpty()) {
        Node* tempPtr = head;
        head = head->next;
        delete tempPtr;
        numItems--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

void SLinkedL::pop_back() {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* tempPtr = head;
            Node* previousPtr = nullptr;

            while (tempPtr->next != nullptr) {
                previousPtr = tempPtr;
                tempPtr = tempPtr->next;
            }

            delete tail;
            tail = previousPtr;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;  // If tail is nullptr, the list is now empty
            }
        }
        numItems--;
    }
    else {
        std::cout << "List is empty. Cannot pop from the back." << std::endl;
    }
}



bool SLinkedL::isEmpty() const {
    return head == nullptr;
}

void SLinkedL::insert(size_t index, const Item_Type& item) {
    if (index < 0) {
        std::cout << "Index should be a positive number" << std::endl;
        return;
    }
    else if (index >= numItems) {
        push_back(item);
    }
    else {
        Node* newNode = new Node;
        newNode->item = item;

        Node* tempPtr = head;
        Node* previousPtr = nullptr;

        for (size_t i = 0; i < index; i++) {
            previousPtr = tempPtr;
            tempPtr = tempPtr->next;
        }
        previousPtr->next = newNode;
        newNode->next = tempPtr;
        numItems++;
    }
}

bool SLinkedL::remove(size_t index) {
    if (index < 0 || index >= numItems) {
        std::cout << "Index is out of range" << std::endl;
        return false;
    }
    else if (index == 0) {
        pop_front();
        return true;
    }
    else {
        Node* tempPtr = head;
        Node* previousPtr = nullptr;

        for (size_t i = 0; i < index; i++) {
            previousPtr = tempPtr;
            tempPtr = tempPtr->next;
        }
        previousPtr->next = tempPtr->next;
        delete tempPtr;
        numItems--;
        return true;
    }
}
size_t SLinkedL::find(const Item_Type& item) const {
    Node* tempPtr = head;
    size_t index = 0;
    while (tempPtr != nullptr) {
        if (tempPtr->item.size == item.size) {
            return index;
        }
        else {
            index++;
            tempPtr = tempPtr->next;
        }
    }
    return numItems;
}

Item_Type SLinkedL::front() const {
    if (!isEmpty()) {
        return head->item;
    }
    throw std::runtime_error("List is empty");
}

Item_Type SLinkedL::back() const {
    if (!isEmpty()) {
        return tail->item;
    }
    throw std::runtime_error("List is empty");
}

size_t SLinkedL::getNumItems() const {
    return numItems;
}
