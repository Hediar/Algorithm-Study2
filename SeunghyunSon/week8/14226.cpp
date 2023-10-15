#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Emoticon {
    int display;
    int clipboard;
    int time;

    Emoticon(int d, int c, int t) : display(d), clipboard(c), time(t) {}
};

int BFS(int S) {

    queue<Emoticon> q;
    q.push(Emoticon(1, 0, 0));

    vector<vector<bool>> visit(1001, vector<bool>(1001, false));
    visit[1][0] = true;

    while (!q.empty()) {
        Emoticon e = q.front();
        q.pop();

        if (e.display == S) {
            return e.time;
        }

        if (0 < e.display && e.display <= 1000) {
            e.time++;

            if (!visit[e.display][e.display]) {
                visit[e.display][e.display] = true;
                q.push(Emoticon(e.display, e.display, e.time));
            }

            if (e.clipboard > 0 && e.display + e.clipboard <= 1000) {
                if (!visit[e.display + e.clipboard][e.clipboard]) {
                    visit[e.display + e.clipboard][e.clipboard] = true;
                    q.push(Emoticon(e.display + e.clipboard, e.clipboard, e.time));
                }
            }

            if (!visit[e.display - 1][e.clipboard]) {
                visit[e.display - 1][e.clipboard] = true;
                q.push(Emoticon(e.display - 1, e.clipboard, e.time));
            }
        }
    }

    return -1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int S;
    cin >> S;

    int ans = BFS(S);
    cout << ans;

    return 0;
}
