#pragma once

#include <algorithm>
#include <functional>
#include <type_traits>


namespace mosure::rest::meta {

    template <typename Arg, typename Tuple>
    struct tuple_concat;

    template <typename Arg, typename... Args>
    struct tuple_concat<Arg, std::tuple<Args...>> {
        using value = std::tuple<Arg, Args...>;
    };

    template <typename Arg, typename... Args>
    using tuple_concat_t = typename tuple_concat<Arg, Args...>::value;

    template <
        template <typename...> typename Condition,
        typename... Args
    >
    struct filter;

    template <
        template <typename...> typename Condition
    >
    struct filter<Condition> {
        using value = std::tuple<>;
    };

    template <
        template <typename...> typename Condition,
        typename Arg,
        typename... Args
    >
    struct filter<Condition, Arg, Args...> {
        using value = std::conditional_v<
            Condition<Arg>,
            tuple_concat_t<Arg, typename filter<Args...>::value>,
            typename filter<Args...>::value
        >;
    }

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
