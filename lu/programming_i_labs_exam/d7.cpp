// Student: Andrejs Jurcenoks aj05044
// Creation date: 2012/10/30

// REQUIREMENTS:
// Klases hederi obligāti novietot atsevišķā hedera failā (program.h).
// Visas metodes realizēt ārpus hedera faila – speciālā C++ failā (program.cpp).
// Funkcija main ievietojama vēl citā C++ failā (main.cpp).
// Klases dati pēc noklusēšanas ir slēpti (private), bet metodes atklātas (public).
// Šīs programmas ietvaros NAV obligāti jānodrošina tāda lietotāja saskarne,
// kāda tika prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst “cieti” iekodēt).
// Citas prasības sk. Laboratorijas darbu noteikumos.

// D7. Izveidot klasi "Skaitļu rinda" (queue, pa vienu pusi ieliek, pa otru izņem!),
// kurā glabājas masīvs ar skaitliskām vērtībām (int) garumā pieci
// un rindas elementu skaits.
// Klasei izveidot šādas metodes:
// (1) konstruktors,
// (2) destruktors,
// kurš paziņo par objekta likvidēšanu
// un likvidēto elementu skaitu
// (ja likvidēšanas brīdī rinda nav tukša),
// (3) metode "enqueu", kas pievieno rindai elementu,
// ja tā nav pilna,
// (4) metode "dequeu", kas izņem no rindas elementu un atgriež tā vērtību,
// (5) metode "Count", kas atgriež elementu skaitu rindā,
// (6) metode "IsEmpty", kas noskaidro, vai rinda ir tukša.
// ----------------------------------------------
#include "utils.h"

class number_queue
{
    static const int queue_size = 5;
    int queue[queue_size];
    int size;

public:

    number_queue()
    {
        size = 0;
    }

    number_queue(int _size, int* elements)
    {
        for(int i = 0; i < _size; i++)
            enqueue(elements[i]);
    }

    ~number_queue()
    {
        print("Queue was destructed.");
        if (size > 0)
            cout << endl << "There were " << size << " elements." << endl;
    }

    void print()
    {
        if (is_empty())
        {
            print("Queue is empty.");
        }
        else
        {
            cout << endl << "Queue:";
            for (int i = 0; i < size; i++)
                cout << " " << queue[i];
            cout << endl;
        }
    }

    void print(string message)
    {
        cout << endl << message << endl;
    }

    void enqueue()
    {
        int input;
        cin >> input;
        enqueue(input);
    }

    void enqueue(int element)
    {
        if (size < queue_size)
        {
            queue[size++] = element;
            print();
        }
        else
        {
            print("Queue is full, enqueuing not possible.");
        }
    }

    int dequeue()
    {
        int dequeueable = queue[0];
        for (int i = 0; i < size; i++)
            queue[i] = queue[i+1];
        size--;
        print();
        return dequeueable;
    }

    int count()
    {
        return size;
    }

    bool is_empty()
    {
        return size == 0;
    }
};

void d7()
{
    const char stop    = 'x';
    const char enqueue = '+';
    const char dequeue = '-';

    string msg_prompt = "Enter +a to enqueue a, - to dequeue, x to stop: ";
    string msg_empty = "Queue is empty, dequeuing not possible.";
    string msg_bad_input = "Your input is incorrect";
    string msg_end = "Program is over.";
    string msg_dequeued = " was just dequeued.";

    number_queue q;
    int input;

    char command = ' ';
    while (command != stop)
    {
        print(msg_prompt);
        cin >> command;
        switch (command)
        {
            case enqueue:
                q.enqueue();
                break;
            case dequeue:
                print( q.is_empty() ? msg_empty : to_char(q.dequeue()) + msg_dequeued);
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
    d7();
    system("pause");
    return 0;
}