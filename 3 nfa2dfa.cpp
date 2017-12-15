//LAB-3 NFA to DFA
//cs-count, i-input, m[][]-transition table, ln-link, cl[k]-count of elements in link[k][];

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int j,k,i1,st,in,p, i,len,flag, cs,m[10][10]={0}, link[10][10]={0},ln,cl[10]={0}, t,tmp[10]={0};

	ifstream inp;                  //1
	string inp_str;                //2
	inp.open("input3.txt");        //3
	getline(inp,inp_str);          //4

    getline(inp,inp_str);
    cs=0,ln=0;
	while(inp)
	{
	    len=inp_str.size();
		for(j=3,i=0;j<len;j+=2,i++)
		{
		    if(j+1<len && inp_str[j+1]==',')
            {
                m[cs][i]=ln+100;
                for(k=0;j<len && inp_str[j+1]==',';k++,j+=2)
                    {//cout<<"Yes";
                    link[ln][k]=int(inp_str[j])-48;}
                link[ln][k++]=int(inp_str[j])-48;
                cl[ln++]=k;
            }
            else if(inp_str[j]=='-')    m[cs][i]=-1;
            else                        m[cs][i]=int(inp_str[j])-48;
		}
		getline(inp,inp_str);
		cs++;
	}
    /*
    for(k=0;k<cs;k++)
        {for(j=0;j<i;j++)
            cout<<m[k][j]<<" ";
        cout<<endl;
        }
    cout<<endl;

    for(k=0;k<ln;k++)
        {for(j=0;j<cl[k];j++)
            cout<<link[k][j]<<" ";
        cout<<endl;
        }
    cout<<i<<"\n\n";
    */
    //New Transition Table
    cout<<"New Transition Table:\nSt ";
    for(j=0;j<i;j++) cout<<j<<" ";

    for(j=0;j<cs;j++)
    {
        cout<<"\nq"<<j<<" ";
        for(k=0;k<i;k++)
        {
            if(m[j][k]>10)
            {
                in=m[j][k]-100;
                for(p=0;p<cl[in]-1;p++)   cout<<link[in][p]<<",";
                cout<<link[in][p]<<" ";
                //cout<<in<<endl;
                m[j][k]=cs;
                for(i1=0;i1<i;i1++)
                {
                    for(st=0,t=0;st<cl[in];st++)
                    {
                        if(m[link[in][st]][i1]>-1)
                            tmp[t++]=m[link[in][st]][i1];
                    }
                    if(t>1)
                    {
                        m[cs][i1]=ln+100;
                        for(p=0;p<t;p++)
                        {//cout<<"Yes";
                            link[ln][p]=tmp[p];}
                        cl[ln++]=p;
                    }
                    else if(t==1)   m[cs][i1]=tmp[0];
                    else            m[cs][i1]=-1;
                }
                cs++;
            }
            else
                cout<<m[j][k]<<" ";
        }
    }

    //Traversal
    cout<<endl;
    for(k=0;k<cs;k++)
        {for(j=0;j<2;j++)
            cout<<m[k][j]<<" ";
        cout<<endl;
        }
    cout<<endl;

    t=0,k=0;
    tmp[t++]=0;
    for(;k<t;k++)
    {
        for(i1=0;i1<i;i1++)
        {
            for(st=0,flag=0;st<t;st++)
            {
                if(m[tmp[k]][i1]==tmp[st])   flag=1;
            }
            if(flag==0) tmp[t++]=m[tmp[k]][i1];
        }
    }

    cout<<"Reduced Transition Table For DFA:\nSt ";
    for(i1=0;i1<i;i1++) cout<<i1<<" ";
    cout<<endl;

    for(st=0;st<t;st++)
        {   cout<<"q"<<tmp[st]<<" ";
            for(i1=0;i1<i;i1++)
                cout<<m[tmp[st]][i1]<<" ";
            cout<<endl;
        }

    cout<<endl;
	return 0;
}
