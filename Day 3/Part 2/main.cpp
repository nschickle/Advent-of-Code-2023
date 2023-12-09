#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("../input.txt");
    string line;


    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            cout << line << endl;
        }
    }
    inputFile.close();
}
