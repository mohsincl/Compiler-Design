//LABex2-2 PDA checker
//GRAMMAR's Regex of the form: a^n b^m c^n  where m is odd

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(void)
{
	int j,k,m, p,len,flag,chlen[100],i,cur;
    char sen[100],st[100],checker[100][100];            //Stack,Checker

	ifstream inp;            //1
	string inp_str;          //2
	inp.open("input7.txt");    //3
	getline(inp,inp_str);    //4
	p=0;
	while(inp)
	{
	    len=inp_str.size();
	    checker[p][0]=inp_str[2];
	    checker[p][1]=inp_str[4];
	    checker[p][2]=inp_str[6];
	    checker[p][3]=inp_str[12];
	    for(j=14,k=4;inp_str[j]!=')';j++,k++)
            checker[p][k]=inp_str[j];
        chlen[p++]=k;
	    getline(inp,inp_str);
	}

    while(1)
	{
	cout<<"Enter a sentence: ";
	cin>>sen;
	if(sen[0]=='-')	break;  //Input termination
	i=0,cur=0;
	st[i++]='z';
	for(j=0;j<strlen(sen);j++)
	{
		for(k=0,flag=0;k<p;k++)
        {
            if(checker[k][0]==(char)(cur+48) && checker[k][1]==sen[j] && checker[k][2]==st[i-1])
            {
                flag=1;
                st[i--];
                cur=(int)checker[k][3]-48;
                if(checker[k][4]!='^')
                    for(m=chlen[k]-1;m>=4;m--)
                        st[i++]=checker[k][m];
                break;
            }
        }
        if(flag==0) break;
	}
	if(j==strlen(sen) && i==0)	cout<<"String Accepted!\n";
	else		                cout<<"Error at index: "<<j<<"; String Rejected!\n";
	}
	return 0;
}
