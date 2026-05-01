#pragma once
#include "StackImplementation.h"

struct Node {
    ValueType value;
    Node* next;

    Node(const ValueType& v, Node* n = nullptr) {
        value = v;
        next = n;
    }
};

class ListImplementation : public IStackImplementation {
public:
    ListImplementation();
    ~ListImplementation() override;

    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;

private:
    Node* _head;
    size_t _size;
};