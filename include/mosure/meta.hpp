#pragma once

#include <algorithm>


namespace mosure::rest::meta {

    // https://ctrpeach.io/posts/cpp20-string-literal-template-parameters/
    template<size_t N>
    struct StringLiteral {
        constexpr StringLiteral(const char (&str)[N]) {
            std::copy_n(str, N, value);
        }
        
        char value[N];
    };
}
