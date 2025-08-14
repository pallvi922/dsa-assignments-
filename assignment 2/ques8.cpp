#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Size of array: ";
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int dup = 0;
        for(int j = 0; j < i; j++) {
            if(a[i] == a[j]) {
                dup = 1;
                break;
            }
        }
        if(dup == 0)
            cnt++;
    }

    cout << "Number of distinct elements: " << cnt << endl;

    return 0;
}
