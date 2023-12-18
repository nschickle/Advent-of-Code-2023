#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <fstream>
#include <vector>

using namespace std;

int cardMatches(string currInput);

int main()
{
    ifstream inputFile("../input.txt");
    string line;
    vector<int> cardMultipliers;
    int multiplier = 1;
    int currMatches;
    int totalPoints = 0;

    cardMultipliers.push_back(1);
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            currMatches = cardMatches(line);
            for (size_t i = 0; i < currMatches; i++)
            {
                /* code */
            }
            
        }
    }
    inputFile.close();

}

int cardMatches(string currInput)
{
    vector<int> winningNumV;
    vector<int> gameNumV;
    regex cardNumber("Card +\\d+:");
    regex winningNumbers("(\\d+ +)+\\|");
    regex gameNumbers("\\|( +\\d+)+");
    regex anyNum("\\d+");
    string tempStr;
    smatch m;
    smatch m2;
    int points;

    if (regex_search(currInput, m, cardNumber))
    {
        tempStr = m.str();
        if(regex_search(tempStr,m2,anyNum))
        {
            cout << "Card Number is " << m2.str() << endl;
        }
    }
    if (regex_search(currInput, m, winningNumbers))
    {
        cout << "Winning numbers are ";
        tempStr = m.str();
        while (regex_search(tempStr, m2, anyNum))
        {
            cout << m2.str() << " ";
            winningNumV.push_back(stoi(m2.str()));
            tempStr = m2.suffix();
        }
        cout << endl;
    }
    if (regex_search(currInput, m, gameNumbers))
    {
        cout << "Game numbers are ";
        tempStr = m.str();
        while (regex_search(tempStr, m2, anyNum))
        {
            cout << m2.str() << " ";
            gameNumV.push_back(stoi(m2.str()));
            tempStr = m2.suffix();
        }
        cout << endl;
    }
    
    vector<int>::iterator it;
    for(it = gameNumV.begin(); it < gameNumV.end(); it++)
    {
        vector<int>::iterator it2;
        for (it2 = winningNumV.begin(); it2 < winningNumV.end(); it2++)
        {
            if (*it == *it2)
            {
                if (points < 1)
                {
                    points++;
                }
                else
                {
                    points = points * 2;
                }
                
            }
            
        }
        

    }
    cout << "This card is worth " << points << " points" << endl;
    return points;
}
