#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int Val = 32000;

void pushIntoStack (int value)
{
    if (s.empty())
    {
        s.push (value);
        Val = value;
        return;
    }

    if (value >= Val)
    {
        s.push (value);
        return;
    }

    s.push ((2 * value) - Val);
    Val = value;
}

void popFromStack ()
{
    if (s.top() < Val)
    {
        Val = (2 * Val) - s.top();
    }  
    s.pop();
}

void peekMin ()
{
    if (!s.empty())    cout << " MIN :: " << Val << endl;
    return;
}

int main (void)
{
    vector <int> input;
    int n = 0, i = 0, key = 0;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> key;
        input.push_back (key);
    }   
    
    n = n * 3;   

    cout << "\n1. FOR PUSH()\n2. FOR POP()\n3. FOR MIN()\n\n";    
    int value = input[0];
    i = 0;

    while (n--)
    {
        cin >> key;
        switch (key)
        {
            case 1 :
                if (i >= (input.size()))
                {
                    cout << "\nERROR\nNo More elements to push\n";
                    return -1;
                }
                pushIntoStack (value);
                i++;
                value = input[i];
                break;
            
            case 2 :
                if (i <= -1)
                {
                    cout << "\nERROR\nNo More elements to pop\n";
                    return -1;
                }
                popFromStack ();
                i--;
                break;

            case 3:
                peekMin ();
                break;

            default :
                cout <<"\n\nWRONG CHOICE !!\n\n";
                break;                
        }
    }

    return 0;
}