/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/
class Solution {

  // MERGE SORT ALGORITHM
    public static void merging(int arr[], int n, int left[], int l, int right[], int r){
        int i=0,j=0,k=0;
        while(i<l && j<r){
            if(left[i] > right[j]){
                arr[k] = right[j];
                j++;
            }
            else{
                arr[k] = left[i];
                i++;
            }
            k++;
        }

        while(i<l){
            arr[k] = left[i];
            i++;
            k++;
        }
        while(j<r){
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    public static void mergeSort(int arr[], int n){
        if(n>1){
            int mid = n/2;
            int left[] = new int[mid];
            int right[] = new int[n-mid];

            for(int i=0 ; i<mid ; i++){
                left[i] = arr[i];
            }
            for(int i= mid ; i<n; i++){
                right[i-mid] = arr[i];
            }
            mergeSort(left,mid);
            mergeSort(right,n-mid);
            merging(arr,n,left,mid,right,n-mid);
        }
    } 
  //MAIN FUNCTION
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[i+m] = nums2[i];
        }
        mergeSort(nums1,m+n);       
    }
}
