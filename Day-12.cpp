//min heap


// kth largest and smallest
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	//  priority_queue<int,vector<int>,greater<int>>pq;
	 sort(nums.begin(),nums.end());
        
		return {nums[k-1],nums[n-k]};

}

// kt max sum combination
#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int N, int K){
	priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        pq.push({A[N-1]+B[N-1],{N-1,N-1}});
        st.insert({N-1,N-1});
        vector<int>ans;
        while(!pq.empty() && K>0)
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.first);
            int L=it.second.first;
            int R=it.second.second;
            if(L>0  && st.find({L-1,R})==st.end())
            {
                pq.push({A[L-1]+B[R],{L-1,R}});
                st.insert({L-1,R});
            }
             if(R>0 && st.find({L,R-1})==st.end())
            {
                pq.push({A[L]+B[R-1],{L,R-1}});
                st.insert({L,R-1});
            }
            K--;
        }
        return ans;
}


//Merge k sorted arrays
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int K)
{
     priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                pq.push(arr[i][j]);
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
}

//k most frequent elements
#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       {
           mp[nums[i]]++;
       }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      for(auto it:mp)
      {
          pq.push({it.second,it.first});
          if(pq.size()>k)
          pq.pop();
      }
      vector<int>ans(k);
      while(!pq.empty())
      {
         ans[k-1]=(pq.top().second);
         k--;
          pq.pop();
      }
      sort(ans.begin(),ans.end());
      return ans;
}
