#include<iostream>

#include<bits/stdc++.h>

using namespace std;

int main()

{

	int n,h,i,j,sum=0,temp;

	int a[50],st[50],dist[50];

	

	cout<<"enter the no. of requests\n";

	cin>>n;

	cout<<"Enter the position of head\n";

	cin>>h;

	cout<<"enter the elements in queue\n";

	for(i=0;i<n;i++) cin>>a[i];

	 

	 //calculating  distance of head from each element in queue

	for(i=0;i<n;i++)

     dist[i]=abs(h-a[i]);



     

     //sort elements based on dist

     for(i=0;i<n;i++)

     {

     	for(j=i+1;j<n;j++)

     	 if(dist[i]>dist[j]){

     	 	temp=dist[i];

     	 	dist[i]=dist[j];

     	 	dist[j]=temp;

     	 	

     	 	temp=a[i];

     	 	a[i]=a[j];

     	 	a[j]=temp;

		  }

	 }

	 int diff=0;
                    int seek=0;
	 for(i=0;i<n;i++)

	 {

	 	diff=abs(h-a[i]);
                                     cout<<"Disk head moves from "<<h<<" to "<<a[i]<<"with seek "<<diff<<endl;
                                     seek=diff+seek;
	 	h=a[i];

	 }

	 

	cout<<"total seek time is:"<<seek;

	

}