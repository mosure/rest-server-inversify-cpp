#pragma once

#include <algorithm>
#include <functional>
#include <type_traits>


namespace mosure::rest::meta {

    template <typename R, typename T, typename... Args>
    struct MemFn {
        constexpr MemFn(R (T::*)(Args...) pm) : function(std::mem_fn(pm)) { }
        
        std::invoke_result_t<decltype(std::mem_fn<R, T, Args...>)> function;
    };

    template <typename R, typename T>
    struct MemFn {
        constexpr MemFn(R T::* pm) : function(std::mem_fn(pm)) { }
        
        std::invoke_result_t<decltype(std::mem_fn<R, T>)> function;
    };

    // https://ctrpeach.io/posts/cpp20-string-literal-template-parameters/
    template<size_t N>
    struct StringLiteral {
        constexpr StringLiteral(const char (&str)[N]) {
            std::copy_n(str, N, value);
        }
        
        char value[N];
    };
}
