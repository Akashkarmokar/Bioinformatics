#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef Akash
//     freopen("input.txt","r",stdin);
// #endif
    cout<<"Enter your string :"<<endl;
    string s;cin>>s;
    cout<<"Enter k-mer value"<<endl;
    int k_mer;cin>>k_mer;
    vector<double>profile_matrix[4];
    for(int i=0;i<4;i++)
    {
        if(i==0)
            cout<<"enter for A row "<<k_mer<<" times :"<<endl;
        if(i==1)
            cout<<"enter for C row "<<k_mer<<" times :"<<endl;
        if(i==2)
            cout<<"enter for T row "<<k_mer<<" times :"<<endl;
        if(i==3)
            cout<<"enter for G row "<<k_mer<<" times :"<<endl;
        for(int j = 1;j<=k_mer;j++)
        {
            double tmp;
            cin>>tmp;
            profile_matrix[i].push_back(tmp);
        }   
    }
    // Output of the profile matrix
    // cout<<"Output of the profile matrix"<<endl;
    // for(int i = 0 ;i<4;i++)
    // {
    //     if(i==0)
    //         cout<<" A  :";
    //     if(i==1)
    //         cout<<" C  :";
    //     if(i==2)
    //         cout<<" T  :";
    //     if(i==3)
    //         cout<<" G  :";
    //     for(int j = 0;j<profile_matrix[i].size();j++)
    //     {
    //         cout<<profile_matrix[i][j]<<" ";
    //     }   
    //     cout<<endl;
    // }
    double maximum_prf_mst_k_mer=0;
    string maximum_profile_string;
    for(int i = 0 ;i<s.size();i++)
    {
        if(i+k_mer>s.size())
            break;
        string tmp = s.substr(i,k_mer);
        double tmp_profile_most =1.0;
        for(int j=0;j<tmp.size();j++)
        {
            if(tmp[j]=='A')
            {
                tmp_profile_most*=profile_matrix[0][j];
            }
            if(tmp[j]=='C')
            {
                tmp_profile_most*=profile_matrix[1][j];
            }
            if(tmp[j]=='T')
            {
                tmp_profile_most*=profile_matrix[2][j];
            }
            if(tmp[j]=='G')
            {
                tmp_profile_most*=profile_matrix[3][j];
            }
        }
        if(tmp_profile_most>maximum_prf_mst_k_mer)
        {
            maximum_prf_mst_k_mer=tmp_profile_most;
            maximum_profile_string= tmp;
        }
    }
    cout<<"_________________________"<<endl;
    cout<<"Maximum profile most string :"<<endl;
    cout<<maximum_profile_string<<endl;
    cout<<"Maximun profile most k_mer:"<<endl;
    cout<<maximum_prf_mst_k_mer<<endl;
    return 0;
}