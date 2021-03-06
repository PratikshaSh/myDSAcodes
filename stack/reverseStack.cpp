// C++ code to reverse a
// stack using recursion
#include<bits/stdc++.h>
using namespace std;




string ns;


void insert_at_bottom(stack<char> &st,char x)
{
    if(st.empty()){
        st.push(x);
        return;
    }
    int data = st.top();
    st.pop();
    insert_at_bottom(st, x);
    st.push(data);
   
}


void reverse(stack<char> &st)
{
    if(st.empty()){
        return;
    }

    char x = st.top();
    st.pop(); 
    reverse(st);
    insert_at_bottom(st,x);

	
}

// Driver Code
int main()
{
	stack<char> st;
	// push elements into
	// the stack
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	
	cout<<"Original Stack"<<endl;
	
	// print the elements
	// of original stack
	cout<<"1"<<" "<<"2"<<" "
		<<"3"<<" "<<"4"
		<<endl;
	
	// function to reverse
	// the stack
	reverse(st);
	cout<<"Reversed Stack"
		<<endl;
	
	// storing values of reversed
	// stack into a string for display
	while(!st.empty())
	{
		char p=st.top();
		st.pop();
		ns+=p;
	}
	
	//display of reversed stack
	cout<<ns[3]<<" "<<ns[2]<<" "
		<<ns[1]<<" "<<ns[0]<<endl;
	return 0;
}

// This code is contributed by Gautam Singh
