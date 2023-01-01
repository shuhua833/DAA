#include <iostream>

using namespace std;

int A[100];  // assume A is an array of integers of size 100
class minimax{
public:
  int n;
  void call(){

  cout << "Enter the number of elements: ";
  cin >> n;
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int min, max;
  MinMax(0, n - 1, min, max);
  cout << "Minimum: " << min << endl;
  cout << "Maximum: " << max << endl;
    }
void MinMax(int l, int r, int &min, int &max) {
  if (l == r) {
    min = max = A[l];
  }
  else if (l == r - 1) {
    if (A[l] < A[r]) {
      min = A[l];
      max = A[r];
    }
    else {
      min = A[r];
      max = A[l];
    }
  }
  else {
    int mid = (l + r) / 2;
    int min1, max1;
    MinMax(l, mid, min, max);
    MinMax(mid + 1, r, min1, max1);
    if (max1 > max) max = max1;
    if (min1 < min) min = min1;
  }
}
};
int main() {
  // read values for the array A from the user
minimax obj;
obj.call();
  return 0;
}
