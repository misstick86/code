package main

func groupThePeople(groupSizes []int) [][]int {
	p := make(map[int][]int, 1)
	for k, v := range groupSizes {
		p[v] = append(p[v], k)
	}
	var result [][]int
	for k, val := range p {
		n := len(val)
		if n > k {
			for i := 0; i < n; i = i + k {
				result = append(result, val[i:i+k])
			}
		} else {
			result = append(result, val)
		}

	}
	return result
}

func main() {
	nums := []int{3, 3, 3, 3, 3, 1, 3}
	groupThePeople(nums)
}
