/* 
 * File:   BinarySearchTree.h
 * Author: Awebber
 *
 * Created on June 30, 2015, 6:40 PM
 */
 
#ifndef BINARYSEARCHTREE_H
#define	BINARYSEARCHTREE_H
#include<iostream>
#include <cstddef>

template <typename Comparable> 
class BinarySearchTree{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs){};     
    BinarySearchTree(const BinarySearchTree && rhs){};
    ~BinarySearchTree();
    
    const Comparable & findMax() const;
    const Comparable & findmin() const;
    bool  contains(const Comparable &value);
    bool  isEmpty()const;
    void  printTree(std::ostream & out = std::cout) const;

    void makeEmpty();
    void insert(const Comparable & value);
    void insert(const Comparable && value);
    void remove(const Comparable & value);
    
    
    
    private:
    struct BinaryNode{
    
        BinaryNode(const Comparable & theElement,BinaryNode *leftPtr,BinaryNode * rightPtr)
        :element{theElement},left{leftPtr},right{rightPtr}{};
        BinaryNode(const Comparable && theElement,BinaryNode * leftPtr,BinaryNode * rightPtr)
        :element{theElement},left{leftPtr},right{rightPtr}{}
        Comparable element;
        BinaryNode * left;
        BinaryNode * right;     
    };  
    
    BinaryNode * root;
    void insert(const Comparable & value,BinaryNode *& treeRoot);
    void insert(const Comparable && value,BinaryNode *& treeRoot);
    BinaryNode * findMax(BinaryNode * treeRoot)const;
    BinaryNode * findMin(BinaryNode * treeRoot)const;
    bool contains(const Comparable & value,BinaryNode *&treeRoot)const;
    void printTree(BinaryNode * treeRoot,std::ostream & out) const;
    void makeEmpty(BinaryNode *& treeRoot);
    
}; 
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode* treeRoot, std::ostream& out) const{
if (treeRoot != nullptr)
   { 
       printTree(treeRoot->left,out);   
       out<<treeRoot->element<< std::endl;   
       printTree(treeRoot->right,out);
   
   }
}
  
template<typename Comparable>  
void BinarySearchTree<Comparable>::printTree(std::ostream & out   ) const{
    
    if(root==nullptr)
        out<<"Empty Tree \n";
        else
           printTree(root,out);
}
template<typename Comparable>  
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode*& treeRoot) {
    if(treeRoot != nullptr)
    {    
           makeEmpty(treeRoot->left);
           makeEmpty(treeRoot->right);
           delete treeRoot;
    }
    }


 template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}


 template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree() {
    makeEmpty();
}

 template<typename Comparable> 
BinarySearchTree<Comparable>::BinarySearchTree(){
    root = nullptr;
}

 template<typename Comparable>
 bool BinarySearchTree<Comparable>::contains(const Comparable& value, BinaryNode*& treeRoot) const {
    if(treeRoot == nullptr)
        return false;          
    else if(treeRoot->element<value)
         return contains(value,treeRoot->right);
    else if(treeRoot->element>value)
         return contains(value,treeRoot->right);
    else
         return true; 
}


 template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& value) {
    contains(value,root);
}


template<typename Comparable> 
void BinarySearchTree<Comparable>::insert(const Comparable& value, BinaryNode*& treeRoot) {
    if(treeRoot == nullptr){       
        treeRoot = new BinaryNode(value,nullptr,nullptr);
    }
    else if (value< treeRoot->element)
        insert(value,treeRoot->left);
    else if(value>treeRoot->element)
        insert(value,treeRoot->right);
    else
       ; //Do nothing
}
   

 template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& value) {
    insert(value,root);
}


#endif	/* BINARYSEARCHTREE_H */


