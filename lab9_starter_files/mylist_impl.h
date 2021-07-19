//
// Created by cyx on 20-5-29.
//

#ifndef INTLIST_IMPL_H
#define INTLIST_IMPL_H

#include <iostream>
#include "mylist.h"

template<class T>
void List<T>::print() {
    Node_t<T> *itr = first;
    while (itr) {
        std::cout << itr->val;
        itr = itr->next;
    }
    std::cout << "\n";
}

template<class T>
void List<T>::removeAll() {
    while (!this->isEmpty()) {
        this->removeFront();
    }
}

template<class T>
void List<T>::copyFrom(const List &l) {
    if (!this->isEmpty()) {
        removeAll();
    }
    if (l.isEmpty()) {
        return;
    }
    Node_t<T> *curr = l.first;
    while (curr) {
        this->insertBack(curr->val);
        curr = curr->next;
    }
}

template<class T>
bool List<T>::isEmpty() const {
    return !this->first;
}

template<class T>
void List<T>::insertBack(T val) {
    auto *newNode = new Node_t<T>;
    newNode->next = nullptr;
    newNode->val = val;
    if (isEmpty()) {
//        std::cout << val << " is added to an empty list!\n";
        first = last = newNode;
    } else {
//        std::cout << val << " is added to the list!\n";
        last->next = newNode;
        last = newNode;
    }
}

template<class T>
T List<T>::removeFront() {
    if (isEmpty()) {
        EmptyList e;
        throw e;
    }
    Node_t<T> *victim = this->first;
    first = victim->next;
    T rslt = victim->val;
    delete victim;
    return rslt;
}

template<class T>
const Node_t<T> *List<T>::returnFront() const {
    return first;
}

template<class T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
}

template<class T>
List<T>::List(const List &l) {
    first = nullptr;
    last = nullptr;
    this->copyFrom(l);
}

template<class T>
List<T> &List<T>::operator=(const List &l) {
    if (this != &l) {
        removeAll();
        copyFrom(l);
    }
    return *this;
}

template<class T>
List<T>::~List() {
    this->removeAll();
}

int List2int(List<int> list) {
    int rslt = 0;
    int weight = 1;
    while (!list.isEmpty()) {
        rslt += weight * list.removeFront();
        weight *= 10;
    }
    return rslt;
}

int size(List<int> list) {
    int size = 0;
    auto *curr = (Node_t<int> *) list.returnFront();
    while (curr) {
        size++;
        curr = curr->next;
    }
    return size;
}

// EFFECTS: returns true if the number represented by
//          a is larger than the number represented by b;
//          otherwise, returns false.
//          returns false if both a and b are empty
bool isLarger(const List<int> &a, const List<int> &b) {
//    List<int> a_copy(a);
//    List<int> b_copy(b);
//    int num_a = List2int(a_copy);
//    int num_b = List2int(b_copy);
//    return num_a > num_b;
    if (a.isEmpty()) {
        return false;
    }
    if (b.isEmpty()) {
        return true;
    }
    int a_size = size(a);
    int b_size = size(b);
    if (a_size > b_size) {
        return true;
    } else if (a_size < b_size) {
        return false;
    }

    bool flag = false;
    auto *curr_a = (Node_t<int> *) a.returnFront();
    auto *curr_b = (Node_t<int> *) b.returnFront();
    while (curr_a) {
        if (curr_a->val > curr_b->val) {
            flag = true;
        } else if (curr_a->val < curr_b->val) {
            flag = false;
        }
        curr_a = curr_a->next;
        curr_b = curr_b->next;
    }
    return flag;

}

// EFFECTS: adds the numbers represented by a and b;
//          returns the result
List<int> add(const List<int> &a, const List<int> &b) {
   /* List<int> a_copy(a);
    List<int> b_copy(b);
    int num_a = List2int(a_copy);
    int num_b = List2int(b_copy);
    int rslt = num_a + num_b;
    List<int> ans;
    while (rslt) {
        ans.insertBack(rslt % 10);
        rslt /= 10;
    }
    return ans;*/
    List<int> a_copy(a);
    List<int> b_copy(b);
    int carry = 0;
    List<int> ans;
    while (!a_copy.isEmpty() && !b_copy.isEmpty()) {
        int bit = a_copy.removeFront() + b_copy.removeFront() + carry;
        carry = bit / 10;
        bit = bit % 10;
        ans.insertBack(bit);
    }
    while (!a_copy.isEmpty()) {
        int bit = a_copy.removeFront() + carry;
        carry = bit / 10;
        bit = bit % 10;
        ans.insertBack(bit);
    }
    while (!b_copy.isEmpty()) {
        int bit = b_copy.removeFront() + carry;
        carry = bit / 10;
        bit = bit % 10;
        ans.insertBack(bit);
    }
    if (carry) {
        ans.insertBack(carry);
    }
    return ans;
}


#endif //INTLIST_IMPL_H
