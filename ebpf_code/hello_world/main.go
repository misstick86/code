package main

import (
	"github.com/cilium/ebpf/link"
	"github.com/cilium/ebpf/rlimit"
	"log"
	"time"
)

// $BPF_CLANG and $BPF_CFLAGS are set by the Makefile.
//go:generate go run github.com/cilium/ebpf/cmd/bpf2go -cc $BPF_CLANG -cflags $BPF_CFLAGS -target native bpf helloworld.c -- -I../headers

func main() {
	fn := "do_sys_openat2"
	if err := rlimit.RemoveMemlock(); err != nil {
		log.Fatalln(err)
	}
	objs := bpfObjects{}
	if err := loadBpfObjects(&objs, nil); err != nil {
		log.Println("load Object Error, ", err)
	}
	defer objs.Close()
	kp, err := link.Kprobe(fn, objs.HelloWorld, nil)
	if err != nil {
		log.Fatalln("Open kprobe: ", err)
	}
	defer kp.Close()
	log.Printf("Successfully started! Please run `sudo cat /sys/kernel/debug/tracing/trace_pipe` " +
		"to see output of the BPF programs.\n")
	for {
		time.Sleep(1 * time.Second)
	}
}
