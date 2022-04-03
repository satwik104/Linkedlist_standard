//For a given singly linked list of integers, find and return its length. Do it using an iterative method.
/*
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
Sample Output 1 :
7
Sample Input 2 :
2
10 76 39 -3 2 9 -23 9 -1
-1
Sample Output 2 :
8
0
*/
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		cout << length(head) << endl;
	}
	return 0;
}

//***********************************************CODE FOR THE PROBLEM*****************************//
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int length(Node *head)
{
    //we have head with us...so address of second node is in next of head
    //so Tail = head -> next
    //and last node will be the orignal tail
    //so it would have NULL in its next
    //hence count till (tail -> next != null)

    if(head == NULL)//if their is no list
        return 0;
    //if above code do not run then atleast their is one node
    Node *tail = head -> next;
    if(tail == NULL)//if head and tail are at same place
        return 1;
    //if the above if do not run then we are sure that their are atleast 2 nodes
    int count = 2;
        while(tail -> next != NULL)
        {
            count++;
            tail = tail->next;
        }
    return count;
}

