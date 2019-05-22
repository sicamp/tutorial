#include <bits/stdc++.h>
using namespace std;

using Vertex = std::size_t;
//using Edge = std::pair<Vertex, Vertex>;

class LabeledGraph {
 public:
  LabeledGraph(size_t vertices_count, string labels) : adjacency_list_(vertices_count) {
    for (Vertex i = 0; i < vertices_count; ++i) {
      label_[i] = labels[i];
    }
  }

  void AddEdge(Vertex v1, Vertex v2) {
    adjacency_list_[v1].insert(v2);
    adjacency_list_[v2].insert(v1);
  }

  char Label(Vertex v) {
    return label_[v];
  }

  vector<Vertex> FindPattern(string& pattern) {
    vector<bool> visited(adjacency_list_.size(), false);

    for (Vertex start = 0; start < Size(); ++start) {
      vector<Vertex> answer(pattern.size(), -1);
      answer[0] = start;
      visited[start] = true;
      if (TryFindPatternRecursive(start, pattern, visited, answer)) {
        return answer;
      }
      visited[start] = false;
    }
  }

  size_t Size() const {
    return adjacency_list_.size();
  }

 private:

  bool TryFindPatternRecursive(Vertex cur_v, string& pattern,
      vector<bool>& visited, vector<Vertex>& answer, size_t _i_=0) {

    if (_i_ >= pattern.size() || (pattern[ _i_ ] != Label(cur_v))) {
      return false;
    }

    if ( _i_ == pattern.size() - 1) {
      return true;
    }

    for (Vertex next: adjacency_list_[cur_v]) {
      if (visited[next]) {
        continue;
      }

      visited[next] = true;
      answer[ _i_ + 1 ] = next;

      if (TryFindPatternRecursive(next, pattern, visited, answer, _i_ + 1)) {
        return true;
      }

      answer[ _i_ + 1 ] = -1;
      visited[ next ] = false;
    }

    return false;
  }

 private:

  vector<set<Vertex> > adjacency_list_;
  map<Vertex, char> label_;
};

int main() {
  //////////////////////////////////////////////////////////////////

  size_t vertices_count, edges_count;
  string labels;

  cin >> vertices_count >> edges_count;
  cin >> labels;

  LabeledGraph g(vertices_count, labels);
  for (int e_num = 0; e_num < edges_count; ++e_num) {
    size_t v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    g.AddEdge(v1, v2);
  }

  string pattern;
  cin >> pattern;

  //////////////////////////////////////////////////////////////////

  vector<Vertex> answer = g.FindPattern(pattern);
  for (auto& v: answer) {
    cout << v + 1 << " ";
  }
  cout << endl;
} // main