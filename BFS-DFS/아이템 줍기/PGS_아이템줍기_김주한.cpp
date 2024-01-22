#include <string>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 52 * 2
#define FOR(i,s,e) for(int i=s; i<e; ++i)

/*
�˰� ������ ��

���� �����δ� ���ϴܺ��� (0,0)������
�� �ڵ�� �»���� (0,0)���� �����Ͽ����ϴ�.

���簢���� ũ��(or ��ǥ)�� 2�踦 �÷Ƚ��ϴ�.
��ǥ�״�� �Է��� ������ �׸������� �������ִ� ��ġ������ ����� ������ �ν��ϴ� ������ �־����ϴ�.
�̿� �Է¹��� ��ǥ�� 2�� �÷� ũ�� ���� 2��� �÷Ƚ��ϴ�.
ex) 0 : ����� / 1 : �簢�� ���� / 2 : �׵θ�
0 0 0 0 0 0 0 0 0
0 2 2 2 2 2 2 2 0   �簢���� 2��� �ø��� ������,
0 2 1 1 1 1 1 2 0   ���ʰ� ���� ������ ����ϴ�..
0 2 1 1 1 1 1 2 0   
0 2 2 2 1 1 2 2 0   ��밪 17
0 0 0 2 1 1 2 0 0   ������°� 16
0 0 2 2 1 1 2 2 2
0 0 2 1 1 1 1 1 2   ���� �׸��� �׷�����
0 0 2 2 2 1 2 2 2   (��, ��) ���� (5,4)�� (6,4) ������ �׵θ�(2) �̾�� �մϴ�.
0 0 0 0 2 2 2 0 0   ������ ��ǥ�� �״�� ����ϴٺ��� �Ʒ� �ڵ忡 ���ؼ� ������ �κ��̶� �׵θ��� �������� ���մϴ�.

�ι�� �ø��ٸ�?
�Ʒ��� �����ϴ�.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0     2��� �ø� ���)
0 2 2 2 2 2 2 2 2 2 2 2 2 2 0 0     ��ǥ 1 --2��--> (1 * 2) - 1 = 1
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0     ��ǥ 3 --2��--> (3 * 2) - 1 = 5
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0     �� �����ϴ�.
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0     ���� �Ǿ���� �׵θ��� �ٱ� ������ ����߸� �Ͱ� ���� ȿ���� ������ϴ�.
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 2 2 2 2 1 1 1 1 1 2 2 2 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 0 0 2 2 2 1 1 1 2 0 0 0 0
0 0 0 0 0 0 0 2 1 1 1 2 0 0 0 0
0 0 0 2 2 2 2 2 1 1 1 2 2 2 2 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 2 2 2 2 1 1 1 2 2 2 2 2
0 0 0 0 0 0 0 2 1 1 1 2 0 0 0 0
0 0 0 0 0 0 0 2 2 2 2 2 0 0 0 0

����) 2��� �ø��� �ʾҴٸ� Ȯ���غ��� �Ʒ� �׸�ó�� �νĵǾ����ϴ�.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 2 2 2 2 2 2 2 2 2 2 2 2 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 2 2 2 2 1 1 1 1 1 2 2 2 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 2 2 2 1 1 1 1 1 2 2 2 2 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 2 2 2 2 1 1 1 2 2 2 2 2
0 0 0 0 0 0 0 2 1 1 1 2 0 0 0 0
0 0 0 0 0 0 0 2 2 2 2 2 0 0 0 0
*/

int sq_map[N_MAX][N_MAX]; // ���簢���� �׷��� ���¸� ����
int map[N_MAX][N_MAX]; //
int route[N_MAX][N_MAX];

int dy[8] = { 0,1,0,-1,1,1,-1,-1 }; // �� �� �� �� (�밢�� * 4)
int dx[8] = { 1,0,-1,0,1,-1,1,-1 };

void create_rectangle(vector<int> rectangle_point) {
    /*
    sq_map�� ���簢���� �������ִ� �Լ�
    */
    int top_y = (rectangle_point[1] * 2) - 1; // �Է¹��� ���ϴ�y��ǥ�� ���y�� ����� ����
    int bottom_y = (rectangle_point[3] * 2) - 1; // �Է¹��� ����y��ǥ�� �ϴ�y�� ����� ����

    int front_x = (rectangle_point[0] * 2) - 1;
    int end_x = (rectangle_point[2] * 2) - 1;

    //-----------------------------------------------------
    // ���簢���� ������ 1�� ǥ����
    FOR(y, top_y, bottom_y + 1) {
        FOR(x, front_x, end_x + 1) {
            sq_map[y][x] = 1;
        }
    }
    //-----------------------------------------------------
}

bool isBorder(pair<int,int> now) {
    // �����¿� �밢���� Ž���� 0�� �������� Ȯ��
    FOR(i, 0, 8) {
        int ny = now.first + dy[i];
        int nx = now.second + dx[i];

        if (ny < 0 || ny>N_MAX || nx < 0 || nx>N_MAX) continue;

        if (sq_map[ny][nx] == 0) return true;
    }
    return false;
}

void draw_border(vector<int> rectangle_point) {
    /*
    bfs Ž������� ���� �׵θ��� ã��
    sq_map�󿡼� 1�� ��ǥ�� 
    �����¿� �׸��� �밢������ 0�� �����ϴٸ� �׵θ� ��.
    */
    queue<pair<int, int>> q;
    int used[N_MAX][N_MAX] = { 0, };

    int sy = (rectangle_point[1] * 2) - 1;
    int sx = (rectangle_point[0] * 2) - 1;

    q.push(make_pair(sy, sx));
    used[sy][sx] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        //-----------------------------------------
        // ���� ��ǥ�� �׵θ����� Ȯ��
        // �׵θ���� 2�� used�迭�� ����ص�
        if (isBorder(now) == true) {
            used[now.first][now.second] = 2;
        }
        //-----------------------------------------

        FOR(i, 0, 4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 1 || ny>N_MAX || nx < 1 || nx>N_MAX) continue; // ���� ũ�⸦ ���
            if (sq_map[ny][nx] != 1) continue; // ���簢���� �ƴ϶��
            if (used[ny][nx] != 0) continue; // �̹� �湮�ߴٸ�

            used[ny][nx] = 1;
            q.push(make_pair(ny, nx));
        }
    }

    //-------------------------------------------------
    // used�迭���� �׵θ� ������ route�迭�� ����
    FOR(y, 0, N_MAX) {
        FOR(x, 0, N_MAX) {
            if (used[y][x] == 2) route[y][x] = 1;
        }
    }
    //-------------------------------------------------
}


int find_route(int characterX, int characterY, int itemX, int itemY) {
    // bfs Ž���� �̿���
    // �׵θ� ������ ���� ���� �������� �ּҰŸ��� ã��
    queue<pair<int, int>> q;
    int used[N_MAX][N_MAX] = { 0, };


    // 2��� �ø� ��ǥ ����
    int sy = (characterY * 2) - 1;
    int sx = (characterX * 2) - 1;
    int gy = (itemY * 2) - 1;
    int gx = (itemX * 2) - 1;

    q.push(make_pair(sy, sx));
    used[sy][sx] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        FOR(i, 0, 4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 1 || ny>N_MAX || nx < 1 || nx>N_MAX) continue; // ���� ũ�⸦ ���
            if (route[ny][nx] != 1) continue; // �׵θ� ������ �ƴ϶��
            if (used[ny][nx] != 0) continue; // �̹� �湮�ߴٸ�

            used[ny][nx] = used[now.first][now.second] + 1;
            if ((ny == gy) && (nx == gx)) // �������� �ֿ�� ��������
                return used[ny][nx];
            q.push(make_pair(ny, nx));
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    // ���簢�� ���� ��ǥ�� ������� �Է¹޾� sq_map�� �׷��ݴϴ�.
    FOR(num, 0, rectangle.size()) {
        create_rectangle(rectangle[num]);
    }

    // ������ ���簢������ �׵θ����θ� �������ݴϴ�.
    draw_border(rectangle[0]);

    // ĳ���Ͱ� �����۱��� �����ϴ� �ּ� ��θ� �������ݴϴ�.
    // (������ 2)�� �� ������ ���簢���� ũ�⸦ 2��� �÷ȱ� �����Դϴ�.
    answer = (find_route(characterX, characterY, itemX, itemY) / 2);

    return answer;
}

int main() {
    vector<vector<int>> rectangle = {
        {1,1,7,4},
        {3,2,5,5},
        {4,3,6,9},
        {2,6,8,8}
    };
    int cx = 1;
    int cy = 3;
    int ix = 7;
    int iy = 8;

    solution(rectangle, cx, cy, ix, iy);
    return 0;
}