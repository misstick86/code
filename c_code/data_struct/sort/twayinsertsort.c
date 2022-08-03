/*
@File    :   insertsort.c
@Time    :   2022/08/02 21:10:46
@Author  :   xiaosongsong
@Desc    :   None

折半插入排序
*/

#include <stdio.h>

void Sort(int *node, int n) {
    int T[n];
    T[0] = node[0];
    int head, tail;
    head = tail =0;
    for (int i=1;i<n; i++){
        if (node[i]<T[head]){
            head = (head-1+n)%n;
            T[head] = node[i];
        } else if (node[i]>T[tail]){
            tail++;
            T[tail] = node[i];
        }else{
            T[tail+1] = T[tail];
            int j;
            for (j=tail; T[(j-1+n)%n]>node[i];j=(j-1+n)%n){
                T[j] = T[(j-1+n)%n];
            }
            tail++;
            T[j] = node[i];
        }
    }
    for(int i=0;i<n; i++){
        node[i] = T[head];
        head = (head+1)%n;
    }
}

int main(int argc, char const *argv[])
{
    int node[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(node) / sizeof(int);
    Sort(node,n);
    for(int i=0; i<n; i++) {
        printf("%d ", node[i]);
    }

    return 0;
}
