#include <iostream>
#include <list>
#include <stdexcept>
using namespace std;

// === ESPEC-1: aliases ===
using Vertex = unsigned int;
using uint = unsigned int;

// === Class GraphAL ===
class GraphAL 
{
private:
    uint num_vertices;   // number of vertices
    uint num_edges;      // number of edges
    list<Vertex>* adj;   // adjacency list (array of lists)

public:
    // === ESPEC-3: Constructor ===
    GraphAL(uint num_vertices) 
    {
        this->num_vertices = num_vertices;
        this->num_edges = 0;
        adj = new list<Vertex>[num_vertices];
    }

    // === ESPEC-4: Destructor ===
    ~GraphAL() {
        delete[] adj;
        adj = nullptr;
    }

    uint get_num_vertices() const 
    {
        return num_vertices;
    }

    uint get_num_edges() const 
    {
        return num_edges;
    }

    // === ESPEC-5: add_edge ===
    void add_edge(const Vertex& u, const Vertex& v) 
    {
        if (u >= num_vertices || v >= num_vertices || u == v) 
        {
            throw invalid_argument("invalid edge");
        }

        // avoid duplicates
        for (auto x : adj[u]) 
        {
            if (x == v) return;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
        num_edges++;
    }

    // === ESPEC-6: get_adj ===
    const list<Vertex>& get_adj(const Vertex& u) const 
    {
        if (u >= num_vertices) 
        {
            throw invalid_argument("invalid vertex");
        }
        return adj[u];
    }

    // === Print adjacency matrix ===
    static void print_adjacency_matrix(const GraphAL& g) 
    {
        cout << "num_vertices: " << g.get_num_vertices() << "\n";
        cout << "num_edges: " << g.get_num_edges() << "\n";

        uint n = g.get_num_vertices();

        for (uint i = 0; i < n; i++) 
        {
            for (uint j = 0; j < n; j++) 
            {
                bool connected = false;
                for (auto v : g.get_adj(i)) 
                {
                    if (v == j) 
                    {
                        connected = true;
                        break;
                    }
                }
                cout << (connected ? 1 : 0);
                if (j < n - 1) cout << " ";
            }
            cout << "\n";
        }
    }
};

// === ESPEC-8: main ===
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint n = 0, m = 0;
    cin >> n >> m;

    GraphAL graph(n);

    uint u = 0, v = 0;
    for (uint i = 0; i < m; i++) 
    {
        cin >> u >> v;
        try {
            graph.add_edge(u, v);
        } catch (invalid_argument& e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }

    GraphAL::print_adjacency_matrix(graph);

    return 0;
}