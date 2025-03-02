#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 10;
int t,n;
struct Trie{
  Trie* go[MAX]; //다음 노드를 가리키는 포인터 배열
  bool output; //이 노드에서 끝나는 전화번호가 있는가?
  bool goexist; //이 노드의 자식이 있는가?

  //생성자
  Trie(){
    fill(go,go+MAX,nullptr);
    output = goexist = false;
  }
  //소멸자
  ~Trie(){
    for (int i=0;i<MAX;++i){
      if (go[i]) delete go[i];
    }
  }
  //문자열 key를 현재 노드부터 삽입
  void insert(const char* key){
    //문자열이 끝남(포인터가 배열의 마지막 부분 가리킴)
    if (*key=='\0') output = true;
    //아닐 경우
    else{
      int next = *key-'0';
      //해당 노드가 없으면 새로 동적 할당해서 만듦
      if (!go[next]) go[next] = new Trie; //중요! 각각의 노드가 goexist,output변수,포인터 배열을 가지고 있다!
      goexist = true;
      //자식 노드에서 이어서 삽입
      go[next]->insert(key+1);
    }
  }
  //이 노드가 일관성이 있는가?
  bool consistent(){
    //자식도 있으면서 여기서 끝나는 전화번호도 있으면 일관성 없음
    if (goexist && output) return false;
    // 자식들 중 하나라도 일관성이 없으면 이 노드도 일관성이 없음
    for(int i=0;i<MAX;++i)
      if(go[i] && !go[i]->consistent()) return false; //재귀 형태
    // 일관성이 있음
    return true;
  }
};

int main(){
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  while (t--){
    cin>>n;
    Trie *root = new Trie;
    for (int i=0;i<n;++i){
      char tel[11];
      scanf("%s",tel);
      root->insert(tel); //string 하나하나씩 insert하기
    }
    puts(root->consistent() ? "YES" : "NO");
    //소멸자를 호출하여 동적 할당 해제를 하지 않으면 힙 메모리가 부족할 수 있음
    delete root;
  }
}