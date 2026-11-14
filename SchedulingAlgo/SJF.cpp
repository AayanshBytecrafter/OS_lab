#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of process";
    cin>> n;

    int bt[n], wt[n], tat[n], pid[n];
    for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout<<"Process : "<<i + 1<<endl;
        cout<<"Enter Burst Time : ";
        cin>>bt[i];
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = i + 1; j<n; j++)
        {
            if(bt[i] > bt[j])
            {
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    wt[0] = 0;
    tat[0] = wt[0] + bt[0];

    for(int i = 1; i<n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    float avgWt = 0, avgTat = 0;
    
    cout<<"Process"<<"\t BT"<<"\t WT"<<"\t TAT"<<endl;

    for(int i = 0; i < n; i++)
    {
        avgWt += wt[i];
        avgTat += tat[i];

        cout<<pid[i]<<"\t"<<bt[i]<<"\t"<< wt[i]<<"\t"<<tat[i]<<endl;
    }
    cout<<"Average Waiting Time "<<avgWt;
    cout<<"Average TurnAroundTIme"<< avgTat;
}