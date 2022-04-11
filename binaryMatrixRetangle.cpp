#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

void calculateNSLIndex (vector <int>& input, vector <int>& NSLIndex, int n)
{
    int i = 0;
    stack <pair <int, int>> s;

    for (i = 0; i < n; i++)
    {        
        while (!s.empty() && s.top().first >= input[i])     s.pop();            

        if (s.empty())                                      NSLIndex.push_back (-1); 
        else                                                NSLIndex.push_back (s.top().second);           
        
        s.push ({input[i], i});
    }
}

void calculateNSRIndex (vector <int>& input, vector <int>& NSRIndex, int n)
{
    int i = 0;
    stack <pair <int, int>> s;

    for (i = n - 1; i >= 0; i--)
    {      
        while (!s.empty() && s.top().first >= input[i])     s.pop();            

        if (s.empty())                                      NSRIndex.push_back (-1); 
        else                                                NSRIndex.push_back (s.top().second);

        s.push ({input[i], i});         
    }
    
    reverse (NSRIndex.begin(), NSRIndex.end()); 

}

int MAH (vector<int> a, int col)
{
    int n = col, key = 0;
    int i = 0, j = 0;

    vector <int> input;
    vector <int> NSLIndex;
    vector <int> NSRIndex;

    for (i = 0; i < col; i++)
    {
        input.push_back (a[i]);
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
    return maxArea;
}

int main (void)
{
    int row = 0, col = 0, i, j;
    cin >> row >> col;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> a;
    i = 0;
    int maxArea = 0;

    for (j = 0; j < col; j++)
    {
        a.push_back (arr[i][j]);
        maxArea = MAH (a, col);
    }

    for (i = 1; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                a[j] = 0;
            }
            else
            {
                a[j] = a[j] + 1;
            }
        }

        maxArea = max (maxArea, MAH (a, col));
    }

    cout << endl << maxArea << endl;

    return 0;
}