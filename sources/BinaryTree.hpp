#include <iostream>
#include <stack>   //using it because we need LIFO from the leaf to the rest of the tree.
                    // using this site : https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
using namespace std;



namespace ariel{
                 
        template<typename T>  
        class BinaryTree {     

                class Node {                                        //        subclass Node
					friend class BinaryTree;
                    private:
                        T data;
                        Node* left;
                        Node* right;
                        Node* parent;
                    public:
                    //,Node* left,Node* right,Node* parent
                    Node(const T x) : data(x) ,left(nullptr), right(nullptr), parent(nullptr) {
                    }
                    ~Node() { if(left) delete left; if(right) delete right; } // recursive
                    T getData(){return this->data;}
					
                };
    /*---------------------------------------------------------------------------------------------------------*/               
                class PreorderIterator{  
                    private: 
                    Node*  PreOr_Point;                 //        subclass Preorder Iterator
                    //stack<Node> Stack;
        
                public:
                    PreorderIterator(Node * EmptyNode=nullptr) : PreOr_Point(EmptyNode) {}
                    ~PreorderIterator(){}
                    

                    bool operator!=( const PreorderIterator&) { return false; }
                    // comparison operators. just compare node pointers
                    bool operator==( const PreorderIterator&)  { return true;
                    }
                        
                    // dereference operator. return a reference to
                    // the value pointed to by nodePtr
                    T& operator* () const{
                        static T temp;
                        return temp;
                    }
                    
                    // preincrement. move forward to next larger value
                    PreorderIterator& operator++ (){
                        return *this;
                    }
                    
                    // postincrement
                    PreorderIterator operator++ (int val){
                        return *this;
                    }
                    
                    // predecrement. move backward to largest value < current value
                    PreorderIterator&  operator-- (){
                        return *this;
                    }
                    
                    // postdecrement
                    PreorderIterator  operator-- (int val){
                        return *this;
                    }

                    T *operator->() {
                    return &(PreOr_Point->data);
                    }
                };
/*---------------------------------------------------------------------------------------------------------*/               
                class InorderIterator{                     //        subclass Inorder Iterator
                    private: 
                    Node* InOr_Pointer;
                    //stack<Node> Stack;
                    

                public:
                    InorderIterator(Node * EmptyNode=nullptr): InOr_Pointer(EmptyNode) {}
                    ~InorderIterator() {}
                    

                    bool operator!=( const InorderIterator&) { return false; }
                    // comparison operators. just compare node pointers
                    bool operator==( const InorderIterator&)  { return true; }
                        
                    // dereference operator. return a reference to
                    // the value pointed to by nodePtr
                    const T& operator* () const    {
                        static T temp;
                        return temp;  }
                    
                    // preincrement. move forward to next larger value
                    InorderIterator& operator++ () {
                        return *this;
                    }
                    
                    // postincrement
                    InorderIterator operator++ (int val){
                        return *this;
                    }
                    
                    // predecrement. move backward to largest value < current value
                    InorderIterator&  operator-- (){
                        return *this;
                    }
                    
                    // postdecrement
                    InorderIterator  operator-- (int val){
                        return *this;
                    }

                    T *operator->()  {
                        return &(InOr_Pointer->data);
                    }
                };

/*---------------------------------------------------------------------------------------------------------*/               
                class PostorderIterator{                     //        subclass Postorder Iterator
                    private: 
                    Node*  PosOr_Pointer;
                                 
        
                public:
                    PostorderIterator(Node * EmptyNode=nullptr) : PosOr_Pointer(EmptyNode){}
                    ~PostorderIterator(){}
                    

                    bool operator!=( const PostorderIterator&) { return false; }
                    // comparison operators. just compare node pointers
                    bool operator==( const PostorderIterator&)  { return true;}
                        
                    // dereference operator. return a reference to
                    // the value pointed to by nodePtr
                    T& operator* () const   { 
                        static T temp;
                        return temp;
                    }
                    
                    // preincrement. move forward to next larger value
                    PostorderIterator& operator++ ()    { return *this; }
                    
                    // postincrement
                    PostorderIterator operator++ (int val) { return *this; }
                    
                    // predecrement. move backward to largest value < current value
                    PostorderIterator&  operator-- ()   { return *this; }
                    
                    // postdecrement
                    PostorderIterator  operator-- (int val)    { return *this; }

                    T *operator->()  {
                    return &(PosOr_Pointer->data);
                    }

                    };

/*---------------------------------------------------------------------------------------------------------*/ 
            private:
            stack<Node> Stack;  
            Node* root;
           
            protected:
            unsigned int tree_size = 0;
            
            public:
            BinaryTree() : root(nullptr) {}
            BinaryTree(BinaryTree* other);
            
            ~BinaryTree() {free(root);}

            BinaryTree& add_root(T newRootVal) {return *this;}              //  Perant
            BinaryTree& add_left(T Parent_val, T Left_val){if(Is_Node_Parent(Parent_val)){return *this;}
                                                            throw " This parent isnt exist";}
            BinaryTree& add_right(T Parent_val, T Right_val){if(Is_Node_Parent(Parent_val)){return *this;}
                                                            throw " This parent isnt exist";} 

            bool is_has_value() { return (this->root!=nullptr);}
            bool Is_Node_Parent(T newRootVal){          // add find()
             return true;
            }

            InorderIterator begin(){
                begin_inorder();
                return root; }
            InorderIterator end(){
                end_inorder();
                return InorderIterator(); }

            PreorderIterator begin_preorder(){return PreorderIterator(root);}          // (אב - שמאל - ימין)
            PreorderIterator end_preorder(){return PreorderIterator();}

            InorderIterator begin_inorder(){return InorderIterator(root);}          // (אב - שמאל - ימין)
            InorderIterator end_inorder(){return InorderIterator();}

            PostorderIterator begin_postorder(){return PostorderIterator(root);}          // (אב - שמאל - ימין)
            PostorderIterator end_postorder(){return PostorderIterator();}
         
            bool operator==(const BinaryTree& CompTree)  { return true;}
            bool operator!=(const BinaryTree& CompTree)  { return false;}
            
            friend std::ostream &operator<<(std::ostream& Output, const BinaryTree& binaryTree){
            Output<<"My BinaryTree is : ";                         //// will want to recieve the tree
            return Output; };

            Node* findMyNode(Node *node,T val);            // not used yet
            Node* find_Element(T val){
            if(val==root->data){
                return root;
            }
                return findMyNode(root,val);
            };
        };
    }