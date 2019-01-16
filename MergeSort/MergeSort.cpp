#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2){
  int arr1Size = arr1.size();
  int arr2Size = arr2.size();
  int n = arr1Size + arr2Size;
  vector<int> result(n);
  int arr1Index = 0;
  int arr2Index = 0;
  int loopIter = 0;

  while(arr1Index < arr1Size && arr2Index < arr2Size){
    int arr1Current = arr1[arr1Index];
    int arr2Current = arr2[arr2Index];

    if(arr1Current <= arr2Current){
      result[loopIter] = arr1[arr1Index];
      arr1Index++;
    }else{
      result[loopIter] = arr2[arr2Index];
      arr2Index++;
    }
    loopIter++;
  }

  while(arr1Index < arr1Size){
    result[loopIter] = arr1[arr1Index];
    arr1Index++;
    loopIter++;
  }

  while(arr2Index < arr2Size){
    result[loopIter] = arr2[arr2Index];
    arr2Index++;
    loopIter++;
  }
  return result;
}


vector<int> mergeSortTD(vector<int> arr){
  if(arr.size() <= 1){
    return arr;
  }
  int middle = arr.size() / 2;
  vector<int> arr1(middle);
  vector<int> arr2(arr.size()-middle);
  for(int i=0 ; i<middle ; i++ ){
    arr1[i] = arr[i];
  }
  for(int i=0 ; i<arr.size()-middle ; i++ ){
    arr2[i] = arr[i+middle];
  }
  arr1 = mergeSortTD(arr1);
  arr2 = mergeSortTD(arr2);
  return merge(arr1, arr2);

}
void mergeSortBU(vector<int> arr1, vector<int> arr2){

}



int main(int argc, char const *argv[]) {
  vector<int> arr{53, 49, 41, 95, 44, 8, 20, 45, 46, 52, 9, 69, 91, 63, 94, 30, 73, 70, 97, 18, 13, 14, 66, 83, 19, 77, 2, 43, 21, 86, 17, 1, 15, 88, 96, 38, 11, 50, 80, 28, 48, 23, 24, 98, 71, 65, 35, 16, 82, 100, 84, 85, 36, 55, 27, 26, 78, 89, 58, 10, 64, 4, 32, 68, 31, 3, 67, 75, 6, 5, 92, 56, 79, 57, 33, 40, 51, 25, 37, 7, 47, 59, 93, 62, 54, 99, 22, 42, 60, 29, 72, 61, 81, 39, 74, 90, 34, 87, 12, 76};
  vector<int> sorted = mergeSortTD(arr);
  cout << endl;
  cout << "sorted array: " << endl;
  for (int i=0 ; i < arr.size() ; i++ ){
    cout << sorted[i] << " ";
  }
  cout << endl << endl;
  return 0;
}
