#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
struct A {
	ll dx,dy;
	bool friend operator < (A &p, A &q) { //기울기 내림차순 정렬
		return (p.dx*q.dy > p.dy*q.dx);
	}
};
int n, m=0;
pii a[1509];
A b[1500]; //다른 점과의 벡터 pair
ll res=0;
bool able(A &p, A &q) {
	return p.dx*q.dx + p.dy*q.dy > 0; //내적이 양수인지
}
bool eqq(A &p, A &q) {
	return p.dx*q.dx + p.dy*q.dy == 0; //내적이 0인지
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	for (int i=0;i<n;++i) cin>>a[i].first>>a[i].second;
	for (int ii=0;ii<n;++ii) { //기준점
		m = 0;
		for (int j=0;j<n;++j) { //비교점들
			if (j == ii)continue;
			b[m].dx = a[j].first - a[ii].first;
			b[m].dy = a[j].second - a[ii].second;
            //1사분면으로 두기
			if (b[m].dy < 0) { //y좌표 양수로 변환
				b[m].dy = -b[m].dy;
				b[m].dx = -b[m].dx;
			}
			if (b[m].dy == 0)
				if (b[m].dx < 0)
					b[m].dx = -b[m].dx; //x좌표 양수로 변환
			++m;
		}
		sort(b,b+m);
        //투포인터
		int si = 0; //현재 탐색 중인 벡터 그룹의 시작 인덱스.
		int ei = 0; //현재 직각을 이룰 수 있는 벡터의 끝 인덱스.
		while (ei<m) {
			int tsi, tei;
			for (tsi = si; tsi < m; tsi++)
				if (b[si] < b[tsi])
					break;
			while (ei < m && able(b[si], b[ei])) { //내적이 양수 = 둔각
				ei++;
			}
			while (ei < m && eqq(b[si], b[ei])) { res+=(tsi-si); ei++; } //내적이 0 = 직각
			si = tsi;
		}
	}
	cout<<res;
}