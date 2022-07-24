package main

/*
go 泛型示例
*/

import (
	"fmt"
)

func PrintValue[T any](value T) {
	fmt.Println(value)
}

func demo1() {
	PrintValue[string]("this is test")
	PrintValue[rune]('*')
	PrintValue[int](42)
	PrintValue[float32](3.14)
	PrintValue[complex64](1 + 2i)
	PrintValue[[]int]([]int{1, 2, 3})
}

type comparable interface {
	int | float64 | string
}

func compare[T comparable](x, y T) bool {
	return x < y
}

func demo2() {
	fmt.Println(compare(1, 2))
	fmt.Println(compare(1.5, 2.6))
	fmt.Println(compare("foo", "bar"))
}

func main() {
	demo2()
}
