import java.util.Arrays;
import java.util.Random;

public class QuickSort {
    public static void main(String[] args) {
        Random r = new Random();
        int[] arr =new int[100000] ;
        for(int i = 0;i<arr.length-1;i++){
            arr[i]  =r.nextInt() ;
        }
        long start = System.nanoTime();
        quicksort(arr , 0,arr.length-1);
        System.out.println(Arrays.toString(arr));


        long end = System.nanoTime();
        long elapsedTime = end - start;
        System.out.println("The time required in nanoseconds is: "+elapsedTime);
    }
    public static void quicksort(int[] arr, int low , int high){
        if(low<high){
        int pvt = partition(arr,low,high);
        quicksort(arr , low ,pvt-1);
        quicksort(arr , pvt+1, high);
        }
    }
public static int partition(int[] nums, int low, int high){
        int i = low;
        int j = high;
        int pivot = nums[low];

        while(j>i){
            while(nums[i]<=pivot){
                i++;
            }
            while(nums[j]>pivot){
                j--;
            }
            if(i<j){
                int temp = nums[i];
                nums[i]  =nums[j];
                nums[j] = temp;
            }

        }
    int temp = nums[j];
    nums[j] = pivot;
    pivot = temp;
    return j;
    }
}
