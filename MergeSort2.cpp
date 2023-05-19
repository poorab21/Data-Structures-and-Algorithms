#include<iostream>
void Merge(int *arr,int left,int middle,int right)
{
    int i=left,j=middle+1,k=left;
    int temp[20];
    while(i<=middle && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            k++,i++;
        }
        else
        {
            temp[k]=arr[j];
            k++,j++;
        }
    }
    while(i<=middle)
    {
        temp[k]=arr[i];
        i++,k++;
    }
    while(j<=right)
    {
        temp[k]=arr[j];
        j++,k++;
    }
    for(int counter=left;counter<=right;counter++)
    {
        arr[counter]=temp[counter];
    }
}
void MergeSort(int *arr,int left,int right)
{
    if(left<right)
    {
        int middle=(left+right)/2;
        MergeSort(arr,left,middle);
        MergeSort(arr,middle+1,right);
        Merge(arr,left,middle,right);
    }
    else
    {
        return;
    }
}
int main()
{
    int arr[100],size;
    std::cout<<"Enter Size:";
    std::cin>>size;
    for(int i=0;i<size;i++)
    {
        std::cout<<"Enter Element:";
        std::cin>>arr[i];
    }
    MergeSort(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<"\n";
    }
}
