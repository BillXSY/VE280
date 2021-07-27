//
// Created by 71401 on 2021/7/24.
//

#ifndef PROJECT5_DLISTIMPL_H
#define PROJECT5_DLISTIMPL_H

#include "Dlist.h"

using namespace std;

// EFFECTS: returns true if list is empty, false otherwise
template<class T>
bool Dlist<T>::isEmpty() const {
    if (first == nullptr && last == nullptr) {
        return true;
    }
    return false;
}

// EFFECTS inserts o at the front of the list
template<class T>
void Dlist<T>::insertFront(T *op) {
    auto newNode = new node;
    newNode->next = first;
    newNode->prev = nullptr;
    newNode->op = op;
    if (isEmpty()) {
        first = last = newNode;
    } else {
        first->prev = newNode;
        first = newNode;
    }
}

// EFFECTS inserts o at the back of the list
template<class T>
void Dlist<T>::insertBack(T *op) {
    auto newNode = new node;
    newNode->next = nullptr;
    newNode->prev = last;
    newNode->op = op;
    if (isEmpty()) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

// EFFECTS removes and returns first object from non-empty list
//         throws an instance of EmptyList if empty
template<class T>
T *Dlist<T>::removeFront() {
    if (isEmpty()) {
        throw EmptyList{};
    }
    node *victim = first;
    T *op = victim->op;
    if (first == last) {
        first = nullptr;
        last = nullptr;
    } else {
        first = first->next;
        first->prev = nullptr;
    }
    delete victim;
    return op;
}

// EFFECTS removes and returns last object from non-empty list
//         throws an instance of EmptyList if empty
template<class T>
T *Dlist<T>::removeBack() {
    if (isEmpty()) {
        throw EmptyList{};
    }
    node *victim = last;
    T *op = victim->op;
    if (first == last) {
        first = nullptr;
        last = nullptr;
    } else {
        last = last->prev;
        last->next = nullptr;
    }
    delete victim;
    return op;
}

// constructor
template<class T>
Dlist<T>::Dlist() {
    first = nullptr;
    last = nullptr;
}

// copy constructor
template<class T>
Dlist<T>::Dlist(const Dlist &l) {
    first = nullptr;
    last = nullptr;
    copyAll(l);
}

// assignment operator
template<class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l) {
    if (this != &l) {
        removeAll();
        copyAll(l);
    }
    return *this;
}

// destructor
template<class T>
Dlist<T>::~Dlist() {
    removeAll();
}

// EFFECT: called by copy constructor/operator= to copy elements
//         from a source instance l to this instance
template<class T>
void Dlist<T>::copyAll(const Dlist &l) {
    removeAll();
    if (l.isEmpty()) {
        return;
    }
    node *curr_tar = l.first;
    while (curr_tar) {
        auto op = new T(*curr_tar->op);
        insertBack(op);
        curr_tar = curr_tar->next;
    }
}

// EFFECT: called by destructor/operator= to remove and destroy
//         all list elements
template<class T>
void Dlist<T>::removeAll() {
    while (!isEmpty()) {
        removeFront();
    }
}

#endif //PROJECT5_DLISTIMPL_H
