/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_LIBARTBASE_BASE_MEMFD_H_
#define ART_LIBARTBASE_BASE_MEMFD_H_

#if defined(__BIONIC__)
#include <linux/memfd.h>  // To access memfd flags.
#endif

namespace art {

// Call memfd(2) if available on platform and return result. This call also makes a kernel version
// check for safety on older kernels (b/116769556)..
int memfd_create(const char* name, unsigned int flags);

// Call memfd(2) if available on platform and return result. Try to give us an unlinked FD in some
// other way if memfd fails or isn't supported.
int memfd_create_compat(const char* name, unsigned int flags);

// Return whether the kernel supports sealing future writes of a memfd.
bool IsSealFutureWriteSupported();

}  // namespace art

#endif  // ART_LIBARTBASE_BASE_MEMFD_H_
