#include <iostream>
#include <vector>
#include <stdexcept>

typedef unsigned int uint;
typedef unsigned int Vertex;

// -------------------
// Grafo NÃO PONDERADO
// -------------------
class MatrizGraph {
private:
    uint num_vertices;
    uint num_edges;
    std::vector<std::vector<int>> matriz;

public:
    MatrizGraph(uint n) : num_vertices(n), num_edges(0) {
        matriz.assign(n, std::vector<int>(n, 0));
    }

    void add_edge(Vertex u, Vertex v) {
        if (u >= num_vertices || v >= num_vertices) {
            throw std::invalid_argument("Aresta inválida");
        }
        matriz[u][v] = 1;
        matriz[v][u] = 1; // não direcionado
        num_edges++;
    }

    uint get_num_vertices() const { return num_vertices; }
    uint get_num_edges() const { return num_edges; }

    const std::vector<std::vector<int>>& get_matriz() const {
        return matriz;
    }
};

// -------------------
// Grafo PONDERADO
// -------------------
class MatrizGraphPonderado {
private:
    uint num_vertices;
    uint num_edges;
    std::vector<std::vector<int>> matriz;

public:
    MatrizGraphPonderado(uint n) : num_vertices(n), num_edges(0) {
        matriz.assign(n, std::vector<int>(n, 0));
    }

    void add_edge(Vertex u, Vertex v, int peso) {
        if (u >= num_vertices || v >= num_vertices) {
            throw std::invalid_argument("Aresta inválida");
        }
        matriz[u][v] = peso;
        matriz[v][u] = peso; // não direcionado
        num_edges++;
    }

    uint get_num_vertices() const { return num_vertices; }
    uint get_num_edges() const { return num_edges; }

    const std::vector<std::vector<int>>& get_matriz() const {
        return matriz;
    }
};

// -------------------
// Funções de impressão
// -------------------
void print_matriz(const MatrizGraph& g) {
    std::cout << "\nMatriz de Adjacência (não ponderado):\n";
    for (uint i = 0; i < g.get_num_vertices(); i++) {
        for (uint j = 0; j < g.get_num_vertices(); j++) {
            std::cout << g.get_matriz()[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void print_matriz(const MatrizGraphPonderado& g) {
    std::cout << "\nMatriz de Adjacência (ponderado):\n";
    for (uint i = 0; i < g.get_num_vertices(); i++) {
        for (uint j = 0; j < g.get_num_vertices(); j++) {
            std::cout << g.get_matriz()[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// -------------------
// Programa principal
// -------------------
int main() {
    // Grafo não ponderado
    MatrizGraph g1(5);
    g1.add_edge(0, 1);
    g1.add_edge(0, 3);
    g1.add_edge(1, 2);
    g1.add_edge(3, 4);

    // Grafo ponderado
    MatrizGraphPonderado g2(5);
    g2.add_edge(0, 1, 5);
    g2.add_edge(0, 3, 2);
    g2.add_edge(1, 2, 3);
    g2.add_edge(3, 4, 4);

    print_matriz(g1);
    print_matriz(g2);

    return 0;
}
