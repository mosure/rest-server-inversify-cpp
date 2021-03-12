#pragma once

#include <algorithm>
#include <functional>


namespace mosure::rest::meta {

    template <typename M, typename T>
    struct MemFunction {
        constexpr MemFunction(M T::* pm) {
            
        }

        std::function
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
