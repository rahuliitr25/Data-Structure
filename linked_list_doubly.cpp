#include <iostream>
using namespace std;

struct  node
{
    int data;
    node* next;
    node* prev;
};

node* head , *tail;

void insbeg(int n , node* start)
{
    node* temp = new node();
    if (start == NULL)
    {
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
        return;
    }

    temp->data = n;
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head = temp;
    
}


void delelem(int n , node* start)
{
    if (n==1)
    { 
        node* temp = head;
        node* temp1 = head->next;
        temp1->prev = NULL;
        head = temp1;
        delete temp;
        return;   
    }

 /*    node* p = start;
    node* q = start->next; */

    for (int i = 0; i < n; i++)
    {
        node* p = start;
        node* q = start->next;
        start = start->next;
    }
    
    // doubt..

/*     for( int i = 0; i < n ; i++)
    {
        node* p = start;
        node* q = start->next;
        start = start->next;
    }  */
    
/*     p->next = q->next;
    q->prev = p;
    delete q;  */
}

void insend(int n, node* start)
{
    node* temp = new node();
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if(start==NULL){
         head = temp;
         tail = temp;
         return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;

}

void print(node* start)
{
    cout<<"The list is  ";
    while (start!=NULL)
    {
        cout<<start->data<<" ";
        start = start->next;
    }
    cout<<endl;
    
}


int main()
{
    head = NULL;
    tail = NULL;
    cout<<"How many number you wanna insert ?"<<endl;
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
         cout<<"Enter the elemt "<<i+1<<endl;
         int x;
         cin>>x;
         insend(x,head);
    }    
    print(head);

}
