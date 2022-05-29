#include<bits/stdc++.h>
using namespace std;

int maxH(int height[], int width[], int length[], int n);

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[1000], b[1000], c[1000];
        for(int i = 0 ; i < n ; i++)
        {
            int A, B, C;
            cin >> A >> B >> C;
            a[i] = A;
            b[i] = B;
            c[i] = C;
        }
        cout << maxH(a, b, c, n);
    }
    return 0;
}

struct box{
    int h, w, l;
};
bool compare(struct box a, struct box b)
{
    return(a.w*a.l > b.w*b.l) ? true: false;
}
int maxH(int height[], int width[], int length[], int n)
{
    int len  = 3 * n;
    box arr[len];
    int index = 0;
    for(int i = 0 ; i  < n; ++i)
    {
        arr[index].h = height[i];
        arr[index].w = max(width[i], length[i]);
        arr[index].l = min(width[i], length[i]);
        index += 1;
        
        arr[index].h  = width[i];
        arr[index].w = max(width[i], length[i]);
        arr[index].l = min(width[i], length[i]);
        index+=1;
        
        arr[index].h  = width[i];
        arr[index].w = max(width[i], length[i]);
        arr[index].l = min(width[i], length[i]);
        index+=1;
     }
     sort(arr, arr+len, compare);
     int lis[len];
     for(int i = 0 ; i < len; ++i)
     lis[i] = arr[i].h;
     
     for(int i = 1; i < len; ++i)
     {
         for(int  j = 0; j < i; ++j)
         {
             if((arr[i].w < arr[j].w) and (arr[i].l < arr[j].l) and (lis[i] < lis[j] + arr[i].h))
             lis[i] = lis[j] + arr[i].h;
         }
     }
     int mx = 0;
     for(int i = 0; i < len; ++i)
     mx = max(mx, lis[i]);
     
     return mx;
}


