/*QUESTION:
Given two sorted arrays nums1 and nums2 of sizes m and n respectively, you need to find the median of the two sorted arrays.

APPROACH:
To find the median of two sorted arrays, we can apply the concept of binary search. The overall time complexity of the solution should be O(log (m+n)).

1. First, we ensure that nums1 is the smaller sized array. If not, we swap nums1 and nums2.
2. Calculate the optimal count opt_cnt, which is (nums1.size() + nums2.size() + 1) / 2. This represents the median index in the merged array.
3. Initialize low to 0 and high to nums1.size() - 1.
4. Perform binary search until low is less than or equal to high:
     - Calculate the cut1 as low + (high - low) / 2, which represents the potential index to partition nums1.
     - Calculate cut2 as opt_cnt - cut1, which represents the corresponding index in nums2.
     - Calculate l1, l2, r1, and r2 as the left and right elements around the potential partition points.
     - If l1 is less than or equal to r2 and l2 is less than or equal to r1, it means we have found the correct partition points.
          - If the total number of elements is even, return the average of the maximum of l1 and l2 and the minimum of r1 and r2.
          - If the total number of elements is odd, return the maximum of l1 and l2.
     - If l1 is greater than r2, move the high pointer to cut1 - 1.
     - Otherwise, move the low pointer to cut1 + 1.
5. If no median is found, return 0.0.

CODE:*/

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

double findMedianSortedArraysBF(vector<int> &nums1, vector<int> &nums2)
{
     int n1 = nums1.size();
     int n2 = nums2.size();

     int n = n1+n2;

     vector<int> arr3(n);

     int i=0;
     int j=0;
     int k=0;

     while(i<n1 && j<n2)
     {
          if(nums1[i] < nums2[j])
          {
               arr3[k] = nums1[i];
               i++;
               k++;
          }
          else
          {
               arr3[k] = nums2[j];
               j++;
               k++;
          }
     }

     while(i<n1)
     {
          arr3[k] = nums1[i];
          i++;
          k++;
     }
     
     while(j<n2)
     {
          arr3[k] = nums2[j];
          j++;
          k++;
     }

     if(n%2 == 0)
     {
          return (double)(arr3[n/2] + arr3[n/2 - 1]) / 2.0;
     }
     else
     {
          return (double)arr3[n/2];
     }
}


double findMedianSortedArraysOptimal(vector<int> &nums1, vector<int> &nums2)
{
     int n1 = nums1.size();
     int n2 = nums2.size();
     int n = n1+n2;

     int i=0;
     int j=0;
     
     int ind2 = n/2;
     int ind1 = ind2 - 1;
     int count = 0;

     int ind1ele = -1;
     int ind2ele = -1;

     while(i<n1 && j<n2)
     {
          if(nums1[i] < nums2[j])
          {
               if(count == ind1) ind1ele = nums1[i];
               if(count == ind2) ind2ele = nums1[i];
               count++;
               i++;
          }
          else
          {
               if(count == ind1) ind1ele = nums2[j];
               if(count == ind2) ind2ele = nums2[j];
               count++;
               j++;
          }
     }

     while(i<n1)
     {
          if(count == ind1) ind1ele = nums1[i];
          if(count == ind2) ind2ele = nums1[i];
          count++;
          i++;
     }

     while(j<n2)
     {
          if(count == ind1) ind1ele = nums2[j];
          if(count == ind2) ind2ele = nums2[j];
          count++;
          j++;
     }

     if(n%2 == 1)
     {
          return ind2ele;
     }

     return (double)(ind1ele + ind2ele) / 2.0; 
}


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
     int n1 = nums1.size();
     int n2 = nums2.size();

     if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

     int n = n1+n2;

     int left = (n1 + n2 + 1) / 2;

     int low = 0;
     int high = n1;

     while(low <= high)
     {
          int cut1 = (low + high) / 2;
          int cut2 = left - cut1;
          
          int l1 = INT_MIN;
          int l2 = INT_MIN;
          int r1 = INT_MAX;
          int r2 = INT_MAX;

          if(cut1 < n1) r1 = nums1[cut1]; // Right of cut1
          if(cut2 < n2) r2 = nums2[cut2]; // Right of cut2
          if(cut1 > 0) l1 = nums1[cut1 - 1]; // Left of cut1
          if(cut2 > 0) l2 = nums2[cut2 - 1]; // Left of cut2

          if(l1 <= r2 && l2 <= r1)
          {
               if(n%2 == 1) return max(l1, l2);
               else return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
          }
          else if(l1 > r2) high = cut1 - 1;
          else low = cut1 + 1;
     }
     return 0.0;
}

int main()
{
     int n1;
     cin>>n1;

     int n2;
     cin>>n2;
     
     vector<int> nums1(n1);
     vector<int> nums2(n2);

     for(int i=0; i<n1; ++i)
     {
          cin>>nums1[i];
     }

     for(int i=0; i<n2; ++i)
     {
          cin>>nums2[i];
     }

     double result1 = findMedianSortedArraysBF(nums1, nums2);
     double result2 = findMedianSortedArraysOptimal(nums1, nums2);
     double result3 = findMedianSortedArrays(nums1, nums2);

     cout<<result1<<" "<<result2<<" "<<result3;

     return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(log(min(m, n))), where m and n are the sizes of the input arrays nums1 and nums2, respectively. We perform binary search on the smaller array.
- Space complexity: O(1), as we use constant extra space throughout the algorithm.
*/
