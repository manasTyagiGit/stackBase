#include <bits/stdc++.h>

using namespace std;

void calculateNGR (vector <int>& input, vector <int>& output, int n)
{
    stack <int> s;
    int i = 0;

    for (i = n - 1; i >= 0; i--)
    {
        if (s.empty())                                  output.push_back (-1);
        else if (s.top() > input[i])                    output.push_back (s.top());

        else
        {
            while (!s.empty() && s.top() <= input[i])
            {   
                s.pop();
            }

            if (s.empty())                              output.push_back (-1);
            else                                        output.push_back (s.top());
        }       

        s.push (input[i]);
    }

    reverse (output.begin(), output.end());
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

    calculateNGR (input, output, n);

    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
    
    cout << endl;
    return 0;
}