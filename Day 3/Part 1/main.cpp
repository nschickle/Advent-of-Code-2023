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
    string tempStr0;
    regex potNum("\\d+");
    regex specChar("[^0-9.\n]");
    smatch m;
    smatch m0;
    int lineNum = 0;
    bool partEligable;
    int partSum = 0;
    int realPos = 0;
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
            realPos = 0;
            while(regex_search(tempStr, m, potNum)) 
            {
                tempStr0 = "";
                realPos = realPos + m.position();
                cout << m.str() << " with size " << m.length() << " at " << realPos << ", " << i << endl;
                partEligable = 0;
                if (i == 0) //first line, don't look for i-1
                {
                    if (realPos == 0) //first character, don't look for realPos-1
                    {
                        cout << "tempstr0: " << endl << m.str() << arr[i][m.length()+1] << endl;
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][j];
                            cout << arr[i+1][j];
                        }
                        cout << endl;
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                        }
                    }
                    else if (realPos+m.length() == 140) //extends to last char, don't look for postion+length+1
                    {
                        cout << "tempstr0: " << endl << arr[i][realPos-1] << m.str() << endl;
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos+j];
                            cout << arr[i+1][realPos+j];
                        }
                        cout << endl;
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                        }
                    }
                    else //middle characters, look for both
                    {
                        cout << "tempstr0: " << endl << arr[i][m.length()+1] << m.str() << arr[i][realPos-1] << endl;
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos+j-1];
                            cout << arr[i+1][realPos+j-1];
                        }
                        cout << endl;
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                        }
                    }
                }
                else if (i == lineNum-1) //last line, don't look for i+1
                {
                    if (realPos == 0) //first character, don't look for realPos-1
                    {
                        cout << "tempstr0: " << endl ;
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][j];
                            cout << arr[i-1][j];
                        }
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                        cout << endl << m.str() << arr[i][m.length()+1] << endl << endl;
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                        }
                    }
                    else if (realPos+m.length() == 140) //extends to last char, don't look for postion+length+1
                    {
                        cout << "tempstr0: " << endl;
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos+j-1];
                            cout << arr[i-1][realPos+j];
                        }
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        cout << endl << arr[i][realPos-1] << m.str() << endl;
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                        }
                    }
                    else //middle characters, look for both
                    {
                        cout << "tempstr0: " << endl;
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos-1+j];
                            cout << arr[i-1][realPos-1+j];
                        }
                        cout << endl << arr[i][realPos-1] << m.str() << arr[i][realPos + m.length()] << endl;;
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        tempStr0 = tempStr0 + arr[i][realPos + m.length()];
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                        }
                    }
                }
                else //middle lines, look above and below
                {
                    if (realPos == 0) //first character, don't look for realPos-1
                    {
                        cout << "tempstr0: " << endl;
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][j];
                            cout << arr[i-1][j];
                        }
                        cout << endl << m.str() << arr[i][m.length()+1] << endl;
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][j];
                            cout << arr[i+1][j];
                        }
                        cout << endl;
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                        }
                    }
                    else if (realPos+m.length() == 140) //extends to last char, don't look for postion+length+1
                    {
                        cout << "tempstr0: " << endl;
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos+j-1];
                            cout << arr[i-1][realPos+j];
                        }
                        cout << endl << arr[i][realPos-1] << m.str() << endl;
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos+j-1];
                            cout << arr[i+1][realPos+j];
                        }
                        cout << endl;
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                        }
                    }
                    else //middle characters, look for both
                    {
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos-1+j];
                            cout << arr[i-1][realPos-1+j];
                        }
                        cout << endl << arr[i][realPos-1] << m.str() << arr[i][realPos + m.length()] << endl;;
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos-1+j];
                            cout << arr[i+1][realPos-1+j];
                        }
                        cout << endl;
                        tempStr0 = tempStr0 + arr[i][realPos + m.length()];
                        if(regex_search(tempStr0, m0, specChar))
                        {
                            partEligable = 1;
                            partSum = partSum + stoi(m.str());
                            cout << "Add " << m.str() << " to get " << partSum << endl;
                        }
                    }
                }
                realPos = realPos + m.length();

                tempStr = m.suffix();
            }
        }
        cout << "Total: " << partSum << endl;
        
    }
    inputFile.close();
}
