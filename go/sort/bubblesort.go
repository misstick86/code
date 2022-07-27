/*
	go 实现的冒泡排序
*/
package main

import "fmt"

func swap(i, j *int) {
	temp := *i
	*i = *j
	*j = temp
}

func main() {
	s := []int{70, 81, 59, 21, 92, 34, 13, 76, 8, 2, 11, 22, 77, 53, 18, 28}
	count := len(s)
	for i := 0; i < count; i++ {
		for j := 0; j < count-i-1; j++ {
			if s[j] > s[j+1] {
				swap(&s[j], &s[j+1])
			}
		}
	}
	fmt.Println(s)

}
