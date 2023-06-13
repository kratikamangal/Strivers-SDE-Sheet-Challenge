// Question --->subset sum 
// #include <bits/stdc++.h> 
//  void solve(vector<int>&arr,vector<int>&ans,int sum, int index)
//     {
//         if(index==arr.size())
//         {
//             ans.push_back(sum);
//             return;
//         }
//         sum+=arr[index];
//         solve(arr,ans,sum,index+1);
//         sum-=arr[index];
//         solve(arr,ans,sum,index+1);
//     }
// vector<int> subsetSum(vector<int> &arr)
// {
//     vector<int>ans;
//         solve(arr,ans,0,0);
//         sort(ans.begin(),ans.end());
//         return ans;
// }

// Question ---> SubsetII
// #include <bits/stdc++.h> 
// void solve(vector<int>& nums,int index,vector<vector<int>>&res,vector<int>& ds)
//     {
//             res.push_back(ds);
//           //  return ;
        
//         for(int i=index;i<nums.size();i++)
//         {
//             if(i!=index && nums[i]==nums[i-1]) continue;
//             ds.push_back(nums[i]);
//             solve(nums,i+1,res,ds);
//             ds.pop_back();
//         }
//     }
// vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
// {
//    vector<vector<int>>res;
//         vector<int>ds;
//         sort(nums.begin(),nums.end());
//         solve(nums,0,res,ds);
//         return res;
// }

// Question --->Combination sum 
// void solve(int index,vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&ds)
//     {
//         if(index==candidates.size())
//         {
//             if(target==0)
//             ans.push_back(ds);
//             return;
//         }
       
//             ds.push_back(candidates[index]);
//             solve(index+1,candidates,target-candidates[index],ans,ds);
//             ds.pop_back();
        
//          solve(index+1,candidates,target,ans,ds);
//     }

// vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int n, int k)
// {
//     vector<vector<int>>ans;
//         vector<int>ds;
//         solve(0,arr,k,ans,ds);
//         return ans;
// }

// Question -->Combination sumII
// #include<bits/stdc++.h>
// void solve(int index,vector<int>&arr,int target,vector<vector<int>>&ans,vector<int>&ds)
//     {
//         if(target==0)
//         {
//             ans.push_back(ds);
//             return;
//         }
//         for(int i=index;i<arr.size();i++)
//         {
//             if(i!=index && arr[i]==arr[i-1])
//             continue;
//             if(arr[i]>target)
//             break;
//             ds.push_back(arr[i]);
//             solve(i+1,arr,target-arr[i],ans,ds);
//             ds.pop_back();
//         }
//     }
// vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
// {
// 	sort(arr.begin(),arr.end());
//         vector<vector<int>>ans;
//         vector<int>ds;
//         solve(0,arr,target,ans,ds);
//         return ans;
// }


// Question --> PAlindrome partitoning
// #include <bits/stdc++.h> 
//  bool isPalindrome(int start,int end,string s)
//     {
//         while(start<=end)
//         {
//             if(s[start++]!=s[end--])
//             return false;
//         }
//         return true;
//     }
//     void solve(int index,string s,vector<string>&move,vector<vector<string>>&ans,int n)
//     {
//         if(index==n)
//         {
//             ans.push_back(move);
//             return;
//         }
//         for(int i=index;i<n;i++)
//         {
//             if(isPalindrome(index,i,s))
//             {
//                 move.push_back(s.substr(index,i-index+1));
//                 solve(i+1,s,move,ans,n);
//                 move.pop_back();
//             }
//         }
//     }
// vector<vector<string>> partition(string &s) 
// {
//     vector<vector<string>>ans;
//         vector<string>move;
//         int n=s.size();
//         solve(0,s,move,ans,n);
//         return ans;
// }

// Question --->kth permutation 
// string kthPermutation(int n, int k) {
//      string ans;
//         vector<int>numbers;
//         int fact=1;
//         for(int i=1;i<n;i++)
//         {
//             fact=fact*i;
//             numbers.push_back(i);
//         }
//         numbers.push_back(n);
//         k=k-1;
//         while(true)
//         {
//             ans+=to_string(numbers[k/fact]);
//             numbers.erase(numbers.begin()+(k/fact));
//             if(numbers.size()==0)
//                 break;
                
//                 k=k%fact;
//             fact=fact/numbers.size();
//         }
//         return ans;
// }
