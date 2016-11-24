#pragma once

#include <iostream>

template <class T>
struct Node {
    Node* next_;
    Node* prev_;

    T data_;

    Node(T data);
};

template <class T>
Node<T>::Node(T data)
    : data_(data),
      next_(nullptr),
      prev_(nullptr) {}

template <class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(T first);

    void add(T entry);
    void remove();
    void removeAll();

    T getFirst();
    T getLast();
    T get();

    void next();
    void prev();

    int size();

    int num_entries_;
    Node<T>* head_;
    Node<T>* curr_;
    Node<T>* tail_;
};

template <class T>
LinkedList<T>::LinkedList()
    : num_entries_(0),
      head_(nullptr),
      tail_(nullptr),
      curr_(nullptr) {

}

template <class T>
LinkedList<T>::LinkedList(T first)
    : num_entries_(0),
      head_(nullptr),
      tail_(nullptr),
      curr_(nullptr) {

    this.add(first);
}

template <class T>
void LinkedList<T>::add(T entry) {
    if (head_ == nullptr || tail_ == nullptr) {
        
        head_ = new Node<T>(entry);
        tail_ = head_;
        curr_ = head_;

        num_entries_ = 1;
    } else {
        Node<T> *node = new Node<T>(entry);

        if (num_entries_ == 1) {
            node->prev_ = head_;
            node->next_ = head_;

            tail_ = node;
            head_->next_ = tail_;
            head_->prev_ = tail_;
        } else {
            node->next_ = head_;
            node->prev_ = tail_;

            tail_->next_ = node;
            tail_ = node;
        }

        num_entries_++;
    }
}

template <class T>
void LinkedList<T>::remove() {
    Node<T>* temp = curr_;
    temp->prev_->next_ = temp->next_;
    temp->next_->prev_ = temp->prev_;

    curr_ = temp->prev_;
    num_entries_ -= 1;

    delete temp;

    if (num_entries_ == 0) {
        curr_ = nullptr;
    }
}

template <class T>
void LinkedList<T>::removeAll() {
    while (num_entries_ > 0) {
        Node<T>* temp = tail_;
        tail_ = tail_->prev_;
        delete temp;
        num_entries_ -= 1;
    }
}

template <class T>
T LinkedList<T>::getFirst() {
    std::cout << "getFirst" << std::endl;
    return head_->data_;
}

template <class T>
T LinkedList<T>::getLast() {
    std::cout << "getLast" << std::endl;
    return tail_->data_;
}

template <class T>
T LinkedList<T>::get() {
    return curr_->data_;
}

template <class T>
void LinkedList<T>::next() {
    if ((curr_ = curr_->next_) == nullptr) {
        std::cout << "No next element";
    }
}

template <class T>
void LinkedList<T>::prev() {
    if ((curr_ = curr_->prev_) == nullptr) {
        std::cout << "No previous element";
    }
}

template <class T>
int LinkedList<T>::size() {
    return num_entries_;
}
