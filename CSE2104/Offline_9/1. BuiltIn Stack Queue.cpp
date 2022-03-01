//#include <stack>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<endl<<"---------Stack---------"<<endl;

    stack<int> st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);

    cout << st.top() <<endl;
    printf("%d\n", st.top());

    while(!st.empty())
    {
        cout << st.top() <<" ";
        st.pop();
    }
    cout<<endl<<"---------QUEUE---------"<<endl;

    queue<int> qu;
    qu.push(5);
    qu.push(6);
    qu.push(7);
    qu.push(8);
    qu.push(9);
    qu.push(10);

    cout << qu.front() <<endl;
    printf("%d\n", qu.front());

    while(!qu.empty())
    {
        cout << qu.front() <<" ";
        qu.pop();
    }

    return 0;
}
