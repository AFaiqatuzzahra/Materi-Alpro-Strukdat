#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Graph {
public:
    int V;
    vector<list<int>> adj;

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // Graf tidak berarah
    }

    // BFS untuk traversal graf
    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            s = q.front();
            cout << s << " ";
            q.pop();

            for (auto i : adj[s]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

// Preorder traversal untuk pohon
void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // Contoh graf
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS traversal dari simpul 2: ";
    g.BFS(2);

    // Contoh pohon
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal dari pohon: ";
    preorderTraversal(root);

    return 0;
}

