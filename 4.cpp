#include <iostream>
using namespace std;
int palindrom(string str, int size)
{
    int s = 0;
    int e = size - 1;
    while (s < e)
    {
        if (str[s] != str[e])
        {

            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}
int main()
{
    string str = "mima";
    int size = str.length();
    if (palindrom(str, size))
    {
        cout << "t" << endl;
    }
    else
    {
        cout << "f" << endl;
    }
}