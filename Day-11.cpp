Question -->Single Duplicate number
int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();
        if(n==1)
        return arr[n-1];
        if(arr[0]!=arr[1])
        return arr[0];
        if(arr[n-1]!=arr[n-2])
        return arr[n-1];
        int low=1,high=n-2;
        while(low<=high)
        {
           int mid=(low+high)/2;
           if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1])
           return arr[mid];
           if((mid%2!=0 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid+1]==arr[mid]))
           low=mid+1;
           else
           high=mid-1;
           
        }
        return -1;
}


Question --->Seacrh and rotated sorted __ARRAy 
int search(int* nums, int n, int key) {
     int l=0;
        int h=n-1;
         while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==key)
            return mid;
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=key && nums[mid]>=key)
            h=mid-1;
            else 
            l=mid+1;
            }
            else
            {
                if(nums[mid]<=key && nums[h]>=key)
                l=mid+1;
                else 
                h=mid-1;
            }
        }
        return -1;
}

Question --->find meadian
double median(vector<int>& nums1, vector<int>& nums2) {
	if(nums2.size()<nums1.size()) return  median(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
	int low=0,high=n1;
        while(low<=high)
        {
            int cut1=(low+high)>>1;
            int cut2=((n1+n2+1)>>1)-cut1;
            int l1=  cut1==0?INT_MIN:nums1[cut1-1];
            int l2=  cut2==0?INT_MIN:nums2[cut2-1];
            
            int r1=  cut1==n1?INT_MAX:nums1[cut1];
             int r2=  cut2==n2?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n1+n2)%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
            {
                high=cut1-1;
            }
            else 
                low=cut1+1;
        }
        return 0.0;
}