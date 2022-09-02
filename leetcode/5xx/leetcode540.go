package main

func halfSearch(nums []int, low int, high int) int {
	mid := (low + high) / 2
	if low == mid || mid == high {
		return -1
	}

	if nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid] {
		return nums[mid]
	}
	p := halfSearch(nums, low, mid)
	if p != -1 {
		return p
	}
	return halfSearch(nums, mid, high)
}

func singleNonDuplicate(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	if nums[0] != nums[1] {
		return nums[0]
	}
	if nums[n-2] != nums[n-1] {
		return nums[n-1]
	}
	p := halfSearch(nums, 0, n-1)
	return p
}

func main() {
	p := []int{1, 1, 2, 2, 3, 3, 4, 4, 5, 8, 8}
	singleNonDuplicate(p)
}
