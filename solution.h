#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol1197
{
  class Solution
  {
  private:
    vector<pair<int, int>> dirs = vector<pair<int, int>>{
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

  public:
    int minMoves(int x, int y);
  };
}
#endif