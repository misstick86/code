/*
https://leetcode.cn/problems/valid-anagram/
*/

package main

func isAnagram(s string, t string) bool {
	sm := make(map[byte]int, 0)
	tm := make(map[byte]int, 0)
	if len(s) != len(t) {
		return false
	}
	for _, v := range s {
		if _, ok := sm[byte(v)]; ok {
			sm[byte(v)]++
			continue
		}
		sm[byte(v)] = 1
	}
	for _, v := range t {
		if _, ok := tm[byte(v)]; ok {
			tm[byte(v)]++
			continue
		}
		tm[byte(v)] = 1
	}
	for k, v := range sm {
		if tv, ok := tm[k]; ok {
			if v != tv {
				return false
			}
			delete(sm, k)
			delete(tm, k)
		}
	}
	if len(sm) != 0 || len(tm) != 0 {
		return false
	}
	return true
}

func main() {
	isAnagram("anagram", "nagaram")
}
