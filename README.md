format-helpers
================

C++20 std::format helpers

[![CodeQL](https://github.com/SiddiqSoft/acw32handle/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/SiddiqSoft/format-helpers/actions/workflows/codeql-analysis.yml)
[![Build Status](https://dev.azure.com/siddiqsoft/siddiqsoft/_apis/build/status/SiddiqSoft.format-helpers?branchName=main)](https://dev.azure.com/siddiqsoft/siddiqsoft/_build/latest?definitionId=5&branchName=main)
![](https://img.shields.io/nuget/v/SiddiqSoft.format-helpers)
![](https://img.shields.io/github/v/tag/SiddiqSoft/format-helpers)
![](https://img.shields.io/azure-devops/tests/siddiqsoft/siddiqsoft/5)
<!--![](https://img.shields.io/azure-devops/coverage/siddiqsoft/siddiqsoft/5)-->

# API

Usage
```cpp
    include "siddiqsoft/formatters.hpp"
    ..
    std::atomic_bool b{false};

    std::cout  << std::format( "b contains {}\n", b);
    std::wcout << std::format(L"b contains {}\n", b);
```

Output
```
    false
    false
```


Type | Comment
-----|----------
`std::atomic<T>`<br/>`std::atomic_int`<br/>`std::atomic_uint`<br/>`std::atomic_uint64_t`<br/>`std::atomic_int64_t`<br/>`std::atomic_bool` | Convenience helpers so you don't have to `.load()` when using std::format.
`std::exception` | Support for both `char` and `wchar_t` destinations.
`std::runtime_error` | Support for both `char` and `wchar_t` destinations.
`nlohmann::json` | If the library `nlohmann.json` is present the source json object is serialized and the output is converted to `std::wstring` as needed.

# Dependencies

None. However, if you're using the [`nlohmann.json`](https://github.com/nlohmann.json/) library then we will enable the serializers for that library.

- This library does not use any Windows-specific code. However, use Visual Studio 2019 v16.11.2 or newer as support for `<format>` is [not present](https://en.cppreference.com/w/cpp/20) for GCC or Clang!
- On Windows with VisualStudio, use the Nuget package! 
- Make sure you use `c++latest` as the `<format>` is no longer in the `c++20` option pending ABI resolution.
