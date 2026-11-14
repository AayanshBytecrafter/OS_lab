#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of pages";
    cin>>n;
    vector<int> pages(n);
    for(int i = 0; i<n; i++)
    {
        cin>> pages[i];
    }
    int capacity;
    cout<<"Enter the number of frames";
    cin>> capacity;

    vector<int> frames(capacity, -1);
    vector<int> times(capacity, 0);
    int faults = 0, t = 0;

    for(int i = 0; i < n; i++)
    {
        int found = 0, pos = 0;
        t++;
        for(int j = 0; j<capacity; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                times[j] = t;
                break;
            }
        }
        if(!found)
        {
            faults++;
            for(int j = 0; j<capacity; j++)
            {
                if(frames[j] == -1)
                {
                   pos = j;
                   break;
                }
                if(times[j] < times[pos])
                {
                    pos = j;
                }
            }
            frames[pos] = pages[i];
            times[pos] = t;
        }
        cout<<"Page" << pages[i] << endl;
        for(int j = 0; j<capacity; j++)
        {
            cout<< frames[j] << " ";
        }
        cout<<endl;
    }
    cout<<"Total Page faults" << faults << endl;
    return 0;

}