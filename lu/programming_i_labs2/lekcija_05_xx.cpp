#include <iostream>
    using namespace std;

    int main() {
        int * m, n;
        cin >> n;
        m = new int[n];
        for (int i=0;i<n;i++) cin >> m[i];
        for (int i=n-1;i>=0;i--) cout << m[i] << endl;
        delete [] m;
        system("pause");
        return 0;
    }
