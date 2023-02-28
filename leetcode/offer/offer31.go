/*
https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
*/
package main

func validateStackSequences(pushed []int, popped []int) bool {
	if len(pushed) != len(popped) {
		return false
	}
	i := 0
	for len(pushed) != 0 || len(popped) != 0 {
		if i > len(pushed)-1 {
			break
		}
		if pushed[i] != popped[0] {
			i++
		} else {
			pushed = append(pushed[:i], pushed[i+1:]...)
			popped = popped[1:]
			if i != 0 {
				i--
			}
		}
	}
	if len(pushed) != 0 || len(popped) != 0 {
		return false
	}
	return true
}
func main() {
	push := []int{0, 1}
	pop := []int{0, 1}
	validateStackSequences(push, pop)
}
