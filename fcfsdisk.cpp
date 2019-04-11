#include<iostream>
using namespace std;
int main()
{
            int queue[20],n,head,i,j,k,seek,max,diff;
            float avg;
            cout<<"Enter the size of queue request\n";
            cin>>n;
            cout<<"Enter the disk positions to be read\n";
            for(i=1;i<=n;i++)
            cin>>queue[i];
            cout<<"Enter the initial head position\n";
            cin>>head;
            queue[0]=head;
            diff=0;
            seek=0;
            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        cout<<"Disk head moves from "<<queue[j]<<" to "<<queue[j+1]<<"with seek "<<diff<<endl;
            }
            cout<<"Total seek time is "<<seek<<endl;
            avg=seek/n;
            cout<<"Average seek time is "<<avg<<endl;
            return 0;
}

