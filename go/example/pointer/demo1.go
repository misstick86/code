package main

import (
	"fmt"
	"unsafe"
)

func demo1() {
	i := 1
	p := &i
	fmt.Println(p)
	fmt.Printf("type is %T", p)
	//  指针类型之间不能转换, 以下代码会报错.
	//  p1 := float64(p)

}

func demo2() {
	//  由于引用同一块地址, 一下i的值会发生改变.
	i := 10
	p := &i
	fp := (*float64)(unsafe.Pointer(p))
	fmt.Println(i)
	fmt.Printf("type is: %T\n", fp)
	*fp = *fp * 3
	fmt.Println(*fp)
	fmt.Println(i)

}

func main() {
	demo2()
}
