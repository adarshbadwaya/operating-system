#include<bits/stdc++.h>

#include<iostream>

using namespace std;

int main()

{    

  int pr;

  cout<<"Enter no. of processes\n\n";

  cin>>pr;

	int at[pr],wt[pr],et[pr],ct[pr],tat[pr]; float avgtat=0,avgwt=0;

	cout<<"Enter Arrival time of all the processes\n\n";

	for(int i=0;i<pr;i++)
{
cout<<"arrival time of P["<<i+1<<"]";
 cin>>at[i];
}
	cout<<"Enter Execution or burst time of processes\n\n";

	for(int i=0;i<pr;i++)
{
cout<<"burst time for process P["<<i+1<<"]";
 cin>>et[i];
}

	

	//Completion time

	ct[0]=et[0];

	

	for(int i=1;i<pr;i++) 

	{

		if(at[i]>ct[i-1])

		ct[i]=at[i]+et[i];

		else

		ct[i]=ct[i-1]+et[i];

	}

	

	//Turn around time

		for(int i=0;i<pr;i++)

	tat[i]=ct[i]-at[i];

		

		//Waiting time

	for(int i=0;i<pr;i++)

	wt[i]=tat[i]-et[i];



	//avg tat

	

	for(int i=0;i<pr;i++)

	avgtat=avgtat+tat[i];

	

		for(int i=0;i<pr;i++)

	avgwt=avgwt+wt[i];

	

		cout<<"TAT time    Waiting time      completion time\n";

	for(int i=0;i<pr;i++)

	cout<<tat[i]<<"           "<<wt[i]<<"                  "<<ct[i]<<endl<<endl;

	

cout<<"Average TAT is  "<<avgtat/pr<<endl;

cout<<"Average WT is   "<<avgwt/pr<<endl;

	return 0;

	

}