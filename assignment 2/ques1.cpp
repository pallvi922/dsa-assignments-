#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in sorted order: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int left = 0, right = n - 1;
    int found = 0;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == key) {
            found = 1;
            cout << "Element found at position " << mid + 1 << endl;
            break;
        } else if(arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if(!found)
        cout << "Element not found" << endl;

    return 0;
}
