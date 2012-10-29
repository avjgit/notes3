#include "d7.cpp"

void d7()
{
    const char enqueue    = '+';
    const char dequeue    = '-';
    const char stop       = 'x';

    string msg_get_input  = "Enter +a to enqueue a, - to dequeue, x to stop: ";
    string msg_bad_input  = "Your input is incorrect";
    string msg_dequeue_ok = " was just dequeued.";
    string msg_dequeue_no = "Queue is empty, dequeuing not possible.";
    string msg_end        = "Program is over.";

    Queue q;
    char command = ' ';
    while (command != stop)
    {
        print(msg_get_input);
        cin >> command;
        switch (command)
        {
            case enqueue:
                q.enqueue();
                break;
            case dequeue:
                print( q.is_empty() ? msg_dequeue_no : to_char(q.dequeue()) + msg_dequeue_ok);
                break;
            case stop:
                break;
            default:
                print(msg_bad_input);
        }
    }
    print(msg_end);
}

int main()
{
    // auto tests
    int init_size = 3;
    Queue q;
    int input [] = {1, 2, 3};

    q.enqueue(init_size, input);
    test(to_char(init_size) + " in queue", init_size, q.count());

    q.dequeue();
    test(to_char(init_size-1) + " in queue", init_size-1, q.count());


    // manual input
    d7();

    system("pause");
    return 0;
}
