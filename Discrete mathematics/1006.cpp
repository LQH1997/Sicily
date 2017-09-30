//1006
#include<iostream>
using namespace std;
int main() {
    int n, element, num, find, a[100][2];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num;
    cin >> element;
    for (int i = 0; i < element; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < element; i++) {
        if (a[i][0] != a[i][1]) {
            for (int j = 0; j < element; j++) {
                if (a[j][0] != a[j][1] && a[i][1] == a[j][0]) {
                    find = 0;
                    for (int k = 0; k < element; k++) {
                        if (a[k][0] == a[i][0] && a[k][1] == a[j][1]) {
                            find = 1;
                            break;
                        }
                    }
                    if (!find) {
                        cout << "0\n";
                        return 0;
                    }
                }
            }
            
        }
    }
    cout << "1\n";
    return 0;
}         
