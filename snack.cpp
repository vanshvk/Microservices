#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000+7

int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;

    else

        // if last bit set add 1 else add 0
        return (n & 1) + countSetBits(n >> 1);
}


//int q=0;
void printPairs( int arr[], int n, int sum,int a1, int a2)
{
    std::vector<pair<int,int>> p;
    // Store counts of all elements in map m
    unordered_map<int, int> m;
    int qw=0;
    // Traverse through all elements
    for (int i = 0; i <= n; i++) {

        // Search if a pair can be formed with
        // arr[i].
        int rem = sum - arr[i];
        if (m.find(rem) != m.end()) {
            int count = m[rem];
            for (int j = 0; j < count; j++){
              p.push_back(make_pair(rem,arr[i]));
              p.push_back(make_pair(arr[i],rem));
              //q++;
              }
                // cout << "(" << rem << ", "
                //      << arr[i] << ")" << endl;
        }
        m[arr[i]]++;

    }
    if(!(sum&1))
      p.push_back(make_pair(sum/2,sum/2));
    for (size_t i = 0; i <p.size(); i++) {
      if(countSetBits(p[i].first)==a1 && countSetBits(p[i].second)==a2){
        std::cout << p[i].first <<" "<<p[i].second<< '\n';
        qw++;
      }

      //

    }
    std::cout << qw << '\n';
}

int main(int argc, char const *argv[]) {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
  //  vector<pair<int,int>>p;
    //std::cin >> n;
    int a[n],sum,x,y;
    std::cin >> x>>y;
    std::cin >> sum;
    int mim=min(x,y);
    int maxm=max({x,y,(sum-mim)});
    int a1=countSetBits(x);
    int a2=countSetBits(y);
    // std::cout << mim << '\n';
    // std::cout << maxm << '\n';

    for (size_t i = 1; i <=sum; i++) {
      a[i-1]=i;
    }
    printPairs(a,sum,sum,a1,a2);
  }

  return 0;
}
