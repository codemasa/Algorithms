#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

// Not memoized
int LCSLength(string s1, string s2, int n, int m){
  // Empty string meaning LCS is 0;
  if(n == 0 || m == 0){
    return 0;
  }
  if(s1[n-1] == s2[m-1]){
    return LCSLength(s1, s2, n-1, m-1)+1;
  }
  return max(LCSLength(s1, s2, n, m-1), LCSLength(s1, s2, n-1, m));
}

// Memoized
int LCSLengthMemoTD(string s1, string s2, int n, int m, unordered_map<string, int> &lookup){
  // Empty string meaning LCS is 0;
  if(n == 0 || m == 0){
    return 0;
  }
  string key = to_string(n) + "|" + to_string(m);

  if(lookup.find(key) == lookup.end()){

    if(s1[n-1] == s2[m-1]){
      lookup[key] = LCSLengthMemoTD(s1, s2, n-1, m-1, lookup) + 1;
    }
    else {
      max(LCSLengthMemoTD(s1, s2, n, m-1, lookup), LCSLengthMemoTD(s1, s2, n-1, m, lookup));
    }

  }

  return lookup[key];
}

int LCSLengthMemoBU(string s1, string s2){
  // Empty string meaning LCS is 0;
  if(n == 0 || m == 0){
    return 0;
  }
  string key = to_string(n) + "|" + to_string(m);

  if(lookup.find(key) == lookup.end()){

    if(s1[n-1] == s2[m-1]){
      lookup[key] = LCSLengthMemoTD(s1, s2, n-1, m-1, lookup) + 1;
    }
    else {
      max(LCSLengthMemoTD(s1, s2, n, m-1, lookup), LCSLengthMemoTD(s1, s2, n-1, m, lookup));
    }

  }

  return lookup[key];
}


int main(int argc, char *argv[]){

  string s1 = "ABCBDAB", s2 = "BDCABA";
  unordered_map<string, int> lookup;

  cout << "LCS of " << s1 << " and " << s2 << " is " << LCSLength(s1,s2,s1.length(),s2.length()) << endl;

  cout << "Memoized LCS of " << s1 << " and " << s2 << " is " << LCSLength(s1,s2,s1.length(),s2.length()) << endl;

}
