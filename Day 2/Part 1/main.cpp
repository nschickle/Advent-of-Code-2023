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
    int gameId;
    int gameIdLength;
    smatch m;
    string tempStr;
    
    size_t colon = currInput.find(':');
    if(colon != string::npos)
    {
        gameIdLength = colon - 5;
    }
    tempStr = currInput.substr(5,gameIdLength);
    gameId = stoi(tempStr);
    cout << gameId << endl;
    //while(regex_search(currInput, m, redReg)){ tempStr = m.str();//cout << tempStr << endl;}


    return 0;
}