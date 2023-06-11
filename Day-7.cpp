// Question --> Roate a linked list 

// Node *rotate(Node *head, int k) {
//      Node *cur=head;
//         if(head==NULL)
//         return head;
//         int len=1;
//         while(cur->next)
//         {
//             cur=cur->next;
//             len++;
//         }
//         k=k%len;
//         k=len-k;
//         cur->next=head;
//         while(k--)
//         cur=cur->next;
//         head=cur->next;
//         cur->next=NULL;
//         return head;

// }

// Question -->3sum
// #include <bits/stdc++.h> 
// vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
// 	 vector<vector<int>>ans;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n;i++)
//         {
//             while(i>0 && i<n && nums[i]==nums[i-1])
//             i++;
//             int j=i+1;
//             int k=n-1;
//             while(j<k)
//             {
//                 int sum=nums[i]+nums[j]+nums[k];
//                 if(sum<K)
//                 j++;
//                 else if(sum>K)
//                 k--;
//                 else{
//                     vector<int>temp= {nums[i],nums[j],nums[k]};
//                     ans.push_back(temp);
//                     j++;
//                     k--;
//                     while(j<k && nums[j]==nums[j-1])
//                     j++;
//                     while(j<k && nums[k]==nums[k+1])
//                     k--;
//                 }
//             }
//         }
//         return ans;
// }

// Question --->Trapping rainwater
// #include <bits/stdc++.h> 
// long getTrappedWater(long *height, int n){
//      long  ans=0;
        
//         long maxr[n],maxl[n];
//         maxr[n-1]=height[n-1];
//         for(int i=n-2;i>=0;i--)
//         {
//             maxr[i]=max(maxr[i+1],height[i]);
//         }
//         maxl[0]=height[0];
//         for(int i=1;i<n;i++)
//         {
//             maxl[i]=max(maxl[i-1],height[i]);
//         }
//         for(int i=0;i<n;i++)
//         {
//             ans+=min(maxr[i],maxl[i])-height[i];
//         }
//         return ans;
// }

// Question -->Remove duplicates from array 

// removeDuplicates(vector<int> &a, int n) {
//         int j=0,cn=1;
//         for(int i=1;i<n;i++)
//         {
//             if(a[i]!=a[i-1])
//             {
//                 a[++j]=a[i];
//                 cn++;
//             }

//         }
//         return cn;
// }

// Question --->maximum consecutive one's 
// int longestSubSeg(vector<int> &arr , int n, int m){
//     int i=0,j=0,x;
//         int count=0;
//         int maxi=-1e9;
//         while(j<n)
//         {
//            if(arr[j]==0)
//            {
//                count++;
//            }
//            if(count<=m)
//            maxi=max(maxi,j-i+1);
//            else
//            {
//                while(count>m)
//                {
//                    if(arr[i]==0)
//                    count--;
//                    i++;
//                }
//            }
//            j++;
//         }
//         maxi=max(maxi,j-i);
//         return maxi;
// }

// Question --->clone a random a linked list
// LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
// {
//      LinkedListNode<int> *itr=head,*front=head;
//         LinkedListNode<int> *copy;
//         LinkedListNode<int> *dummy=new LinkedListNode<int>(0);
//         dummy->random=NULL;
//         if(head==NULL)
//         return dummy->next;
//         while(itr!=NULL)
//         {
//             front=itr->next;
//             copy=new LinkedListNode<int>(itr->data);
//             copy->random=NULL;
//             itr->next=copy;
//             copy->next=front;
//             itr=front;
//         }
//         itr=head;
//         while(itr!=NULL)
//         {
//             if(itr->random!=NULL)
//                 itr->next->random=itr->random->next;
//             itr=itr->next->next;
//         }
//         itr=head;
//         copy=dummy;
//         while(itr!=NULL)
//         {
//             front=itr->next->next;
//             copy->next=itr->next;
//             itr->next=front;
//             copy=copy->next;
//             itr=itr->next;
//         }
//         return dummy->next;
// }

