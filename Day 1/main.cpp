#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int calibrationValue(string currLine);

int main()
{
    string line;
    ifstream inputFile("input.txt");
    int total = 0;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            total = total + calibrationValue(line);
        }
    }
    cout << total << endl;
    inputFile.close();
}

int calibrationValue(string currLine)
{
    int currChar=0;
    char firstDigitChar=65;
    char secondDigitChar=65;
    int firstDigit=0;
    int secondDigit=0;

    while(currLine[currChar])
    {
        if(isdigit(currLine[currChar]))
        {
            if(firstDigitChar=='A')
            {
                firstDigitChar=currLine[currChar];
                firstDigit=firstDigitChar - '0';
            }
            else
            {
                secondDigitChar=currLine[currChar];
                secondDigit=secondDigitChar - '0';
            }
        }
        if (secondDigitChar=='A')
        {
            secondDigit=firstDigit;
        }
        
        currChar+=1;
        //cout << "(" << firstDigit << " " << secondDigit << ")" << currLine[currChar] << " ";
    }

    return (firstDigit*10)+secondDigit;
}