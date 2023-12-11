#include<iostream>
#include<stack>
using namespace std;
stack<char> st1;
string input = "aaabbb";

bool shift() {
    if (input.size() > 0) {
        st1.push(input[0]);
        input = input.substr(1);
        return true;
    }
    return false;
}

bool reduce() {
    // Check if there are at least two characters on the stack and the top two are 'a' and 'b'
    if (st1.size() >= 2 && st1.top() == 'b') {
        st1.pop(); // pop 'b'
        if (st1.top() == 'a') {
            st1.pop(); // pop 'a'
            st1.push('A'); // push 'A'
            return true;
        }
    }
    if (st1.size() >= 2 && st1.top() == 'A') {
        st1.pop(); // pop 'b'
        if (st1.top() == 'a') {
            st1.pop(); // pop 'a'
            st1.push('A'); // push 'A'
            return true;
        }
    }
    if (st1.size() >= 2 && st1.top() == 'A') {
        st1.pop(); // pop 'b'
        if (st1.top() == 'b') {
            st1.pop(); // pop 'a'
            st1.push('A'); // push 'A'
            return true;
        }
    }
    if (st1.size() >= 2 && st1.top() == 'b') {
        st1.pop(); // pop 'b'
        if (st1.top() == 'A') {
            st1.pop(); // pop 'a'
            st1.push('A'); // push 'A'
            return true;
        }
    }
    return false;
}


bool parse() {
    while (!input.empty()) {
        if (reduce()) {
            continue; 
        }
        if (!shift()) {
            cout << "Parsing failed .\n";
            return false;
        }
    }
    while (reduce()) {} 
    return st1.size() == 1 && st1.top() == 'S';
}

int main() {
    if (parse()) {
        cout << "Parsing succeeded.\n";
    } else {
        cout << "Parsing failed.\n";
    }

    return 0;
}
