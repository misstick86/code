/*
https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
*/

package main

func firstUniqChar(s string) byte {
	m := make(map[byte]int, 0)
	p := make([]byte, 0)
	for _, v := range s {
		if _, ok := m[byte(v)]; ok {
			for i := 0; i < len(p); i++ {
				if byte(v) == p[i] {
					p = append(p[:i], p[i+1:]...)
					break
				}
			}
		} else {
			m[byte(v)] = 1
			p = append(p, byte(v))
		}

	}
	if len(p) != 0 {
		return p[0]
	}
	return byte(' ')
}

func main() {
	firstUniqChar("leetcode")
}
