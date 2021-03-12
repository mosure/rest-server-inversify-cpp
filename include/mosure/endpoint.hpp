#pragma once

#include <mosure/meta.hpp>
#include <mosure/method.hpp>


namespace mosure::rest {

    template <
        Method method,
        meta::StringLiteral Path,
        typename M,
        typename T
    >
    struct Endpoint {
        constexpr auto 
    };
}
