#include <bits/stdc++.h>

using namespace std;

void calculateNGL (vector <int>& input, vector <int>& output, int n)
{
    int i = 0;
    stack <int> s;

    for (i = 0; i < n; i++)
    {        
        while (!s.empty() && s.top() <= input[i])       s.pop();            

        if (s.empty())                                  output.push_back (-1);
        else                                            output.push_back (s.top());     

        s.push (input[i]);
    }    
}

int main (void)
{
    int n, key;
    cin >> n;

    vector <int> input;
    vector <int> output;

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        input.push_back (key);
    }

    calculateNGL (input, output, n);

    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
    
    cout << endl;
    return 0;
}