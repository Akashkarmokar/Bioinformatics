#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int main()
{
#ifndef Akash
    freopen("input.txt","r",stdin);
#endif // Akash
    int n;
    cout<<"Enter the number of input"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int cnt=0;
    for(int pos=1;pos<=n;pos++)
    {
        cout<<"Position : "<<pos<<endl;
        if(pos==arr[pos])
        {
            cout<<"step value : "<<cnt<<endl;
            for(int i= 1 ;i<=n;i++)
                cout<<arr[i]<<" ";
            cout<<"\n\n";
            continue;
        }
        if(pos==abs(arr[pos]))
        {
            arr[pos]=arr[pos]*(-1);
            cnt++;
            //cout<<cnt<<endl;
            cout<<"step value : "<<cnt<<endl;
            for(int i= 1 ;i<=n;i++)
                cout<<arr[i]<<" ";
            cout<<"\n\n";
            continue;
        }
        for(int j=pos;j<=n;j++)
        {
            if(abs(arr[j])==pos)
            {
                int i = pos;
                int k = j ;
                while(i<=k)
                {
                    arr[i]=arr[i]*(-1);
                    arr[k]=arr[k]*(-1);
                    swap(arr[i],arr[k]);
                    i++;
                    k--;
                }
                cnt++;
                int tmp = pos + j;
                if(tmp%2==0)
                {
                    arr[tmp/2]=arr[tmp/2]*(-1);
                }
                break;
            }
        }
        cout<<"step value : "<<cnt<<endl;
        for(int i= 1 ;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        if(pos!=arr[pos])
        {
            arr[pos]=arr[pos]*(-1);
            cnt++;
        }
        cout<<"step value : "<<cnt<<endl;
        for(int i= 1 ;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<"\n\n";
    }
    cout<<"Total Number of steps :"<<cnt<<endl;
    for(int i= 1 ;i<=n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
//6
//5 -6 1 3 -2 -4
