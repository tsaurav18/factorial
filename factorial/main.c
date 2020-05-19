

//#include <time.h>
//clock_t clock(void);
//int factorial(int n);
//int  count =0;
//int main(void) {
//    clock_t start, finish;
//    double duration;
//    start = clock();
//    int n,result;
//    printf("enter a number: ");  //input a number
//    scanf("%d",&n);
//    result=factorial(n);  //function call
//    printf("factorial of the number is: %d\n", result );
//    finish = clock();
//    duration =(double)(finish-start)/CLOCKS_PER_SEC;
//    printf("%f 초입니다.\n함수후출회수: %d", duration, count);
//    return 0;
//}
//int factorial(int n){
//   int fact;
//    if(n==0 ||n==1 ){
//        return 1;
//        }
//    else{
//       count++;
//        fact = n*factorial(n-1);  //recursion
//
//        return fact;
//    }
//}

//
//
//#include <stdio.h>
//#include <time.h>
//clock_t clock(void);
// int factorial(int n);
//int count =0;
//int main(void) {
//    clock_t start, finish;
//    double duration;
//    start = clock();
//    int n;
//    printf("enter a number: ");  //input a number
//    scanf("%d",&n);
//    printf("factorial of the number is: %d\n", factorial(n));
//    finish = clock();
//    duration =(double)(finish-start)/CLOCKS_PER_SEC;
//    printf("%f 초입니다.\n함수후출회수: %d", duration, count);
//    return 0;
//}
// int factorial(int n){
//   int fact=1;
//    if(n==0 || n==1){
//        return 1;
//        }
//    else{
//        for(int i= 2 ; i<=n; i++){
//            fact  = fact *i;
//            count++;}
//    return fact;
//    }
//}
#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    // create temp arrays
    int Left[n1], Right[n2];
  
//Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        Left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[m + 1+ j];
  
    // Merge the temp arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
 
        }
        
        else
        {
            arr[k] = Right[j];
            j++;

        }
        k++;
        
    }
  
    //Copy the remaining elements of Left[] array
       
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
  
    ///Copy the remaining elements of Right[] array
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
  
/* left is for left index and right is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right)
{
       
    if (left < right)
        {
            int mid = left+(right -left)/2;
          
         // Same as (left+right)/2
        mergeSort(arr, left, mid);
          // Sort first halves
        mergeSort(arr, mid+1, right);//sort secong halves
            
        merge(arr, left, mid, right);  //conqure the array

    }
}
//print the arrays
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 22, 20};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
  
    printf("Given array is \n");
    printArray(arr, arr_size);
    
  
    mergeSort(arr, 0, arr_size - 1);
  
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
