#include<bits/stdc++.h>
using namespace std;
int no_of_DNA_seq,k;

char s[10005][10005];
vector<string>possible_kmers;
vector<vector<string>>vec;
vector<string>row;


// K-mer formation function
string kmers(int i, int K) {
  static const char* DNA = "acgt";
  if (K==0) return string();
  return DNA[i%4] + kmers(i / 4, K-1);
}


int diference(string k_mer,string p)
{
    int res = 0;
    for(int i = 0;i<k;i++)
    {
        if(k_mer[i]==p[i])
            res++;
    }
    return res;
}


void find(string k_mer)
{
    for(int i = 0 ;i<no_of_DNA_seq;i++)
    {
        int mx = -1;
        string dash;
        for(int j =0 ;j<vec[i].size();j++)
        {
            string p = vec[i][j];
            int dif = diference(k_mer,p);
            if(dif>mx)
            {
                mx=dif;
                dash=p;
            }   
        }
        for(int j=0;j<dash.length();j++)
        {
            s[i][j]=dash[j];
        }
        //cout<<s[i]<<endl;
    }
}


int hamming_distance(string pick)
{
    int ans=0;
    for(int i = 0 ;i<k;i++)
    {
        map<char,int>m;
        int mx = 0;
        for(int j = 0;j<no_of_DNA_seq;j++)
        {
            //cout<<j<<" "<<i<<" "<<s[j][i]<<endl;
            m[s[j][i]]++;
        }
        map<char,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            //cout<<(*it).first<<" "<<(*it).second<<endl;
            int value = (*it).second;
            mx = max(mx,value);
        }        
        ans+=no_of_DNA_seq-mx;
    }
    return ans ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif

    cout<<"ENTER no of DNA Sequence : ";
    cin>>no_of_DNA_seq;
    cout<<endl;
    cout<<"ENTER VALUE OF K : ";
    cin>>k;
    cout<<endl;
    
    //Generating All possible combinations 
    for(int i = 0 ;i<1<<(2*k);i++)
    {
        string tmp = kmers(i,k) ;
        possible_kmers.push_back(tmp);
    }
    
    
    for(int i=0;i<no_of_DNA_seq;i++)
    {
        string tmp;
        cin>>tmp;
        int len = tmp.length();
        
        for(int j=0;j<=len-k;j++)
        {
            string tmpp="";
            for(int p=j;p<=j+(k-1);p++)
            {
                tmpp+=tmp[p];
            }
            row.push_back(tmpp);
        } 
        vec.push_back(row);
        row.clear();
    }
    // for(int i = 0 ;i<no_of_DNA_seq;i++)
    // {
    //     for(int j = 0 ;j<vec[i].size();j++)
    //     {
    //         cout<<vec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int mx = -1 ;
    string target_kmer;
    int hamming_dis = 0;
    for(int i = 0;i<1;i++)
    {
        string tmp = possible_kmers[i];
        //cout<<tmp<<endl;
        find(tmp);
        hamming_dis = hamming_distance(tmp);
        //cout<<hamming_dis<<endl;
        if(hamming_dis>mx)
        {
            mx=hamming_dis;
            target_kmer=tmp;
        }
    }
    cout<<"Target K_mer : "<<"\t"<<"Value"<<endl;
    cout<<"   "<<target_kmer<<":"<<"\t"<<mx<<endl;
    return 0;
}







// 5
// 3
// ggcgttcag
// aagaatcag
// caaggagtt
// cacgtcaat
// caataatat