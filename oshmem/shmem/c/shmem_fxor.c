/*
 * Copyright (c) 2018      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#include "oshmem_config.h"

#include "oshmem/constants.h"
#include "oshmem/include/shmem.h"
#include "oshmem/include/shmemx.h"

#include "oshmem/runtime/runtime.h"

#include "oshmem/op/op.h"
#include "oshmem/mca/atomic/atomic.h"

/*
 * These routines perform an atomic fetch-and-xor operation.
 * The fetch and xor routines retrieve the value at address target on PE pe, and update
 * target with the result of 'xor' operation value to the retrieved value. The operation
 * must be completed without the possibility of another process updating target between
 * the time of the fetch and the update.
 */
#if OSHMEM_PROFILING
#include "oshmem/include/pshmem.h"
#pragma weak shmem_uint_atomic_fetch_xor      = pshmem_uint_atomic_fetch_xor
#pragma weak shmem_ulong_atomic_fetch_xor     = pshmem_ulong_atomic_fetch_xor
#pragma weak shmem_ulonglong_atomic_fetch_xor = pshmem_ulonglong_atomic_fetch_xor
#pragma weak shmemx_int32_atomic_fetch_xor    = pshmemx_int32_atomic_fetch_xor
#pragma weak shmemx_int64_atomic_fetch_xor    = pshmemx_int64_atomic_fetch_xor
#pragma weak shmemx_uint32_atomic_fetch_xor   = pshmemx_uint32_atomic_fetch_xor
#pragma weak shmemx_uint64_atomic_fetch_xor   = pshmemx_uint64_atomic_fetch_xor
#include "oshmem/shmem/c/profile/defines.h"
#endif

OSHMEM_TYPE_FOP(uint, unsigned int, shmem, xor)
OSHMEM_TYPE_FOP(ulong, unsigned long, shmem, xor)
OSHMEM_TYPE_FOP(ulonglong, unsigned long long, shmem, xor)
OSHMEM_TYPE_FOP(int32, int32_t, shmemx, xor)
OSHMEM_TYPE_FOP(int64, int64_t, shmemx, xor)
OSHMEM_TYPE_FOP(uint32, uint32_t, shmemx, xor)
OSHMEM_TYPE_FOP(uint64, uint64_t, shmemx, xor)