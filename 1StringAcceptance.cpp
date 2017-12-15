//LAB-1 String acceptance or rejectance given a grammar
//s-state, v-input variable, i-initial state, f[]-set of final states, g[][]- transition table, cur-current state
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int j,k, s,v, tmp,len,count,cur, i,f[10]={0},g[10][10]={0};
	char sen[100],c;

	ifstream inp;            //1
	string inp_str;          //2
	inp.open("input1.txt");  //3
	getline(inp,inp_str);    //4
 	i=int(inp_str[0])-48;

	getline(inp,inp_str);
	len=inp_str.size();

	for(j=0;j<len;j++)
	{
		tmp=int(inp_str[j++])-48;
		f[tmp]=1;
	}

	getline(inp,inp_str);
	s=0;
	while(inp)
	{
	    len=inp_str.size();
		for(count=0,v=0,j=0;j<len;j++)
		{
			if(inp_str[j]=='-')	{
                        g[s][v++]=-1;j+=2;
						//cout<<"-1 ";
						}
			else
			{
			tmp=int(inp_str[j++])-48;
			g[s][v++]=tmp;
			//cout<<tmp<<" ";
			}
			count++;
		}
		s++;
		getline(inp,inp_str);
		//cout<<endl;
	}
	/*cout<<endl;
	cout<<i<<endl;
	for(j=0;j<10;j++)
		cout<<f[j]<<" ";
	cout<<endl;
	for(j=0;j<s;j++)
		{for(k=0;k<count;k++)
			cout<<g[j][k]<<" ";
		cout<<endl;
		}*/
	while(1)
	{
	cout<<"Enter a sentence: ";
	cin>>sen;
	if(sen[0]=='-')	break;  //Input termination
	for(j=0,cur=i;j<strlen(sen);j++)
	{
		tmp=int(sen[j])-97;
		if(g[cur][tmp]==-1)
		{
			cout<<"String Rejected!\n";
			break;
		}
		else
		{
			cur=g[cur][tmp];
		}
	}
	if(j==strlen(sen) && f[cur]==1)	cout<<"String Accepted!\n";
	else if(j==strlen(sen))		cout<<"String Rejected!\n";
	}
	return 0;
}
