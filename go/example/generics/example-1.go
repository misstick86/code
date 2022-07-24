package main

import (
	"fmt"
)

type Slice[T any] []T

func (s Slice[T]) Print() {
	for _, v := range s {
		fmt.Println(v)
	}
}

func print[T any](s Slice[T]) {
	for _, v := range s {
		fmt.Println(v)
	}
}

func main() {
	s := Slice[int]{1, 2, 3}
	s.Print()
	print[int](s)
}
