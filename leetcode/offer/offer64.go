/*
https://leetcode.cn/problems/qiu-12n-lcof/
*/
package main

import "fmt"

func sumNums(n int) int {
	if n != 0 {
		return n + sumNums(n-1)
	}
	return n

}

func main() {
	p := sumNums(9)
	fmt.Println(p)
}
