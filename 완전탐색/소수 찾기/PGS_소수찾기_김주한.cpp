#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 10000000
#define FOR(i,s,e) for(int i=s; i<e; ++i)

vector<int> v;
bool arr[N_MAX];
int num;
vector<int> ans;
vector<int> used;

void dfs(int max_lv, int lv, int n) {
    if (max_lv == lv) {
        if (arr[n] == true)  ans.push_back(n);
        return;
    }
    FOR(i, 0, v.size()) {
        if (used[i] == 1) continue;
        used[i] = 1;
        n = (n * 10) + v[i];
        dfs(max_lv, lv + 1, n);
        n = (n / 10);
        used[i] = 0;
    }
}

int solution(string numbers) {
    int answer = 0;

    //-----------------------------------------------------
    //���ڿ����� �� ���� ī�带 '���� ��' ����
    FOR(i, 0, numbers.length()) {
        v.push_back(int(numbers[i] - '0'));
    }
    //-----------------------------------------------------


    //-----------------------------------------------------
    //���� ū ���� Ȯ���ϱ� ���� ������������ ����
    sort(v.begin(), v.end(), greater<int>());

    // num������ ���� ū �� ����
    FOR(i, 0, v.size()) {
        num = (num * 10) + v[i];
    }
    //-----------------------------------------------------

    
    //-----------------------------------------------------
    // �Ҽ�Ȯ�� �� �Ǻ��ϱ� ���� arr�迭 �ʱ�ȭ
    // �Ҽ���� true, �ƴ϶�� false
    memset(arr, true, sizeof(arr));
    
    // 0�� 1�� �Ҽ��� �ƴϴ�.
    arr[0] = false;
    arr[1] = false;

    // ���� ū �� 9999999�̹Ƿ� �迭�� ũ��� 10000000
    // ī�� ���� �� ���� �� �ִ� ���� ū ��(num)���� �Ҽ� �Ǻ��� �Ѵ�.
    FOR(i, 1, 10000000) {
        if (arr[i] == false) continue;
        for (int j = i * 2; j <= num; j += i) {
            arr[j] = false;
        }
    }
    //-----------------------------------------------------

    //-----------------------------------------------------
    // ī�带 ������ ���� �� �ִ� ��� ���� ���Ѵ�.
    FOR(i, 1, v.size() + 1) {
        used = vector<int>(v.size(), 0);
        dfs(i, 0, 0);
    }
    //-----------------------------------------------------

    
    //-----------------------------------------------------
    // �ߺ� ���� ó��
    
    // �ߺ��� �����ϱ� ���� ������ �Ѵ�.
    sort(ans.begin(), ans.end());
    // unique()�� �ߺ��� ���� vector�� ���� �ڷ� ������
    // �̷��� ���� ���� ���� ��ġ�� ��ȯ�Ѵ�.
    // erase()�� ����� �ߺ����� �����ϴ� ��ġ���� ������ �����ش�.
    ans.erase(unique(ans.begin(), ans.end()),ans.end());
    //-----------------------------------------------------

    answer = ans.size();
    return answer;
}