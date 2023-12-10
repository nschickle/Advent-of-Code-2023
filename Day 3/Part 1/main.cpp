#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <array>
#include <regex>

using namespace std;

int main()
{
    ifstream inputFile("../input.txt");
    string line;
    string tempStr;
    regex potNum("\\d+");
    smatch m;
    int lineNum = 0;
    string arr [140];

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            arr[lineNum] = line;
            lineNum++;
        }
        for (size_t i = 0; i < arr->size(); i++)
        {
            tempStr = arr[i];
            while(regex_search(tempStr, m, potNum)) 
            {
                cout << m.str() << " at " << m.position() << ", " << i << endl;
                tempStr = m.suffix();
            }
        }
        
        
    }
    inputFile.close();
}
