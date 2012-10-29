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
    Queue q;

    int input [] = {1, 2, 3};
    q.enqueue(3, input);

    test("3 in queue", 3, q.count());

    d7();
    system("pause");
    return 0;
}
