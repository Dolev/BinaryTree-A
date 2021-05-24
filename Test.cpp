#include "BinaryTree.hpp"
#include "doctest.h"
#include <stack>  

using namespace ariel;

  
TEST_CASE(" Test my BinaryTree : ") {  
      BinaryTree<int> test1;
      test1.add_root(1)
      .add_left(1, 2)
      .add_right(1, 3);
      CHECK_THROWS(test1.add_left(9,6));        // Node 9 isnt in The Tree           //0
      CHECK_THROWS(test1.add_right(9,6));           
      /*
      1 - - - 3
      |        
      2 
      */

      BinaryTree<int> test2;
      test2.add_root(9)
      .add_right(1, 3)
      .add_left(1, 2);    
      CHECK_NOTHROW(test2.add_root(1));                   //  Overload check "9" turned -> "1"       

      BinaryTree<unsigned int> test4;
      CHECK_NOTHROW(test4.add_root(1));                                                             
      CHECK_THROWS(test4.add_right(1, 19));                           //   5 Tests
      unsigned int x= (3)*(2^9);                  //    1536
      CHECK_NOTHROW(test4.add_left(1,x)); 
      CHECK_THROWS(test4.add_left(1, '4'));

      BinaryTree<char> test5;
      CHECK_NOTHROW(test5.add_root('A'));
      CHECK_THROWS(test5.add_left('A', 4));
      CHECK_THROWS(test5.add_left('A', '4'));                        //   10 Tests
      CHECK_THROWS(test5.add_left('a', '5'));                        // a isnt in tree
      test5.add_left('A','D').add_right('A','C');
      /*
      A - - - C
      |        
      D
      */
      std::string ans="";
      auto In_Or_It2=test5.begin_inorder();
      for (auto In_Or_It=test5.begin_inorder(); In_Or_It!=test5.end_inorder(); ++In_Or_It) {
          
      }  
      std::cout<< ans;
      //CHECK_EQ(ans=="DAC");
      CHECK_NOTHROW(In_Or_It2++);
      CHECK_NOTHROW(++In_Or_It2);
      CHECK_NOTHROW(--In_Or_It2);                                //  15 Tests
      CHECK_NOTHROW(In_Or_It2--); 
      
      
}


TEST_CASE(" Test my Iterators : ") {       

BinaryTree<int> test3;
test3.add_root(1)
  .add_left(1, 2)
  .add_left(2, 3)
  .add_right(2, 5)
  .add_right(1, 4)
  .add_right(4, 7)
  .add_left(4, 6);
  /*
  1 - - - 4 - - 7
  |        \
  2 - - 5    6
  |
  3
  */
 /*
 std::string pre="";
 for (auto preorderIt = test3.begin_preorder(); preorderIt!=test3.end_preorder(); ++preorderIt) {
          ans=ans+(*preoderIt);
      } 
CHECK_EQ(pre=="1235467");

 std::string post="";
 for (auto postorderIt = test3.begin_postorder(); postorderIt!=test3.end_postorder(); ++postorderIt) {
          ans=ans+(*postorderIt);
      } 
CHECK_EQ(post=="3524671");
*/
auto postorderIt = test3.begin_postorder();
CHECK_THROWS(--postorderIt);
CHECK_NOTHROW(++postorderIt);
CHECK_NOTHROW(--postorderIt);   
CHECK_NOTHROW(postorderIt++);                             
CHECK_NOTHROW(postorderIt--);                               //  20 Tests


}

