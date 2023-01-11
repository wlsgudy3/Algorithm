#include <iostream>

using namespace std;

int A, B, C, ret = 0, n;
int num[100] = {0};

struct Truck {
    int in;
    int out;
};

int main() {
    cin >> A >> B >> C;
    Truck a[3];

    for (int i = 0; i < 3; i++) {
        cin >> a[i].in >> a[i].out;
        num[a[i].in] += 1;
        num[a[i].out] += -1;
    }

    n = 0;
    for (int i = 0; i < 100; i++) {
        n += num[i];
        if(n == 1){
            ret += n * A;
        }
        if(n == 2){
            ret += n * B;
        }
        if(n == 3){
            ret += n * C;
        }
    }

    cout << ret;

    
}