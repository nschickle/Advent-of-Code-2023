#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

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
            cout << calibrationValue(line) << endl;
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

    if(string::npos != foundOne)
    {
        while(foundOne < newLine.length())
        {
            foundOne = newLine.find("one");
            //cout << newLine << endl;
            newLine.replace(foundOne,3,"1");
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
    }
    
    if(string::npos != foundTwo)
    {
        while(foundTwo < newLine.length())
        {
            foundTwo = newLine.find("two");
            //cout << newLine << endl;
            newLine.replace(foundTwo,3,"2");
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
    }
    if(string::npos != foundThree)
    {
        while(foundThree < newLine.length())
        {
            foundThree = newLine.find("three");
            //cout << newLine << endl;
            newLine.replace(foundThree,5,"3");
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
    }
    if(string::npos != foundFour)
    {
        while(foundFour < newLine.length())
        {
            foundFour = newLine.find("four");
            //cout << newLine << " at " << foundFour << endl;
            newLine.replace(foundFour,4,"4");
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
    }
    if(string::npos != foundFive)
    {
        while(foundFive < newLine.length())
        {
            foundFive = newLine.find("five");
            //cout << newLine << endl;
            newLine.replace(foundFive,4,"5");
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
    }
    if(string::npos != foundSix)
    {
        while(foundSix < newLine.length())
        {
            foundSix = newLine.find("six");
            //cout << newLine << endl;
            newLine.replace(foundSix,3,"6");
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
    }
    if(string::npos != foundSeven)
    {
        while(foundSeven < newLine.length())
        {
            foundSeven = newLine.find("seven");
            //cout << newLine << endl;
            newLine.replace(foundSeven,5,"7");
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
    }
    if(string::npos != foundEight)
    {
        while(foundEight < newLine.length())
        {
            foundEight = newLine.find("eight");
            //cout << newLine << endl;
            newLine.replace(foundEight,5,"8");
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
    }
    if(string::npos != foundNine)
    {
        while(foundNine < newLine.length())
        {
            foundNine = newLine.find("nine");
            //cout << newLine << " at " << foundNine << endl;
            newLine.replace(foundNine,4,"9");
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
    }
    cout << currLine << " to " << newLine << endl;
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

    return (firstDigit*10)+secondDigit;
}
