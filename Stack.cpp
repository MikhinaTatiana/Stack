#include "Stack.h"
#include "StackImplementation.h"
#include "List.h"
#include "Vector.h"

//
// constructor
//
Stack::Stack(StackContainer container) {
    _containerType = container;

    if (container == StackContainer::List) {
        _pimpl = new ListImplementation();
    } else {
        _pimpl = new VectorImplementation();
    }
}

Stack::Stack(const ValueType* valueArray,
             const size_t arraySize,
             StackContainer container) {
    _containerType = container;

    if (container == StackContainer::List) {
        _pimpl = new ListImplementation();
    } else {
        _pimpl = new VectorImplementation();
    }

    for (size_t i = 0; i < arraySize; i = i + 1) {
        push(valueArray[i]);
    }
}

//
// destructor
//
Stack::~Stack() {
    delete _pimpl;
}

//
// basic methods
//
void Stack::push(const ValueType& value) {
    _pimpl->push(value);
}

void Stack::pop() {
    _pimpl->pop();
}

const ValueType& Stack::top() const {
    return _pimpl->top();
}

bool Stack::isEmpty() const {
    return _pimpl->isEmpty();
}

size_t Stack::size() const {
    return _pimpl->size();
}

//
// copy constructor (explicit!)
//
Stack::Stack(const Stack& other) {
    _containerType = other._containerType;

    if (_containerType == StackContainer::List) {
        _pimpl = new ListImplementation();
    } else {
        _pimpl = new VectorImplementation();
    }

    Stack temp(other._containerType);
    Stack copy(other);   // ❗ ВАЖНО: не "=", а прямой вызов

    while (!copy.isEmpty()) {
        temp.push(copy.top());
        copy.pop();
    }

    while (!temp.isEmpty()) {
        push(temp.top());
        temp.pop();
    }
}

//
// copy assignment
//
Stack& Stack::operator=(const Stack& other) {
    if (this == &other) return *this;

    delete _pimpl;

    _containerType = other._containerType;

    if (_containerType == StackContainer::List) {
        _pimpl = new ListImplementation();
    } else {
        _pimpl = new VectorImplementation();
    }

    Stack temp(other._containerType);
    Stack copy(other);   // ❗ тоже фикс

    while (!copy.isEmpty()) {
        temp.push(copy.top());
        copy.pop();
    }

    while (!temp.isEmpty()) {
        push(temp.top());
        temp.pop();
    }

    return *this;
}

//
// move constructor
//
Stack::Stack(Stack&& other) noexcept {
    _pimpl = other._pimpl;
    _containerType = other._containerType;

    other._pimpl = nullptr;
}

//
// move assignment
//
Stack& Stack::operator=(Stack&& other) noexcept {
    if (this == &other) return *this;

    delete _pimpl;

    _pimpl = other._pimpl;
    _containerType = other._containerType;

    other._pimpl = nullptr;

    return *this;
}
#include <iostream>

int main() {
    Stack s(StackContainer::List);

    s.push(10);
    s.push(20);

    std::cout << s.top() << std::endl;

    return 0;
}