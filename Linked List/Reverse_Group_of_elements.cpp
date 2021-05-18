#include<iostream>
#include<vector>
#include<cstdlib>
#include<conio.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
}

Node* head = NULL;

void insert(int n)
{
    newN = new Node();
    newN->data = n;
    newN->next = NULL;
    if(head == NULL)
    {
        head = newN;
    }
    else
    {
        Node* t = NULL;
        t = head;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = newN;
    }
}

void display()
{
    Node* t = NULL;
    t = head;
    while(t->next != NULL)
    {
        cout<<t->data<<'\t';
    }
    cout<<'\n';
}

int main()
{
    string st;
    cout<<"Enter the values in the array for reversal. Press Q/q to stop entering values.\n";
    while(true)
    {
        cin>>st;
        if(st.compare("q") == 0 or st.compare("Q") == 0)
        {
            break;
        }
        else
        {
            insert(stoi(st));
        }
    }
    display();


    return 0;
}