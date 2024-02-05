#include <math.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)
#define N_MAX 101

vector<vector<int>> graph;
vector<vector<int>> map;
vector<int> used;

void bfs(int node, int num) {
    queue<int> q;

    q.push(node);
    used[node] = num;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        FOR(i, 0, map[now].size()) {
            if (map[now][i] == 0) continue;
            if (used[i] != 0) continue;
            used[i] = num;
            q.push(i);
        }
    }
}

int divide_net() {
    int my_abs = -1;
    int num = 1;

    used = vector<int>(N_MAX, 0);
    FOR(y, 0, map.size()) {
        FOR(x, 0, map[y].size()) {
            if (map[y][x] == 0) continue;
            if (used[x] != 0) continue;
            bfs(x, num++); // Ʈ���� ����� ���� ã��
        }
    }
    
    if (num == 2) { // Ʈ���� ���1���� �̷���� �и�, (num�� 1�� Ʈ�� �� num��ȣ�� ���� ���� ���)
        int fir = 0, sec = 0;
        FOR(i, 1, N_MAX) {
            if (used[i] == 1) fir += 1;
            if (used[i] == 0) sec += 1;
        }
        my_abs = abs(fir - sec);
    }
    else if (num == 3) { // �ΰ��� Ʈ���� �̷���� �и�, (num�� 1�� Ʈ�� �� num�� 2�� Ʈ��)
        int fir = 0, sec = 0;
        FOR(i, 1, N_MAX) {
            if (used[i] == 1) fir += 1;
            if (used[i] == 2) sec += 1;
        }
        my_abs = abs(fir - sec);
    }
    // �������� ���� �������� Ʈ���� �����⶧���� ó�� �ʿ����.

    return my_abs;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int min_abs = 2134567890; // ���� ������ �ּڰ� ����

    // wires�� ���� ������ graph��� ���¸� �׸�
    graph = vector<vector<int>>(N_MAX, vector<int>(N_MAX, 0));
    FOR(i, 0, wires.size()) {
        graph[wires[i][0]][wires[i][1]] = 1;
        graph[wires[i][1]][wires[i][0]] = 1;
    }

    // graph ����� map�� �����ϰ�
    // ����� ���� �ϳ��� ����� �и�
    FOR(y, 0, graph.size()) {
        FOR(x, 0, graph[y].size()) {
            if (graph[y][x] == 0) continue;
            map = graph;
            map[y][x] = 0;
            map[x][y] = 0;
            int my_abs = divide_net();
            if(my_abs != -1) min_abs = min(my_abs, min_abs);
        }
    }

    answer = min_abs;
    return answer;
}