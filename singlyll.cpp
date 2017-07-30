#include<iostream>
#include<stdlib.h>
using namespace std;
class List{
private:

typedef struct node{
node* next;
int data;
}* ptr;

ptr head;
ptr curr;
ptr temp;

public:
    List();
    void AddNode(int addData);
    void DelNode(int deldata);
    void print();

};

 List::List()
 {
     head=NULL;
     curr=NULL;
     temp=NULL;
 }

 void List::AddNode(int addData)
 {

     ptr n=new node;
     n->next=NULL;
     n->data= addData;

      if(head!=NULL)
      {
          curr=head;
          while(curr->next !=NULL)
          {
              curr= curr->next;
          }
          curr->next=n;
      }
      else{
        head=n;
         }
         }
   void List::DelNode(int deldata)
   {
       ptr delptr=NULL;
       temp=head;
       curr=head;
       while(curr!=NULL && curr->data!=deldata)
          {
              temp=curr;
              curr=curr->next;
          }
              if(curr==NULL)
              {
                  cout<<deldata<<"was not in the list"<<endl;
                  delete delptr;
              }
              else{
              delptr=curr;
              curr=curr->next;
              temp->next=curr;
              if(delptr==head)
              {
                  head=head->next;
                  temp=NULL;
              }
              delete delptr;
              cout<<"The value "<<deldata<<" was deleted"<<endl;
          }
          }
   void List::print(){
   curr=head;
   while(curr!=NULL)
   {
       cout<<curr->data<<endl;
       curr=curr->next;
   }
   }
int main()
{
    List divyanshi;
    divyanshi.AddNode(8);
    divyanshi.AddNode(5);
    divyanshi.AddNode(7);
    divyanshi.AddNode(6);
    divyanshi.AddNode(3);
    divyanshi.print();
    divyanshi.DelNode(6);
    divyanshi.print();


  return 0;
}
