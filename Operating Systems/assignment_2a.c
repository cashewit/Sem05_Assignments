#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
        arr[i] = i+1;

    int pid = fork();

    if(pid == 0) {
        printf("Executing Child Process with ID: %d", getpid());

        quickSort(arr, 0, n-1);

        printf("After Sorting: \n");
        for(int i=0; i<n; i++)
            printf("%d ",arr[i]);

        printf("\n");

    } else {
        printf("Executing Parent Process with ID: %d", getpid());

        mergeSort(arr, 0, n-1);

        printf("After Sorting: \n");
        for(int i=0; i<n; i++)
            printf("%d ",arr[i]);

        printf("\n");
    }
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot);
        quickSort(arr, pivot+1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++) {
        if(arr[j] < high){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int n = mid - low + 1;
    int m = high - low;

    int left[n], right[m];

    for(int i=0; i<n; i++)
        left[i] = arr[low + i];
    for(int i=0; i<m; i++)
        right[i] = arr[mid + i + 1];

    int i=0, j=0, k=low;

    while(i<n && j<m){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n){
        arr[k] = left[i];
        i++; k++;
    }

    while(j < m){
        arr[k] = right[j];
        j++; k++;
    }
}