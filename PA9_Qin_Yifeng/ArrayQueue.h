//
// Created by yifengq on 11/20/2017.
//

#ifndef PROJECT9_ARRAYQUEUE_H
#define PROJECT9_ARRAYQUEUE_H

#include "DataType.h"

const size_t ARRAY_MAX = 1000;
class ArrayQueue {
    friend std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue);

public:
    ArrayQueue();

    ArrayQueue(size_t count, const DataType &value);

    ArrayQueue(const ArrayQueue &other);

    ~ArrayQueue();

    ArrayQueue &operator=(const ArrayQueue &rhs);

    DataType &front();

    const DataType &front() const;

    DataType &back();

    const DataType &back() const;

    void push(const DataType &value);

    void pop();

    size_t size() const;

    bool empty() const;

    bool full() const;

    void clear();

    void serialize(std::ostream &os) const;

private:

    DataType m_array[ARRAY_MAX];
    size_t m_front;
    size_t m_back;
    size_t m_size;

};

#endif //PROJECT9_ARRAYQUEUE_H

