/*
?´? ‡ê²? ?Š¹? • ìª½ì—?„œë§? ?‚½?… ?‚­? œ ?—°?‚°?´ ?´ë£¨ì–´ì§?ë¯?ë¡? ?—°ê²? ë¦¬ìŠ¤?Š¸ë¡? êµ¬í˜„?•´?•¼ ?•©?‹ˆ?‹¤. ?—°ê²? ë¦¬ìŠ¤?Š¸ë¡? êµ¬í˜„?•´?•¼ push,pop, top ?—°?‚°?´ ëª¨ë‘ O(1)?´ì£?.
?—°ê²? ë¦¬ìŠ¤?Š¸ë¡? êµ¬í˜„?•  ê²½ìš° head ?¬?¸?„°ê°? top ?›?†Œë¥? ë°”ë¡œ ê°?ë¦¬í‚¤ê³? ?ˆ?Š” ?˜•?ƒœê°? ?˜ë©?, pushë¥? ?•  ?•Œë§ˆë‹¤ headë¥? ê°?ë¦¬í‚¤?Š” ?ƒˆë¡œìš´ ?…¸?“œë¥? ë§Œë“¤?–´ ê·¸ê±¸ ?‹¤?‹œ headë¡? ?®?–´?”Œ?š°ê³?, pop?„ ?•  ?•Œë§ˆë‹¤ head ?…¸?“œë¥? ì§??š°ê³? ê·? ?‹¤?Œ ?…¸?“œë¥? headë¡? ë°”ê¾¸?Š” ?‹?œ¼ë¡? êµ¬í˜„?•  ?ˆ˜ ?ˆ?Šµ?‹ˆ?‹¤.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class UnderflowException{};

template<typename T>
class ListNode{ //ë¦¬ìŠ¤?Š¸ ?…¸?“œ ?´?˜?Š¤
public:
  T value; //ê°?
  ListNode<T> *next; //?‹¤?Œ?…¸?“œ

  ListNode<T>(): next(nullptr){}
  ListNode<T>(T value1,ListNode<T> *next1): value(value1), next(next1){}
};

template<typename T>
class Stack{ //?Š¤?ƒ ?´?˜?Š¤
public:
  int size; //?Š¤?ƒ?¬ê¸?
  ListNode<T> *tail; //?‹¤?Œ ê°’ì„ ê°?ë¦¬í‚´.

  //?ƒ?„±?
  Stack<T>(): size(0), tail(nullptr){}

  //?†Œë©¸ì
  ~Stack<T>(){
    ListNode<T> *t1 = tail, *t2;
    while (t1 != nullptr){
      t2 = t1->next; //?¬?¸?„°?´ë¦?->ë©¤ë²„ë³??ˆ˜?´ë¦? = ê°?
      delete t1;
      t1 = t2;
    }
  }

  //ë©¤ë²„ ?•¨?ˆ˜
  void push(T value){
    tail = new ListNode<T>(value, tail); //tailê³? ?ƒˆ listnodeë¥? ?—°ê²°í•œ?‹¤.
    size++;
  }

  T top(){ //ë§? ?œ„ ?›?†Œ ë°˜í™˜
    try{
      //?˜ˆ?™¸ì²˜ë¦¬ : ?Š¤?ƒ?´ ë¹„ì–´?ˆ?Œ
      if (size==0) throw UnderflowException();

      return tail->value;
    }
    catch(UnderflowException e){
      cerr<<"?Š¤?ƒ?´ ë¹„ì–´ ?ˆ?Š”?° top ?—°?‚°?„ ?‹œ?„?–ˆ?Šµ?‹ˆ?‹¤."<< endl;
      exit(1);
    }
  }

  void pop(){ //ë§? ?œ„?˜ ?›?†Œ ? œê±?
    try{
      //?˜ˆ?™¸ ì²˜ë¦¬: ?Š¤?ƒ?´ ë¹„ì–´ ?ˆ?Œ
      if (size==0) throw UnderflowException();

      ListNode<T> *temp = tail->next;
      delete tail;
      tail = temp;
      size--;
    }
    catch(UnderflowException e){
      cerr<<"?Š¤?ƒ?´ ë¹„ì–´ ?ˆ?Š”?° pop ?—°?‚°?„ ?‹œ?„?–ˆ?Šµ?‹ˆ?‹¤." << endl;
      exit(2);
    }
  }
};

template<typename T>
ostream& operator <<(ostream &out,const Stack<T> &LL){//?›?†Œ?“¤?„ ?•œ ì¤„ì— ì°¨ë?????ë¡? ì¶œë ¥
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