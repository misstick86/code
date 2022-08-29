/**

给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。



示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]


提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100


*/

package main

import "fmt"

func dailyTemperatures(temperatures []int) []int {
	var result []int
	for key, _ := range temperatures {
		p := key + 1
		for p < len(temperatures) {
			if temperatures[p] > temperatures[key] {
				break
			}
			p++
		}
		if p == len(temperatures) {
			result = append(result, 0)
		} else {
			result = append(result, p-key)
		}

	}
	return result

}

func main() {
	n := []int{73, 74, 75, 71, 69, 72, 76, 73}
	fmt.Println(dailyTemperatures(n))
}
