// 访问者模式， 在kubectl 源码中使用 visitor模式迭代处理Build产生的一系列资源

package main

import "fmt"

type VisitorFunc func(*Info, error) error

// 定义一个访问者接口, 每一个访问者都要实现这个访问者接口
type Visitor interface {
	Visit(fn VisitorFunc) error
}


// 定义一个数据实体

type Info struct {
	name string
	namespace string
	OtherThings string
}

func (info *Info)Visit(fn VisitorFunc) error{
	return fn(info, nil)
}


// 定义一个NameVisitor

type NameVisitor struct {
	visitor Visitor
}

func (v NameVisitor)Visit(fn VisitorFunc) error  {
	return v.visitor.Visit(func(info *Info, err error) error {
		err = fn(info,err)
		return nil

	})
}


func main() {
	info := Info{}
	var v Visitor = &info
	v = NameVisitor{v}
	v.Visit(func(info *Info, err error) error {
		fmt.Println("doing something...")
		return nil
	})

}
