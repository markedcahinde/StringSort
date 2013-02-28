#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cstring>

const int max_value = 100;
using namespace std;

class StringSort {
public:
    void read();
    void insertionSort();
    void int_insertionSort();
    void bubbleSort();
    void int_bubbleSort();
    void stringConvert();
    void print();

    static int counter;

private:
    string name[max_value];
    int o[max_value];
    };

int StringSort::counter = 0;

void StringSort::read()
{
    ifstream myFile;
    myFile.open("top_passwords.txt");
    string line;
    int n=0;

    while (myFile.good())
    {
        getline(myFile, line);
        name[n] = line;
        n++;
    }
}

void StringSort::stringConvert()
{
    for (int i=0; i<max_value; i++)
    {
        if (string::npos != name[i].find_first_of("0123456789"))
        {
            stringstream(name[i]) >> o[i];
            counter++;
        }
    }
}

void StringSort::insertionSort()
{
    string key;
    for (int i = 0; i < max_value; i++){
        key = name[i];
        int j;
        for(j = i-1; j >=0 && _strcmpi(name[j].c_str(), key.c_str()) > 0; j--)
        {
            name[j+1] = name[j];
        }
        name[j+1] = key;
    }
}

void StringSort::int_insertionSort()
{
    stringConvert();
    int key;
    for (int i = 0; i < counter; i++){
        key = o[i];
        int j;
        for(j = i-1; j >=0 && o[j] > key; j--)
        {
            o[j+1] = o[j];
        }
        o[j+1] = key;
    }
}

void StringSort::bubbleSort()
{
    string temp;
    for(long i = 0; i < max_value; i++)
    {
        for(long j = 0; j < max_value-i-1; j++)
        {
            if (_strcmpi(name[j].c_str(), name[j+1].c_str()) > 0)
            {
                temp        = name[j];
                name[j]     = name[j+1];
                name[j+1]   = temp;
            }
        }
    }
}

void StringSort::int_bubbleSort()
{
    stringConvert();
    int temp;
    for(int i = 0; i < max_value; i++)
    {
        for(int j = 0; j < max_value-i-1; j++)
        {
            if (o[j] > o[j+1])
            {
                temp        = o[j];
                o[j]     = o[j+1];
                o[j+1]   = temp;
            }
        }
    }
}

void StringSort::print()
{
    for (int j=0; j < counter-1; j++)
    {
        cout << j+1 << ". " << o[j+1] << endl;
    }

    for (int i = 0; i < max_value - counter + 2; i++)
    {
        cout << i+counter << ". " << name[i+counter-2] << endl;
    }

}

int main()
{
    StringSort sort;
    char chr;
    cout << "Choose type of sorting: a. Insertion Sort; b. Bubble Sort: ";
    cin >> chr;
    sort.read();
    if (chr=='a')
    {
        sort.insertionSort();
        sort.int_insertionSort();
        sort.print();
    }

    else if (chr=='b')
    {
        sort.bubbleSort();
        sort.int_bubbleSort();
        sort.print();
    }


    return 0;
}

