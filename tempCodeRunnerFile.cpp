#include <iostream>
#include <string>
using namespace std;
int winning_check(string str, char symbol,int count)
{
    int i = 0;
    cout<<"Count: "<<count<<endl;
    while (i < 7)
    {
        if (str[i] == str[i + 1] && str[i + 2] == str[i])
        {
            cout << "*****************************************" << endl;
            cout << symbol << " Win the match" << endl;
            cout << "*****************************************" << endl;
            return 1;
        }
        else
        {
            i = i + 3;
        }
    }
    i = 0;
    while (i < 7)
    {
        if (str[i] == str[i + 3] && str[i + 6] == str[i])
        {
            cout << "*****************************************" << endl;
            cout << symbol << " Win the match" << endl;
            cout << "*****************************************" << endl;
            return 1;
        }
        else
        {
            i = i + 1;
        }
    }
    i = 0;
    if (str[i] == str[i + 4] && str[i + 8] == str[i])
    {
        cout << "*****************************************" << endl;
        cout << symbol << " Win the match" << endl;
        cout << "*****************************************" << endl;
        return 1;
    }
    else if (str[i + 2] == str[i + 4] && str[i + 4] == str[i + 6])
    {
        cout << "*****************************************" << endl;
        cout << symbol << " Win the match" << endl;
        cout << "*****************************************" << endl;
        return 1;
    }
    else if (count == 9)
    {
        cout << "*****************************************" << endl;
        cout << "The Match has been drawn" << endl;
        cout << "*****************************************" << endl;
    }
}
void display(string str)
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 8)
        {
            cout << str[i] << " ";
        }
        else if (i == 2 || i == 5)
        {
            cout << str[i] << endl;
            cout << "---------" << endl;
        }
        else
        {
            cout << str[i] << " "
                 << "|";
        }
    }
    cout << endl;
}
int main()
{
    int count = 0;
    char symb;
    char sym2;
    string str = "123456789";
    char box;
    cout << "*****************************************" << endl;
    cout << "Choose Symbol For PLayer 1" << endl;
    cout << "X or 0" << endl;
    cout << "*****************************************" << endl;
    cin >> symb;
    if (symb == 'X' || symb == 'x')
    {
        sym2 = '0';
    }
    else if (symb == '0')
    {
        sym2 = 'X';
    }
    cout << "***************************" << endl;
    display(str);
    cout << "***************************" << endl;

    for (int j = 0; j < 9; j++)
    {
        if (j % 2 == 0)
        {
            cin >> box;
            for (int i = 0; i < 9; i++)
            {
                if (box == str[i])
                {
                    count++;
                    str[i] = symb;
                    int ch = winning_check(str, symb,count);
                    if (ch == 1)
                    {
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            cout << "***************************" << endl;
            display(str);
            cout << "***************************" << endl;
        }
        else
        {
            cin >> box;
            for (int i = 0; i < 9; i++)
            {
                if (box == str[i])
                {
                    count++;
                    str[i] = sym2;
                    int ch = winning_check(str, sym2,count);
                    if (ch == 1)
                    {
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            cout << "***************************" << endl;
            display(str);
            cout << "***************************" << endl;
        }
    }
    return 0;
}