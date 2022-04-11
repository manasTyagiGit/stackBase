#include <bits/stdc++.h>
using namespace std;

vector <int> findMaxLeft (vector <int> input)
{    
    vector <int> maxLeft;
    int i = 1;
    int n = input.size();

    maxLeft.push_back (input[0]); 

    for (i = 1; i < n; i++)
    {
        maxLeft.push_back (0);
    }      

    for (i = 1; i < n; i++)
    {        
        if (input[i] > maxLeft[i - 1])      maxLeft[i] = input[i];
        else                                maxLeft[i] = maxLeft[i - 1];       
    }

    return maxLeft;
}

vector <int> findMaxRight (vector <int> input)
{    
    int n = input.size();
    int i = n - 2;
    vector <int> maxRight;   

    for (i = 0; i < n - 1; i++)
    {
        maxRight.push_back (0);
    }

    maxRight[n - 1] = input[n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        if (input[i] > maxRight[i + 1])     maxRight[i] = input[i];
        else                                maxRight[i] = maxRight[i + 1];
    }   

    return maxRight;
}

vector <int> calcWaterOnTop (vector <int> input, vector <int>& maxLeft, vector <int>& maxRight)
{
    int n = maxLeft.size();
    int minOfMax = 0;
    vector <int> waterOnTop;
    int i = 0;

    for (i = 0; i < n; i++)
    {        
        minOfMax = min (maxLeft[i], maxRight[i]);         
        waterOnTop.push_back (minOfMax - input[i]);       
    }    

    return waterOnTop;
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

    vector <int> maxLeft    = findMaxLeft (input);
    vector <int> maxRight   = findMaxRight (input);

    vector <int> waterOnTop = calcWaterOnTop (input, maxLeft, maxRight);   

    int sumWater = 0;  

    for (i = 0; i < n; i++)
    {                
        sumWater += waterOnTop[i];
    }

    cout << endl << sumWater << endl;

    return 0;
}