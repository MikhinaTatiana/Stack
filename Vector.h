#pragma once
#include "StackImplementation.h"

class VectorImplementation : public IStackImplementation {
public:
    VectorImplementation() {
        _data = nullptr;
        _size = 0;
        _capacity = 0;
    }

    ~VectorImplementation() override {
        delete[] _data;
    }

    void push(const ValueType& value) override {
        if (_size == _capacity) {
            if (_capacity == 0) {
                resize(4);
            } else {
                resize(_capacity * 2);
            }
        }

        _data[_size] = value;
        _size = _size + 1;
    }

    void pop() override {
        if (_size > 0) {
            _size = _size - 1;
        }
    }

    const ValueType& top() const override {
        return _data[_size - 1];
    }

    bool isEmpty() const override {
        if (_size == 0) return true;
        return false;
    }

    size_t size() const override {
        return _size;
    }

private:
    void resize(size_t newCap) {
        ValueType* newData = new ValueType[newCap];

        for (size_t i = 0; i < _size; i = i + 1) {
            newData[i] = _data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = newCap;
    }

    ValueType* _data;
    size_t _size;
    size_t _capacity;
};