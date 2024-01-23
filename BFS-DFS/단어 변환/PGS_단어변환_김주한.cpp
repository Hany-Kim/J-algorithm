#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

string path[51]; // ����� ���ڸ� ����ص� �迭
vector<bool> used; // ����� ���ڸ� ����� �迭
int min_num = 2134567890; 

int mstrcmp(string str1, string str2) {
    int diff = 0; // �� ���ڿ����� "���� �ڸ�"�� "���� ����"��� ī�������ִ� ����
    
    FOR(i, 0, str1.size()) {
        if (str1[i] == str2[i]) ++diff;
    }

    return diff;
}

void dfs(string begin, string target, vector<string> words, int lv) {
    // ---------------------------------------------------
    // Ÿ�� ���ڿ� ������ 
    // �ּ� ���� Ƚ���� ������Ʈ �� return
    if (path[lv - 1] == target) {
        if (min_num > (lv - 1)) {
            min_num = lv - 1;
        }
        return;
    }
    // ---------------------------------------------------

    FOR(i, 0, words.size()) {
        // �̹� ��ȯ�ߴ� �ܾ�� �ǳ� ��
        if (used[i] == true) continue;

        // ---------------------------------------------------
        // mstrcmp() �Լ��� �� ���ڿ��� �� ��
        // ���� �ڸ��� ���� ������ ���� return ����
        // ex) aba, aaa => return 2
        //     abc, aaa => return 1
        // 
        // �ܾ��� ���̴� ���� ������ begin ���ڿ��� �������� ����.
        // return�� ���� ���ڿ� ���̿��� 1�� ���ٸ�
        // ���� �ܰ�� ��ȯ�� ������ �ܾ�� �Ǵ�
        // ex) aba, aaa => return 2 | ��ȯ �Ҽ� �ִ� ����
        //     abc, aaa => return 1 | ��ȯ�� �� ���� ����
        if (mstrcmp(path[lv - 1], words[i]) == begin.size() - 1) {
            path[lv] = words[i]; // ����� �ܾ��� �α� ���
            used[i] = true; // ����ߴ� �ܾ� ó��
            dfs(begin, target, words, lv + 1);
            used[i] = false;
            path[lv] = "";
        }
        // ---------------------------------------------------

    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    used = vector<bool>(words.size(), false);

    // ��Ʈ��ŷ ������� ���� �ذ� ----------------------
    path[0] = begin;
    dfs(begin, target, words, 1);
    // ---------------------------------------------------


    // ---------------------------------------------------
    // �ּڰ��� ���� ���� �ʾҴٸ� answer�� 0
    // �ּڰ��� ���� �Ǿ��ٸ� answer�� �ּڰ�
    if (min_num == 2134567890)
        answer = 0;
    else
        answer = min_num;
    // ---------------------------------------------------

    return answer;
}

int main() {
    //freopen("input.txt", "r", stdin);
    string begin = "aoa";
    string target = "aof";
    vector<string> words = { "aob", "aoc", "aod", "aof", "aoe" };

    solution(begin, target, words);
    return 0;
}