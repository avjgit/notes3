// http://en.wikipedia.org/wiki/Include_guard
#ifndef NUMBER_QUEUE_H_GUARD
#define NUMBER_QUEUE_H_GUARD

#include "utils.h"

class number_queue
{
private:
    static const int queue_size = 5;
    int queue[queue_size];
    int size;

public:

    number_queue();
    number_queue(int _size, int* elements);

    ~number_queue();

    void print();
    void print(string a);

    void enqueue();
    void enqueue(int element);

    int dequeue();

    int count();

    bool is_empty();
};
#endif
