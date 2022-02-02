# include<stdio.h>
# include<stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
 
typedef struct BST {
   int data;
   struct BST *lchild, *rchild;
} node;

int leaf = 0;
 
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
void countLeaf(node *);
int countHeight(node *);
node *search(node *, int, node **);
 
int main() {
   int choice;
   char ans = 'y';
   int n = 1;
   int key;
   node *new_node, *root, *tmp, *parent;
   node *get_node();
   root = NULL;
 
   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Create");
      printf("\n2.Search");
      printf("\n3.Traversal");
      printf("\n4.Count leaf nodes");
      printf("\n5.Count Height");
      printf("\n6.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);
 
      switch (choice) {
      case 1:
        printf("Enter number of elements: ");
        scanf("%d", &n);
        for(int i = 0 ; i < n ; i++) {
          new_node = get_node();
            printf("\nEnter Element: ");
            scanf("%d", &new_node->data);
 
            if (root == NULL)
               root = new_node;
            else
               insert(root, new_node);
        }
         break;
 
      case 2:
         printf("\nEnter Element to be searched :");
         scanf("%d", &key);
 
         tmp = search(root, key, &parent);
         printf("\nParent of node %d is %d", tmp->data, parent->data);
         break;
 
      case 3:
         if (root == NULL)
            printf("Tree Is Not Created");
         else {
            printf("\nThe Inorder display : ");
            inorder(root);
            printf("\nThe Preorder display : ");
            preorder(root);
            printf("\nThe Postorder display : ");
            postorder(root);
         }
         break;
      case 4:
        countLeaf(root);
        printf("%d leaf\n", leaf);
        break;
      
      case 5:
        printf("Height = %d\n", countHeight(root));
        break;
      }
   } while (choice != 6);

   return 0;
}

node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}

void insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }
 
   if (new_node->data > root->data) {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
}

node *search(node *root, int key, node **parent) {
   node *temp;
   temp = root;
   while (temp != NULL) {
      if (temp->data == key) {
         printf("\nThe %d Element is Present", temp->data);
         return temp;
      }
      *parent = temp;
 
      if (temp->data > key)
         temp = temp->lchild;
      else
         temp = temp->rchild;
   }
   return NULL;
}

void inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d, ", temp->data);
      inorder(temp->rchild);
   }
}

void preorder(node *temp) {
   if (temp != NULL) {
      printf("%d, ", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}

void postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d, ", temp->data);
   }
}

void countLeaf(node *temp) {
  if (temp != NULL) {  
    if(temp->lchild == NULL && temp->rchild == NULL) {
      leaf++;
    }
    countLeaf(temp->lchild);
    countLeaf(temp->rchild);
   }
}

int countHeight(node *temp) {
  if(temp != NULL) {
    int leftHeight = countHeight(temp->lchild);
    int rightHeight = countHeight(temp->rchild);
    if (leftHeight >= rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
  }
  else {
    return 0;
  }
}