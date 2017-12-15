//LABex2-1 Chomsky
//p-production no.(new), i-Var_iter, i1-Var1_iter, flag-Set if Left Recursion available, opc[]-len of o/p prod, op[]-o/p prod
//Type-3 - RG  (Regular)
//Type-2 - CFG (Context Free)
//Type-1 - CSG (Context Sensitive)
//Type-0 - REG (All)

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(void)
{
	int j,k, p,len,type,r,llen,rlen;

	ifstream inp;            //1
	string inp_str;          //2
	inp.open("input6.txt");    //3
	getline(inp,inp_str);    //4
	p=0;
    type=3;
	while(inp)
	{
	    len=inp_str.size();
	    if(type==0) break;
	    if(isalpha(inp_str[1]))
            if(type>1) type=1;
        if(type==1)
        {
            j=0;
            while(isalpha(inp_str[j]))  {j++;}
            if(j==1)    break;
            else
            {
                llen=j;
                j+=2;
                for(j;j<len;j++)
                {
                    r=j;
                    while(j<len && inp_str[j]!='|')  {j++;}
                    rlen=j;
                    if(!(inp_str[0]==inp_str[r] || inp_str[llen]==inp_str[rlen]))
                        type=0;
                }
            }
        }
        else if(type==3)
        {
            for(j=3;j<len;j++)
            {
                r=j;
                while(j<len && inp_str[j]!='|')  {j++;}
                rlen=j-r;
                if(rlen>=2)
                if(!(rlen==2 && islower(inp_str[r]) && isupper(inp_str[r+1])) || rlen>2)
                    type=2;
            }
        }
        p++;
	    getline(inp,inp_str);
	}
	cout<<"Type: "<<type<<endl;
	return 0;
}
