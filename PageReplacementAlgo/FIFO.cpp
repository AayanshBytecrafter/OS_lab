#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of pages";
    cin>> n;
    cout<<"Enter pages";
    vector<int> pages(n);
    cout<<"Enter the pages";
    for(int i = 0; i<n; i++)
    {
        cin>> pages[i];
    }

    int cap;
    cout<<"Enter the capacity of frames";
    cin>> cap;

    vector<int> frames(cap, -1);

    int faults = 0, pos = 0;

    for(int i = 0; i<n; i++)
    {
        int found = 0;
        for(int j = 0; j < cap; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            faults ++;
            frames[pos] = pages[i];
            pos = (pos + 1) % cap;

        }
        cout<<"Pages" << pages[i];
        cout<<endl;
        for(int j = 0; j < cap; j++)
        {
            cout<<frames[j] << " ";
        }
        cout<<endl;
    }
    cout<<"Total faults are : "<< faults;
    return 0;
}