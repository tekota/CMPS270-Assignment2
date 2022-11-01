#include <iostream>
#include <vector>

using namespace std;

template<class T> class Stack;
// overloads the + operator to add two stacks
// requires: two stacks
// effects: returns a new stack with the elements of the two stacks
template <typename T>
Stack<T> operator+(Stack<T>& s1, Stack<T>& s2) {
    Stack<T> s3;
    for (int i = 0; i < s1.stack.size(); i++) {
        s3.stack.push_back(s1.stack[i]);
    }
    for (int i = 0; i < s2.stack.size(); i++) {
        s3.stack.push_back(s2.stack[i]);
    }
    return s3;
}

// Stack class
template <typename T>
class Stack 
{
    friend Stack<T> operator+<>(Stack<T>& s1, Stack<T>& s2);
    vector<T> stack;     // stack using vector
    
    public:

        // push an element onto the stack
        // requires: a value T 
        // effects: adds the value to the top of the stack
        void push(T value) { stack.push_back(value); } 


        // pop an element off the stack
        // requires: nothing
        // effects: removes the value from the top of the stack and returns it
        T pop() { T value = stack.back(); stack.pop_back(); return value; }


        // get the top element of the stack
        // requires: nothing
        // effects: returns a reference to the top of the stack
        T top() { return stack.back(); }

        // checks if the stack is empty
        // requires: nothing
        // effects: returns true if the stack is empty, false otherwise
        bool empty() { return stack.empty(); }
        
        
};





int main(){

    // Int Stack
    Stack<int> s1;
    Stack<int> s2;
    Stack<int> s3;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(4);
    s2.push(5);
    s2.push(6);
    if (s3.empty()) cout << "s3 is empty" << endl;
    s3 = s1 + s2;
    // Should return 
    // 6
    // 5
    // 4
    // 3
    // 2
    // 1
    cout << "Firt element in the stack s3 is " << s3.top() << endl;
    cout << s3.pop() << endl;
    cout << s3.pop() << endl;
    cout << s3.pop() << endl;
    cout << s3.pop() << endl;
    cout << s3.pop() << endl;
    cout << s3.pop() << endl;

    cout <<  "----------------" << endl;
    
    //Char Stack
    Stack<char> s4;
    Stack<char> s5;
    Stack<char> s6;
    s4.push('a');
    s4.push('b');
    s4.push('c');
    s5.push('d');
    s5.push('e');
    s5.push('f');
    if (s6.empty()) cout << "s6 is empty" << endl;
    s6 = s4 + s5;

    // Should return
    // f
    // e
    // d
    // c
    // b
    // a
    cout << "Firt element in the stack s6 is " << s6.top() << endl;
    cout << s6.pop() << endl; 
    cout << s6.pop() << endl;
    cout << s6.pop() << endl;
    cout << s6.pop() << endl;
    cout << s6.pop() << endl;
    cout << s6.pop() << endl;

    return 0;

}