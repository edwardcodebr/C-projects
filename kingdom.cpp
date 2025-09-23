#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int INF = 1000000000;

struct Pos { int r, c; Pos(): r(0), c(0) {} Pos(int rr,int cc): r(rr), c(cc) {} };

int rc_to_idx(int r, int c, int n) { return r * n + c; }
Pos idx_to_rc(int idx, int n) { return Pos(idx / n, idx % n); }
bool inside(int r, int c, int n) { return r >= 0 && r < n && c >= 0 && c < n; }

int ascii_of_col(int c) { char ch = char('a' + c); return int((unsigned char)ch); }

Pos parse_pos(const string &s) {
    char letter = s[0];
    string num = s.substr(1);
    int col = tolower(letter) - 'a';
    int row = atoi(num.c_str()) - 1;
    return Pos(row, col);
}

struct Edge { int to; int w; Edge(): to(0), w(0) {} Edge(int t,int ww): to(t), w(ww) {} };

struct Graph {
    int n, V;
    vector<vector<Edge>> adj;
    Graph(int nn=0) { init(nn); }
    void init(int nn) { n = nn; V = n * n; adj.assign(V, vector<Edge>()); }
    void build_knight_graph() {
        int dr[8] = {2,2,-2,-2,1,1,-1,-1};
        int dc[8] = {1,-1,1,-1,2,-2,2,-2};
        for (int r = 0; r < n; ++r) for (int c = 0; c < n; ++c) {
            int u = rc_to_idx(r,c,n);
            for (int k = 0; k < 8; ++k) {
                int rr = r + dr[k], cc = c + dc[k];
                if (inside(rr,cc,n)) {
                    int v = rc_to_idx(rr,cc,n);
                    int w = edge_weight(r,c,rr,cc);
                    adj[u].push_back(Edge(v,w));
                }
            }
        }
    }
    int edge_weight(int r1,int c1,int r2,int c2) const {
        int ascii_u = ascii_of_col(c1);
        int ascii_v = ascii_of_col(c2);
        int beta_u = r1 + 1;
        int beta_v = r2 + 1;
        return (ascii_u * beta_u + ascii_v * beta_v) % 19;
    }
    void sort_adjacency_lists() {
        for (int u = 0; u < V; ++u) {
            // insertion sort by target index
            for (size_t i = 1; i < adj[u].size(); ++i) {
                Edge key = adj[u][i];
                int j = (int)i - 1;
                while (j >= 0 && adj[u][j].to > key.to) {
                    adj[u][j+1] = adj[u][j];
                    --j;
                }
                adj[u][j+1] = key;
            }
        }
    }
};

struct MinHeap {
    vector<pair<int,int>> heap; // (dist, v)
    MinHeap() { heap.clear(); }
    bool empty() const { return heap.empty(); }
    void push(int d, int v) {
        heap.push_back(make_pair(d,v));
        int i = (int)heap.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p].first <= heap[i].first) break;
            swap(heap[p], heap[i]); i = p;
        }
    }
    pair<int,int> pop() {
        if (heap.empty()) return make_pair(INF, -1);
        pair<int,int> root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0;
        while (true) {
            int l = 2*i + 1, r = 2*i + 2, smallest = i;
            if (l < (int)heap.size() && heap[l].first < heap[smallest].first) smallest = l;
            if (r < (int)heap.size() && heap[r].first < heap[smallest].first) smallest = r;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
        return root;
    }
};

void dijkstra(const Graph &G, int src, vector<int> &dist, vector<int> &pred) {
    int V = G.V;
    dist.assign(V, INF);
    pred.assign(V, -1);
    MinHeap pq;
    dist[src] = 0;
    pq.push(0, src);
    while (!pq.empty()) {
        pair<int,int> t = pq.pop();
        int d = t.first, u = t.second;
        if (d != dist[u]) continue;
        for (const Edge &e : G.adj[u]) {
            int v = e.to, w = e.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pred[v] = u;
                pq.push(dist[v], v);
            }
        }
    }
}

vector<int> build_path(int src, int dest, const vector<int> &pred) {
    vector<int> tmp;
    int cur = dest;
    while (cur != -1) {
        tmp.push_back(cur);
        if (cur == src) break;
        cur = pred[cur];
    }
    vector<int> path;
    if (tmp.empty() || tmp.back() != src) return path;
    for (int i = (int)tmp.size()-1; i >= 0; --i) path.push_back(tmp[i]);
    return path;
}

struct Army {
    string color;
    int posIdx;
    vector<string> enemies;
    int moves;
    int weight_sum;
    bool arrived;
    bool stunned;
    Army(): posIdx(-1), moves(0), weight_sum(0), arrived(false), stunned(false) {}
};

bool is_enemy_by_names(const Army &a, const Army &b) {
    for (const string &s : a.enemies) if (s == b.color) return true;
    for (const string &s : b.enemies) if (s == a.color) return true;
    return false;
}

void remove_from_vec(vector<int> &v, int x) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == x) { v.erase(v.begin() + i); return; }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    int numArmies;
    cin >> numArmies;
    string line;
    getline(cin, line); // consume rest

    vector<Army> armies;
    armies.reserve(numArmies);
    for (int i = 0; i < numArmies; ++i) {
        getline(cin, line);
        while (line.size() == 0 && !cin.eof()) getline(cin, line);
        stringstream ss(line);
        string col, pos;
        ss >> col >> pos;
        Army a;
        a.color = col;
        Pos p = parse_pos(pos);
        a.posIdx = rc_to_idx(p.r, p.c, n);
        string e;
        while (ss >> e) a.enemies.push_back(e);
        armies.push_back(a);
    }

    string castlePos;
    cin >> castlePos;
    Pos castleP = parse_pos(castlePos);
    int castleIdx = rc_to_idx(castleP.r, castleP.c, n);

    int t; cin >> t;
    vector<int> tormentasIdx;
    for (int i = 0; i < t; ++i) {
        string ps; cin >> ps;
        Pos tp = parse_pos(ps);
        tormentasIdx.push_back(rc_to_idx(tp.r, tp.c, n));
    }

    Graph G(n);
    G.build_knight_graph();
    G.sort_adjacency_lists();

    // occupant lists per vertex
    vector<vector<int>> occupants(G.V);
    for (int i = 0; i < numArmies; ++i) {
        if (armies[i].posIdx >= 0 && armies[i].posIdx < G.V) occupants[armies[i].posIdx].push_back(i);
    }

    vector<int> tormenta_map(G.V, 0);
    for (int idx : tormentasIdx) if (idx >= 0 && idx < G.V) tormenta_map[idx] = 1;

    bool finished = false;
    vector<int> winners;
    int round = 0;

    while (!finished) {
        ++round;
        vector<char> moved_this_round(numArmies, false);
        vector<int> remove_tormenta_later;

        // movement order: in input order (index 0..numArmies-1)
        for (int ai = 0; ai < numArmies; ++ai) {
            if (armies[ai].arrived) continue;
            if (moved_this_round[ai]) continue;
            if (armies[ai].stunned) {
                armies[ai].stunned = false;
                moved_this_round[ai] = true;
                continue;
            }
            int pos = armies[ai].posIdx;
            // coalition at that position (current occupants)
            vector<int> coalition_all = occupants[pos];
            // moving members are those in coalition that have not yet moved this round
            vector<int> moving_members;
            for (int m : coalition_all) if (!moved_this_round[m]) moving_members.push_back(m);
            if (moving_members.empty()) {
                moved_this_round[ai] = true;
                continue;
            }

            vector<int> dist, pred;
            dijkstra(G, pos, dist, pred);
            if (dist[castleIdx] >= INF) {
                // no path, consume turn
                moved_this_round[ai] = true;
                continue;
            }
            vector<int> path = build_path(pos, castleIdx, pred);
            if (path.size() < 2) {
                moved_this_round[ai] = true;
                continue;
            }
            int nextv = path[1];
            bool hasTor = (tormenta_map[nextv] > 0);

            if (hasTor) {
                if ((int)coalition_all.size() >= 2) {
                    // coalition defeats storm and moves; move only moving_members
                    tormenta_map[nextv] = 0;
                    Pos u = idx_to_rc(pos, G.n);
                    Pos v = idx_to_rc(nextv, G.n);
                    int w = G.edge_weight(u.r, u.c, v.r, v.c);
                    for (int m : moving_members) {
                        remove_from_vec(occupants[armies[m].posIdx], m);
                        occupants[nextv].push_back(m);
                        armies[m].posIdx = nextv;
                        armies[m].moves += 1;
                        armies[m].weight_sum += w;
                        moved_this_round[m] = true;
                    }
                } else {
                    // single army fights and is stunned, it moves into storm cell and is stunned
                    int m = ai;
                    remove_from_vec(occupants[armies[m].posIdx], m);
                    occupants[nextv].push_back(m);
                    Pos u = idx_to_rc(pos, G.n);
                    Pos v = idx_to_rc(nextv, G.n);
                    int w = G.edge_weight(u.r, u.c, v.r, v.c);
                    armies[m].posIdx = nextv;
                    armies[m].moves += 1;
                    armies[m].weight_sum += w;
                    armies[m].stunned = true;
                    moved_this_round[m] = true;
                    remove_tormenta_later.push_back(nextv);
                }
                continue;
            }

            // no storm
            if (occupants[nextv].empty()) {
                // empty -> move moving_members
                Pos u = idx_to_rc(pos, G.n);
                Pos v = idx_to_rc(nextv, G.n);
                int w = G.edge_weight(u.r, u.c, v.r, v.c);
                for (int m : moving_members) {
                    remove_from_vec(occupants[armies[m].posIdx], m);
                    occupants[nextv].push_back(m);
                    armies[m].posIdx = nextv;
                    armies[m].moves += 1;
                    armies[m].weight_sum += w;
                    moved_this_round[m] = true;
                }
            } else {
                // occupied by other armies
                bool enemy = false;
                for (int a : moving_members) {
                    for (int b : occupants[nextv]) {
                        if (is_enemy_by_names(armies[a], armies[b])) { enemy = true; break; }
                    }
                    if (enemy) break;
                }
                if (enemy) {
                    // moving army ai loses its turn (consume ai's movement only)
                    moved_this_round[ai] = true;
                    continue;
                } else {
                    // ally -> move moving_members and join
                    Pos u = idx_to_rc(pos, G.n);
                    Pos v = idx_to_rc(nextv, G.n);
                    int w = G.edge_weight(u.r, u.c, v.r, v.c);
                    for (int m : moving_members) {
                        remove_from_vec(occupants[armies[m].posIdx], m);
                        occupants[nextv].push_back(m);
                        armies[m].posIdx = nextv;
                        armies[m].moves += 1;
                        armies[m].weight_sum += w;
                        moved_this_round[m] = true;
                    }
                }
            }
        } // end for each army this round

        // remove tormentas scheduled to be removed after the round
        for (int p : remove_tormenta_later) if (p >= 0 && p < G.V) tormenta_map[p] = 0;

        // check winners that reached castle this round
        winners.clear();
        for (int i = 0; i < numArmies; ++i) {
            if (!armies[i].arrived && armies[i].posIdx == castleIdx) {
                armies[i].arrived = true;
                winners.push_back(i);
            }
        }
        if (!winners.empty()) {
            finished = true;
            break;
        }

        // stop if nobody can reach
        bool any_can_move = false;
        for (int i = 0; i < numArmies; ++i) {
            if (armies[i].posIdx == castleIdx) continue;
            vector<int> dist, pred;
            dijkstra(G, armies[i].posIdx, dist, pred);
            if (dist[castleIdx] < INF) { any_can_move = true; break; }
        }
        if (!any_can_move) {
            finished = true;
            winners.clear();
            break;
        }
    } // end while rounds

    if (winners.empty()) return 0;

    struct OutRec { string color; int moves; int weight; };
    vector<OutRec> out;
    for (int idx : winners) {
        OutRec o; o.color = armies[idx].color; o.moves = armies[idx].moves; o.weight = armies[idx].weight_sum;
        out.push_back(o);
    }
    // insertion sort by color
    for (size_t i = 1; i < out.size(); ++i) {
        OutRec key = out[i];
        int j = (int)i - 1;
        while (j >= 0 && out[j].color > key.color) { out[j+1] = out[j]; --j; }
        out[j+1] = key;
    }
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i].color << ' ' << out[i].moves << ' ' << out[i].weight;
    }
    cout << "\n";
    return 0;
}
