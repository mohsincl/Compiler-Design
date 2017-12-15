//LAB-2 Moore Machine
//cs-cur_state, i-input, ns[][]-next_state, op[]-output
// machine: [cur_state][input]->[next_state][output]

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int j,k, cs,i, len,count, ns[10][10]={0},op[10];
	char sen[100];

	ifstream inp;                  //1
	string inp_str;                //2
	inp.open("input2moore.txt");   //3
	getline(inp,inp_str);          //4

    getline(inp,inp_str);
    cs=0;
	while(inp)
	{
	    len=inp_str.size();
		for(j=3,i=0;j<len;j++,i++)
		{
		    if(inp_str[j]=='q')
                {ns[cs][i]=int(inp_str[++j])-48; j++;}
            if(inp_str[j]=='-')
                {ns[cs][i]=-1;j+=2;}
            else
                op[cs]=int(inp_str[j])-48;
		}
		getline(inp,inp_str);
		cs++;
	}
    count=cs;

    for(i=0;i<5;i++)
        {for(j=0;j<2;j++)
            cout<<ns[i][j]<<" ";
        cout<<op[i]<<endl;
        }

	while(1)
	{
	cout<<"Enter a string: ";
	cin>>sen;
	if(sen[0]=='-')	break;  //Input termination
	for(j=0,cs=0;j<strlen(sen);j++)
	{
	    if(j==0)    cout<<"\nInit State: q"<<cs<<" ; Output: "<<op[cs];
		i=int(sen[j])-48;
		if(ns[cs][i]==-1)
		{
			cout<<"\nError: No valid transition henceforth.\n";
			break;
		}
		else
		{
		    cout<<"\nNext State: q"<<ns[cs][i];
		    cs=ns[cs][i];
		    cout<<" ; Output: "<<op[cs];
		}
	}
	if(j==strlen(sen))		cout<<"\n\n";
	}
	return 0;
}
