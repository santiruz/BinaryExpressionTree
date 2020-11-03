//
// Created by Santi on 10/27/2020.
//
#include "bet.h"
#include <iostream>

using namespace std;

bool isOperator(string s)
{
    for(int i =0; i < s.length(); i++)
        if(isalnum(s[i]))
            return false;

    return true;

}

BET ::BET():root{nullptr} {

}
BET ::~BET() {
    makeEmpty(root);
}
BET::BET(const string postfix): root{nullptr}{
    buildFromPostfix(postfix);
}

BET ::BET(const BET & data) : root{nullptr} {
    root = clone(data.root);


}
const BET & BET::operator=(const BET & data){ // assignment operator
    root = clone(data.root);
    return *this;
}
void BET::printInfixExpression(){ // print infix form (use private recursive function to help)
    printInfixExpression(root);
    cout << endl;
}

BET::BinaryNode * BET::clone(BinaryNode *t) const{
    if(t == nullptr)
        return nullptr;
    else
        return new BinaryNode(t->data, clone(t->left), clone(t->right));
}

bool BET::buildFromPostfix(const string &postfix) //hardest function
{

    string input;
    stack<BinaryNode*> stack;
    stringstream s(postfix);
    int operands = 0, operators = 0;

    if(postfix.empty())
    {
        cout << "Wrong postfix expression" << endl;
        return false;
    }

    if(root != nullptr)
    makeEmpty(root);



    while(s >> input)
    {
        auto tempNode = new BinaryNode(input);


        if(!isOperator(input))
        {
        stack.push(tempNode);
        operands++;

        }


        if(isOperator(input))
        {
            operators++;
            if(operators == operands) {

                cout << "Wrong postfix expression" << endl;
                return false;
            }
            tempNode->right = stack.top();
            stack.pop();
            tempNode->left = stack.top();
            stack.pop();
            stack.push(tempNode);

        }

    }


    if(stack.size() > 1)
    {
        cout << "Wrong postfix expression" << endl;
        return false;
    }
    root = stack.top();
    stack.pop();
    return true;



}

void BET::printPostfixExpression() {
    printPostfixExpression(root);
    cout << endl;

}

size_t BET::size() {
    return size(root);
}

size_t BET::leaf_nodes() {
    return leaf_nodes(root);
}

bool BET::empty() {
    return (root == nullptr);
}

void BET::makeEmpty(BET::BinaryNode *&t) {
    if( t != nullptr )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = nullptr;


}

void BET::printInfixExpression(BET::BinaryNode *n) {
    if(n != nullptr)
    {
        if (n->left == nullptr && n->right == nullptr) {
            cout << n->data << " ";
            return;
        }

        if (*&n != *&root)
        cout << "(" << " ";
        printInfixExpression(n->left);
        cout << n->data << " ";
        printInfixExpression(n->right);
        if (*&n != *&root)
        cout << ")" << " ";
    }

}

void BET::printPostfixExpression(BET::BinaryNode *n) {
    if(n != nullptr)
    {
        printPostfixExpression(n->left);
        printPostfixExpression(n->right);
        cout << n->data << " ";
    }

}

size_t BET::size(BET::BinaryNode * n) {
    if(n == nullptr)
        return 0;
    else
        return size(n->left) + 1 + size(n->right) ;
}

size_t BET::leaf_nodes(BET::BinaryNode *t) {
    if(t == nullptr)
        return 0;
    else if(t->left == NULL)
        return 1;
    else
        return (leaf_nodes(t->left) + leaf_nodes(t->right));
}
