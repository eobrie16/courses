#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node{
  int data;
  struct Node* next;
};

typedef struct Node item;

int pop(struct Node** headRef)
{
    int retVal;
    struct Node* temp;
    if (*headRef == NULL)
      return 0;

    retVal = (*headRef)->data;
    temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);

    return retVal;
}

void insert_n(struct Node** headRef, int data, int n)
{
  assert(headRef!=NULL);
  assert(n>=0);

  if (n==0)
  {
    item* newcur = (item *)malloc(sizeof(item));
    newcur->data = data;
    newcur->next = *headRef;
    *headRef = newcur;
    return;
  }

  int count=0;
  struct Node* curr=*headRef;
  struct Node* prev=*headRef;

  while ((count<n)&&(curr!=NULL))
  {
    count++;
    prev=curr;
    curr=curr->next;
  }
  item* newcur = (item *)malloc(sizeof(item));
  newcur->data = data;
  newcur->next = curr;
  prev->next = newcur;

}

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

void front_back_split (struct Node *source, struct Node** frontRef,
  struct Node** backRef)
{
	struct Node *p1, *p2, *curr;
  if (frontRef==NULL && backRef==NULL)
    return;
  if (source==NULL) {
    *frontRef = NULL;
    *backRef = NULL;
    return;
  }
  if (source->next == NULL)
  {
    *frontRef = source;
    *backRef = NULL;
  }
	p1 = source;
	p2 = source;
	while (p2->next)
	{
    if (p2->next->next) {
      p1=p1->next;
      p2=p2->next->next;
    }
    else
      break;
	}
  printf("source = %d\n", source->data);
  *frontRef = source;
  printf("frontRef = %d\n", (*frontRef)->data);
  printf("backRef = %d\n", (*backRef)->data);
  *backRef = p1->next;
  printf("frontRef = %d\n", (*frontRef)->data);
  printf("backRef = %d\n", (*backRef)->data);
  p1->next = NULL;

  curr = *frontRef;
  while(curr) {
     printf("%d\n", curr->data);
     curr = curr->next;
   }
  printf("end\n");
}

void remove_duplicates(struct Node *source)
{
  struct Node *prevnode, *curnode;
  if (source==NULL)
    return;
  prevnode = source;
  curnode = source->next;
  while (curnode)
  {
    if (curnode->data == prevnode->data)
    {
      prevnode->next = curnode->next;
      free(curnode);
      curnode = prevnode->next;
    }
    else
    {
      prevnode = curnode;
      curnode = curnode->next;
    }
  }

}

void move_node (struct Node** source, struct Node** dest)
{
  struct Node *temp;
  if (source==NULL)
    return;

  temp = (*source)->next;
  (*source)->next = *dest;
  *dest = *source;
  *source = temp;
}

struct Node* sorted_merge (struct Node* a, struct Node* b)
{
  struct Node *head, *curr;
  if ((a==NULL)&&(b==NULL))
    return NULL;

  if (a==NULL) {
    head = b;
    return head;
  }

  if (b==NULL) {
    head = a;
    return head;
  }

  head = (item *)malloc(sizeof(item));
  if (a->data < b->data) {
    head->data = a->data;
    a = a->next;
  }
  else {
    head->data = b->data;
    b = b->next;
  }

  curr = (item *)malloc(sizeof(item));
  if (a->data < b->data) {
    curr->data = a->data;
    a = a->next;
  }
  else {
    curr->data = b->data;
    b = b->next;
  }
  head->next = curr;

  while (a != NULL && b!=NULL)
  {
    curr->next = (item *)malloc(sizeof(item));
    curr = curr->next;
    if (a == NULL) {
      curr->data = b->data;
      b = b->next;
    }
    else if (b == NULL) {
      curr->data = a->data;
      a = a->next;
    }
    else if (a->data < b->data) {
      curr->data = a->data;
      a = a->next;
    }
    else {
      curr->data = b->data;
      b = b->next;
    }
  }

  return head;
}

struct Node* reverse(struct Node* list)
{
  struct Node* reversed, *curr;
  if (list == NULL)
    return NULL;

  reversed = list;
  list = list->next;
  reversed->next = NULL;
  while (list)
  {
    curr = reversed;
    reversed = list;
    list = list->next;
    reversed->next = curr;
  }

  return reversed;
}

int main(void) {
   item * curr, * head, *head2;
   int i;

   head = NULL;

   for(i=20;i>0;i-=2) {
      curr = (item *)malloc(sizeof(item));
      curr->data = i;
      curr->next  = head;
      head = curr;
   }

   //remove_duplicates(head);

   curr = head;
   while(curr) {
      printf("%d\n", curr->data);
      curr = curr->next ;
   }

   printf("head2\n");
   head2 = NULL;

   for(i=19;i>0;i-=2) {
      curr = (item *)malloc(sizeof(item));
      curr->data = i;
      curr->next  = head2;
      head2 = curr;
   }

   //remove_duplicates(head);

   curr = head2;
   while(curr) {
      printf("%d\n", curr->data);
      curr = curr->next ;
   }

   //struct Node *mergedhead = sorted_merge(head,head2);
   struct Node *newhead = reverse(head);

   curr=newhead;
   printf("reverse\n");
   while(curr) {
     printf("%d\n", curr->data);
     curr = curr->next ;
   }



   /*item **headRef, **headRef2;
   headRef = malloc(sizeof(item));
   headRef2 = malloc(sizeof(item));
   *headRef = head;
   *headRef2 = head2;
   move_node(headRef, headRef2);

   printf("newlist\n");
   curr = *headRef2;
   while(curr) {
      printf("%d\n", curr->data);
      curr = curr->next ;
   }

   item **headRef, **backRef;
   headRef = malloc(sizeof(item));
   backRef = malloc(sizeof(item));
   *headRef = head;
   *backRef = head;
   //front_back_split(head, headRef, backRef);
   //move_node(head)

   //printf("popped, %d\n", pop(headRef));
   //insert_n(headRef, 500, 0);

   printf("headref:\n");
   curr = *headRef;
   while(curr) {
      printf("%d\n", curr->data);
      curr = curr->next ;
   }
   printf("backref\n");
   curr = *backRef;
   while(curr) {
      printf("%d\n", curr->data);
      curr = curr->next ;
   }*/
}
