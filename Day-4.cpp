// //Question --->2sum
//  vector<int>ans;
//         unordered_map<int,int>mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(mp.find(target-nums[i])!=mp.end())
//             {
//                 return {mp[target-nums[i]],i};
//             }
//             mp[nums[i]]=i;
//         }
//         return ans;

// Question --->4sum
// string ans="No";
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             if(i!=0 && nums[i]==nums[i-1])continue;
//             for(int j=i+1;j<n;j++)
//             {
//                 if(j!=i+1 && nums[j]==nums[j-1])continue;
//                 int k=j+1;
//                 int l=n-1;
//                 while(k<l)
//                 {
//                     long long sum=nums[i];
//                     sum+=(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
//                     if(sum==target)
//                     {
//                        return "Yes";
//                     }else if(sum<target)
//                     k++;
//                     else
//                     l--;
//                 }
//             }
//         }
//         return ans;


// Question -->Longest Consecutive Sequence
//   int longestConsecutive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         int cur_count=0,last=INT_MIN,l=0;
//         for(int i=0;i<n;i++)
//         {
//             if(last!=nums[i]-1 && last!=nums[i])
//            { cur_count=1;
//             }
//             else if(last==nums[i]-1)
//             {
//                 cur_count++;
//             }
//             last=nums[i];
//             l=max(l,cur_count);
//         }
//         return l;
//     }


// Question --->Longest subarray with K sum
// map<int,int>mp;
//          mp[0]=1;
//         int sum=0;
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             sum+=A[i];
//             if(sum==0)
//             ans=max(ans,i+1);
//              if(mp.find(sum)!=mp.end())
//             {
//                 ans=max(ans,i-mp[sum]);
//             }
//             else
//             mp[sum]=i;
//         }
//         return ans;

// Question -->count subarry with xor k
//  map<int,int>mp;
//         int xr=0;
//         mp[xr]++;
//         int count=0;
//        for(int i=0;i<N;i++)
//        {
//            xr=xr^arr[i];
//            int x=xr^k;
//              count+=mp[x];  
           
//            mp[xr]++;
//        }
//        return count;
    

// Question -->Longest substring without replacement
// int lengthOfLongestSubstring(string s) {
//         vector<int>v(256,-1);
//         int j=0;
//         int ans=0;
//         for(int i=0;i<s.size();i++)
//         {
//             if(v[s[i]]!=-1)
//             j=max(v[s[i]]+1,j);
//             v[s[i]]=i;
//             ans=max(ans,i-j+1);
//         }
//         return ans;
//     }