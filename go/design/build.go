// 在看kubectl源码时发现kubectl主要是使用建造者模式将命令行中的数据装换为资源对象,这里简单来介绍写一下

package main

import "fmt"

type Deployment struct {
	name string
	replicas uint
	namespaces string
}

func NewDeployment() *Deployment  {
	return &Deployment{replicas: 1}
}

func (d *Deployment)NewDeploymentWithName(name string) *Deployment  {
	d.name = name
	return d
}

func (d *Deployment)NewDeploymentWithNameSpaces(namespaces string) *Deployment  {
	d.namespaces = namespaces
	return d
}

func (d *Deployment)NewDeploymentWithReplicas(replicas uint) *Deployment {
	d.replicas = replicas
	return d
}

func main() {
	deploy := NewDeployment().NewDeploymentWithName("twmt-deploy").NewDeploymentWithNameSpaces("babel")
	fmt.Println(deploy)
}
