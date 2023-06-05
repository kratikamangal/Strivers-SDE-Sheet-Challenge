// Question ----> sort 0,1,2
// int low=0,mid=0,high=n-1;
//    while(mid<=high)
//    {
//       if(arr[mid]==0)
//       {
//          swap(arr[low],arr[mid]);
//          low+=1;
//          mid+=1;
//       }  
//       else if(arr[mid]==1)
//       {
//          mid++;
//       }
//       else
//       {
//          swap(arr[mid],arr[high]);
//          high--;
//       }
//    }



//Question----> Set matrix zero
// int n=matrix.size();
//         int m=matrix[0].size();
//         int col0=1;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     matrix[i][0]=0;
//                     if(j!=0)
//                     matrix[0][j]=0;
//                     if(j==0)
//                     col0=0;
//                 }
                
//             }
//         }
//          for(int i=1;i<=n-1;i++)
//          {
//              for(int j=1;j<m;j++)
//              {
//                  if(matrix[i][j]!=0)
//                  if(matrix[i][0]==0 || matrix[0][j]==0)
//                  matrix[i][j]=0;
//              }
//          }
//          if(matrix[0][0]==0)
//          {
//              for(int i=0;i<m;i++)
//              matrix[0][i]=0;
//          }
//          if(col0==0)
//          {
//              for(int i=0;i<n;i++)
//              matrix[i][0]=0;
//          }

// Question---> Pascal Triangle
// vector<int> genraterows(int n)
//     {
//         int ans=1;
//         vector<int>ansRow;
//         ansRow.push_back(ans);
//         for(int i=1;i<n;i++)
//         {
//             ans=ans*(n-i);
//             ans=ans/i;
//             ansRow.push_back(ans);
//         }
//         return ansRow;
//     }

// vector<vector<int>> generate(int numRows) {
//         vector<vector<int>>ans;
//         for(int i=1;i<=numRows;i++)
//         {
//             ans.push_back(genraterows(i));
//         }
//         return ans;
//     }

// Question---> Next Permuation
// int n=nums.size(),k,l;
//         for( k=n-2;k>=0;k--)
//         {
//           if(nums[k]<nums[k+1])
//           break;
//         }
//         if(k<0)
//         reverse(nums.begin(),nums.end());
//         else{
//           for(l=n-1;l>k;l--)
//           {
//             if(nums[l]>nums[k])
//             break;
//           }
//           swap(nums[k],nums[l]);
//           reverse(nums.begin()+k+1,nums.end());
//         }

//Question--->  Kadane's algorithm

// int maxi_sum=INT_MIN;
//         int sum=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];
//             maxi_sum=max(maxi_sum,sum);
//             if(sum<0)
//             sum=0;
//         }
//         return maxi_sum;
//     }

// Question --> Stock buy and sell
// int maxi_sum=INT_MIN;
//         int sum=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];
//             maxi_sum=max(maxi_sum,sum);
//             if(sum<0)
//             sum=0;
//         }
//         return maxi_sum;
//     }