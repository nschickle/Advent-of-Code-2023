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
    const int red = 12;
    const int green = 13;
    const int blue = 14;
    int numOfReds = 0;
    int numOfGreens = 0;
    int numOfBlues = 0;
    int gameId;
    int gameIdLength;
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
            if(numOfReds>red)
            {
                return 0;
            }
            //cout << numOfReds << endl;
        }
        tempStr = m.suffix();
    }
    tempStr=currInput;
    while(regex_search(tempStr, m, greenReg)) 
    {
        int tempInt = m[0].str().find(" ");
        tempStr = m[0].str().substr(0,tempInt);
        tempInt=stoi(tempStr);
        if (tempInt > numOfGreens)
        {
            numOfGreens=tempInt;
            if(numOfGreens>green)
            {
                return 0;
            }
            //cout << numOfGreens << endl;
        }
        tempStr = m.suffix();
    }
    tempStr=currInput;
    while(regex_search(tempStr, m, blueReg)) 
    {
        int tempInt = m[0].str().find(" ");
        tempStr = m[0].str().substr(0,tempInt);
        tempInt=stoi(tempStr);
        if (tempInt > numOfReds)
        {
            numOfBlues=tempInt;
            if(numOfBlues>blue)
            {
                return 0;
            }
            cout << numOfBlues << endl;
        }
        tempStr = m.suffix();
    }
    size_t colon = currInput.find(':');
    if(colon != string::npos)
    {
        gameIdLength = colon - 5;
    }
    tempStr = currInput.substr(5,gameIdLength);
    gameId = stoi(tempStr);
    cout << gameId << endl;
    //while(regex_search(currInput, m, redReg)){ tempStr = m.str();//cout << tempStr << endl;}


    return gameId;
}