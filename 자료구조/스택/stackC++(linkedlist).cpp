/*
?ด? ๊ฒ? ?น?  ์ชฝ์?๋ง? ?ฝ? ?ญ?  ?ฐ?ฐ?ด ?ด๋ฃจ์ด์ง?๋ฏ?๋ก? ?ฐ๊ฒ? ๋ฆฌ์ค?ธ๋ก? ๊ตฌํ?ด?ผ ?ฉ??ค. ?ฐ๊ฒ? ๋ฆฌ์ค?ธ๋ก? ๊ตฌํ?ด?ผ push,pop, top ?ฐ?ฐ?ด ๋ชจ๋ O(1)?ด์ฃ?.
?ฐ๊ฒ? ๋ฆฌ์ค?ธ๋ก? ๊ตฌํ?  ๊ฒฝ์ฐ head ?ฌ?ธ?ฐ๊ฐ? top ??๋ฅ? ๋ฐ๋ก ๊ฐ?๋ฆฌํค๊ณ? ?? ??๊ฐ? ?๋ฉ?, push๋ฅ? ?  ?๋ง๋ค head๋ฅ? ๊ฐ?๋ฆฌํค? ?๋ก์ด ?ธ?๋ฅ? ๋ง๋ค?ด ๊ทธ๊ฑธ ?ค? head๋ก? ?ฎ?ด??ฐ๊ณ?, pop? ?  ?๋ง๋ค head ?ธ?๋ฅ? ์ง??ฐ๊ณ? ๊ท? ?ค? ?ธ?๋ฅ? head๋ก? ๋ฐ๊พธ? ??ผ๋ก? ๊ตฌํ?  ? ??ต??ค.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class UnderflowException{};

template<typename T>
class ListNode{ //๋ฆฌ์ค?ธ ?ธ? ?ด??ค
public:
  T value; //๊ฐ?
  ListNode<T> *next; //?ค??ธ?

  ListNode<T>(): next(nullptr){}
  ListNode<T>(T value1,ListNode<T> *next1): value(value1), next(next1){}
};

template<typename T>
class Stack{ //?ค? ?ด??ค
public:
  int size; //?ค??ฌ๊ธ?
  ListNode<T> *tail; //?ค? ๊ฐ์ ๊ฐ?๋ฆฌํด.

  //??ฑ?
  Stack<T>(): size(0), tail(nullptr){}

  //?๋ฉธ์
  ~Stack<T>(){
    ListNode<T> *t1 = tail, *t2;
    while (t1 != nullptr){
      t2 = t1->next; //?ฌ?ธ?ฐ?ด๋ฆ?->๋ฉค๋ฒ๋ณ???ด๋ฆ? = ๊ฐ?
      delete t1;
      t1 = t2;
    }
  }

  //๋ฉค๋ฒ ?จ?
  void push(T value){
    tail = new ListNode<T>(value, tail); //tail๊ณ? ? listnode๋ฅ? ?ฐ๊ฒฐํ?ค.
    size++;
  }

  T top(){ //๋ง? ? ?? ๋ฐํ
    try{
      //??ธ์ฒ๋ฆฌ : ?ค??ด ๋น์ด??
      if (size==0) throw UnderflowException();

      return tail->value;
    }
    catch(UnderflowException e){
      cerr<<"?ค??ด ๋น์ด ???ฐ top ?ฐ?ฐ? ????ต??ค."<< endl;
      exit(1);
    }
  }

  void pop(){ //๋ง? ?? ?? ? ๊ฑ?
    try{
      //??ธ ์ฒ๋ฆฌ: ?ค??ด ๋น์ด ??
      if (size==0) throw UnderflowException();

      ListNode<T> *temp = tail->next;
      delete tail;
      tail = temp;
      size--;
    }
    catch(UnderflowException e){
      cerr<<"?ค??ด ๋น์ด ???ฐ pop ?ฐ?ฐ? ????ต??ค." << endl;
      exit(2);
    }
  }
};

template<typename T>
ostream& operator <<(ostream &out,const Stack<T> &LL){//???ค? ? ์ค์ ์ฐจ๋?????๋ก? ์ถ๋ ฅ
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