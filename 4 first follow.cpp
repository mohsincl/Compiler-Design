//LAB-4 First and Follow of a Given Grammar

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int i,j,k,l,m,n,v,v2, len,nv,nv1, cfirst[10]={0},cfollow[10]={0},cff[10]={0};
	char first[10][10],follow[10][10],ff[10][10],c;

	ifstream inp;                  //1
	string inp_str;                //2
	inp.open("input4.txt");        //3
	getline(inp,inp_str);          //4

    c=inp_str[0];
    v=0,v2=0;
	while(inp)
	{
	    len=inp_str.size();
		first[v][0]=inp_str[0];
		first[v][1]=inp_str[3];
		for(j=3,i=2;j<len;j++)
		{
		    if(inp_str[j]=='|'){first[v][i++]=inp_str[++j];}
		    if(inp_str[j]>64 && inp_str[j]<91)
            {
                for(k=0;k<v2 && inp_str[j]!=follow[k][0];k++){}
                if(k==v2)   {follow[v2][0]=inp_str[j]; ff[v2++][0]=inp_str[j]; cfollow[k]++; cff[k]++;}
                if(inp_str[j+1]=='|' || j+1==len){if(inp_str[0]!=ff[k][0])   ff[k][cff[k]++]=inp_str[0];}
                else    follow[k][cfollow[k]++]=inp_str[j+1];
            }
		}
		cfirst[v++]=i;
        getline(inp,inp_str);
	}
	for(i=0;i<v2;i++)
        if(follow[i][0]==c) follow[i][cfollow[i]++]='$';

	for(i=0;i<v2;i++)
    {
        cout<<"Follow("<<follow[i][0]<<"): ";
        for(j=1;j<cfollow[i];j++)
        {    cout<<follow[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<v2;i++)
    {
        cout<<"FF("<<ff[i][0]<<"): ";
        for(j=1;j<cff[i];j++)
        {    cout<<ff[i][j]<<" ";
        }
        cout<<endl;
    }
    //FIRST
	for(i=0;i<v;i++)
    {
        for(j=1;j<cfirst[i];j++)
        {
            if(first[i][j]>64 && first[i][j]<91)
            {
                for(k=0;k<v && first[k][0]!=first[i][j];k++){}
                nv=k;
                for(k=1;k<cfirst[nv];k++)
                    {for(l=0;l<cfirst[i];l++)
                        if(first[i][l]==first[nv][k])
                            break;
                    if(l==cfirst[i])    first[i][cfirst[i]++]=first[nv][k];
                    }
            }
        }
    }

    //FOLLOW FROM FIRST
    for(i=0;i<v2;i++)
    {
        for(j=1;j<cfollow[i];j++)
        {
            if(follow[i][j]>64 && follow[i][j]<91)
            {
                for(k=0;k<v && first[k][0]!=follow[i][j];k++){}
                nv=k;
                for(k=1;k<cfirst[nv];k++)
                    {for(l=0;l<cfollow[i];l++)
                        if(follow[i][l]==first[nv][k])
                            break;
                    if(l==cfollow[i])
                    {
                        if(first[nv][k]!='1')
                            follow[i][cfollow[i]++]=first[nv][k];
                        else
                        {
                            ff[i][cff[i]++]=first[nv][0];
                            for(m=0;m<v2;m++)
                                if(first[nv][0]==follow[m][0])  break;
                            nv1=m;
                            for(m=0;m<cff[nv1];m++)
                                ff[i][cff[i]++]=ff[nv1][m];
                        }
                            //for(m=0;m<cfirst[nv];m++)
                            //ff[i][cff[i]++]=first[nv][0];
                    }
                    }
            }
        }
    }

    //FOLLOW FROM FOLLOW
    for(i=0;i<v2;i++)
    {
        for(j=1;j<cff[i];j++)
        {
            if(ff[i][j]>64 && ff[i][j]<91)
            {
                for(k=0;k<v && follow[k][0]!=ff[i][j];k++){}
                nv=k;
                for(k=1;k<cfollow[nv];k++)
                    {for(l=0;l<cfollow[i];l++)
                        if(follow[i][l]==follow[nv][k])
                            break;
                    if(l==cfollow[i])
                    {
                        follow[i][cfollow[i]++]=follow[nv][k];
                        //else
                        //    ff[i][cff[i]++]=first[nv][0];
                    }
                    }
            }
        }
    }

    //Display "FIRST"
    for(i=0;i<v;i++)
    {
        cout<<"First("<<first[i][0]<<"): ";
        for(j=1;j<cfirst[i];j++)
            if(!(first[i][j]>64 && first[i][j]<91))
                cout<<first[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    //Display "FOLLOW"
	for(i=0;i<v2;i++)
    {
        cout<<"Follow("<<follow[i][0]<<"): ";
        for(j=1;j<cfollow[i];j++)
            if(!(follow[i][j]>64 && follow[i][j]<91))
                cout<<follow[i][j]<<" ";
        cout<<endl;
    }
	return 0;
}
