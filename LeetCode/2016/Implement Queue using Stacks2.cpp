class Queue {
	stack<int> queue;
public:
    // Push element x to the back of queue.
    void push(int x) {
        push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp;
        int size = queue.size();
        while(size > 0) {
        	temp.push(queue.top());
        	queue.pop();
        	size--;
        }

        temp.pop();
        int tsize = temp.size();
        while(tsize > 0) {
        	queue.push(temp.top());
        	temp.pop();
        	tsize--;
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> temp;
        int size = queue.size();
        while(size > 0) {
        	temp.push(queue.top());
        	queue.pop();
        	size--;
        }

        int t = temp.pop();
        queue.push(t);
        int tsize = temp.size();
        while(tsize > 0) {
        	queue.push(temp.top());
        	temp.pop();
        	tsize--;
        }

        return t;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return  queue.size() == 0;
    }
};