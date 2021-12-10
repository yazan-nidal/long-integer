#include "iostream"
#include <string>
using namespace std;

typedef int itemtype;

struct nodetype
{ itemtype item;
  struct nodetype *next;
};

typedef struct nodetype *nodepointer;

typedef struct headernode 
{nodepointer first, last;
} header;

//typedef struct headernode header;

void clear(header &head)
{
	head.first = head.last = NULL;
}


void insert(header &head , itemtype i)
{   nodepointer  q;
    q = new nodetype; // allocate memory
	q->item = i; // copy information
	q->next  = head.first; // establ the link
    head.first = q; // establ the link
}

void insertlast(header &head, itemtype i)
{   nodepointer  q;
    q = new nodetype; // allocate memory
	q->item = i; // copy information
	if (head.first == NULL)
		{head.first  = head.last = q;
	     head.last->next = NULL;
	    }
	else 
	{
		q->next  = head.last->next; // establ the link
        head.last->next = q; // establ the link
		head.last = q;
	}
}


itemtype remove (header &head)
{   nodepointer  q;
    itemtype i;
	if (head.first != NULL)
    {    q = head.first;     
        head.first  = q->next;  
        i = q->item;
	    free(q);
		return i;
     }
    else cout << "List is empty";
}

void print(header head)
{   nodepointer  q = head.first;
	cout << "The list is" << endl;
	while (q != NULL)
	{ 
	   cout << q->item;
	   q = q->next;
	}
	cout << endl;
}

header ReadLong()
{ header head;
  clear(head); 
  char ch;
  int val;
  cin >> ch;
  while (ch != '.')
  {
	  val = ch - '0';
      insert(head, val);
      cin >> ch;
  }
return head;
}



header add(header l1, header l2)
{ nodepointer p, q, r;
  header l3;
  clear(l3);
  int sum,result, carry = 0; 
  p = l1.first; q = l2.first;

  while (p && q)
  {
	  sum = p->item + q ->item + carry;
	  p = p->next; q = q->next;
	  result = sum % 10;
	  carry = sum /10;
	  insertlast(l3, result);
  }
  while (p)
  {
	  sum = p->item + carry;
	  p = p->next;
	  result = sum % 10;
	  carry = sum /10;
	  insertlast(l3, result);
  }

  while (q)
  {
	  sum =  q ->item + carry;
	  q = q->next;
	  result = sum % 10;
	  carry = sum /10;
	  insertlast(l3, result);
  }

  return l3; 
}

void main()
{ header l1, l2, l3;
  
  cout << "Enter long number one ended with '.' ===> ";
 // cout <<"Enter the name number "<< 1 <<"  ==> ";
   //   cin >> st;
//  list = new nodepointer;
//  list->item = st;
  l1 = ReadLong();
  print(l1);

  cout << "Enter number two ended with '.' ===> ";
  l2 = ReadLong();
  print(l2);

  l3 = add(l1, l2);
  print(l3);
}
