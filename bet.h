//
// Created by Santi on 10/27/2020.
//

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

class BET
{
    struct BinaryNode{		// struct must be called BinaryNode and contain all node-related information. (such as elements and pointers to children nodes)
        string data;
        BinaryNode *left; 		// pointer to left node
        BinaryNode *right; 		// pointer to right node
        BinaryNode(const string & d = string{}, BinaryNode *lef = nullptr, BinaryNode *righ = nullptr) : data{d}, left{lef}, right{righ} {}
    };

public:
    BET();										 // default constructor (build empty tree)
    BET(const string postfix);					 //  one-parameter constructor, where parameter "postfix" is string containing a postfix expression.
    BET(const BET&);							 // copy constructor
    ~BET();										 // destructor
    bool buildFromPostfix(const string& postfix); // build tree
    const BET & operator=(const BET &);			 // assignment operator
    void printInfixExpression();				 //  Print out the infix expression. Should do this by making use of the private (recursive) version
    void printPostfixExpression();				 // Print the postfix form of the expression. Use the private recursive function to help
    size_t size();								 // return the number of nodes in the tree
    size_t leaf_nodes();						 // return the number of leaf nodes in the tree (use private recursive function to help)
    bool empty();								 // return true if the tree is empty

private:
    void printInfixExpression(BinaryNode *n);	 // print infix expression
    void makeEmpty(BinaryNode* &t);				 // delete all nodes in subtree pointed to by t
    BinaryNode * clone(BinaryNode *t) const;	 // clone all nodes in subtree pointed to by t
    void printPostfixExpression(BinaryNode *n);  //  print to the standard output the corresponding postfix expression.
    size_t size(BinaryNode *t);					 // returns number of nodes in subtree pointed to by t
    size_t leaf_nodes(BinaryNode *t);			 // return number of leaf nodes in the subtree pointed to by t
    BinaryNode * root;
};


