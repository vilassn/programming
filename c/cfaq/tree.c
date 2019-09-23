#include <stdio.h>
#include <stdlib.h>

enum choice {ADD='a', DELETE='d', SEARCH='s', PRINT='p', EXIT='e'};

typedef struct tree
{
 int data;
 struct tree *left;
 struct tree *right;
}Tree;

Tree *head=0;

void main()
{
 int i, num;
 char ch;

 while(1)
 {
  printf("Enter Choice: %c.Add, %c.Delete, %c.Search, %c.Print, %c.Exit: ", ADD, DELETE, SEARCH, PRINT, EXIT);
  scanf(" %c",&ch);
  switch(ch)
  {
   case ADD:
            printf("Enter num to add: ");
            scanf("%d",&num);
            add(num, head);
            break;
   case DELETE:
            printf("Enter num to delete: ");
            scanf("%d",&num);
            delete(num);
            break;
   case SEARCH:        
            printf("Enter num to search: ");
            scanf("%d",&num);
            search(num);
            break;
   case PRINT:
            inOrder(head);
            break;
   case EXIT:
            exit(0);
   default: printf("Invalid choice");
  }
  printf("\n");
 }
}
 

struct node
{
    char* key;
    node* left;
    node* right;
};
 struct node *root=0;
void insert(char * ch)//non recursive
{
 node *temp = new node;
 temp->key = ch;
 temp->left = NULL;
 temp->right = NULL;

 if(root==NULL)
  root = temp;
 else
 {
  // find the correct location for the new node
  // and insert it
  bool inserted = false;
  node *locn = root;
  while( !inserted)
  {
   if(locn->key > temp->key)
   {
    if(locn->left == NULL)
    {
     locn->left = temp;
     inserted = true;
    }
    else
     locn = locn->left;
   }
   else
   { 
    if(locn->right == NULL)
    {
     locn->right = temp;
     inserted = true;
    }
    else
     locn = locn->right;
   }
  }
 }
}

void insert(node ** tree, node * item) //recursive
{
   if(!(*tree)) {
      *tree = item;
      return;
   }
   if(item->val<(*tree)->val)
      insert(&(*tree)->left, item);
   else if(item->val>(*tree)->val)
      insert(&(*tree)->right, item);
}

void destroy_tree(node* p)
{
 if (p != NULL)
 {
  destroy_tree(p->left);
  destroy_tree(p->right);
  delete p;
 }
}
 
node* find(char * ch)
{
 node* curr = root;
    while( curr)
    {
        if(!strcmp(ch, curr->key))
        {
            return curr;
        }
        else if(strcmp(ch, curr->key)>0)
            curr = curr->right;
        else if(strcmp(ch, curr->key)<0)
            curr = curr->left;
    }
 return NULL;
}

void mirror(Tree* node)
{
  if (node==NULL)
    return; 
  else
  {
    Tree* temp;
     
    /* do the subtrees */
    mirror(node->left);
    mirror(node->right);
 
    /* swap the pointers in this node */
    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
} 

void inOrder(Tree* node)
{
  if (node == NULL)
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}  

void btree::remove(char* data)
{
 node *temp = root;
 node *prev = root;
 while (1)
 {
  if(temp == NULL)
   return;
  if(strcmp(temp->key , data) == 0)
  {
   bool left = false;
   if(prev->left == temp)
    left = true;
   if(temp->left == NULL && left)
   { 
    prev->left = temp->right;
    delete temp;
    return;
   }
   if(temp->right == NULL && left)
   {
    prev->left = temp->left;
    delete temp;
    return;
   }
   if(temp->left == NULL && left == false)
   {
    prev->right = temp->right;
    delete temp;
    return;
   }
   if(temp->right == NULL && left == false)
   {
    prev->right = temp->left;
    delete temp;
    return;
   }
   while(temp->left != NULL && temp->right != NULL)
   {
    temp->key = temp->right->key;
    prev = temp;
    temp = temp->right;
   }
   if(temp->right == NULL)
    prev->right = temp->left;
   if(temp->left == NULL)
    prev->right = temp->right;
   delete temp;
   return;
  }
  prev = temp;
  if(strcmp(temp->key,data) < 0)
   temp = temp->right;
  else
   temp = temp->left;
 }
}

int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}

