#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Hàm duyệt BFS
void BFS_AdjMatrix(vector<vector<int>> &adjMatrix, int start) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS (Ma trận lân cận): ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << char('a' + node) << " ";

        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// Hàm duyệt DFS
void DFS_AdjMatrix(vector<vector<int>> &adjMatrix, int start) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    cout << "DFS (Ma trận lân cận): ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            cout << char('a' + node) << " ";
            visited[node] = true;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (adjMatrix[node][i] && !visited[i]) {
                s.push(i);
            }
        }
    }
    cout << endl;
}

// Hàm duyệt BFS (Danh sách lân cận)
void BFS_AdjList(vector<vector<int>> &adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS (Danh sách lân cận): ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << char('a' + node) << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// Hàm duyệt DFS (Danh sách lân cận)
void DFS_AdjList(vector<vector<int>> &adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    cout << "DFS (Danh sách lân cận): ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            cout << char('a' + node) << " ";
            visited[node] = true;
        }

        for (int i = adjList[node].size() - 1; i >= 0; i--) {
            int neighbor = adjList[node][i];
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 7; // Số đỉnh (a, b, c, d, e, f, g)
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0)); // Ma trận lân cận
    vector<vector<int>> adjList(n);                      // Danh sách lân cận

    // Nhập đồ thị
    cout << "Nhập thông tin đồ thị (Ma trận lân cận):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j]) {
                adjList[i].push_back(j);
            }
        }
    }

    // In kết quả duyệt BFS và DFS
    BFS_AdjMatrix(adjMatrix, 0);
    DFS_AdjMatrix(adjMatrix, 0);
    BFS_AdjList(adjList, 0);
    DFS_AdjList(adjList, 0);

    return 0;
}
