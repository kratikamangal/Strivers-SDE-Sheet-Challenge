// //Question --->Stack implementation
// #include <bits/stdc++.h>
// // Stack class.
// class Stack {
//     stack<int>st;
//     int size=0;
// public:

//     Stack(int capacity) {
//         size=capacity;
//     }

//     void push(int num) {
//         if(st.size()!=size)
//         st.push(num);
//     }

//     int pop() {
//         if(st.empty())
//         return -1;
//         int x=st.top();
//         st.pop();
//         return x;
//     }

//     int top() {
//          if(st.empty())
//         return -1;
//         return st.top();
//     }

//     int isEmpty() {
//         return st.empty()?true:false;
//     }

//     int isFull() {
//         if(st.size()==size)
//         return 1;
//         return 0;
//     }

// };

// Question --->implement a queueu
#include <bits/stdc++.h>
class Queue
{
    queue<int> q;

public:
    Queue()
    {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return q.empty() ? true : false;
    }

    void enqueue(int data)
    {
        q.push(data);
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (q.empty())
            return -1;
        int x = q.front();
        q.pop();
        return x;
    }

    int front()
    {
        // Implement the front() function
        if (q.empty())
            return -1;
        return q.front();
    }
};

Question--->Stack using a Queue
#include <bits/stdc++.h>
    class Stack
{
    // Define the data members.
    queue<int> q;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return q.empty() ? true : false;
    }

    void push(int x)
    {
        // Implement the push() function.
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (!q.empty())
        {
            int x = q.front();
            q.pop();
            return x;
        }
        else
            return -1;
    }

    int top()
    {
        if (!q.empty())
            return q.front();
        return -1;
    }
};

Question--->Queue using stack
#include <bits/stdc++.h>
    class Queue
{
    // Define the data members(if any) here.
    stack<int> input, output;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        input.push(val);
    }

    int deQueue()
    {
        int x = -1;
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (!output.empty())
        {
            x = output.top();
            output.pop();
        }
        return x;
    }

    int peek()
    {
        int x = -1;
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (!output.empty())
        {
            x = output.top();
            //  output.pop();
        }
        return x;
    }

    bool isEmpty()
    {
        if (output.empty() && input.empty())
            return true;
        return 0;
    }
};

Question--->Valid Parenthisis bool isValidParenthesis(string x)
{
    int i = 0;
    stack<char> st;
    while (x[i] != '\0')
    {
        if (x[i] == '{' || x[i] == '(' || x[i] == '[')
            st.push(x[i]);
        else
        {
            if (!st.empty() && (abs(st.top() - x[i]) == 2 || abs(st.top() - x[i]) == 1))
                st.pop();
            else
                return 0;
        }
        i++;
    }
    if (st.empty())
        return true;
    return 0;
}

Question--->Next greater element
#include <bits/stdc++.h>

    vector<int>
    nextGreater(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

Question-- > sort a stack
#include <bits/stdc++.h>
    void
    insert(stack<int> &st, int temp)
{
    if (st.empty() || st.top() <= temp)
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
    return;
}
void sortStack(stack<int> &s)
{
    if (s.empty())
        return;
    else if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insert(s, temp);
    return;
}