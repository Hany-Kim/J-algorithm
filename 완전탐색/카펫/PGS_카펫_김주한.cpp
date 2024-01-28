#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

vector<int> length_v; // ��� ����
vector<int> width_v; // ��� ����

void get_divisor(int num) {
    /*
    num�� ���� ����� ã�� �Լ�
    */
    FOR(i, 1, num + 1) {
        if ((num % i) != 0) continue; // ������ �������� ������ ����� �ƴ�
        if (i > (num / i)) break; // ���� ���̰� ���� ���̺��� ��� �ȵ�
        length_v.push_back(i);
        width_v.push_back(num / i);
    }
}

bool isSame(int n1, int n2, int brown) {
    /*
    yellow�� ���ΰ� �ִ� brown�� ũ��� �׻�
    yellow�� ���α����� 2��, ���α����� 2�迡 ������ 4���� ���� ���̴�.
    */
    int width = n2 * 2;
    int length = n1 * 2;
    int corner = 4;

    /*
    num�� yellow�� ũ�⿡ ���� �׵θ��� ���� ũ��
    */
    int num = width + length + corner;

    if (num == brown) return true; // brown�� ���ٸ� ã���� �ϴ� ���� ���� ������
    else return false;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    get_divisor(yellow);

    FOR(i, 0, length_v.size()) {
        if (isSame(length_v[i], width_v[i], brown) == true) {
            answer.push_back(width_v[i] + 2);
            answer.push_back(length_v[i] + 2);
        }
    }

    return answer;
}