// +build ignore

#include"common.h"

char __license[] SEC("license") = "Dual MIT/GPL";

SEC("kprobe/do_sys_openat2")
int hello_world() {
    char m[]="hello world";
    bpf_trace_printk(m,sizeof(m));
    return 0;
}
