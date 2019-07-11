#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* link;
};

node* head;
node* tail;

void pushfront(int n,node* next)
{
   //  1. Add to front ...
   node* temp = new node();
   if(next == NULL)
   {
      temp->data = n;
      temp->link = NULL;
      head = temp;
   }
   else
   {
      temp->data = n;
      temp->link = next;
      head = temp;
   }
}

void topfront(node* next)
{  
     // 2. Show front..
    if(next==NULL){
        cout<<"List is Empty ..!"<<endl;
    }
    cout<<next->data<<endl;
}

void popfront(node* next)
{
    // 3. Remove front..
    if(next == NULL)
    {
        cout<<"List is Empty ..!"<<endl;
    }
    head = next->link;
    delete next;
}

void pushback(int n,node* next)
{
   //  4. Add to back ...
   node* run = next;
   while (run!=NULL)
   {
       tail = run;
       run = run->link;
   }
   
   node* temp = new node();
   if(next == NULL)
   {
      temp->data = n;
      temp->link = NULL;
      head = temp;
   }
   else
   {
      temp->data = n;
      temp->link = NULL;
      tail->link = temp;
   }
}

void topback(node* next)
{  
     // 5. Show back..
   node* run = next;
   while (run!=NULL)
   {
       tail = run;
       run = run->link;
   } 
    if(next==NULL){
        cout<<"List is Empty ..!"<<endl;
    }
    cout<<tail->data<<endl;
}

void popback(node* next)
{
    // 6. Remove back..
    
    if(next == NULL)
    {
        cout<<"List is Empty ..!"<<endl;
    }
    node* run  ;
    node* last;

    while (next->link!=NULL)
    {
        run = next;
        next = next->link;
    }
    last  = run->link;
    run->link = NULL;
    delete last;
    
}

bool find(int m,int n, node* next)
{  
    // 7. Find the element...!

    for (int i = 0 ; i < m ; i++)
    {
        if(next->data == m){
            return true;
            next = next->link;
        }
    }
    return false;
}

bool empty(node* next)
{
    // 8. Check Empty ?

    if(next==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void reverselist(node* rev)
{
    // 9. Reverse List

    node* current,*prev,*next;
    current = rev;
    prev = NULL;

    while(current!=NULL)
    {
        next = current->link;
        current->link =prev;
        prev = current;
        current =next;
    }

    head = prev;
    
}

void revprint(node *rev)
{
    // 10. Reverse print with recursion.

    if(rev == NULL)
    {
        return;
    }
    
    revprint(rev->link);
    cout<<(rev->data)<<" ";
}

void revlinkwithrec(node *rev)
{
    // 11. Reversing link with recursion .
    if(rev->link == NULL)
    {
        head = rev;
        return ;
    } 
    revlinkwithrec(rev->link);
    node* temp = rev->link;
    temp->link = rev;
    rev->link = NULL;
}

void addbeforenode(int n, node* next,int k)
{
    // 12. adding an elemnt 

    node* temp = new node();
    node* p ,*q;
    if(n == 1){
        temp->data = k;
        temp->link = head;
        head = temp;
        return;
    }
    for (int i = 0; i < n-1; i++)
    {
        p = next;
        q = p->link;
        next = q;
    }

    temp->data = k;
    temp->link = q;
    p->link = temp;
    
}

void removeaelem(int n,node* next)
{
    // 13. Remove a element ..
    node* p,*q;
    if(n==1)
    {
        p = head;
        q = head->link;
        head = q;
        delete p;
        return;
    }

    for (int i = 0; i < n-1 ; i++)
    {
        p = next;
        q = p->link;
        next = q;
    }

    p->link = q->link;
    delete q;


}

void print(node* next)
{
   while(next!= NULL)
   {
       cout<<next->data<<" ";
       next = next->link;
   }
   cout<<endl;
}

int main()
{
              /* Singly Linked List */

    head = NULL;
    
    cout<<"Enter the number of data..?"<<endl;

    int m;
    cin>>m;

    cout<<"Enter the data ..?"<<endl;
    
    int n;
    for(int i=0; i<m; i++)
    {
         cin>>n;
         pushfront(n,head);
    }

    // Use any function you need...!   

}