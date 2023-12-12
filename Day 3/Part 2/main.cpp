#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <array>
#include <regex>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ifstream inputFile("../inputSmol.txt");
    string line;
    string tempStr;
    string tempStr0;
    regex potNum("\\d+");
    regex specChar("\\*");
    smatch m;
    smatch m0;
    int lineNum = 0;
    int partSum = 0;
    int realPos = 0;
    string arr [140];
    vector<pair<int, int>> arrV;

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
                if (i == 0) //first line, don't look for i-1
                {
                    if (realPos == 0) //first character, don't look for realPos-1
                    {
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                        if(arr[i][m.length()+1] == '*')
                        {
                            cout << "* at " << i << ", " << m.length()+1 << endl;
                            arrV.push_back(make_pair(i,m.length()+1));
                        }
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][j];
                            if(arr[i+1][j] == '*')
                            {
                                cout << "* at " << i+1 << ", " << j << endl;
                                arrV.push_back(make_pair(i+1,j));
                            }
                        }
                    }
                    else if (realPos+m.length() == 140) //extends to last char, don't look for postion+length+1
                    {
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        if (arr[i][realPos-1] == '*')
                        {
                            cout << "* at " << i << ", " << realPos-1 << endl;
                            arrV.push_back(make_pair(i,realPos-1));
                        }
                        
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos+j];
                            if(arr[i+1][realPos+j] == '*')
                            {
                                cout << "* at " << i+1 << ", " << realPos+j << endl;
                                arrV.push_back(make_pair(i+1,realPos+j));
                            }
                        }
                    }
                    else //middle characters, look for both
                    {
                        if (arr[i][realPos-1] == '*')
                        {
                            cout << "* at " << i << ", " << realPos-1 << endl;
                            arrV.push_back(make_pair(i,realPos-1));
                        }
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos+j-1];
                            if (arr[i+1][realPos+j-1] == '*')
                            {
                                cout << "* at " << i+1 << ", " << realPos+j-1 << endl;
                                arrV.push_back(make_pair(i+1,realPos+j-1));
                            }
                        }
                        if (arr[i][m.length()+1] == '*')
                        {
                            cout << "* at " << i << ", " << m.length()+1 << endl;
                            arrV.push_back(make_pair(i,m.length()+1));
                        }
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                    }
                }
                else if (i == lineNum-1) //last line, don't look for i+1
                {
                    if (realPos == 0) //first character, don't look for realPos-1
                    {
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][j];
                            if (arr[i-1][j] == '*')
                            {
                                cout << "* at " << i-1 << ", " << j << endl;
                                arrV.push_back(make_pair(i-1,j));
                            }
                        }
                        if (arr[i][m.length()+1] == '*')
                        {
                            cout << "* at " << i << ", " << m.length()+1 << endl;
                            arrV.push_back(make_pair(i,m.length()+1));
                        }
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                    }
                    else if (realPos+m.length() == 140) //extends to last char, don't look for postion+length+1
                    {
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos+j-1];
                            if (arr[i-1][realPos+j-1] == '*')
                            {
                                cout << "* at " << i-1 << ", " << realPos+j-1 << endl;
                                arrV.push_back(make_pair(i-1,realPos+j-1));
                            }
                        }
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        if (arr[i][realPos-1] == '*')
                        {
                            cout << "* at " << i << ", " << realPos-1 << endl;
                            arrV.push_back(make_pair(i,realPos-1));
                        }
                    }
                    else //middle characters, look for both
                    {
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos-1+j];
                            if (arr[i-1][realPos+j-1] == '*')
                            {
                                cout << "* at " << i-1 << ", " << realPos+j-1 << endl;
                                arrV.push_back(make_pair(i-1,realPos+j-1));
                            }
                        }
                        
                        if (arr[i][realPos-1] == '*')
                        {
                            cout << "* at " << i << ", " << realPos-1 << endl;
                            arrV.push_back(make_pair(i,realPos-1));
                        }
                        if (arr[i][realPos + m.length()] == '*')
                        {
                            cout << "* at " << i << ", " << realPos + m.length() << endl;
                            arrV.push_back(make_pair(i,realPos + m.length()));
                        }
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        tempStr0 = tempStr0 + arr[i][realPos + m.length()];
                    }
                }
                else //middle lines, look above and below
                {
                    if (realPos == 0) //first character, don't look for realPos-1
                    {
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][j];
                            if(arr[i-1][j] == '*')
                            {
                                cout << "* at " << i-1 << ", " << j << endl;
                                arrV.push_back(make_pair(i-1,j));
                            }
                        }
                        if(arr[i][m.length()+1] == '*')
                        {
                            cout << "* at " << i << ", " << m.length()+1 << endl;
                            arrV.push_back(make_pair(i,m.length()+1));
                        }
                        tempStr0 = tempStr0 + arr[i][m.length()+1];
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][j];
                            if(arr[i-1][j] == '*')
                            {
                                cout << "* at " << i+1 << ", " << j << endl;
                                arrV.push_back(make_pair(i+1,j));
                            }
                        }
                    }
                    else if (realPos+m.length() == 140) //extends to last char, don't look for postion+length+1
                    {
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos+j-1];
                            if(arr[i-1][realPos+j-1] == '*')
                            {
                                cout << "* at " << i-1 << ", " << realPos+j-1 << endl;
                                arrV.push_back(make_pair(i-1,realPos+j-1));
                            }
                        }
                        if(arr[i][realPos-1] == '*')
                        {
                            cout << "* at " << i << ", " << realPos-1 << endl;
                            arrV.push_back(make_pair(i,realPos-1));
                        }
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        for (size_t j = 0; j < m.length()+1; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos+j-1];
                            if(arr[i+1][realPos+j-1] == '*')
                            {
                                cout << "* at " << i+1 << ", " << realPos+j-1 << endl;
                                arrV.push_back(make_pair(i+1,realPos+j-1));
                            }
                        }
                    }
                    else //middle characters, look for both
                    {
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i-1][realPos-1+j];
                            if(arr[i-1][realPos+j-1] == '*')
                            {
                                cout << "* at " << i-1 << ", " << realPos+j-1 << endl;
                                arrV.push_back(make_pair(i-1,realPos+j-1));
                            }
                        }
                        if(arr[i][realPos-1] == '*')
                        {
                            cout << "* at " << i << ", " << realPos-1 << endl;
                            arrV.push_back(make_pair(i,realPos-1));
                        }
                        tempStr0 = tempStr0 + arr[i][realPos-1];
                        for (size_t j = 0; j < m.length()+2; j++)
                        {
                            tempStr0 = tempStr0 + arr[i+1][realPos-1+j];
                            if(arr[i+1][realPos+j-1] == '*')
                            {
                                cout << "* at " << i+1 << ", " << realPos+j-1 << endl;
                                arrV.push_back(make_pair(i+1,realPos+j-1));
                            }
                        }
                        if(arr[i][realPos + m.length()] == '*')
                        {
                            cout << "* at " << i << ", " << realPos + m.length() << endl;
                            arrV.push_back(make_pair(i,realPos + m.length()));
                        }
                        tempStr0 = tempStr0 + arr[i][realPos + m.length()];
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
