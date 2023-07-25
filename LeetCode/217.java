// Given an integer array nums, return true if any 
// value appears at least twice in the array, and return false if every element is distinct.

class Solution {
    public static void merge(int[] arr, int n, int left[], int l, int[] right, int r){
        int i=0,j=0,k=0;
        while(i<l && j<r){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
            }
            else if(left[i] > right[j]){
                arr[k] = right[j];
                j++;
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
            j++;
            k++;
        }
    }

    public static void mergeSort(int[] arr, int n){
        if(n>1){
        int mid = n/2;
        int left[] = new int[mid];
        int right[] = new int[n-mid];

        for(int i=0; i<mid; i++){
            left[i] = arr[i];
        }
        for(int i=mid ; i<n; i++){
            right[i-mid] = arr[i];
        }
        mergeSort(left,mid);
        mergeSort(right,n-mid);
        merge(arr,n,left,mid,right,n-mid);
        }
    }
    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;
        mergeSort(nums,n);
        for(int i=1 ; i<n; i++){
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
}