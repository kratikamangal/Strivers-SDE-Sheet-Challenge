// Question----> Rotate matrix

// void rotateMatrix(vector<vector<int>> &arr, int n, int m)
// {
//     int top=0,bottom=n-1;
//     int left=0,right=m-1;
//     while(top<bottom && left<right)
//     {
//         int ch=arr[left][top];
//         for(int i=left;i<=right;i++)
//         {
//             swap(arr[top][i],ch);
//         }
//         top++;
//         for(int j=top;j<=bottom;j++)
//         {
//             swap(ch,arr[j][right]);
//         }
//         right--;
//         if(top<=bottom)
//         {
//             for(int i=right;i>=left;i--)
//             {
//                 swap(ch,arr[bottom][i]);
//             }
//             bottom--;
//         }
//         if(left<=right)
//         {
//             for(int i=bottom;i>=top;i--)
//             {
//                 swap(ch,arr[i][left]);
//             }
//             left++;
//         }
//         arr[left-1][top-1]=ch;
//     }
// }

// Question ---> Merge Overlapping Subintervals
// vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
// {
//     vector<vector<int>>ans;
//          int n=intervals.size();
//          sort(intervals.begin(),intervals.end());
//          for(int i=0;i<n;i++)
//          {
//             if(ans.empty() || ans.back()[1]<intervals[i][0])
//             {
//                 ans.push_back({intervals[i][0],intervals[i][1]});
//             }
//             else{
//                 if(ans.back()[1]>=intervals[i][0]){
//                     if(ans.back()[1]<intervals[i][1])
//                     ans.back()[1]=intervals[i][1];
//                 }
//             }
//          }
//          return ans;
// }


//Question --->merge two sorted arrays
// void swapifGrater(vector<int>& arr1, vector<int>& arr2,int left,int right)
//     {
//         if(arr1[left]>arr2[right])
//         {
//             swap(arr1[left],arr2[right]);
//         }
//     }

// vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m) {
// 	int len=n+m;
//            int gap=(len/2)+(len%2);
//            while(gap>0)
//            {
//                int left=0;
//                int right=left+gap;
//                while(right<len)
//                {
//                    if(left<n && right>=n)
//                    {
//                        swapifGrater(arr1,arr2,left,right-n);
//                    }else if(left>=n){
//                        swapifGrater(arr2,arr2,left-n,right-n);
//                    }else{
//                        swapifGrater(arr1,arr1,left,right);
//                    }
//                    left++;
//                    right++;
//                }
//                if(gap==1)
//                break;
//                gap=(gap/2)+gap%2;
//            }
//            int l=0;
//            while(l<m)
//            {
//              arr1[n++]=arr2[l++];
//            }
// 		   return arr1;
// }


//Question ---->duplicates in array

// int findDuplicate(vector<int> &arr, int n){
// 	unordered_map<int,int>mp;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(mp[arr[i]]!=0)
// 		return arr[i];
// 		mp[arr[i]]++;
// 	}
// 	// for(auto it:mp)
// 	// {
// 	// 	if(it.second>1)
// 	// 	return it.first;
// 	// }
// 	return -1;
// }

// Question ---> repeat and missing number
// pair<int,int> missingAndRepeating(vector<int> &arr, int n1)
// {
// 	 long long int n=(long long int)n1;
//         long long int sn=(n*(n+1))/2;
//        long long int sn2=(n*(n+1)*(2*n+1))/6;
//         long long int s=0,s2=0;
//         for(int i=0;i<n;i++)
//         {
//             s+=(long long int)arr[i];
//             s2+=(long long int)arr[i]*(long long)arr[i];
//         }
//         long long int val1=s-sn;
//          long long int val2=s2-sn2;
//         val2=val2/val1;
//          long long int x=(val1+val2)/2;
//          long long int y=x-val1;
// 		 pair<int,int>ans;
//          ans={(int)y,(int)x};
// 		 return ans;
	
// }


// Question -->inversion
// long long  merge(long long arr[],long long low,long long mid,long long high)
//     {
//         long long  cnt=0;
//         long long left=low;
//         long long right=mid+1;
//         vector<long long>temp;
//         while(left<=mid && right<=high)
//         {
//             if(arr[left]<=arr[right])
//             {
//                 temp.push_back(arr[left]);
//                 left++;
//             }else
//             {
//                 cnt=cnt+(mid-left+1);
//                 temp.push_back(arr[right++]);
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
//         for(long long i=low;i<=high;i++)
//         {
//             arr[i]=temp[i-low];
//         }
//         return cnt;
//     }

// long long  mergeSort(long long arr[],long long low,long long high)
//     {
//         long long  cnt=0;
//         if(low<high)
//         {
//             long long mid=(low+high)/2;
//             cnt+=mergeSort(arr,low,mid);
//             cnt+=mergeSort(arr,mid+1,high);
//             cnt+=merge(arr,low,mid,high);
//         }
//         return cnt;
//     }
    
// long long getInversions(long long *arr, int n){
//     return mergeSort(arr,0,n-1);
// }