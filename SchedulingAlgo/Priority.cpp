#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of Process";
    cin>>n;

    int bt[n], wt[n], pid[n], tat[n], pr[n];

     for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout<<"Process : "<<i + 1<<endl;
        cout<<"Enter Burst Time : ";
        cin>>bt[i];
        cout<<endl;
        cout<<"Enter Priority: ";
        cin>> pr[i];
    }


    for(int i = 0; i<n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for(int i = 1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    float avgWT = 0, avgTAT = 0;

    cout<<"\nProcess\tBT\tPriority\tWT\tTAT"<<endl;

    for(int i = 0; i<n; i++)
    {
        avgWT += wt[i];
        avgTAT += tat[i];

        cout<<"P"<<pid[i]<<"\t"
            <<bt[i]<<"\t"
            <<pr[i]<<"\t\t"
            <<wt[i]<<"\t"
            <<tat[i]<<endl;
    }

    cout<<"\nAverage Waiting Time: "<<avgWT/n;
    cout<<"\nAverage Turnaround Time: "<<avgTAT/n;

    return 0;
}