/*
이렇게 특정 쪽에서만 삽입 삭제 연산이 이루어지므로 연결 리스트로 구현해야 합니다. 연결 리스트로 구현해야 push,pop, top 연산이 모두 O(1)이죠.
연결 리스트로 구현할 경우 head 포인터가 top 원소를 바로 가리키고 있는 형태가 되며, push를 할 때마다 head를 가리키는 새로운 노드를 만들어 그걸 다시 head로 덮어씌우고, pop을 할 때마다 head 노드를 지우고 그 다음 노드를 head로 바꾸는 식으로 구현할 수 있습니다.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class UnderflowException{};

template<typename T>
class ListNode{ //리스트 노드 클래스
public:
  T value; //값
  ListNode<T> *next; //다음노드

  ListNode<T>(): next(nullptr){}
  ListNode<T>(T value1,ListNode<T> *next1): value(value1), next(next1){}
};

template<typename T>
class Stack{ //스택 클래스
public:
  int size; //스택크기
  ListNode<T> *tail; //다음 값을 가리킴.

  //생성자
  Stack<T>(): size(0), tail(nullptr){}

  //소멸자
  ~Stack<T>(){
    ListNode<T> *t1 = tail, *t2;
    while (t1 != nullptr){
      t2 = t1->next; //포인터이름->멤버변수이름 = 값
      delete t1;
      t1 = t2;
    }
  }

  //멤버 함수
  void push(T value){
    tail = new ListNode<T>(value, tail); //tail과 새 listnode를 연결한다.
    size++;
  }

  T top(){ //맨 위 원소 반환
    try{
      //예외처리 : 스택이 비어있음
      if (size==0) throw UnderflowException();

      return tail->value;
    }
    catch(UnderflowException e){
      cerr<<"스택이 비어 있는데 top 연산을 시도했습니다."<< endl;
      exit(1);
    }
  }

  void pop(){ //맨 위의 원소 제거
    try{
      //예외 처리: 스택이 비어 있음
      if (size==0) throw UnderflowException();

      ListNode<T> *temp = tail->next;
      delete tail;
      tail = temp;
      size--;
    }
    catch(UnderflowException e){
      cerr<<"스택이 비어 있는데 pop 연산을 시도했습니다." << endl;
      exit(2);
    }
  }
};

template<typename T>
ostream& operator <<(ostream &out,const Stack<T> &LL){//원소들을 한 줄에 차례대로 출력
  ListNode<T> *temp = LL.tail;
  out<<"top [";
  for (int i=0;i<LL.size;i++){
    out<<temp->value;
    temp = temp->next;
    if (i < LL.size-1) out<<", ";
  }
  out<<"] bottom";
  return out;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Stack<int> S;
  S.push(0); cout << S << endl;
  S.push(1); cout << S << endl;
  S.push(2); cout << S << endl;
  S.push(3); cout << S << endl;
  S.pop(); cout << S << endl;
  S.push(4); cout << S << endl;
  S.pop(); cout << S << endl;
  S.pop(); cout << S << endl;
  S.push(5); cout << S << endl;
  S.pop(); cout << S << endl;
  S.pop(); cout << S << endl;
  S.pop(); cout << S << endl;
}