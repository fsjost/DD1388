#include <cxxtest/TestSuite.h>

#include "count_if_followed_by.h"


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      char const  data[6] = {'G','G','X','G','X','G'};
      int  const test_len = 4;

      int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

      // SYNOPSIS:
      //   result should be 1 since the length specified is 4,
      //   and only one pair of [X, G] is present in that range!

      TS_ASSERT_EQUALS(result, 1);
    }
};
