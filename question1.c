#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

struct node *element(struct node *dll, int i) {
    while(i>0 && dll!=NULL&& dll->next != NULL) {
       dll=dll->next;
       i--;
    }
    return dll;
    if (i > 0) {
      struct node *dll = NULL;
    }
    return dll;
}

struct node *add(struct node *dll, int i, int value) {
   struct node *new=(struct node *)malloc(sizeof(struct node));
   new->value=value;
   new->prev=NULL;
   new->next=NULL;
   struct node *last=NULL;
   struct node *node=dll;

   if(i<0) {
       if(dll==NULL) {
           return new;
       }
       while(node->next!=NULL) {
           node=node->next;
       }
       node->next=new;
       new->prev=node;
       return dll;
   }

    node = element(node,i);
    last = node->prev;
    
    if(node->next==NULL) {
        last->next->next=new;
        new->prev=last;
    }
    else if(last->next==NULL ) {
       new->next=dll;
       if(dll!=NULL) {
           dll->prev=new;
       }
       dll=new;
   }
   else {
       new->prev=last;
       new->next=last->next;
       last->next=new;
       new->next->prev=new;
   }
   return dll;
}

struct node *delete(struct node *dll, int i) {
   if(i<0) {
       return dll;
   }
   struct node *new=(struct node *)malloc(sizeof(struct node));
   struct node *last=NULL;
   struct node *node=dll;
   while(i>0 && node!=NULL) {
       last=node;
       node=node->next;
       i--;
   }
   if(last==NULL) {
       dll=dll->next;
       if(dll!=NULL) {
           dll->prev=NULL;
       }
   }
   else if(i==0 && node!=NULL) {
       last->next=node->next;
       if(node->next!=NULL) {
           node->next->prev=last;
       }
   }
   return dll;
}



void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
 
    //Testing code! 
    struct node *dll = malloc(sizeof(struct node));
    dll->next = NULL;
    dll->prev = NULL;
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    printLL(dll);
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 