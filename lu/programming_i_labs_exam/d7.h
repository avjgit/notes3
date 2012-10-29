// http://en.wikipedia.org/wiki/Include_guard
#ifndef NUMBER_QUEUE_H_GUARD
#define NUMBER_QUEUE_H_GUARD

#include "utils.h"

class Queue
{
private:
    static const string msg_destructed;
    static const string msg_destructed_size;
    static const string msg_empty;
    static const string msg_full;
    static const string msg_queue;

    static const int queue_max_size = 5;
    int queue[queue_max_size];
    int size;

public:

    Queue();
    Queue(int _size, int* elements);
    ~Queue();

    void print();
    void print(string a);

    void enqueue();
    void enqueue(int element);
    void enqueue(int _size, int* elements);

    int dequeue();

    int count();

    bool is_empty();
    bool is_full();
};
#endif
