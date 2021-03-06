Problem Statement  : https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

/********************* Time Comp : O(n^2) *********************/

int maxsumsqu(int *arr,int n)
{
    int *dp=new int[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=arr[i];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j]  && dp[i]<dp[j]+arr[i])
            {
                dp[i]=dp[j]+arr[i];
                
            }
        }
    }
    
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(max<dp[i])
          max=dp[i];
    }      
    return max;
}
