#include <bits/stdc++.h>
using namespace std;

struct edge {
  int from, to, w;
  edge(int from_, int to_, int w_) :
   from(from_), to(to_), w(w_)
  {}
};

struct fenvick {
  int n;
  vector<long long> tree;
  vector<int> a;

  fenvick(int n_=0) :
   n(n_)
   {
     tree.resize(n, 0LL);
     a.resize(n, 0LL);
   }

  int next(int i) {
    return (i & (i + 1)) - 1;
  }

  void add(int i, int delta) {
    while (i < n) {
      //  cerr << "tree[" << i << "] += " << delta << endl;
      tree[i] += delta;
      i = i | (i + 1);
    }
  }

  void set(int i, int new_val) {
    int prev_val = a[i];
    // cerr << "SET " << i << " -> " << new_val << ": " << "prev val = " << prev_val << endl;
    int delta = new_val - prev_val;
    a[i] = new_val;
    add(i, delta);
  }

  long long sum(int i) {
    // cerr << "tree query [0;" << i << "]\n";
    // print();
    long long ans = 0;
    while (i >= 0) {
      // cerr << "    at " << i << endl;
      ans += tree[i];
      i = next(i);
    }
    return ans;
  }

  void print() {
    cerr << "FENWICK:\n   tree: ";
    for (auto t_val: tree) {
      cerr << t_val << " ";
    }
    cerr << "\n      a: ";
    for (auto a_val: a) {
      cerr << a_val << " ";
    }
    cerr << endl;
  }
};

int cur_time = 1;
void dfs(int v, vector<vector<edge> > &g,
                vector<bool> &used,
                vector<edge> &edges,
                vector<int> &tms) {
    tms[v] = cur_time++;
    used[v] = true;
    for (auto e: g[v]) {
      if (!used[e.to]) {
        edges.emplace_back(v, e.to, e.w);
        dfs(e.to, g, used, edges, tms);
      }
    }
}

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<edge> > g(n);
  int center = -1;
  for (int i = 0; i < n - 1; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
  }

  for (int i = 0; i < n; ++i) {
    if (g[i].size() > 2) {
      center = i;
    }
  }

  if (center == -1) {
    center = 0;
  }

  // cerr << "CENTER: " << center + 1 << endl;
  vector<fenvick> trees;
  vector<bool> used(n, false);
  vector<int> tms(n);
  map<int, pair<int, int> > where;
  tms[center] = 0;
  used[center] = true;

  int cur_tree_i = 0;
  for (auto start_e: g[center]) {
    vector<edge> cur_edges;
    cur_edges.emplace_back(center, start_e.to, start_e.w);
    dfs(start_e.to, g, used, cur_edges, tms);

    trees.emplace_back(cur_edges.size());

    int local_i = 0;
    for (auto e: cur_edges) {
      trees.at(cur_tree_i).set(local_i, e.w);
      where[e.to] = {cur_tree_i, local_i};
      // cerr << "edge to " << e.to + 1 << ", w=" <<e.w << ", is #" << local_i
      //      << " at " << cur_tree_i << "th tree\n";
      local_i++;
    }

    // trees.at(cur_tree_i).print();
    cur_tree_i++;
  }

  // for (auto it: where) {
  //   cerr << it.first + 1 << " at " << "{" <<
  //           it.second.first << ":" <<
  //           it.second.second
  //           << "}\n";
  // }

  int q;
  cin >> q;
  for (int cur_q = 0; cur_q < q; cur_q++) {
    char q_type;
    cin >> q_type;
    int a, b, new_w;
    pair<int, int> location_a, location_b;
    long long ans;
    switch (q_type)
    {
      case 'c':
        cin >> a >> b >> new_w;
        a--;b--;
        if (tms[a] > tms[b]) {
          swap(a, b);
        }
        location_b = where[b];
        trees[location_b.first].set(location_b.second, new_w);
        // trees.at(location_b.first).print();
        break;
      case '?':
        cin >> a >> b;
        a--;b--;
        if (tms[a] > tms[b]) {
          swap(a, b);
        }
        if (a == center) {
          location_b = where[b];
          // cerr << b << "at {" << location_b.first << ": " << location_b.second << "}\n";
          ans = trees.at(location_b.first).sum(location_b.second);
        } else {
          location_a = where[a];
          location_b = where[b];

          // cerr << a + 1 << "at {" << location_a.first << ": " << location_a.second << "}\n";
          // cerr << b + 1 << "at {" << location_b.first << ": " << location_b.second << "}\n";
          if (location_a.first != location_b.first) {
            // different branches
            ans = trees.at(location_a.first).sum(location_a.second) +
                  trees.at(location_b.first).sum(location_b.second);
          } else {
            ans = trees.at(location_b.first).sum(location_b.second) -
                  trees.at(location_a.first).sum(location_a.second);
          }
        }
        cout << ans << endl;
    }
    // cerr << "############################\n";
  }

  return 0;
}
