#include <iostream>
#include <stack>
#include<queue>
using namespace std;

struct node
{
  node *left;
  node *right;
  int el;
  int size() const
  {
    int size_left = 0;
    if(left != 0)
      size_left = left->size();
    int size_right = 0;
    if( right != 0 )
      size_right = right->size();
    return size_left + size_right + 1;
  }
  ~node()
  {
    if(left != 0 )
      delete left;
    if( right != 0 )
      delete right;
  }
  void print_inorder() const
  {
    cout << "[ ";

    cout << el<< " ";
    
    if(left != 0)
      left->print_inorder();
    else
      cout << "L";
    


    if(right != 0)
      right->print_inorder();
    else
      cout << "R";

    cout << " ] ";
  }
};

struct tree
{
  node *root;
  
  tree():root(0) {}
  
  ~tree()
  {
    if(root != 0)
            delete root;
  }
  
  void add(int el)
  {
    if( root == 0 )
      {
	root = new node();
	root->el = el;
	root->left = 0;
	root->right = 0;
      }
    else
      {
	node **parent = 0;
	node *n = root;
	while(true)
	  {
	    if(n != 0)
	      {
		if(n->el == el)
		  {
		    break;
		  }
		else if( n->el > el )
		  {
		    parent = &n->left;
		    n = n->left;
		  }
		else // if (n->el > el)
		  {

		    parent = &n->right;
		    n = n->right;
		  }
	      }
	    else
	      {
		n = new node();
		n->el = el;
		n->left = 0;
		n->right = 0;
		*parent = n;
		break;
	      }
	  }
      }
  }
  
  int size() const
  {
    if(root != 0)
      return root->size();
    else
      return 0;
  }
  
  void print_inorder() const
  {
    if(root != 0)
      root->print_inorder();
    cout << "\n";
  }

  void print_preorder_stack() const
  {
    if(root == 0)
      return;
    
    stack<node*> s;
    s.push(root);
    while( !s.empty() )
      {
	node* n = s.top();
	s.pop();
	cout <<n->el<<'\n';
	if( n->left != 0 )
	  s.push(n->left);
	if( n->right != 0 )
	  s.push(n->right);
      }
  }

  void print_bfs()
  {
    if(root == 0)
	  return;
    
    queue<node*> s;
    s.push(root);
    while( !s.empty() )
      {
	node* n = s.front();
	s.pop();
	cout <<n->el<<'\n';
	if( n->left != 0 )
	  s.push(n->left);
	if( n->right != 0 )
	  s.push(n->right);
      }
  }

};




void algorithm()
{
  tree t1;
  int m;
  cin >> m;
  for( int i = 0 ; i < m ; i++ )
    {
      int n;
      cin >> n;
      t1.add(n);
    }
  //    cout << t1.size()<<'\n';
  t1.print_inorder();
  cout <<"print preorder stack :\n";
  t1.print_preorder_stack();
  cout <<"print bfs: \n";
  t1.print_bfs();
}



int main()
{
  ios_base::sync_with_stdio(0);
  algorithm();

  
  return 0;
}
