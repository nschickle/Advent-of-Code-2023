#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("../input.txt");
    string line;
    int lineNum = 0;
    char arr [140][140];

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            for (size_t i = 0; i < line.size(); i++)
            {
                arr[lineNum][i] = line[i];
            }
            lineNum++;
        }
    }
    inputFile.close();
}
