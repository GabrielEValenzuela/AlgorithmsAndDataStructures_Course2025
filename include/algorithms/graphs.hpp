#ifndef GRAPH_ALGORITHMS_HPP
#define GRAPH_ALGORITHMS_HPP

#include <functional>
#include <unordered_map>
#include <vector>

namespace graph
{

    /**
     * @brief Búsqueda en profundidad (DFS) en grafo representado por lista de adyacencia
     *
     * @tparam TData Tipo de los nodos
     * @param graph Diccionario de nodos y sus vecinos
     * @param start Nodo inicial
     * @param visit Función callback para cada nodo
     */
    template<typename TData>
    void depthFirstSearch(const std::unordered_map<TData, std::vector<TData>>& graph,
                          const TData& start,
                          const std::function<void(const TData&)>& visit);

    /**
     * @brief Búsqueda en amplitud (BFS) en grafo representado por lista de adyacencia
     */
    template<typename TData>
    void breadthFirstSearch(const std::unordered_map<TData, std::vector<TData>>& graph,
                            const TData& start,
                            const std::function<void(const TData&)>& visit);

    /**
     * @brief Algoritmo de Dijkstra para caminos mínimos desde un nodo origen
     */
    template<typename TData>
    std::unordered_map<TData, int> dijkstra(const std::unordered_map<TData, std::vector<std::pair<TData, int>>>& graph,
                                            const TData& start);

    /**
     * @brief Algoritmo de Bellman-Ford para grafos con pesos negativos
     */
    template<typename TData>
    std::unordered_map<TData, int> bellmanFord(const std::vector<std::tuple<TData, TData, int>>& edges,
                                               const TData& start);

    /**
     * @brief Floyd-Warshall: todos los pares de caminos mínimos
     */
    template<typename TData>
    void floydWarshall(std::vector<std::vector<int>>& matrix);

    /**
     * @brief Algoritmo de Prim para árbol de expansión mínima
     */
    template<typename TData>
    void prim(const std::unordered_map<TData, std::vector<std::pair<TData, int>>>& graph, const TData& start);

    /**
     * @brief Algoritmo de Kruskal para árbol de expansión mínima
     */
    template<typename TData>
    std::vector<std::tuple<TData, TData, int>> kruskal(const std::vector<std::tuple<TData, TData, int>>& edges);

} // namespace graph

#endif // GRAPH_ALGORITHMS_HPP
