//LABex2-1 Eliminating Left Recursion
//p-production no.(new), i-Var_iter, i1-Var1_iter, flag-Set if Left Recursion available, opc[]-len of o/p prod, op[]-o/p prod
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int j,k, p,i,i1,flag,len, opc[50];
	char op[50][50];


	ifstream inp;            //1
	string inp_str;          //2
	inp.open("input5.txt");    //3
	getline(inp,inp_str);    //4
	p=0;

	while(inp)
	{
	    len=inp_str.size();
		i=0;
		op[p][i++]=inp_str[0];
		op[p][i++]=inp_str[1];
		op[p][i++]=inp_str[2];

		for(j=3,i1=0,flag=0;j<len;j++)
		{
			if(inp_str[j]==op[p][0])
			{
			    if(flag==0)
                {
                    flag=1;
                    op[p+1][i1++]=op[p][0];
                    op[p+1][i1++]='1';
                    op[p+1][i1++]=op[p][1];
                    op[p+1][i1++]=op[p][2];
                }
                j++;
                while(j<len && inp_str[j]!='|')
                {
                    op[p+1][i1++]=inp_str[j++];
                }
                op[p+1][i1++]=op[p][0];
                op[p+1][i1++]='1';
                op[p+1][i1++]='|';
			}
			else
            {
                while(j<len && inp_str[j]!='|')
                    {op[p][i++]=inp_str[j++];}
                op[p][i++]=op[p][0];
                op[p][i++]='1';
                op[p][i++]='|';
            }
		}
		opc[p++]=i-1;
        if(flag==1) {op[p][i1++]='e';opc[p++]=i1;}
		getline(inp,inp_str);
		//cout<<endl;
	}
	for(j=0;j<p;j++)
    {
        for(k=0;k<opc[j];k++)
            cout<<op[j][k];
        cout<<endl;
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
	return 0;
}
