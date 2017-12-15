//LABex2-2 Epsilon NFA to DFA

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(void)
{
    int j,k,p,tmp, v1,v2, i[10]={0},f[10]={0},cs,v, len,flag, m[10][10]={0},eps[10][10]={0},epsc[10]={0};
    //ln=0,link[10][10]={0},linkc[10]={0};

	ifstream inp;            //1
	string inp_str;          //2
	inp.open("input8.txt");    //3
	getline(inp,inp_str);    //4
    i[(int)inp_str[0]-48]=1;
	getline(inp,inp_str);

	for(j=0;j<inp_str.size();j++)
	{
		tmp=int(inp_str[j++])-48;
		f[tmp]=1;
	}

	getline(inp,inp_str);
	getline(inp,inp_str);
	cs=0;
	while(inp)
	{
	    len=inp_str.size();
	    m[cs][0]=(int)inp_str[1]-48;
        for(j=3,v=1,p=0;j<len;j+=2)
        {
            if(inp_str[j]=='-')
                m[cs][v++]=-1;
            else if(inp_str[j+1]==',' || j+1==len)
            {
                for(j;j<len;j+=2)   eps[cs][p++]=(int)inp_str[j]-48;
                epsc[cs]=p;
            }
            else
                m[cs][v++]=(int)inp_str[j]-48;
        }
        cs++;
	    getline(inp,inp_str);
	}
	/*for(j=0;j<cs;j++)
    {
        for(k=1;k<v;k++)
            cout<<m[j][k]<<" ";
        cout<<endl;
    }*/
    for(j=cs-1;j>=0;j--)
    {
        if(epsc[j]>0)  //if epsilon transition present;
        {
            v1=j;
            //Step1
            for(p=0;p<epsc[j];p++)
                {
                    v2=eps[j][p];
                    for(k=0;k<v;k++)
                        if(m[v2][k]!=-1)
                            if(m[v1][k]==-1)
                                m[v1][k]=m[v2][k];
                }
            //Step2
            if(f[v2]==1)    f[v1]=1;
            //Step3
            if(i[v1]==1)    i[v2]=1;
        }
    }

    cout<<"Initial States: ";
    for(j=0;j<cs;j++)
        if(i[j]==1)
            cout<<j<<" ";

    cout<<"\nFinal States: ";
    for(j=0;j<cs;j++)
        if(f[j]==1)
            cout<<j<<" ";
    cout<<endl;
    for(j=0;j<cs;j++)
    {
        cout<<"q"<<m[j][0]<<": ";
        for(k=1;k<v-1;k++)
            cout<<m[j][k]<<" ";
        cout<<endl;
    }

	return 0;
}
