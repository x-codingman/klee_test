file(REMOVE_RECURSE
  "../lib/libkleeUBSan32_Debug+Asserts.bca"
  "../lib/libkleeUBSan32_Debug.bca"
  "../lib/libkleeUBSan32_Release+Asserts.bca"
  "../lib/libkleeUBSan32_Release+Debug+Asserts.bca"
  "../lib/libkleeUBSan32_Release+Debug.bca"
  "../lib/libkleeUBSan32_Release.bca"
  "../lib/libkleeUBSan64_Debug+Asserts.bca"
  "../lib/libkleeUBSan64_Debug.bca"
  "../lib/libkleeUBSan64_Release+Asserts.bca"
  "../lib/libkleeUBSan64_Release+Debug+Asserts.bca"
  "../lib/libkleeUBSan64_Release+Debug.bca"
  "../lib/libkleeUBSan64_Release.bca"
  "CMakeFiles/UBSan"
  "ubsan_handlers32_Debug+Asserts.bc"
  "ubsan_handlers32_Debug.bc"
  "ubsan_handlers32_Release+Asserts.bc"
  "ubsan_handlers32_Release+Debug+Asserts.bc"
  "ubsan_handlers32_Release+Debug.bc"
  "ubsan_handlers32_Release.bc"
  "ubsan_handlers64_Debug+Asserts.bc"
  "ubsan_handlers64_Debug.bc"
  "ubsan_handlers64_Release+Asserts.bc"
  "ubsan_handlers64_Release+Debug+Asserts.bc"
  "ubsan_handlers64_Release+Debug.bc"
  "ubsan_handlers64_Release.bc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/UBSan.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
