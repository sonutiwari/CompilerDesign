#include<bits/stdc++.h>
using namespace std;
string compareString(string a, string b)
{
    int i,j,strASize,strBSize,flag=0;
    string str;
    strASize=a.length();
    strBSize=b.length();
    for(i=0; i<strASize&&i<strBSize; i++)
    {
        if(a[i]==b[i])
        {
            str+=a[i];
        }
        else
            break;
    }
    return str;
}
int main()
{
    int i=0,n,j,k,flag=0,b=0,x,numOfLines=0;
    string temp;
    fstream fin,fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    string str[8],tok[20][20],alpha,beta[20];
    string var[10];
    while(!fin.eof())
    {
        numOfLines++;
        getline(fin,str[i]);
        var[i]=str[i][0];
        i++;
    }
    for(x=0; x<numOfLines; x++)
    {
        b=0;
        k=0;
        for(j=2; str[x][j]!='\0'; j++)
        {
            if(str[x][j]=='|'||str[x][j]=='>')
            {
                j++;
                for(; str[x][j]!='\0'&&str[x][j]!='|'; j++)
                    tok[x][k]+=str[x][j];

                j--;
                k++;
            }
        }
label:
        flag=0;
        for(k=0; (!(tok[x][k].empty()))&&flag==0; k++)
        {
            for(j=k+1; (!(tok[x][j].empty())); j++)
            {
                alpha=compareString(tok[x][k],tok[x][j]);
                if(!alpha.empty())
                {
                    flag=1;
                    break;

                }
            }
            if(flag==1)
                break;
        }


        int len;

        if(flag==1)
        {
            for(i=0; (!(tok[x][i].empty())); i++)
            {
                len=alpha.length();
                temp=compareString(alpha,tok[x][i]);
                if(temp==alpha)
                {
                    tok[x][i].erase(0,len);
                    if(tok[x][i].empty())
                        beta[b]+="e";
                    else
                        beta[b]+=tok[x][i];
                    b++;
                    j=i;
                    do
                    {
                        tok[x][j]= tok[x][j+1];
                        j++;
                    }
                    while((!(tok[x][j].empty())));


                    i--;
                }

            }

            for(n=0; (!(tok[x][n].empty())); n++);
            tok[x][n]+=alpha;
            tok[x][n]+=var[x];
            tok[x][n]+="'";

            goto label;
        }

        cout<<var[x]<<"->";
        fout<<var[x]<<"->";
        for(i=0; (!(tok[x][i].empty())); i++)
        {
            cout<<tok[x][i]<<"|";
            fout<<tok[x][i]<<"|";
        }
        fout.seekg(-1,ios::cur);
        cout<<'\b';
        cout<<" "<<endl;
        fout<<" "<<endl;
        if(!beta[0].empty())
        {
            var[numOfLines]=var[x];
            var[numOfLines]+="'";
            for(i=0; i<b; i++)
            {
                tok[numOfLines][i]=beta[i];
                beta[i].clear();
            }

            numOfLines++;
        }
    }

}
