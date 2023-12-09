#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

int gameIdIfWon(string currInput);

int main()
{
    ifstream inputFile("../input.txt");
    string line;
    int sumOfWonGames = 0;
    int gameId;


    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            sumOfWonGames = sumOfWonGames + gameIdIfWon(line);
        }
    }
    cout << sumOfWonGames << endl;
    inputFile.close();
}

int gameIdIfWon(string currInput)
{
    regex gameReg("Game \\d+:");
    regex redReg("\\d+ red");
    regex greenReg("\\d+ green");
    regex blueReg("\\d+ blue");
    int numOfReds = 0;
    int numOfGreens = 0;
    int numOfBlues = 0;
    int gameId;
    int power;
    smatch m;
    string tempStr = currInput;

    cout << currInput << endl;

    while(regex_search(tempStr, m, redReg)) 
    {
        int tempInt = m[0].str().find(" ");
        tempStr = m[0].str().substr(0,tempInt);
        tempInt=stoi(tempStr);
        if (tempInt > numOfReds)
        {
            numOfReds=tempInt;
        }
        tempStr = m.suffix();
    }
    cout << "Red: " << numOfReds << endl;
    tempStr=currInput;
    while(regex_search(tempStr, m, greenReg)) 
    {
        int tempInt = m[0].str().find(" ");
        tempStr = m[0].str().substr(0,tempInt);
        tempInt=stoi(tempStr);
        if (tempInt > numOfGreens)
        {
            numOfGreens=tempInt;
        }
        tempStr = m.suffix();
    }
    cout << "Green: " << numOfGreens << endl;
    tempStr=currInput;
    while(regex_search(tempStr, m, blueReg)) 
    {
        int tempInt = m[0].str().find(" ");
        tempStr = m[0].str().substr(0,tempInt);
        tempInt=stoi(tempStr);
        if (tempInt > numOfBlues)
        {
            numOfBlues=tempInt;
        }
        tempStr = m.suffix();
    }
    cout << "Blue: " << numOfBlues << endl;
    power=numOfBlues*numOfGreens*numOfReds;
    cout << "Power: " << power << endl;
    
    return power;
}