
// Implement a last in first out(LIFO) stack using only two queues.The implemented stack should support all the functions of a normal
// queue(push, top, pop, and empty).

//     Implement the MyStack class :

//     void push(int x) Pushes element x to the top of the stack.int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.boolean empty() Returns true if the stack is empty,
//     false otherwise.Notes :

//     You must use only standard operations of a queue,
//     which means only push to back, peek / pop from front, size, and is empty operations are valid.Depending on your language, the queue
// may not be supported natively.You may simulate a queue using a list or deque(double - ended queue), as long as you use only a queue's
// standard operations.

// Testcases:
// ["MyStack","push","push","top","pop","empty"]
// [[],[1],[2],[],[],[]]
// ["MyStack","push","push","top","pop","top","empty"]
// [[],[1],[2],[],[],[],[]]
// ["MyStack","push","push","push","push","top","pop","top","empty"]
// [[],[1],[2],[3],[4],[],[],[],[]]
// ["MyStack","push","top","top","pop","empty"]
// [[],[1],[],[],[],[]]
// ["MyStack","push","pop","push","pop","empty"]
// [[],[1],[],[2],[],[]]
// ["MyStack","push","push","push","top","pop","push","pop","empty"]
// [[],[1],[2],[3],[],[],[2],[],[]]
// ["MyStack","push","push","top","pop","pop","empty"]
// [[],[1],[2],[],[],[],[]]

// Result:
// [null,null,null,2,2,false]
// [null,null,null,2,2,1,false]
// [null,null,null,null,null,4,4,3,false]
// [null,null,1,1,1,true]
// [null,null,1,null,2,true]
// [null,null,null,null,3,3,null,2,false]
// [null,null,null,2,2,1,true]

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
// Memory Usage: 6.9 MB, less than 57.78% of C++ online submissions for Implement Stack using Queues.
// Next challenges:

// https://leetcode.com/problems/implement-stack-using-queues/submissions/
class MyStack
{
    queue<int> q1{}, q2{};
    int topElem{0};

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        auto &tgt = (q1.empty()) ? q2 : q1;
        tgt.push(x);
        topElem = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        // If q1 is not empty move all elements to q2 except the last and vice versa
        auto &src = (q1.empty()) ? q2 : q1;
        auto &tgt = (q2.empty()) ? q1 : q2;

        auto n = src.size();

        // Latest element is at the back of the queue
        for (auto i = 0; i < (n - 1); ++i)
        {
            tgt.push(src.front());
            if (i == (n - 2))
            {
                topElem = src.front();
            }
            src.pop();
        }

        auto ret = src.front();
        src.pop();

        return ret;
    }

    /** Get the top element. */
    int top()
    {
        return topElem;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */