#include <iostream>
using namespace std;

void printMatrix(int a[][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrix(int m1[][2], int m2[][2], int ans[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void expoentialMatrix(int a[][2], int n, int result[][2]) {
    if (n == 0) {
        //returning identity matrix
        result[0][0] = 1;
        result[0][1] = 0;
        result[1][0] = 0;
        result[1][1] = 1;
        return;
    }

    if (n == 1) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = a[i][j];
            }
        }
        return;
    }

    int temp[2][2];
    expoentialMatrix(a, n / 2, temp);
    multiplyMatrix(temp, temp, result);
    if (n % 2 != 0) {
        int temp2[2][2];
        multiplyMatrix(result, a, temp2);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = temp2[i][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Creating basic matrix 2x2
    int a[2][2] = {{1, 1}, {1, 0}};
    int result[2][2];
    expoentialMatrix(a, n, result);

    cout << "Resultant matrix:" << endl;
    printMatrix(result, 2, 2);

    return 0;
}
