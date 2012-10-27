// REQUIREMENTS:
// C15. Skaitļu trijnieks nosaka taisni, kas uzdota sekojošā veidā: ax+by=c.
// Dotas n (n<=6) taisnes.
// Noteikt, kuras no taisnēm ir paralēlas.
// Vai eksistē trīs tādas taisnes, kas krustojas vienā punktā.
// Ja eksistē, tad izdrukāt šo taišņu parametrus.
// ----------------------------------------------
#include "utils.h"

const int parameters = 3;
const int max_number_of_lines = 1;
const int parameter_a = 0;
const int parameter_b = 1;
const int parameter_c = 2;

bool is_line_wrong(int line[parameters])
{
    return line[parameter_b] == 0;
}

int* get_line()
{
    int line[parameters] = {0, 0, 0};
    // while (is_line_wrong(line))
    // {
        cout << "Enter line's ax + by = c parameters, as space-separated integers a b c: ";
        cin >> line[0];
        cin >> line[1];
        cin >> line[2];


    cout << endl << "Your input is being interpreted as "
        << line[0] << ", "
        << line[1] << " and "
        << line[2] << endl;

        // if (is_line_wrong(line))
            // cout << "You have entered incorrect parameter B. It can not be 0." << endl;
    // }
    return line;
}

int main()
{
    // http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-using-new
    int** lines = new int*[max_number_of_lines];
    int real_number_of_lines = 0;

    for (int line = 0; line < max_number_of_lines; line++)
    {
        lines[line] = get_line();

    cout << endl << "Your input is being interpreted as "
        << lines[0][0] << ", "
        << lines[0][1] << " and "
        << lines[0][2] << endl;
    }
    cout << endl << "Your input is being interpreted as "
        << lines[0][0] << ", "
        << lines[0][1] << " and "
        << lines[0][2] << endl;
    cout << endl << "You have entered " << real_number_of_lines << " lines.";
    system("pause");
    return 0;
}
