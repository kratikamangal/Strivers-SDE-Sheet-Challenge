// // Question --->Min stack
// #include <bits/stdc++.h>
// // Implement class for minStack.
// class minStack
// {
//     // Write your code here.
//     stack<long long> st;
//     long long mini;

// public:
//     // Constructor
//     minStack()
//     {
//         // Write your code here.
//         // while(!st.empty())st.pop();
//         mini = INT_MAX;
//     }

//     // Function to add another element equal to num at the top of stack.
//     void push(int value)
//     {
//         // Write your code here.
//         long long val = (long long)value;
//         if (st.empty())
//         {
//             st.push(val);
//             mini = val;
//         }
//         else
//         {
//             if (mini < val)
//             {
//                 st.push(val);
//             }
//             else
//             {
//                 st.push(2 * val * 1LL - mini);
//                 mini = val;
//             }
//         }
//     }

//     // Function to remove the top element of the stack.
//     int pop()
//     {
//         if (st.empty())
//             return -1;
//         long long x = mini;
//         if (mini > st.top())
//         {
//             mini = 2 * mini - st.top();
//             st.pop();
//         }
//         else
//         {
//             x = st.top();
//             st.pop();
//         }
//         if (st.empty())
//             mini = INT_MAX;
//         return (int)x;
//     }

//     // Function to return the top element of stack if it is present. Otherwise return -1.
//     int top()
//     {
//         // Write your code here.
//         if (st.empty())
//             return -1;

//         long long e = st.top();
//         if (mini > e)
//             return (int)mini;
//         else
//             return (int)e;
//     }

//     // Function to return minimum element of stack if it is present. Otherwise return -1.
//     int getMin()
//     {
//         // Write your code here.
//         if (mini == INT_MAX)
//             return -1;
//         return (int)mini;
//     }
// };

// Question-- > Reverse words in a string
//                  stringstream str(s);
// string word;
// stack<string> st;
// while (str >> word)
// {
//     st.push(word);
// }
// string ans = "";
// while (!st.empty())
// {
//     ans += st.top();
//     st.pop();
//     if (!st.empty())
//         ans += " ";
// }
// return ans;
// }

// Question--->roman to int #include<bits / stdc++.h> int romanToInt(string s)
// {
//     // Write your code here
//     int ans = 0;
//     int n = s.size();
//     stack<char> st;
//     for (int i = 0; i < n; i++)
//     {
//         st.push(s[i]);
//     }
//     while (!st.empty())
//     {
//         char x = st.top();
//         st.pop();
//         if (x == 'M')
//         {
//             if (!st.empty() && st.top() == 'C')
//             {
//                 ans += 900;
//                 st.pop();
//             }
//             else
//                 ans += 1000;
//         }
//         else if (x == 'D')
//         {
//             if (!st.empty() && st.top() == 'C')
//             {
//                 ans += 400;
//                 st.pop();
//             }
//             else
//                 ans += 500;
//         }
//         else if (x == 'L')
//         {
//             if (!st.empty() && st.top() == 'X')
//             {
//                 ans += 40;
//                 st.pop();
//             }
//             else
//                 ans += 50;
//         }
//         else if (x == 'C')
//         {
//             if (!st.empty() && st.top() == 'X')
//             {
//                 ans += 90;
//                 st.pop();
//             }
//             else
//                 ans += 100;
//         }
//         else if (x == 'V')
//         {
//             if (!st.empty() && st.top() == 'I')
//             {
//                 ans += 4;
//                 st.pop();
//             }
//             else
//                 ans += 5;
//         }
//         else if (x == 'X')
//         {
//             if (!st.empty() && st.top() == 'I')
//             {
//                 ans += 9;
//                 st.pop();
//             }
//             else
//                 ans += 10;
//         }
//         else if (x == 'I')
//         {
//             int x = 1;
//             while (!st.empty() && st.top() == 'I')
//             {
//                 x++;
//                 st.pop();
//             }
//             ans += x;
//         }
//     }
//     return ans;
// }

// // Question -->implement atoi function
// #include <bits/stdc++.h>
// int atoi(string s)
// {
//     // Write your code here.
//     long long ans = 0;
//     int n = s.size();
//     int i = 0;
//     for (i = 0; i < n; i++)
//     {
//         if (s[i] != ' ')
//             break;
//     }
//     int x = 1;
//     if (s[i] == '-')
//     {
//         x = -1;
//         i++;
//     }
//     else if (s[i] == '+')
//     {
//         x = 1;
//         i++;
//     }
//     for (; i < n; i++)
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//         {
//             ans = ans * 10 + (s[i] - 48);
//         }
//         if (x == -1 && (-1) * ans < INT_MIN)
//             return INT_MIN;
//         else if (x == 1 && ans > INT_MAX - 1)
//             return INT_MAX;
//     }
//     return (ans * (x));
// }

// Question-- > longest common prefix
// #include <bits/stdc++.h>
//                  string
//                  longestCommonPrefix(vector<string> &arr, int n)
// {
//     // Write your code here
//     sort(arr.begin(), arr.end());
//     string s1 = arr[0];
//     string sN = arr[arr.size() - 1];
//     string ans = "";
//     for (int i = 0; i < s1.size(); i++)
//     {
//         if (s1[0] != sN[0])
//             return "";
//         if (s1[i] == sN[i])
//             ans += s1[i];
//         else
//             break;
//     }
//     return ans;
// }

// Question-- > check permutation
// #include <bits/stdc++.h>
//     bool
//     areAnagram(string &s, string &t)
// {
//     // Write your code here.
//     if (s.size() != t.size())
//         return false;
//     int freq[26] = {0};
//     int freq1[26] = {0};
//     for (int i = 0; i < s.size(); i++)
//     {
//         freq[s[i] - 'a']++;
//     }
//     for (int j = 0; j < t.size(); j++)
//     {
//         freq1[t[j] - 'a']++;
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         if (freq[i] != freq1[i])
//             return false;
//     }
//     return true;
// }

// // Compare numbers
// #include <bits/stdc++.h>
// int compareVersions(string version1, string version2)
// {
//     int n = version1.length();
//     int m = version2.length();
//     int i = 0, j = 0;
//     long long n1, n2;
//     while (i < n || j < m)
//     {
//         n1 = n2 = 0;
//         while (version1[i] != '.' && i < n)
//         {
//             n1 = n1 * 10 + (version1[i] - '0');
//             i++;
//         }
//         while (version2[j] != '.' && j < m)
//         {
//             n2 = n2 * 10 + (version2[j] - '0');
//             j++;
//         }
//         if (n1 > n2)
//             return 1;
//         else if (n1 < n2)
//             return -1;
//         if (i < n)
//             i++;
//         if (j < m)
//             j++;
//     }
//     return 0;
// }
