/* SPDX-License-Identifier: GPL-2.0 */
/*
 * GPU memory trace points
 *
 * Copyright (C) 2020 Google, Inc.
 */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM gpu_mem

#if !defined(_TRACE_GPU_MEM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_GPU_MEM_H

#include <linux/tracepoint.h>

/*
 * The gpu_memory_total event indicates that there's an update to either the
 * global or process total gpu memory counters.
 *
 * This event should be emitted whenever the kernel device driver allocates,
 * frees, imports, unimports memory in the GPU addressable space.
 *
 * @gpu_id: This is the gpu id.
 *
 * @pid: Put 0 for global total, while positive pid for process total.
 *
 * @size: Virtual size of the allocation in bytes.
 *
 */
TRACE_EVENT(gpu_mem_total,

    TP_PROTO(u32 gpu_id, u32 pid, u64 size),

    TP_ARGS(gpu_id, pid, size),

    TP_STRUCT__entry(
        __field(u32, gpu_id)
        __field(u32, pid)
        __field(u64, size)
    ),

    TP_fast_assign(
        __entry->gpu_id = gpu_id;
        __entry->pid = pid;
        __entry->size = size;
    ),

    TP_printk("gpu_id=%u pid=%u size=%llu",
        __entry->gpu_id,
        __entry->pid,
        __entry->size)
);

#endif /* _TRACE_GPU_MEM_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
