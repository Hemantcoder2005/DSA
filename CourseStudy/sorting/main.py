

sortings=["BubbleSort",'SelectionSort','InsertionSort','MergeSort','QuickSort','Random QuickSort','CountSort','RadixSort','BucketSort']

file_extension=".cpp"
for file in range(len(sortings)):
    file=open(f'{file+1}.'+sortings[file]+file_extension,'w')
    file.write('''#include<iostream>\n
using namespace std;\n
\n
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){\n
\t int size=5;
\t int arr[size]={5,4,3,2,1};\n
\t cout<<"before Sorting : ";
\t print(arr,size);

\t cout<<"before Sorting : ";
\t print(arr,size);   
        
    
               
                

}

''')
    file.close()
    