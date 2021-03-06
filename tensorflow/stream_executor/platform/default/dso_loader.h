/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// Common DSO loading functionality: exposes callables that dlopen DSOs
// in either the runfiles directories

#ifndef TENSORFLOW_STREAM_EXECUTOR_DSO_LOADER_H_
#define TENSORFLOW_STREAM_EXECUTOR_DSO_LOADER_H_

#include <vector>
#include "tensorflow/stream_executor/platform/port.h"

#include "absl/strings/string_view.h"
#include "tensorflow/stream_executor/lib/status.h"
#include "tensorflow/stream_executor/lib/statusor.h"
#include "tensorflow/stream_executor/platform.h"
#include "tensorflow/stream_executor/platform/mutex.h"

namespace stream_executor {
namespace internal {

namespace DsoLoader {
// The following methods either load the DSO of interest and return a dlopen
// handle or error status.
port::StatusOr<void*> GetCudaDriverDsoHandle();
port::StatusOr<void*> GetCudaRuntimeDsoHandle();
port::StatusOr<void*> GetCublasDsoHandle();
port::StatusOr<void*> GetCufftDsoHandle();
port::StatusOr<void*> GetCurandDsoHandle();
port::StatusOr<void*> GetCuptiDsoHandle();
port::StatusOr<void*> GetCudnnDsoHandle();
}  // namespace DsoLoader

// Wrapper around the DsoLoader that prevents us from dlopen'ing any of the DSOs
// more than once.
namespace CachedDsoLoader {
// Cached versions of the corresponding DsoLoader methods above.
port::StatusOr<void*> GetCudaDriverDsoHandle();
port::StatusOr<void*> GetCudaRuntimeDsoHandle();
port::StatusOr<void*> GetCublasDsoHandle();
port::StatusOr<void*> GetCufftDsoHandle();
port::StatusOr<void*> GetCurandDsoHandle();
port::StatusOr<void*> GetCuptiDsoHandle();
port::StatusOr<void*> GetCudnnDsoHandle();
}  // namespace CachedDsoLoader
}  // namespace internal
}  // namespace stream_executor

#endif  // TENSORFLOW_STREAM_EXECUTOR_DSO_LOADER_H_
