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

number_queue::number_queue()
{
    size = 0;
}

number_queue::number_queue(int _size, int* elements)
{
    for(int i = 0; i < _size; i++)
        enqueue(elements[i]);
}

number_queue::~number_queue()
{
    print("Queue was destructed.");
    if (size > 0)
        cout << endl << "There were " << size << " elements." << endl;
}

void number_queue::print()
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

void number_queue::print(string message)
{
    cout << endl << message << endl;
}

void number_queue::enqueue()
{
    int input;
    cin >> input;
    enqueue(input);
}

void number_queue::enqueue(int element)
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

int number_queue::dequeue()
{
    int dequeueable = queue[0];
    for (int i = 0; i < size; i++)
        queue[i] = queue[i+1];
    size--;
    print();
    return dequeueable;
}

int number_queue::count()
{
    return size;
}

bool number_queue::is_empty()
{
    return size == 0;
}
