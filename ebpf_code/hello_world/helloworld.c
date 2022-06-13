// +build ignore

#include"common.h"

char __license[] SEC("license") = "Dual MIT/GPL";



SEC("do_sys_openat2")
int hello_world() {
    bpf_trace_printk("hello world");
}
