#ifndef TREE_SEARCH_HPP
#define TREE_SEARCH_HPP

#include <functional>

namespace tree
{

    /**
     * @brief Recorrido in-order (DFS) de un árbol binario
     */
    template<typename TNode>
    void inOrder(const TNode* node, const std::function<void(const TNode*)>& visit);

    /**
     * @brief Recorrido pre-order (DFS) de un árbol binario
     */
    template<typename TNode>
    void preOrder(const TNode* node, const std::function<void(const TNode*)>& visit);

    /**
     * @brief Recorrido post-order (DFS) de un árbol binario
     */
    template<typename TNode>
    void postOrder(const TNode* node, const std::function<void(const TNode*)>& visit);

    /**
     * @brief Recorrido en amplitud (BFS) usando una cola
     */
    template<typename TNode>
    void breadthFirst(const TNode* root, const std::function<void(const TNode*)>& visit);

    /**
     * @brief Búsqueda de un valor usando DFS
     */
    template<typename TNode, typename TKey>
    const TNode* depthFirstSearch(const TNode* node, const TKey& target);

    /**
     * @brief Búsqueda de un valor usando BFS
     */
    template<typename TNode, typename TKey>
    const TNode* breadthFirstSearch(const TNode* root, const TKey& target);

} // namespace tree

#endif // TREE_SEARCH_HPP
