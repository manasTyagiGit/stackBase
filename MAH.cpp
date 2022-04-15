#include <bits/stdc++.h>
using namespace std;

void calculateNSLIndex (vector <int>& input, vector <int>& NSLIndex, int n)
{
    int i = 0;
    stack <pair <int, int>> s;

    for (i = 0; i < n; i++)
    {
        if (s.empty())
        {
            NSLIndex.push_back (-1);
        }

        else if (s.top().first < input[i])
        {
            NSLIndex.push_back (s.top().second);
        }

        else
        {
            while (!s.empty() && s.top().first >= input[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                NSLIndex.push_back (-1); 
            }
            else
            {
                NSLIndex.push_back (s.top().second);   
            }
        }
        s.push ({input[i], i});
    }

    /*for (i = 0; i < n; i++)
    {
        cout << NSLIndex[i] << "\t";
    }
    cout << endl;*/
}

void calculateNSRIndex (vector <int>& input, vector <int>& NSRIndex, int n)
{
    int i = 0;
    stack <pair <int, int>> s;

    for (i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            NSRIndex.push_back (-1);
        }

        else if (s.top().first < input[i])
        {
            NSRIndex.push_back (s.top().second);
        }

        else
        {
            while (!s.empty() && s.top().first >= input[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                NSRIndex.push_back (-1); 
            }
            else
            {
                NSRIndex.push_back (s.top().second);   
            }
        }

        s.push ({input[i], i});         
    }
    
    reverse (NSRIndex.begin(), NSRIndex.end()); 

    /*for (i = 0; i < n; i++)
    {
        cout << NSRIndex[i] << "\t";
    }
    cout << endl;*/

}

int main (void)
{
    int n = 0, i = 0, key = 0;
    cin >> n;
    vector <int> input;
    vector <int> NSLIndex;
    vector <int> NSRIndex;

    for (i = 0; i < n; i++)
    {
        cin >> key;
        input.push_back (key);
    }

    n = n + 2;

    input.insert (input.begin(), 0);
    input.push_back (0);
    calculateNSRIndex (input, NSRIndex, n);
    calculateNSLIndex (input, NSLIndex, n);

    int width[n];
    int area[n];
    int maxArea = 0;

    for (i = 0; i < n; i++)
    {        
        width[i] = NSRIndex[i] - NSLIndex[i] - 1;
        area[i]  = width[i] * input[i];
        //printf ("\n%d :: %d", i, area[i]);        //DEBUG OUTPUT
        if (area[i] > maxArea)
        {
            maxArea = area[i];
        }
    }

    cout << endl << maxArea << endl;

    return 0;
}