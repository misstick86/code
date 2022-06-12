package main

import (
	"github.com/cilium/ebpf/link"
	"github.com/cilium/ebpf/rlimit"
	"log"
	"time"
)

// $BPF_CLANG and $BPF_CFLAGS are set by the Makefile.
//go:generate go run github.com/cilium/ebpf/cmd/bpf2go -cc $BPF_CLANG -cflags $BPF_CFLAGS bpf kprobe.c -- -I../headers

const mapKey uint32 = 0

func main() {
	fn := "sys_execve"
	if err := rlimit.RemoveMemlock(); err != nil {
		log.Fatalln(err)
	}
	objs := bpfObjects{}
	if err := loadBpfObjects(&objs, nil); err != nil {
		log.Fatalln("load Object Error, ", err)
	}
	defer objs.Close()
	kp, err := link.Kprobe(fn, objs.KprobeExecve, nil)
	if err != nil {
		log.Fatalln("open kprobe:", err)
	}
	defer kp.Close()
	ticker := time.NewTicker(1 * time.Second)
	defer ticker.Stop()
	log.Println("Waiting Event...")
	for range ticker.C {
		var value uint64
		if err := objs.KprobeMap.Lookup(mapKey, &value); err != nil {
			log.Fatalln("Read map: ", err)
		}
		log.Printf("%s Called %d times.", fn, value)
	}
}
