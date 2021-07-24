//
// Created by 71401 on 2021/7/24.
//

#ifndef PROJECT5_DLISTIMPL_H
#define PROJECT5_DLISTIMPL_H

#include "Dlist.h"

template<class T>
bool Dlist<T>::isEmpty() const {
    return !first;
}

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

template<class T>
T *Dlist<T>::removeFront() {
    T *op = first->op;
    node *victim = first;
    first = first->next;
    if (!first) {
        last = nullptr;
    } else {
        first->prev = nullptr;
    }
    delete victim;
    return op;
}

template<class T>
T *Dlist<T>::removeBack() {
    T *op = last->op;
    node *victim = last;
    last = last->prev;
    if (!last) {
        first = nullptr;
    } else {
        last->next = nullptr;
    }
    delete victim;
    return op;
}

template<class T>
Dlist<T>::Dlist() {
    first = nullptr;
    last = nullptr;
}

template<class T>
Dlist<T>::Dlist(const Dlist &l) {
    first = nullptr;
    last = nullptr;
    copyAll(l);
}

template<class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l) {
    copyAll(l);
    return *this;
}

template<class T>
Dlist<T>::~Dlist() {
    removeAll();
}

template<class T>
void Dlist<T>::copyAll(const Dlist &l) {
    removeAll();
    node *curr_tar = l.first;
    while (curr_tar) {
        auto newNode = new node;
        newNode->op = curr_tar->op;
        if (!first) {
            first = last = newNode;
        } else {
            last->next = newNode;
            newNode->prev = last;
            last = last->next;
        }
        curr_tar = curr_tar->next;
    }
}

template<class T>
void Dlist<T>::removeAll() {
    while (!isEmpty()) {
        node *victim = first;
        first = first->next;
        delete victim;
    }
    last = nullptr;
}


#endif //PROJECT5_DLISTIMPL_H
