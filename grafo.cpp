#include <iostream>
#include <list>
#include <stdexcept>

typedef unsigned int uint;
typedef unsigned int Vertex;

class grafo {
private:
    uint num_vertices;
    uint num_edges;
    std::list<Vertex>* adjacente;

public:
    grafo() : num_vertices(0), num_edges(0), adjacente(nullptr) {}

    grafo(uint n) : num_vertices(n), num_edges(0) {
        adjacente = new std::list<Vertex>[n];
    }

    ~grafo() {
        delete[] adjacente;
    }

    void add_edge(Vertex u, Vertex v) {
        if (u >= num_vertices || v >= num_vertices) {
            throw std::invalid_argument("\nAresta inválida\n");
        }
        adjacente[u].push_back(v);
        adjacente[v].push_back(u);
        num_edges++;
    }

    std::list<Vertex> get_adjacente(Vertex u) {
        if (u >= num_vertices) {
            throw std::invalid_argument("\nVértice inválido\n");
        }
        return adjacente[u];
    }

    uint get_num_vertices() const {
        return num_vertices;
    }

    uint get_num_edges() const {
        return num_edges;
    }
};

void print_grafo(const grafo& g) {
    for (uint i = 0; i < g.get_num_vertices(); ++i) {
        std::cout << i << ": ";
        std::list<Vertex> adj = g.get_adjacente(i);
        for (auto v : adj) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    grafo g(5);

    g.add_edge(0,3);
    g.add_edge(0,1);
    g.add_edge(3,2);
    g.add_edge(3,0);
    g.add_edge(1,3);
    g.add_edge(1,2);
    g.add_edge(2,1);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,3);

    print_grafo(g);

    return 0;
}
