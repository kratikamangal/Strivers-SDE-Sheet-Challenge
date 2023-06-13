// Question---> MAximum activities
// #include<bits/stdc++.h>
// struct meeting{
//   int start,end,pos;
// };
// static bool comp(meeting a,meeting b)
// {
//     if(a.end<b.end)
//     return true;
//     else if(a.end>b.end)
//     return false;
//     else if(a.pos<b.pos)
//     return true;
//     return false;
// }
// int maximumActivities(vector<int> &start, vector<int> &end) {
//     int n=start.size();
//         struct meeting arr[n];
//         for(int i=0;i<n;i++)
//         {
//            arr[i].start=start[i];
//            arr[i].end=end[i];
//            arr[i].pos=i+1;
//         }
//         sort(arr,arr+n,comp);
//         int count=1;
//         int time=arr[0].end;
//         for(int i=1;i<n;i++)
//         {
//             if(arr[i].start>=time)
//             {
//                 count++;
//                 time=arr[i].end;
//             }
//         }
//         return count;
// }


// //Question --->Minimum number of Platforms
// int calculateMinPatforms(int arr[], int dep[], int n) {
//     sort(dep,dep+n);
//     	sort(arr,arr+n);
//     	int i=0,j=0;
//     	int count=0;
//     	int maxi=0;
//     	while(i<n && j<n)
//     	{
//     	    if(arr[i]<=dep[j])
//     	    {
//     	        i++;
//     	        count++;
//     	        maxi=max(maxi,count);
//     	    }
//     	    else
//     	    {
//     	        j++;
//                 i++;
                
//     	    }
//     	}
//     	return maxi;
// }

// Question --->find minimum number of coins 
// #include <bits/stdc++.h> 
// int findMinimumCoins(int amount) 
// {
//   int arr[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
//   int i=8;
//   int cnt=0;
//   while(amount>0)
//   {
//       if(amount>=arr[i])
//       {
//           amount-=arr[i];
//           cnt++;
//       }else
//       i--;
//   }
//     return cnt;
// }


// Question----> Maximum meetings in one room 
// #include <bits/stdc++.h> 
// struct meeting{
//   int start,end,pos;
// };
// static bool comp(meeting a,meeting b)
// {
//     if(a.end<b.end)
//     return true;
//     else if(a.end>b.end)
//     return false;
//     else if(a.pos<b.pos)
//     return true;
//     return false;
// }

// vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
//    int n=start.size();
//     struct meeting arr[n];
//         for(int i=0;i<n;i++)
//         {
//            arr[i].start=start[i];
//            arr[i].end=end[i];
//            arr[i].pos=i+1;
//         }
//         sort(arr,arr+n,comp);
//         int count=1;
//         vector<int>ans;
//         int time=arr[0].end;
//         ans.push_back(arr[0].pos);
//         for(int i=1;i<n;i++)
//         {
//             if(arr[i].start>time)
//             {
//                 ans.push_back(arr[i].pos);
//                 time=arr[i].end;
//             }
//         }
//         return ans;
// }

// Question --->Job sequencing 
// #include <bits/stdc++.h> 
// static bool comp(vector<int> a,vector<int>b){
//     if(a[1]>b[1])
//     return true;
//     else if(a[1]<b[1])
//     return false;
//     else if(a[0]>b[0])
//     return true;
//     return false;
// }
// int jobScheduling(vector<vector<int>> &arr)
// {
//     int n=arr.size();
//        vector<int>v(3000+1,-1);
//     //    map<int,int>v;
//        sort(arr.begin(),arr.end(),comp);
//        int max_profit=0;
//        int count=0;
//        for(int i=0;i<n;i++)
//        {
//            while(arr[i][0]>=1)
//            {
               
//                if(v[arr[i][0]]==-1){
//                    v[arr[i][0]]=i+1;
//                    max_profit+=arr[i][1];
//                    count++;
//                    break;
//                }
//                else
//                {
//                    arr[i][0]--;
//                }
//            }
//        }
       
//        return max_profit;
// }


// //Question --->Fractional Knapsack
// #include <bits/stdc++.h> 

// static bool comp(pair<int,int> &a,pair<int,int>&b)
//     {
//         double r1=(double)a.second/a.first;
//          double r2=(double)b.second/b.first;
//          if(r1>r2)
//          return true;
//          return false;
//     }
// double maximumValue (vector<pair<int, int>>& arr, int n, int w)
// {
//      vector<int>ans;
//        sort(arr.begin(),arr.end(),comp);
//        double finalValue=0;
//        int currWeight=0;
//        for(int i=0;i<n;i++)
//        {
//            if(w>=arr[i].first+currWeight)
//            {
//                currWeight+=arr[i].first;
//                finalValue+=arr[i].second;
//            }
//            else
//            {
//                int remain=w-currWeight;
//                finalValue+=((double)arr[i].second/arr[i].first)*remain;
//                break;
//            }
//        }
//        return finalValue;
// }