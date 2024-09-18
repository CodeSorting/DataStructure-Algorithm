int list[100];

int seq_search(int key,int low,int high) {
    int i;
    for (i=low;i<=high;++i) {
        if (list[i]==key) {
            return i;
        }
    }
    return -1;
}

int seq_search2(int key,int low,int high) {
    int i;
    list[high+1] = key;
    for (i=low;list[i]!=key;++i);
    if (i==(high+1)) return -1; //탐색 실패
    else return i;
}