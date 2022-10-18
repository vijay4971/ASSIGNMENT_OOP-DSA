#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class SingleLinkedList
{
private:
  Node * header = NULL;
public:
  void InsertAtBeginning ();
  void Display_list ();
  void Insert_at_end ();
  void Delete_first ();
  void Delete_last ();
  void Insert_at_position ();
  void Delete_at_position ();
};

void
SingleLinkedList::InsertAtBeginning ()
{
  Node *newnode;
  newnode = new Node ();
  cout << "\n\nEnter the data part of the node : ";
  int n;
  cin >> n;
  newnode->data = n;
  newnode->next = header;
  header = newnode;
}

void
SingleLinkedList::Insert_at_end ()
{
  Node *newnode;
  newnode = new Node ();
  cout << "\n\nEnter the data part if the node : ";
  int n;
  cin >> n;
  newnode->data = n;
  newnode->next = NULL;
  if (header == NULL)
    {
      header = newnode;
    }
  else
    {
      Node *temp;
      temp = header;
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->next = newnode;
    }
}


void
SingleLinkedList::Display_list ()
{
  Node *temp;
  temp = header;
  while (temp != NULL)
    {
      cout << temp->data << "\t";
      temp = temp->next;
    }
}

void
SingleLinkedList::Delete_first ()
{
  header = header->next;
}

void
SingleLinkedList::Delete_last ()
{
  if (header != NULL)
    {
      Node *temp;
      Node *temp1;
      temp = header->next;
      temp1 = header;
      while (temp->next != NULL)
	{
	  temp1 = temp;
	  temp = temp->next;
	}
      delete temp;
      temp1->next = NULL;
    }
  else
    cout << "\nYou haven't entered any element ! \n";

}

void
SingleLinkedList::Insert_at_position ()
{
  Node *temp;
  int count = 0;
  cout << "\n\nEnter at which position you want to insert : ";
  int n;
  cin >> n;
  temp = header;
  while (temp != NULL)
    {
      temp = temp->next;
      count++;
    }
  if (n > count)
    {
      cout << "\n\nYou can't add element at " << n << " ! As only " << count <<
	" Elements are in list .";
    }
  else if (n == 1)
    {
      InsertAtBeginning ();
    }				/*
				   else if(n==count)
				   {
				   Insert_at_end();
				   } */
  else
    {
      Node *newnode;
      Node *prenode;
      newnode = new Node ();
      cout << "\n\nEnter the data part of the node : ";
      int p;
      cin >> p;
      newnode->data = p;
      Node *temp = header;
      for (int i = 0; i < n - 2; i++)
	{
	  //prenode=temp;
	  temp = temp->next;
	}
      /*prenode=temp->next;
         temp->next=newnode;
         newnode->next=prenode; */
      newnode->next = temp->next;
      temp->next = newnode;
    }
}

void
SingleLinkedList::Delete_at_position ()
{
  Node *temp;
  int count = 0;
  temp = header;
  while (temp != NULL)
    {
      temp = temp->next;
      count++;
    }
  int n;
  cout << "\n\nEnter at which position you want to delete node : ";
  cin >> n;
  if (n > count)
    {
      cout << "\n\nYou can't delete element at " << n << " ! As only " << count
	<< " Elements are in list .";
    }
  else
    {
      temp = header;
      for (int i = 0; i < n - 2; i++)
	{
	  temp = temp->next;
	}
      temp->next = temp->next->next;
    }
}

int
main ()
{
  SingleLinkedList s;
  int lc = 0;
  while (lc != -1)
    {
      int ch;
      cout <<
	"\n1.InsertAtBeginning\n2.Insert_at_end\n3.Insert_at_position\n4.Delete_first\n5.Delete_last\n6.Delete_at_position\n7.Display_list\n8.exit";
      cout << "\nEnter your choice : ";
      cin >> ch;
      switch (ch)
	{
	case 1:
	  s.InsertAtBeginning ();
	  break;
	case 2:
	  s.Insert_at_end ();
	  break;
	case 3:
	  s.Insert_at_position ();
	  break;
	case 4:
	  s.Delete_first ();
	  break;
	case 5:
	  s.Delete_last ();
	  break;
	case 6:
	  s.Delete_at_position ();
	  break;
	case 7:
	  s.Display_list ();
	  break;
	case 8:
	  cout << "\n\n*******************THANK YOU!********************" <<
	    endl;
	  lc = -1;
	  break;
	default:
	  cout << "\n\nPlease enter a valid choice ! " << endl;
	  break;

	}
    }
    return 0;
}
