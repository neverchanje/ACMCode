#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string gg, ap;

int main() {
    // aab  aab
    // aaa aaa
    cin >> gg >> ap;

    int count = 0;
    for (int i = 0; i < gg.length(); i++) {
        bool match = true;

        if (i + ap.length() > gg.length()) {
            match = false;
            break;
        }

        if (gg.compare(i, ap.length(), ap) != 0) {
            match = false;
        }

        if (match == true) {
            count++;
            i += ap.length() - 1;
        }
    }
    cout << count << endl;
}
