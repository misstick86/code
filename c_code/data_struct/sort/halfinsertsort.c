/*
@File    :   insertsort.c
@Time    :   2020/03/04 21:10:46
@Author  :   xiaosongsong
@Desc    :   None

折半插入排序
*/

#include <stdio.h>

void Sort(int *node, int n) {
    int temp;
    for(int i=1; i<n;i++){
        temp = node[i];
        int low = 0;
        int high = i-1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (temp >= node[mid] ) {            
                low = mid +1;
            }else{
                high = mid -1;
            }
        }
        for(int j=i; j>high+1;j--){
            node[j] = node[j-1];
        }
        node[high+1] = temp;
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
