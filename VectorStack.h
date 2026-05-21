#pragma once
#include "StackImplementation.h"
#include <vector>

class VectorStack : public IStackImplementation {
public:
    VectorStack() = default;
    ~VectorStack() override = default;

    void push(const ValueType& value) override {
        _data.push_back(value);
    }
    
    void pop() override {
        if (!isEmpty()) {
            _data.pop_back();
        }
    }
    const ValueType& top() const override {
        return _data.back();
    }
    bool isEmpty() const override {
        return _data.empty();
    }
    size_t size() const override {
        return _data.size();
    }
private:
    std::vector<ValueType> _data;
};
