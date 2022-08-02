#include <algorithm> // for sorting the open vector
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;
using std::sort;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}


// Function to compare the f-value of two nodes here.
// vector format: x, y, g, h
bool Compare(const vector<int>& n1, const vector<int>& n2)
{
  // f = g + h
  int f1 = n1[2] + n1[3];
  int f2 = n2[2] + n2[3];
  return f1 > f2;
}


// Sort vector in desc order
void CellSort(vector<vector<int>> *v)
{
  sort(v->begin(), v->end(), Compare);
}


// Heuristic function using Manhattan Distance.
int Heuristic(const int& x1, const int& y1, const int& x2, const int& y2)
{
  return abs(x2-x1) + abs(y2-y1);
}


// Check that the cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(const int& x, const int& y, const vector<vector<State>>& grid)
{
  if ((x >= 0 && x < grid.size()) && (y >= 0 && y < grid[0].size()))
    return grid[x][y] == State::kEmpty;

  return false;
}


// Add a node to the open list and mark it as open.
void AddToOpen(const int& x, const int& y, const int& g, const int& h,
               vector<vector<int>>& openNodes,
               vector<vector<State>>& grid)
{
  openNodes.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}


void ExpandNeighbors(const vector<int> curNode,
                     const int goal[2],
                     vector<vector<int>>& openList,
                     vector<vector<State>>& grid)
{
  int x = curNode[0];
  int y = curNode[1];
  int g = curNode[2];

  // Loop through current node's neighbors
  for(int i = 0; i < 4; i++) 
  {
    int x2 = x + delta[i][0];
    int y2 = y + delta[i][1];

    if (CheckValidCell(x2, y2, grid))
    {
      int g2 = g + 1;
      int h2 = Heuristic(x2, y2, goal[0], goal[1]);
      AddToOpen(x2, y2, g2, h2, openList, grid);
    }
  }
}


vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2])
{
  // Create the vector of open nodes.
  vector<vector<int>> open {};

  // Initialize the starting node.
  int x1 = init[0];
  int y1 = init[1];
  int g = 0;
  int h = Heuristic(x1, y1, goal[0], goal[1]);
  
  // Use AddToOpen to add the starting node to the open vector.
  AddToOpen(x1, y1, g, h, open, grid);

  while(!open.empty())
  {
    CellSort(&open);
    auto curNode = open.back();
    open.pop_back();
    int x = curNode[0];
    int y = curNode[1];
    grid[x][y] = State::kPath;

    if (x == goal[0] && y == goal[1])
    {
      grid[init[0]][init[1]] = State::kStart;
      grid[goal[0]][goal[1]] = State::kFinish;
      return grid;
    }

    ExpandNeighbors(curNode, goal, open, grid);
  }

  cout << "No path found!\n";
  return vector<vector<State>> {};
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦   ";
    case State::kFinish: return "🏁   ";
    default: return "0   ";
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}


int main() {
  // Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init[2] = {0, 0};
  int goal[2] = {4, 5};

  auto board = ReadBoardFile("1.board");
  
  // Call Search with "board", "init", and "goal". Store the results in the variable "solution".
    auto solution = Search(board, init, goal);
  
  PrintBoard(solution);
}
