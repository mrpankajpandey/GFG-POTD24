
/*

Author : mrpankajpandey
Date : 01/05/2024
Problem : Arrange Consonants and Vowels
Difficulty : Medium
Problem Link :https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1
Video Solution : NA

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    struct Node* arrangeCV(Node *head)
    {
        
       //Code here
       if(!head || !head->next) return head;
       unordered_set<char> st={'a','e','i','o','u'};
       
       Node*temp=head, *tail;
       int cons=0, length=0;
       while(temp){
           if(st.find(temp->data)==st.end()){
               cons++;
           }
           length++;
           if(temp->next==NULL){
               tail=temp;
           }
           temp=temp->next;
       }
       
        if(cons==0 || length==cons){
            return head;
        }
        
            while(head && st.find(head->data)==st.end()){
                Node* x=head;
                head=head->next;
                tail->next=x;
                tail=x;
                x->next=NULL;
                cons--;
            }
        temp=head;
        Node*prev=NULL;
        while(cons){
            if(tail==temp){
                break;
            }
            if(st.find(temp->data)==st.end()){
                prev->next=temp->next;
                tail->next=temp;
                temp->next=NULL;
                tail=temp;
                cons--;
                temp=prev->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends