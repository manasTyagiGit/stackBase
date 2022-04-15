#include <bits/stdc++.h>

using namespace std;

void calculateNGL (vector <int>& input, vector <int>& output, int n)
{
    int i = 0;
    stack <pair <int, int>> s;          

    for (i = 0; i < n; i++)
    {
        if (s.empty())
        {                   
            output.push_back (-1);
        }

        else if (s.top().first > input[i])
        {
            output.push_back (s.top().second);
        }

        else
        {
            while (!s.empty() && s.top().first <= input[i])
            {
                s.pop();
            }            

            if (s.empty())              output.push_back (-1);
            else                        output.push_back (s.top().second);
        }

        s.push ({input[i], i});
    }  

    for (i = 0; i < n; i++)
    {
        output[i] = i - output[i];
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