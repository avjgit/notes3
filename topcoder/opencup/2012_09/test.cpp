#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

string read_input(string filename)
{
    filename += ".in";
    const char *infile = filename.c_str();
    string input_line;
    ifstream input(infile);
    getline (input, input_line);
    input.close();
    return input_line;
}
void write_output(string filename, int output)
{
    filename += ".out";
    const char *outfile = filename.c_str();
    ofstream myfile;
    myfile.open (outfile);
    myfile << output;
    myfile.close();
}
int* fill_input(string filename, int input_size)
{
    string input_line = read_input(filename);
    int *array = new int[input_size];
    istringstream iss(input_line);
    string sub;
    for (int i = 0; i < input_size; i++)
    {
        iss >> sub;
        array[i] = atoi(sub.c_str());
    }
    return array;
}
int main()
{
    const string    task_name = "taisnst";
    const int       task_input_size = 2;

    // reading input data from input file and writing them to array
    const int *input = fill_input(task_name, task_input_size);

    ////////////////////////////////// task logic
    int size1 = input[0];
    int size2 = input[1];
    int squares = 0;

    while(size1 && size2)
    {
        // cout << "sizes are now " << size1 << " and " << size2 << endl;
        if (size1 > size2)
        {
            size1 -= size2;
        }
        else
        {
            size2 -= size1;
        }
        squares++;
        // cout << "square " << squares << endl;
    }
    // system("pause");
    const int answer = squares;
    //////////////////////////////////

    // writing answer to output file
    write_output(task_name, answer);
    return 0;
}
