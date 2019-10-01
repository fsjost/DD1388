#include <cxxtest/TestSuite.h>
#include "bintree.cpp"

class TestSuite1 : public CxxTest::TestSuite {
  public:
    Node *root = nullptr;
    void testNull( void )
    {
      TS_ASSERT_THROWS(find(root,5),std::out_of_range);
      TS_ASSERT_THROWS(edit(root,5),std::out_of_range);
      TS_ASSERT_EQUALS(max_height(root),0);
      TS_ASSERT_EQUALS(min_height(root),0);
      TS_ASSERT_EQUALS(size(root),0);
      TS_ASSERT_EQUALS(is_balanced(root),true);
      TS_ASSERT_THROWS(remove(root,4),std::out_of_range);
    }

    void testOne( void )
    {
      insert(root, 5, 5);
      TS_ASSERT_EQUALS(find(root,5),5);
      TS_ASSERT_EQUALS(edit(root,5),5);
      TS_ASSERT_EQUALS(max_height(root),1);
      TS_ASSERT_EQUALS(min_height(root),1);
      TS_ASSERT_EQUALS(size(root),1);
      TS_ASSERT_EQUALS(is_balanced(root),true);
      delete_tree(root);
    }

    void testMore( void )
    {
      insert(root, 6, 6);
      insert(root, 2, 2);
      insert(root, 3, 3);
      TS_ASSERT_EQUALS(find(root,2),2);
      TS_ASSERT_EQUALS(edit(root,3),3);
      TS_ASSERT_EQUALS(max_height(root),3);
      TS_ASSERT_EQUALS(min_height(root),1);
      TS_ASSERT_EQUALS(size(root),3);
      TS_ASSERT_EQUALS(is_balanced(root),false);
      remove(root,3);
      TS_ASSERT_THROWS(find(root,3),std::out_of_range);
      insert(root,3,9);
      TS_ASSERT_EQUALS(find(root,3),9);
      delete_tree(root);
    }

    void testShitLoads( void )
    {
      insert(root, 6, 6);
      insert(root, 20, 20);
      insert(root, 11, 11);
      insert(root, 3, 3);
      insert(root, 49, 49);
      insert(root, 7, 7);
      insert(root, 2, 2);
      insert(root, 1, 1);
      insert(root, 31, 31);
      remove(root,20);                                    //REMOVE TWO CHILDREN
      TS_ASSERT_EQUALS(find(root,31),31);
      TS_ASSERT_THROWS(find(root,20),std::out_of_range);
      TS_ASSERT_EQUALS(find(root,49),49);                   //finding children
      TS_ASSERT_EQUALS(find(root,11),11);                   //finding children
      TS_ASSERT_EQUALS(find(root,7),7);                     //finding children
      remove(root,2);                                       // REMOVE WITH ONE CHLD
      TS_ASSERT_THROWS(find(root,2),std::out_of_range);
      TS_ASSERT_EQUALS(find(root,3),3);
      TS_ASSERT_EQUALS(find(root,1),1);
      remove(root,1);                                       // REMOVE LEAF
      TS_ASSERT_THROWS(find(root,1),std::out_of_range);
      TS_ASSERT_EQUALS(find(root,3),3);
      TS_ASSERT_EQUALS(is_balanced(root),false);
      delete_tree(root);
    }
};
