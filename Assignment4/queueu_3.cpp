#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q) {
    if (q.size() % 2 != 0) {
      cout << "Queue should be even en lenghth";
      return;
    }
    int n = q.size();
    stack<int>s;
    int halfSize = n/2;
    
    // Puh first half of queue to stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Enqueue back from stack (this reverses the first half)
    while (!s.empty()) {
      q.push(s.top());
       s.pop();
    }
    
    // Dequeue and enqueue first half again
    for (int i = 0; i < halfSize; i++) {
      q.push(q.front());
       q.pop();
    }
    
    // Push first half to stack again
    for (int i = 0; i < halfSize; i++) {
      s.push(q.front());
       q.pop();
    }
    
    // Interleave one from stack one from queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    
    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    
    interleaveQueue(q);
    
    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}