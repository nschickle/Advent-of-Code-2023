#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

int cardPoints(string currInput);

int main()
{
    ifstream inputFile("../input.txt");
    string line;


    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            cardPoints(line);
        }
    }
    inputFile.close();
}

int cardPoints(string currInput)
{
    regex cardNumber("Card \\d+:");
    regex winningNumbers("(\\d+ +)+\\|");
    regex gameNumbers("\\|( +\\d+)+");
    return 0;
}
