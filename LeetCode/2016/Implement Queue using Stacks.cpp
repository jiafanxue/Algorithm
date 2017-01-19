#include <iostream>
using namespace std;

class Queue {
	stack<int> input, output;
public:
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
    	peek();
    	output.pop();
    }

    // Get the front element.
    int peek(void) {
    	if(output.empty()) {
    		while(input.size()) {
    			output.push(input.out);
    			input.pop();
    		}
    	}
    	return output.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return  input.size() && output.size();
    }
};

int main()
{

	return 0;
}