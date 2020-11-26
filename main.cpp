#include <iostream>
using namespace std;
int k = 0, c = 0;
void q(int *a, int l, int r) {
    int t, x = l, y = r, m = (l + r) / 2;
    do {
        while (x != m && a[x] < a[m]) {
            k++;
            x++;
        }
        if (x != m) {
            k++;
        }
        while (y != m && a[y] > a[m]) {
            k++;
            y--;
        }
        if (y != m) {
            k++;
        }
        if (x <= y) {
            if (x != y) {
                t = a[x];
                a[x] = a[y];
                a[y] = t;
                c++;
                if (x == m) {
                    x++;
                }
                if (y == m) {
                    y--;
                }
            }
            x++;
            y--;
        }
    } while (x <= y);
    if (l < y) {
        q(a, l, y);
    }
    if (r > x) {
        q(a, x, r);
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    int *a, l = 0, r = n - 1;
    a = ( int *) malloc ((n) * sizeof ( int ));
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    q(a, l, r);
    cout << "Кол-во перестановок: " << c;
    cout << endl << "Кол-во сравнений: " << k;
}
