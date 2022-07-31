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

enum class State {kEmpty, kObstacle, kClosed};


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

// Heuristic function using Manhattan Distance.
int Heuristic(const int& x1, const int& y1, const int& x2, const int& y2)
{
  return abs(x2-x1) + abs(y2-y1);
}

// Add a node to the open list and mark it as open.
void AddToOpen(const int& x, const int& y, const int& g, const int& h,
               vector<vector<int>>& openNodes,
               vector<vector<State>>& grid)
{
  openNodes.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}

// TODO: Write the Search function stub here.
vector<vector<State>> Search(const vector<vector<State>> board,
                             const int startPoint[2],
                             const int endPoint[2])
{
  cout << "No path found!\n";
  return vector<vector<State>> {};
}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
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
