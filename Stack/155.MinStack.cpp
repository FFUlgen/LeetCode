#include <limits>
#include <algorithm>

/*
155. Min Stack - Explanation

    Description
        Design a stack class that supports the push, pop, top, and getMin operations.

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    Each function should run in O(1) time.

    Example 1:

        Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

        Output: [null,null,null,null,0,null,2,1]

    Explanation:
        MinStack minStack = new MinStack();
        minStack.push(1);
        minStack.push(2);
        minStack.push(0);
        minStack.getMin(); // return 0
        minStack.pop();
        minStack.top();    // return 2
        minStack.getMin(); // return 

    Constraints:

        -2^31 <= val <= 2^31 - 1.
        pop, top and getMin will always be called on non-empty stacks.
*/

// Without using std::stack : Time Complexity O(1) Space Complexity O(n)
class MinStack {
public:
    MinStack() {

        mainData = new int[capacity];
        minData = new int[capacity];
    }

    void push(int val) {
        if (topIndex + 1 == capacity)
        {
            capacity *= 2;
            int* newData = new int[capacity];
            int* newMinData = new int[capacity];

            for (int i = 0; i <= topIndex; i++)
            {
                newData[i] = mainData[i];
                newMinData[i] = minData[i];
            }

            delete[] mainData;
            delete[] minData;

            mainData = newData;
            minData = newMinData;
        }

        topIndex++;
        mainData[topIndex] = val;
        if (topIndex == 0)
        {
            minData[topIndex] = val;
        }
        else
        {
            minData[topIndex] = std::min(val, minData[topIndex - 1]);
        }
    }

    void pop() {
        if (topIndex >= 0)
        {
            topIndex--;
        }
    }

    int top() {
        return mainData[topIndex];
    }

    int getMin() {
        return minData[topIndex]; 
    }

private:
    int* mainData = nullptr;
    int* minData = nullptr;
    int capacity = 10;
    int topIndex = -1; // stack empty if this is -1

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */