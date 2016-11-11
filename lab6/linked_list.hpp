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
      prev_(nullptr) {

}

template <class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(T first);

    void add(T entry);
    void remove(T entry);
    void removeAll();
    void sort();

    T getFirst();

    int num_entries_;
    Node<T>* head_;
    Node<T>* tail_;
};

template <class T>
LinkedList<T>::LinkedList()
    : num_entries_(0),
      head_(nullptr),
      tail_(nullptr) {

}

template <class T>
LinkedList<T>::LinkedList(T first)
    : num_entries_(0) {

    this.add(first);
}

template <class T>
void LinkedList<T>::add(T entry) {
    if (head_ == nullptr || tail_ == nullptr) {
        std::cout << "First" << std::endl;

        head_ = new Node<T>(entry);
        tail_ = head_;

        num_entries_ = 1;
        std::cout << "End first" << std::endl;
    } else {
        std::cout << "More than first" << std::endl;

        Node<T> *node = new Node<T>(entry);

        node->next_ = tail_;
        node->prev_ = head_;

        tail_->prev_ = node;
        tail_ = node;

        num_entries_++;
    }
}

template <class T>
void LinkedList<T>::remove(T entry) {

}

template <class T>
void LinkedList<T>::removeAll() {

}

template <class T>
T LinkedList<T>::getFirst() {
    std::cout << "getFirst" << std::endl;
    return head_->data_;
}

template <class T>
void LinkedList<T>::sort() {

}


