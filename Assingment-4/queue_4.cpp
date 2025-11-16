#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    queue<char> q;
    int freq[26] = {0};

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;

        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}
