package main

import (
	"fmt"
	"unsafe"
)

type User struct {
	name string
	age  int
}

func demo3() {
	// 同过操作内存来赋值u的值
	u := new(User)
	fmt.Println(*u)
	Uname := (*string)(unsafe.Pointer(u))
	*Uname = "zhangsan"

	Uage := (*int)(unsafe.Pointer(uintptr(unsafe.Pointer(u)) + unsafe.Offsetof(u.age)))
	*Uage = 20
	fmt.Println(u)
}

func main() {
	demo3()
}
