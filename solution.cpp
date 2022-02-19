#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <deque>
#include <sstream>
using namespace sol1197;
using namespace std;

/*takeaways
  - we limit our search on the first quadrant only
    due to the fact of how knight move in a symmetric
    way when finding the counterpart target

  - as a result we want to limit the chessboard to
    expand to the left and down.
*/

int Solution::minMoves(int x, int y)
{
  /*
     - how the knight moves to reach the
       targets that are only different
       in the sign of the values is
       symmetric in all 4 quadrants
       (x,y) (x,-y) (-x,y) (-x,-y)
     - we only care about the steps
       so we can just focus on the
       first quadrant
  */
  x = abs(x), y = abs(y);

  /* count the steps; mark a position as visited */
  auto steps = map<pair<int, int>, int>();
  auto q = queue<pair<int, int>>();
  steps[{0, 0}] = 0;
  q.push({0, 0});

  auto within = [](pair<int, int> next, pair<int, int> pos)
  {
    /*
      - in general we don't want the knight
        to go left or down to a position
        of negative coordinates but need
        to allow some wiggle room
      - let say the target is (2,0)
        the moves are (0,0)->(1,-2)->(2,0)
      - why not going down or left too much?
        we already limit our search to the
        first quadrant
    */
    return next.first >= -5 &&
           next.second >= -5;
  };

  while (!q.empty())
  {
    auto pos = q.front();
    q.pop();
    if (pos == make_pair(x, y))
      return steps[pos];

    for (auto d : dirs)
    {
      auto next = make_pair(
          pos.first + d.first, pos.second + d.second);
      if (within(next, pos) && !steps.count(next))
        steps[next] = steps[pos] + 1, q.push(next);
    }
  }

  return -1;
}