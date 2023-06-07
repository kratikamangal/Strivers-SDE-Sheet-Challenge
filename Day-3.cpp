// Question ---> search in a 2d matrix
//  int low=0;
//        int n=matrix.size();
//        int m=matrix[0].size();
//        int high=n*m-1;
//        while(low<=high)
//        {
//            int mid=low+(high-low)/2;
//            if(matrix[mid/m][mid%m]==target)
//            return true;
//            if(matrix[mid/m][mid%m]<target)
//            low=mid+1;
//            else
//            high=mid-1;
//        }
//        return false;

//Question ---> pow(x,n)
// int ans=1;
// 	while(n>0)
// 	{
// 		if(n&1)
// 		ans=(ans*1LL*x)%m;
// 		x=(x*1LL*x)%m;
// 		n=n>>1;
// 	}
// 	return ans;

// Question ---> MAjority element >(n/2)
// int n=nums.size();
//         int count=0;
//         int ele;
//         for(int i=0;i<n;i++)
//         {
//             if(count==0 || ele==nums[i])
//             {
//                 ele=nums[i];
//                 count++;
//             }
//             else
//             count--;
//         }
//          int cnt=0;
//        if(count>0)
//        {
          
//            for(int i=0;i<n;i++)
//            {
//                if(ele==nums[i])
//                cnt++;
//            }
//        }
//        if(cnt>n/2)
//        return ele;
//        return -1;

// Question ----> Majority element >(n/3)
// vector<int>ans;
//         int cnt=0,ele1=INT_MIN;
//         int cnt2=0,ele2=INT_MIN;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(cnt==0 && nums[i]!=ele2)
//             {
//                 cnt=1;
//                 ele1=nums[i];
//             }
//             else if(cnt2==0 && nums[i]!=ele1)
//             {
//                 cnt2=1;
//                 ele2=nums[i];
//             }
//             else if(ele1==nums[i])
//             cnt++;
//             else if(ele2==nums[i])
//             cnt2++;
//             else
//             {
//                 cnt--;
//                 cnt2--;
//             }
//         }
//         int c1=0,c2=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==ele1)
//             c1++;
//             if(nums[i]==ele2)
//             c2++;
//         }
//         int n=nums.size()/3;
//         if(c1>n)
//         ans.push_back(ele1);
//         if(c2>n)
//         ans.push_back(ele2);
//         return ans;


// Question ---> grid Unique Path
//   vector<int>dp(n);
//     for(int i=0;i<m;i++)
//     {
//         vector<int>temp(n);
//         for(int j=0;j<n;j++)
//         {
//             int up=0,left=0;
//             if(i==0 && j==0)
//                 temp[0]=1;
//             else{
//             if(i>0)
//              up=dp[j];
//             if(j>0)
//                left=temp[j-1];
//             temp[j]=up+left;}
//         }
//         dp=temp;
//     }
//     return dp[n-1];


// Question --->Reverse Pairs
//  int cnt=0;
//      void merge(vector<int>&arr,int low,int mid,int high)
//     {
//          int right=mid+1;
//         for(int i=low;i<=mid;i++)
//         {
//             while(right<=high && (long long)arr[i]>(long long)2*arr[right])right++;
//             cnt=cnt+(right-(mid+1));
//         }
//         int left=low;
//          right=mid+1;
//         vector<int>temp;
//         while(left<=mid && right<=high)
//         {
//             if(arr[left]<=arr[right])
//             {
//                 temp.push_back(arr[left]);
//                 left++;
//             }else
//             {
//                 temp.push_back(arr[right]);
//                 right++;
//             }
//         }
//         while(left<=mid)
//         {
//             temp.push_back(arr[left]);
//                 left++; 
//         }
//         while(right<=high)
//         {
//              temp.push_back(arr[right]);
//                 right++;
//         }
//         for(int i=low;i<=high;i++)
//         {
//             arr[i]=temp[i-low];
//         }
        
//     }
    
//     // int countPairs(vector<int>arr,int low,int mid,int high)
//     // {
//     //     int cnt=0;
//     //     int right=mid+1;
//     //     for(int i=low;i<=mid;i++)
//     //     {
//     //         while(right<=high && (long long)arr[i]>(long long)2*arr[right])right++;
//     //         cnt=cnt+(right-(mid+1));
//     //     }
//     //     return cnt;
//     // }
    
//      void mergeSort(vector<int>&arr,int low,int high)
//     {
//        int cnt=0;
//         if(low<high)
//         {
//             int mid=(low+high)/2;
//            mergeSort(arr,low,mid);
//            mergeSort(arr,mid+1,high);
//           //  countPairs(arr,low,mid,high);
//             merge(arr,low,mid,high);
//         }
//         //return cnt;
//     }
// public:
//     int reversePairs(vector<int>& arr) {
//          mergeSort(arr,0,arr.size()-1);
//         return cnt;
//     }