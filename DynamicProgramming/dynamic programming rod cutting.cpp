using namespace std;
#include<iostream>
#include<vector>

class RodCutting{
    public:
    int MaxProfitOfRodCutting(int price[], int length[], int RodLength){
        int n = sizeof(price)/sizeof(price[0]);
        return this->solve(price, length, RodLength, n);
    }
    private:
    int solve(int price[], int length[], int RodLength, int n){
        
        int dp[n][RodLength+1];
        for(int i = 0; i < n; i++)
        for(int j = 0; j <= RodLength; j++)
        {
            
                int skip = 0, pick = 0;
                if(length[i] <= j)
                pick = price[i]+dp[i][j - length[i]];
                if(i > 0)
                skip = dp[i-1][j];
                dp[i][j] = max(skip, pick);
            
        }
        return dp[n-1][RodLength];
    }
};

int main()
{
    RodCutting *rod  = new RodCutting();
    int price[]  = {2,6,7,10,13};
    int length[] = {1,2,3,4,5};
    int RodLength = 5;
    cout << rod->MaxProfitOfRodCutting(price, length, RodLength) << endl;
    delete rod;
}
