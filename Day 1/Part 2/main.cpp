#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int calibrationValue(string currLine);


int main()
{
    string line;
    ifstream inputFile("../input.txt");
    int total = 0;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            //cout << calibrationValue(line) << endl;
            total = total + calibrationValue(line);
        }
    }
    cout << total << endl;
    inputFile.close();
    return 0;
}

int calibrationValue(string currLine)
{
    int currChar=0;
    char firstDigitChar=65;
    char secondDigitChar=65;
    int firstDigit=0;
    int secondDigit=0;
    string newLine = currLine;
    size_t foundOne = currLine.find("one");
    size_t foundTwo = currLine.find("two");
    size_t foundThree = currLine.find("three");
    size_t foundFour = currLine.find("four");
    size_t foundFive = currLine.find("five");
    size_t foundSix = currLine.find("six");
    size_t foundSeven = currLine.find("seven");
    size_t foundEight = currLine.find("eight");
    size_t foundNine = currLine.find("nine");
    bool numWordsRemain;

    
    while(foundOne != string::npos || foundTwo != string::npos || foundThree != string::npos || foundFour != string::npos || foundFive != string::npos || foundSix != string::npos || foundSeven != string::npos || foundEight != string::npos || foundNine != string::npos)
    {
        //cout << "1: " << foundOne << " 2: " << foundTwo << " 3: " << foundThree << " 4: " << foundFour << " 5: " << foundFive << " 6: " << foundSix << " 7: " << foundSeven << " 8: " << foundEight << " 9: " << foundNine << endl;
        int firstOccurrence=99;
        int occurrenceLength = 0;
        string occurrenceNum = "a";
        if(foundOne != string::npos)
        {
            firstOccurrence = foundOne;
            occurrenceLength = 3;
            occurrenceNum = "1";
        }
        if(foundTwo != string::npos && foundTwo < firstOccurrence)
        {
            firstOccurrence = foundTwo;
            occurrenceLength = 3;
            occurrenceNum = "2";
        }
        if(foundThree != string::npos && foundThree < firstOccurrence)
        {
            firstOccurrence = foundThree;
            occurrenceLength = 5;
            occurrenceNum = "3";
        }
        if(foundFour != string::npos && foundFour < firstOccurrence)
        {
            firstOccurrence = foundFour;
            occurrenceLength = 4;
            occurrenceNum = "4";
        }
        if(foundFive != string::npos && foundFive < firstOccurrence)
        {
            firstOccurrence = foundFive;
            occurrenceLength = 4;
            occurrenceNum = "5";
        }
        if(foundSix != string::npos && foundSix < firstOccurrence)
        {
            firstOccurrence = foundSix;
            occurrenceLength = 3;
            occurrenceNum = "6";
        }
        if(foundSeven != string::npos && foundSeven < firstOccurrence)
        {
            firstOccurrence = foundSeven;
            occurrenceLength = 5;
            occurrenceNum = "7";
        }
        if(foundEight != string::npos && foundEight < firstOccurrence)
        {
            firstOccurrence = foundEight;
            occurrenceLength = 5;
            occurrenceNum = "8";
        }
        if(foundNine != string::npos && foundNine < firstOccurrence)
        {
            firstOccurrence = foundNine;
            occurrenceLength = 4;
            occurrenceNum = "9";
        }
        if(firstOccurrence != 99)
        { 
            newLine.replace(firstOccurrence,occurrenceLength,occurrenceNum);
        }
        //cout << newLine << endl;
        foundOne = newLine.find("one");
        foundTwo = newLine.find("two");
        foundThree = newLine.find("three");
        foundFour = newLine.find("four");
        foundFive = newLine.find("five");
        foundSix = newLine.find("six");
        foundSeven = newLine.find("seven");
        foundEight = newLine.find("eight");
        foundNine = newLine.find("nine");
    }

    
    
    while(newLine[currChar])
    {
        if(isdigit(newLine[currChar]))
        {
            if(firstDigitChar=='A')
            {
                firstDigitChar=newLine[currChar];
                firstDigit=firstDigitChar - '0';
            }
            else
            {
                secondDigitChar=newLine[currChar];
                secondDigit=secondDigitChar - '0';
            }
        }
        if (secondDigitChar=='A')
        {
            secondDigit=firstDigit;
        }
        
        currChar+=1;
        //cout << "(" << firstDigit << " " << secondDigit << ")" << newLine[currChar] << " ";
    }
    cout << currLine << " to " << newLine << " resulting in " << firstDigit << secondDigit << endl;
    return (firstDigit*10)+secondDigit;
}
