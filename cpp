class Solution{
public:
    int maxIndexDiff(int arr[], int n) {

        vector<int>suf(n);
        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)suf[i]=max(suf[i+1],arr[i]);
        
        int ans=0;
        for(int i=0;i<n-1;i++){
            int lo=i+1,hi=n-1,mid,ind=i;
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                if(suf[mid]>=arr[i]){
                    ind=mid;
                    lo=mid+1;
                }
                else hi=mid-1;
            }
            ans=max(ans,ind-i);
        }
        return ans;
    }
};
    
