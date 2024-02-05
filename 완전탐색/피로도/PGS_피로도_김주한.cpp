#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

vector<int> path; // ���� ���
vector<int> used; // �̹� ����� ���� üũ
int cnt; // �ִ� ���� Ƚ�� ����

void backTracking(int k, vector<vector<int>> dg, int lv) {
    if (lv == dg.size()) {
        int cur_k = k; // ���� �������� ���� �Ƿε� ���
        int cur_size = path.size();
        int cur_cnt = 0; // ���� �������� ������ �� �ִ� �ִ� ���� ��
        FOR(i, 0, cur_size) {
            if (cur_k < dg[path[i]][0]) { // �ּ� �ʿ� �Ƿε����� ������ ��
                break;
            }
            cur_k -= dg[path[i]][1]; // �Ҹ� �Ƿε� ����
            cur_cnt += 1; // ���� �� ����
        }

        cnt = max(cnt, cur_cnt);
        return;
    }

    FOR(i, 0, dg.size()) {
        if (used[i] == 1) continue;
        path.push_back(i);
        used[i] = 1;
        backTracking(k, dg, lv + 1);
        used[i] = 0;
        path.pop_back();
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    used = vector<int>(dungeons.size(), 0);
    backTracking(k, dungeons, 0);

    answer = cnt;
    return answer;
}