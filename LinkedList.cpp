#include<iostream>

using namespace std;

class node
{
  public:
  int data;
  node* next;
};

void print(node* n)
{
  while(n!=NULL)
  {
    cout<<n->data<<" ";
    n = n->next;
  }
  cout<<"\n";
}

node* pushfront(node *n,int data)
{
  if(n == NULL)
  {
    node* new_node= new node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
  }
  else
  {
    node* new_node= new node();
    new_node->data = data;
    new_node->next = n;
    return new_node;
  }
}

node* pushlast(node *n,int data)
{
  if(n == NULL)
  {
    cout<<"Nothing in the list.Try Pushing in the front\n";
    return 0;
  }
  else
  {
    while(n->next!=NULL)
    {
      n = n->next;
    }
    node* new_node= new node();
    n->next = new_node;
    new_node->data = data;
    new_node->next = NULL;
    return 0;
  }
}

node* pushmiddle(node *n,int data,int position)
{
  long count=1;
  while(n->next!=NULL)
  {
    n = n->next;
    count++;
    if(position==count)
      break;
  }
  if(n == NULL)
  {
    cout<<"Nothing in the list.Try Pushing in the front\n";
    return 0;
  }
  else if(position>count)
  {
  cout<<"No suh node is present\n";
  }
  else
  {
    node* new_node= new node();
    new_node->data = data;
    new_node->next = n->next;
    n->next = new_node;
  }
  return 0;
}

node* popfront(node* n)
{
  if(n == NULL)
  {
    cout<<"Nothing in the list.Try Pushing in the front\n";
    return 0;
  }
  else
  {
    node* temp = n;
    n = n->next;
    delete(temp);
    return n;
  }
}

node* poplast(node* n)
{
  if(n == NULL)
  {
    cout<<"Nothing in the list.Try Pushing in the front\n";
    return 0;
  }
  else
  {
    while(n->next->next!=NULL)
    {
      n = n->next;
    }
    node* temp = n->next;
    n->next = NULL;
    delete(temp);
    return 0;
  }
}

node* popmiddle(node* n,int position)
{
  long count=1;
  node* temp;
  while(n->next!=NULL)
  {
    temp = n;
    n = n->next;
    count++;
    if(position==count)
      break;
  }
  if(n == NULL)
  {
    cout<<"Nothing in the list.Try Pushing in the front\n";
    return 0;
  }
  else if(position>count)
  {
  cout<<"No suh node is present\n";
  return 0;
  }
  else
  {
    node* todel = n;
    temp->next = n->next;
    delete(todel);
    return 0;
  }
}

node* listreverse(node* n)
{
  if(n == NULL)
  {
    cout<<"Nothing in the list.Try Pushing in the front\n";
    return 0;
  }
  else
  {
  node *temp,*temp2,*temp3;
  temp = n;
  temp2 = NULL;
  temp3 = NULL;
  while(temp!=NULL)
  {
    temp2 = temp->next;
    temp->next = temp3;
    temp3 = temp;
    temp = temp2;
  }
  n->next = NULL;
  return temp3;
  }
}

node* clear(node* head)
{
  if(head == NULL)
  return head;
  else
  {
    node* temp = head;
    head = head->next;
    delete(temp);
    return clear(head);
  }
}

int main()
{
  node* head = NULL;
  bool a = true;
  while(a)
  {
    long ch,data,Position;
    cout<<"1-PushFront\n";
    cout<<"2-PushMiddle\n";
    cout<<"3-PushLast\n";
    cout<<"4-PopFront\n";
    cout<<"5-PopMiddle\n";
    cout<<"6-PopLast\n";
    cout<<"7-Print List\n";
    cout<<"8-reverse List\n";
    cout<<"9-clear List\n";
    cout<<"Enter your choice:";
    cin>>ch;
    switch (ch) {
      case 1:
             cout<<"\nEnter Data to be pushed:\n";
             cin>>data;
             head = pushfront(head,data);
             break;
      case 2:
             cout<<"\nEnter the Data and the Position:";
             cin>>data>>Position;
             pushmiddle(head,data,Position);
             break;
      case 3:
            cout<<"\nEnter Data to be pushed:\n";
            cin>>data;
            pushlast(head,data);
            break;
      case 4:
              head = popfront(head);
              cout<<"\nPopped front\n";
              break;
      case 5:
              cout<<"\nEnter the Position:";
              cin>>Position;
              popmiddle(head,Position);
              cout<<"\n Poped at "<<Position;
              break;
      case 6:
              poplast(head);
              cout<<"\n Poped at Last";
              break;
      case 7:
              cout<<"\nPrinting The List\n";
              print(head);
              break;
      case 8:
              head = listreverse(head);
              break;
      case 9:
              head = clear(head);
              break;
      default:
              cout<<"Wrong choice\n";
              a = false;
    }
  }
}
