#include <stdio.h>

struct Node{
  int data;
  struct Node* next;
};

void append_second_list (struct Node** a, struct Node** b)
{
  struct Node* cur;
  if (*b==NULL)
    return;
  cur = *a;
  while(cur->next)
  {
    cur=cur->next;
  }
  cur->next = *b;
  cur = cur->next;
  while(cur)
  {
    cur = cur->next;
  }
  *b = NULL;
}

void front_back_split (struct Node* source, struct Node** frontRef, struct Node** backRef)
{
	struct Node *p1, *p2;
	p1 = source;
	p2 = source;
	while (p1->next->next)
	{
		p2=p1->next->next;
		p1=p1->next;
	}
}

void main()
{
  int i;
  struct Node *head, *head2, *curnode;
  struct Node **a, **b;
  head = NULL;
  for (i=0; i<10; i++)
  {
    curnode = (struct Node *)malloc(sizeof(struct Node));
    curnode->data = i+1;
    curnode->next  = head;
    head = curnode;
  }
  
  head2 = NULL;
  for (i=10; i<20; i++)
  {
    curnode = (struct Node *)malloc(sizeof(struct Node));
    curnode->data = i+1;
    curnode->next  = head2;
    head2 = curnode;
  }
  
  a = &head;
  b = &head2;
  append_second_list(a,b);
  curnode = head;

   while(curnode) {
      printf("%d\n", curnode->data);
      curnode = curnode->next ;
   }
}