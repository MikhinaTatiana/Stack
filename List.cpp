#include "List.h"

ListImplementation::ListImplementation() {
    _head = nullptr;
    _size = 0;
}

ListImplementation::~ListImplementation() {
    while (_head) {
        Node* tmp = _head;
        _head = _head->next;
        delete tmp;
    }
}

void ListImplementation::push(const ValueType& value) {
    _head = new Node(value, _head);
    _size = _size + 1;
}

void ListImplementation::pop() {
    if (!_head) return;

    Node* tmp = _head;
    _head = _head->next;
    delete tmp;
    _size = _size - 1;
}

const ValueType& ListImplementation::top() const {
    return _head->value;
}

bool ListImplementation::isEmpty() const {
    if (_head == nullptr) return true;
    return false;
}

size_t ListImplementation::size() const {
   return _size;
}