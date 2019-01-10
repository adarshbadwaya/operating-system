#include<iostream>
#define max 100
using namespace std;
int main()
{
	int n;
	cout<<"enter number of process\n";
	cin>>n;
	int AT[max],ET[max],CT[max],TAT[max],WT[max];
	for(int i=0;i<=n-1;i++)
	{
		cout<<"enter arrival time for process - P"<<(i+1)<<endl;
		cin>>AT[i];
		cout<<"enter execution time for process - P"<<(i+1)<<endl;
		cin>>ET[i];
    } 
    	cout<<"1. completion time for processes\n";
    	cout<<"2. turn arround time\n";
    	cout<<"3. waiting time\n";
    	CT[0]=ET[0];
    		for(int i=1;i<=n-1;i++)
    		{
    			
				if(CT[i-1]<AT[i])
				{
					CT[i]=AT[i]+ET[i];
				}
				if(CT[i-1]>AT[i])
				{
					CT[i]=CT[i-1]+ET[i];
				}
			}
			for(int i=0;i<=n-1;i++)
			{
				cout<<"completion time of process - P"<<i<<"  "<<CT[i]<<endl;
			}
		for(int i=0;i<=n-1;i++)
		{
			TAT[i]=CT[i]-AT[i];
			cout<<"turn arround time for process - P"<<i<<"  "<<TAT[i]<<endl;
		}
		for(int i=0;i<=n-1;i++)
		{
			WT[i]=TAT[i]-ET[i];
			cout<<"waiting time for process - P"<<i<<"  "<<WT[i]<<endl;
		}
		cout<<"Process   arrival T   executionT   turn arroundT   waiting no.\n";
		for(int i=0;i<=n-1;i++)
		{
			cout<<"  P"<<i<<"          "<<AT[i]<<"              "<<ET[i]<<"           "<<TAT[i]<<"           "<<WT[i]<<endl;
		}
	return 0;
}
