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
// kurā glabājas masīvs ar skaitliskām vērtībām (int) garumā pieci                      //todo
// un rindas elementu skaits.                                                           //todo
// Klasei izveidot šādas metodes:
// (1) konstruktors,                                                                    //ok
// (2) destruktors,                                                                     //ok
// kurš paziņo par objekta likvidēšanu                                                  //ok
// un likvidēto elementu skaitu                                                         //ok
// (ja likvidēšanas brīdī rinda nav tukša),                                             //ok
// (3) metode "enqueue", kas pievieno rindai elementu,                                  //ok
// ja tā nav pilna,
// (4) metode "dequeue", kas izņem no rindas elementu un atgriež tā vērtību,
// (5) metode "Count", kas atgriež elementu skaitu rindā,
// (6) metode "IsEmpty", kas noskaidro, vai rinda ir tukša.
// ----------------------------------------------
#include "utils.h"

class number_queue
{
    static const int queue_size = 5;
public:
    int list[queue_size];
    int amount;

    number_queue()
    {
        amount = 0;
    }

    ~number_queue()
    {
        amount = 999;
        cout << endl << "Queue is being destructed. ";
        if (amount > 0)
            cout << "There were " << amount << " elements.";
    }

    void print()
    {
        cout << endl << "Queue:";
        for (int i = 0; i < 5; i++)
            cout << " " << list[i];
    }

    void enqueue(int element)
    {
        if (amount < queue_size)
        {
            list[amount++] = element;
        }
        else
        {
            cout << endl << "Queue is full, enqueuing not possible.";
        }
    }
};

void d7()
{
    const char stop = 'x';
    const char push = '+';
    const char pull = '-';

    number_queue queue;
    int input;

    char command = ' ';
    while (command != stop)
    {
        print("Enter desired action.");
        cin >> command;
        if (command == push)
        {
            cin >> input;
            queue.list[0] = input;
            cout << "do entering";
            queue.print();
        }
        else if (command == pull)
        {
            cout << "do removal";
        }
        else if (command != stop)
        {
            cout << "you input is incorrect";
        }
    }
    print("Program is over. ");
}

int main()
{
    d7();
    system("pause");
    return 0;
}