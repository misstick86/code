// +build ignore

#include"vmlinux.h"
#include <bpf/bpf_helpers.h>
char __license[] SEC("license") = "Dual MIT/GPL";


struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries,1);
    __type(key, u32);
    __type(value, u64);
} kprobe_map SEC("maps");


int kprobe_execve() {
   u32 key = 0;
   u64 initval = 1, *valp;
   valp = bpf_map_lookup_elem(&kprobe_map, &key);
   if (!valp) {
        bpf_map_update_elem(&kprobe_map, &key, &initval, BPF_ANY);
        return 0;
    }
    __sync_fetch_and_add(valp, 1);
    return 0;

}

