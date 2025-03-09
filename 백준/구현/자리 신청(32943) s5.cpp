#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
struct Person {
    ll t,s,n; // 좌석 시간, 좌석 번호, 학생의 학번
};
vector<Person> log;
ll x,c,k;
bool cmp(Person &a,Person &b) {
    return a.t < b.t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>x>>c>>k; // 학생 수, 좌석 개수, 로그 개수수
    for (int i=0;i<k;++i) {
        int t,s,n;
        cin>>t>>s>>n;
        log.push_back({t,s,n});
    }
    sort(log.begin(),log.end(),cmp);
    unordered_map<int, int> studentSeat; // {학생 번호: 배정된 좌석}
    unordered_map<int, int> seatOwner;   // {좌석 번호: 학생 번호}

    for (const auto &person : log) {
        int time = person.t, seat = person.s, student = person.n;

        // 이미 해당 좌석이 신청된 상태라면 무효
        if (seatOwner.find(seat) != seatOwner.end()) continue;

        // 기존에 좌석을 가지고 있다면, 반납 처리
        if (studentSeat.find(student) != studentSeat.end()) {
            int prevSeat = studentSeat[student];
            seatOwner.erase(prevSeat);
        }

        // 새로운 좌석 배정
        studentSeat[student] = seat;
        seatOwner[seat] = student;
    }

    // 학번 오름차순
    vector<pair<int, int>> result;
    for (const auto &entry : studentSeat) {
        result.emplace_back(entry.first, entry.second);
    }
    sort(result.begin(), result.end());
    for (const auto &entry : result) {
        cout << entry.first << " " << entry.second << "\n";
    }
}