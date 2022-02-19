#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1197;

/*
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
*/
tuple<int, int, int> testFixture1()
{
  return make_tuple(2, 1, 1);
}

/*
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
*/
tuple<int, int, int> testFixture2()
{
  return make_tuple(5, 5, 4);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  auto result = sol.minMoves(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  auto result = sol.minMoves(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}
main()
{
  test1();
  test2();
  return 0;
}