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
#include "d7.h"

// messages to display to user
const string Queue::msg_destructed      = "Queue was destructed.";
const string Queue::msg_destructed_size = "Queue's size was ";
const string Queue::msg_empty           = "Queue is empty.";
const string Queue::msg_full            = "Queue is full, enqueuing not possible.";
const string Queue::msg_queue           = "Queue: ";

Queue::Queue()
{
    size = 0;
}

Queue::Queue(int _size, int* elements)
{
    for(int i = 0; i < _size; i++)
        enqueue(elements[i]);
}

Queue::~Queue()
{
    print(msg_destructed);
    if (size > 0)
        print(msg_destructed_size + to_char(size));
}

// prints out contents of a queue
void Queue::print()
{
    if (is_empty())
    {
        print(msg_empty);
    }
    else
    {
        string describe = msg_queue;
        for (int i = 0; i < size; i++)
            describe = describe + " " + to_char(queue[i]);
        print(describe);
    }
}

// prints out a message to user
void Queue::print(string message)
{
    cout << endl << message << endl;
}

void Queue::enqueue(int element)
{
    if (!is_full())
    {
        queue[size++] = element;
        print();
    }
    else
    {
        print(msg_full);
    }
}

void Queue::enqueue()
{
    int input;
    cin >> input;
    enqueue(input);
}

void Queue::enqueue(int _size, int* elements)
{
    for(int i = 0; i < _size; i++)
        enqueue(elements[i]);
}

int Queue::dequeue()
{
    int dequeueable = queue[0];     // take first element
    for (int i = 0; i < size; i++)  // shift next elements forward
        queue[i] = queue[i+1];
    size--;
    print();
    return dequeueable;
}

int Queue::count()
{
    return size;
}

bool Queue::is_empty()
{
    return size == 0;
}

bool Queue::is_full()
{
    return size == queue_max_size;
}
