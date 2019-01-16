#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> arr){
  int n = arr.size();
  bool swapped = false;
  int efficiency=0;
  for (int j=0 ; j < arr.size() ; j++ ){
    for ( int i=1 ; i<n ; i++ ){
      if(arr[i-1] > arr[i]){
        int temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
        swapped = true;

      }
      ++efficiency;
    }
  }
  cout << "efficiency: " << efficiency << endl;
  return arr;
}

vector<int> bubbleSortOpt1(vector<int> arr){
  int n = arr.size();
  bool swapped = false;
  int efficiency=0;
  for (int j=0 ; j < arr.size() ; j++ ){
    for ( int i=1 ; i<n ; i++ ){
      if(arr[i-1] > arr[i]){
        int temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
        swapped = true;

      }
      ++efficiency;

    }
    --n;
  }
  cout << "efficiency: " << efficiency << endl;
  return arr;
}

vector<int> bubbleSortOpt2(vector<int> arr){
  int n = arr.size();
  bool swapped = false;
  int efficiency=0;
  while(n > 1){
    int newn = 0;
    for ( int i=1 ; i<n ; ++i ){
      if(arr[i-1] > arr[i]){
        int temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
        newn = i;

      }
      ++efficiency;

    }
    n = newn;
  }
  cout << "efficiency: " << efficiency << endl;
  return arr;
}

int main(int argc, char const *argv[]) {
  vector<int> arr{53, 49, 41, 95, 44, 8, 20, 45, 46, 52, 9, 69, 91, 63, 94, 30, 73, 70, 97, 18, 13, 14, 66, 83, 19, 77, 2, 43, 21, 86, 17, 1, 15, 88, 96, 38, 11, 50, 80, 28, 48, 23, 24, 98, 71, 65, 35, 16, 82, 100, 84, 85, 36, 55, 27, 26, 78, 89, 58, 10, 64, 4, 32, 68, 31, 3, 67, 75, 6, 5, 92, 56, 79, 57, 33, 40, 51, 25, 37, 7, 47, 59, 93, 62, 54, 99, 22, 42, 60, 29, 72, 61, 81, 39, 74, 90, 34, 87, 12, 76};
  vector<int> arrOpt1{53, 49, 41, 95, 44, 8, 20, 45, 46, 52, 9, 69, 91, 63, 94, 30, 73, 70, 97, 18, 13, 14, 66, 83, 19, 77, 2, 43, 21, 86, 17, 1, 15, 88, 96, 38, 11, 50, 80, 28, 48, 23, 24, 98, 71, 65, 35, 16, 82, 100, 84, 85, 36, 55, 27, 26, 78, 89, 58, 10, 64, 4, 32, 68, 31, 3, 67, 75, 6, 5, 92, 56, 79, 57, 33, 40, 51, 25, 37, 7, 47, 59, 93, 62, 54, 99, 22, 42, 60, 29, 72, 61, 81, 39, 74, 90, 34, 87, 12, 76};
  vector<int> arrOpt2{53, 49, 41, 95, 44, 8, 20, 45, 46, 52, 9, 69, 91, 63, 94, 30, 73, 70, 97, 18, 13, 14, 66, 83, 19, 77, 2, 43, 21, 86, 17, 1, 15, 88, 96, 38, 11, 50, 80, 28, 48, 23, 24, 98, 71, 65, 35, 16, 82, 100, 84, 85, 36, 55, 27, 26, 78, 89, 58, 10, 64, 4, 32, 68, 31, 3, 67, 75, 6, 5, 92, 56, 79, 57, 33, 40, 51, 25, 37, 7, 47, 59, 93, 62, 54, 99, 22, 42, 60, 29, 72, 61, 81, 39, 74, 90, 34, 87, 12, 76};
  cout << "unsorted array: " << endl;
  for (int i=0 ; i < arr.size() ; i++ ){
    cout << arr[i] << " ";
  }
  cout << endl;
  vector<int> sorted = bubbleSort(arr);
  cout << "sorted array: " << endl;
  for (int i=0 ; i < arr.size() ; i++ ){
    cout << sorted[i] << " ";
  }
  cout << endl << endl;
  vector<int> sortedOpt1 = bubbleSortOpt1(arrOpt1);
  cout << "sorted Opt1 array: " << endl;

  for (int i=0 ; i < arr.size() ; i++ ){
    cout << sortedOpt1[i] << " ";
  }
  cout << endl << endl;
  vector<int> sortedOpt2 = bubbleSortOpt2(arrOpt2);
  cout << "sorted Opt2 array: " << endl;

  for (int i=0 ; i < arr.size() ; i++ ){
    cout << sortedOpt2[i] << " ";
  }
  cout << endl;
  return 0;
}
