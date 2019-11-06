#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int n,k,t;
vector<string>vec;
vector<string>motif;


int printRandoms(int lower, int upper, int count)
{
    int i,num;
    num = (rand()%(upper - lower + 1)) + lower;
    return num;
}
int main()
{
#ifndef Akash
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif // Akash

    cout<<"Enter the value of n , k , t :"<<endl;
    cin>>n>>k>>t;// n=length of the strings, k= k-mer value , t=total DNA string
    cout<<n<<" "<<k<<" "<<t<<endl;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        vec.push_back(s);
    }

    srand(time(0)); // used for Random Function

    int lower = 0;
    int upper = n-k ;
    int cnt = 1;
    cout<<"MOTIFS:"<<endl;
    for(int i = 0 ;i<t;i++)
    {
        int pos=printRandoms(lower,upper,cnt);
        //cout<<pos<<endl;
        int lmt = pos+k-1;
        //cout<<"lmt"<<lmt<<endl;
        string tmp = vec[i];
        //cout<<tmp<<endl;
        string mt="";
        for(int j = pos;j<=lmt;j++)
        {
            mt+=tmp[j];
        }
        cout<<"\t\t"<<mt<<endl;
        motif.push_back(mt);
    }
    //cout<<motif.size()<<endl;

    double prf[4][k+1]; // Profile Matrix array 
    for(int i = 0 ;i<4;i++)
        for(int j=0;j<k;j++)
            prf[i][j]=0;

    for(int i=0;i<motif.size();i++)
    {
        string x=motif[i];
        for(int j = 0 ;j<x.size();j++)
        {
            if(x[j]=='a')
                prf[0][j]++;
            if(x[j]=='c')
                prf[1][j]++;
            if(x[j]=='t')
                prf[2][j]++;
            if(x[j]=='g')
                prf[3][j]++;
        }
    }
    cout<<endl;

    // Count Matrix  //

    cout<<"Count Matrix:"<<endl;
    for(int i = 0 ;i<4;i++)
    {
        if(i==0)
            cout<<"\t\tA :";
        else if(i==1)
            cout<<"\t\tC :";
        else if(i==2)
            cout<<"\t\tT :";
        else if(i==3)
            cout<<"\t\tG :";
        for(int j=0;j<k;j++)
        {
            cout<<prf[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i = 0 ;i<4;i++)
    {
        for(int j=0;j<k;j++)
        {
            prf[i][j]=prf[i][j]/t;
        }
    }
    cout<<endl;

    // Profile Matrix //

    cout<<"Profile Matrix :"<<endl;
    for(int i = 0 ;i<4;i++)
    {
        if(i==0)
            cout<<"\t\tA :";
        else if(i==1)
            cout<<"\t\tC :";
        else if(i==2)
            cout<<"\t\tT :";
        else if(i==3)
            cout<<"\t\tG :";
        for(int j=0;j<k;j++)
        {
            cout<<"\t\t"<<prf[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<pair<string,double> > final_ans;
    // Checking for i-th DNA string 
    for(int i = 0 ;i<vec.size();i++)
    {
        string tmp = vec[i];
        double mx = -1;
        string ans;
        for(int j = 0;j+k-1<n;j++)
        {
            string tmp_motif = tmp.substr(j,k);
            //m cout<<j+1<<")\t"<<tmp_motif<<endl;
            double res = 1.0;
            for(int posi = 0;posi<k;posi++)
            {
                //cout<<"Position "<<posi<<" ";
                if(tmp_motif[posi]=='a')
                {
                    //m cout<<prf[0][posi];
                    res*=prf[0][posi];
                }
                else if(tmp_motif[posi]=='c')
                {
                    //m cout<<prf[1][posi];
                    res*=prf[1][posi];
                }
                else if(tmp_motif[posi]=='t')
                {
                    //m cout<<prf[2][posi];
                    res*=prf[2][posi];
                }
                else if(tmp_motif[posi]=='g')
                {
                    //m cout<<prf[3][posi];
                    res*=prf[3][posi];
                }
                //m if(posi<k-1)
                //m     cout<<" * ";
            }
            // cout<<endl;
            //m cout<<"= "<<res<<endl;
            if(res>mx)
            {
                mx = res;
                ans = tmp_motif;
            }
        }
        //m cout<<"BEST : "<<mx<<" "<<ans<<endl; 
        //m cout<<endl;
        final_ans.push_back(make_pair(ans,mx));
    }
    cout<<"------------------------------------------------------"<<endl;
    //cout<<final_ans.size()<<endl;
    cout<<"After First Iteration : \n\n";
    for(int i = 0 ;i<final_ans.size();i++)
    {
        cout<<i+1<<")\t"<<final_ans[i].first<<" "<<final_ans[i].second<<endl;
    }
    return 0;
}

// 8
// 3
// 4
// cgaatgca
// tgcatgac
// ggcagggc
// tcacctgt
//
// to understand the code  delete comments which start with 'm'
