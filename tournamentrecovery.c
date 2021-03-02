#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;
//BT struct.
struct TreeNode {
   struct TreeNode * left;
   struct TreeNode * right;
   int value;
};
//function prototypes.
TreeNode * CreateTree(int preorder[],int postorder[], int start1, int end1,int start2, int end2);
TreeNode * createNode(int value);
void printTree(TreeNode * cur);
void cleanTree(TreeNode *);

int main (){

int numnodes, i;
scanf("%d", &numnodes);
//initializes arrays for postorder and preorder to be inputted.
int postorder[numnodes], preorder[numnodes];
//after scanning the number of nodes, for loop, scans the proper ammount into the arrays.
for(i=0; i< numnodes; i++)
{
	scanf("%d", &postorder[i]);
}
for(i=0; i< numnodes; i++)
{
	scanf("%d", &preorder[i]);
}
//call functions.
TreeNode * Root = CreateTree(preorder, postorder, 0, numnodes-1,0, numnodes-1);
printTree(Root);
cleanTree(Root);

return 0;
}
//This recursive function creates the binary tree based on the preorder and postoder.
//start1 and end1 indicate the starting and ending indicies for the preorder array.
//start2 and end2 indicate the starting and ending indicies for the preorder array.
TreeNode * CreateTree(int preorder[],int postorder[], int start1, int end1,int start2, int end2)
{
	
	int i, j, newpostend, newpreend;
	//create the current node that the function is considering.
	//the first number in the preorder array is the value of the current node.
	TreeNode* Root = createNode(preorder[start1]);
	//if the post order array has only 1 number, then return pointer for node with that number.
	if(start1==end1|| start2 == end2)
	{
		return Root;
	}	
	//This loop finds where in the postorder is the the next value from the preorder
	//this will be where the function splits the arrays into the left and right subtrees.
	for(i=start2; i<end2; i++)
	{
		if(postorder[i]==preorder[start1+1])
		{
			newpostend = i;
			break;	
		}
		
	}
	//This loop finds where in the preorder the next value being considered is.
	for(j=start1; j<end1; j++)
	{
		if(preorder[j]==postorder[end2-1])
		{
			newpreend = j;
			break;	
		}
			
	}
	//this case is if there is one child, in this case, the function defaults the next node as a left child.
	if(start1+1>j-1)
	{
		//recursively call function with updated array indicies.
		Root->left = CreateTree(preorder, postorder, j, end1, start2, i);
		return Root;
	}
	//recursively call function with updated array indicies.
	//The indicies are updated based on the values found in the loops above.
	Root->left = CreateTree(preorder, postorder, start1+1, j-1, start2, i);
	Root->right = CreateTree(preorder, postorder,j, end1, i+1, end2-1);
	return Root;
	
}
//this function creates a node of the inputted value.
TreeNode * createNode(int value)
{
   // Allocate
   TreeNode * newNode =
      (TreeNode *) calloc(1, sizeof (TreeNode));
      
   // Initialize the value
   newNode->value = value;
   
   // Set the left and right children to empty trees
   newNode->right = (newNode->left = NULL);
   
   // Return the created value
   return newNode;
}
//This function prints the tree in its inorder traversal.
void printTree(TreeNode * cur)
{
   if (cur == NULL)
      return;
  
   printTree(cur->left);
   printf("%d ", cur->value);
   printTree(cur->right);
}

// Function to free an entire tree
void cleanTree(TreeNode * cur)
{
   if (cur == NULL)
      return;
   cleanTree(cur->left);
   cleanTree(cur->right);
   free(cur);
}

