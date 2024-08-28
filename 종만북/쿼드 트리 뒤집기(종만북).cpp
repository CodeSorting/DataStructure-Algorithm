#include <iostream>
#include <string>
using namespace std;

string reverse_quadtree(string::iterator& it);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c=0;
    string quadtree;
    cin >>c;
    for (int i=0;i<c;i++) {
        cin >> quadtree;
        string::iterator iter = quadtree.begin();
        string ans = reverse_quadtree(iter);
        cout << ans <<'\n';
    }
}

string reverse_quadtree(string::iterator& it) {
    char head = *it;
    it+=1;
    if (head =='b' || head=='w') {
        return string(1,head);
    }
    string upperLeft = reverse_quadtree(it);
    string upperRight = reverse_quadtree(it);
    string lowerLeft = reverse_quadtree(it);
    string lowerRight = reverse_quadtree(it);
    //각각 위와 아래 조각들의 위치를 바꾼다.
    return 'x'+lowerLeft+lowerRight+upperLeft+upperRight;
}