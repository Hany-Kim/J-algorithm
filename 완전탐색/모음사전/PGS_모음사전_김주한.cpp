#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

int start_num;
string path = "_____";
string v = "AEIOU";
int ans;

bool mstrcmp(string word) {
    /*
    path�� word�� _�� ����� �ڸ����� ����

    ���� ���ڿ��̸� true
    �ٸ� ���ڿ��̸� false
    ����
    */
    FOR(i, 0, (path.size() - word.size())) {
        word += "_";
    }
    FOR(i, 0, word.size()) {
        if (word[i] != path[i]) {
            return false;
        }
    }

    return true;
}

void output(string word) {
    /*
    ���� ������ ���°���� ���÷� ������Ʈ ����
    ã�ƾ��ϴ� �ܾ�� ���ٸ� ���°���� üũ�ص�
    */
    start_num += 1;
    /*cout << start_num << " ";
    FOR(i, 0, path.size()) {
        if (path[i] == '_')continue;
        cout << path[i];
    }
    cout << '\n';*/
    if (mstrcmp(word) == true) ans = start_num;
}

int solution(string word) {
    int answer = 0;


    FOR(a, 0, v.size()) {
        //nothing
        path[0] = v[a];
        output(word);
        FOR(b, 0, v.size()) {
            //nothing
            path[1] = v[b];
            output(word);
            FOR(c, 0, v.size()) {
                //nothing
                path[2] = v[c];
                output(word);
                FOR(d, 0, v.size()) {
                    //nothing
                    path[3] = v[d];
                    output(word);
                    FOR(e, 0, v.size()) {
                        path[4] = v[e];
                        output(word);
                        path[4] = '_';
                    }
                    path[3] = '_';
                }
                path[2] = '_';
            }
            path[1] = '_';
        }
        path[0] = '_';
    }
    answer = ans;

    return answer;
}