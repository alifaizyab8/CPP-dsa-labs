
#include <iostream>
using namespace std;

int factorialIterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int num = 4;
    cout << "Iterative Factorial of " << num << " is: " << factorialIterative(num) << endl;
    return 0;
}

#include <iostream>
using namespace std;

void towersOfHanoi(int n, char source, char aux, char dest) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }
    towersOfHanoi(n - 1, source, dest, aux);
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    towersOfHanoi(n - 1, aux, source, dest);
}

int main() {
    int disks = 3;
    towersOfHanoi(disks, 'A', 'B', 'C');
    return 0;
}