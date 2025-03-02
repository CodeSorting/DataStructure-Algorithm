#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll n, t;
ll arr[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    int x = 1, step = 0;
    unordered_map<int, int> visited; // 노드 방문 시 step 저장
    while (visited.find(x) == visited.end()) { 
        visited[x] = step;
        x = arr[x];
        ++step;
    }

    int cycle_start = visited[x];   // 사이클 시작점
    int cycle_length = step - cycle_start; // 사이클 길이

    if (t >= cycle_start) {
        t = (t - cycle_start) % cycle_length + cycle_start; // 처음부터 사이클이 아닐수도 있으니 t-cycle_start 하고 cycle_length로 나눈다.
        //처음에 cycle_start를 뺐으니 나중에 다시 더해줘서 보정한다.
    }

    int cur = 1;
    while (t--) {
        cur = arr[cur];
    }
    cout << cur;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int N, a[104], vis[104];
lint T;

int main() {
  cin >> N >> T;
  for (int i = 1; i <= N; i++) cin >> a[i];

  vector<int> v;

  int now = 1;
  while (true) {
    if (vis[now]) break;
    vis[now] = true;
    v.push_back(now);

    now = a[now];
  }

  int idx = 0;
  while (v[idx] != now) idx++;

  if (T < v.size()) {
    cout << v[T] << '\n';
  } else {
    cout << v[idx + (T - idx) % (v.size() - idx)] << '\n';
  }
}
*/