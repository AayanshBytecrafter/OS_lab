#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of processes";
    cin>> n;

    int bt[n], wt[n], tat[n], pid[n];

    cout<<"Enter burst time of each process";

    for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout<<"Process : "<< i + 1; 
        cout<<endl;
        cout<<"Enter burst time : ";
        cin>> bt[i];
    }

    wt[0] = 0;
    tat[0] = wt[0] + bt[0];
    for(int i = 1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    float avgWt = 0;
    float avgTat = 0;

    cout<<"Process"<<"\t BT"<<"\t WT"<<"\t TAT"<<endl;

    for(int i = 0; i<n; i++)
    {
        avgWt += wt[i];
        avgTat += tat[i];

        cout<<pid[i] << "\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    cout<<"Average Waiting Time is "<< avgWt / n;
    cout<<"Average TurnAroundTime is "<<avgTat / n;
    return 0; 
}