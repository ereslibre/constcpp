#include "test.h"

#include <iostream>

class TestIt
  : public Test
{
public:
#if DOCONSTPLZ
  virtual void test(int a, float b, double c) const {
      std::cout << "Const stuff" << std::endl;
  }
#else
  virtual void test(int a, float b, double c) {
      std::cout << "No const stuff" << std::endl;
  }
#endif
};

int main(int argc, char **argv)
{
    TestIt *testIt = new TestIt;
    testIt->test(1, 2, 3);

    return 0;
}