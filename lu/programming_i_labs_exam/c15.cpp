// REQUIREMENTS:
// C15. Skaitļu trijnieks nosaka taisni, kas uzdota sekojošā veidā: ax+by=c.
// Dotas n (n<=6) taisnes.
// Noteikt, kuras no taisnēm ir paralēlas.
// Vai eksistē trīs tādas taisnes, kas krustojas vienā punktā.
// Ja eksistē, tad izdrukāt šo taišņu parametrus.
// ----------------------------------------------
#include "utils.h"

const int parameters = 3;
const int max_number_of_lines = 4;

const int parameter_a  = 0;
const int parameter_b  = 1;
const int parameter_c  = 2;
const int state        = 3;
const int parallelness = 4;

bool is_line_wrong(double line[parameters])
{
    return
        line[parameter_a] == 0 &&
        line[parameter_b] == 0;
}

bool is_stop(double line[parameters])
{
    return
        line[parameter_a] == 0 &&
        line[parameter_b] == 0 &&
        line[parameter_c] == 0;
}

double* get_line()
{
    double line[parameters] = {0, 0, 0};
    while (is_line_wrong(line))
    {
        print("If you want to stop, enter 0 0 0.");
        print("Enter line's ax + by = c parameters, as space-separated integers a b c: ");
        cin >> line[parameter_a];
        cin >> line[parameter_b];
        cin >> line[parameter_c];

        if (is_stop(line))
            break;

        if (is_line_wrong(line))
            print("You have entered incorrect parameter A and B. They can not be 0 simultaneously.");
    }
    return line;
}

bool are_parallel_to_abscissa(double line1[3], double line2[3])
{
    return line1[parameter_a] == 0 &&
           line2[parameter_a] == 0;
}

bool are_parallel_to_ordinate(double line1[3], double line2[3])
{
    return line1[parameter_b] == 0 &&
           line2[parameter_b] == 0;
}

bool has_same_slope(double line1[3], double line2[3])
{
    // transforming line equation
    // from ax + by = c
    // to slope-intercept form y = slope * x + y_intercept:
    // ax + by =  c
    //      by =  c - ax
    //      by =  -ax + c
    //       y = (-ax + c)/b
    //       y = (-a/b)x + c/b
    // so, slope is -a/b and y_intercept is c/b
    // lines are parallel, when their slopes are equal
    return (-1 * line1[parameter_a] / line1[parameter_b]) ==
           (-1 * line2[parameter_a] / line2[parameter_b]);
}

bool is_parallel(double line1[3], double line2[3])
{
    return are_parallel_to_abscissa(line1, line2)
        || are_parallel_to_ordinate(line1, line2)
        || has_same_slope(line1, line2);
}

void c15()
{
    // http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-using-new
    double lines[max_number_of_lines][parameters + 2];
    int lines_entered = 0;
    const int checked = 1;
    const int not_checked = -1;

    // getting lines from user
    for (int line = 0; line < max_number_of_lines; line++, lines_entered++)
    {
        double* input_line = get_line();

        if (is_stop(input_line))
        {
            lines_entered--;
            break;
        }
        else
        {
            lines[line][parameter_a]  = input_line[parameter_a];
            lines[line][parameter_b]  = input_line[parameter_b];
            lines[line][parameter_c]  = input_line[parameter_c];
            lines[line][state]        = not_checked;
            lines[line][parallelness] = not_checked;
        }
    }

    bool exists_parallels = false;

    // mark lines parallel
    for (int line = 0; line < lines_entered; line++)
    {
        // if line not yet marked as being parallel
        if (lines[line][state] == not_checked)
        {
            // loop through lines, starting from next one till end
            for (int next_line = line + 1; next_line < lines_entered; next_line++)
            {
                if (is_parallel(lines[line], lines[next_line]))
                {
                    // mark current line as parallel to line from outer loop
                    lines[next_line][state] = checked;
                    lines[next_line][parallelness] = line;
                    exists_parallels = true;
                }
            }
        }
    }

    // reseting state for printing
    for (int line = 0; line < lines_entered; line++)
        lines[line][state] = not_checked;

    // for (int line = 0; line < lines_entered; line++)
    // {
    //     cout << endl << "line " << line << ": ";
    //     for (int i = 0; i <= parallelness; i++)
    //         cout << lines[line][i] << " ";
    // }

    // print out result of parallelness check
    if (exists_parallels)
    {
        bool has_parallels;
        print("Parallel lines are:");
        for (int line = 0; line < lines_entered; line++)
        {
            // cout << "entering with line " << line + 1 << endl;

            string output_lines = "    Line " + to_char(line+1);
            has_parallels = false;

            // if line is not yet printed
            if (lines[line][state] == not_checked)
            {
                for (int next_line = line + 1; next_line < lines_entered; next_line++)
                {
                    if (lines[next_line][parallelness] == line)
                    {
                        lines[next_line][state] = checked;
                        output_lines += ", line " + to_char(next_line+1);
                        has_parallels = true;
                    }
                }
            }
            if (has_parallels) print(output_lines);
        }
    }
    else
    {
        print("There are no parallel lines.");
    }


    cout << endl;
    cout << "Your input is being interpreted as "
        << lines[0][parameter_a] << ", "
        << lines[0][parameter_b] << " and "
        << lines[0][parameter_c] << endl;


    cout << "Your input is being interpreted as "
        << lines[1][parameter_a] << ", "
        << lines[1][parameter_b] << " and "
        << lines[1][parameter_c] << endl;

    cout << "Your enetered " << lines_entered << " lines. ";

}
int main()
{
    c15();

    system("pause");
    return 0;
}
