package main

import (
	"fmt"
	"math"
)

func choose(num int, key int) string {

	mapResult := map[int]string{1: "I", 4: "IV", 5: "V", 9: "IX", 10: "X", 40: "XL", 50: "L", 90: "XC", 100: "C",
		400: "CD", 500: "D", 900: "CM", 1000: "M"}
	n := num * key
	if val, ok := mapResult[n]; ok {
		return val
	}
	result := ""
	if num < 4 {
		for num > 0 {
			result += mapResult[key]
			num--
		}
		return result
	}
	if num%5 != 0 {
		result += mapResult[5*key]
		result += choose(num%5, key)
		return result
	}
	return result
}

func intToRoman(num int) string {
	result := ""
	for i := 4; i > 0; i-- {
		result += choose(num/int(math.Pow10(i-1)), int(math.Pow10(i-1)))
		num = num % int(math.Pow10(i-1))
	}
	return result
}
func main() {
	num := 888
	result := intToRoman(num)
	fmt.Println(result)
}
