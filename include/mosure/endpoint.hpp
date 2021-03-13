#pragma once

#include <mosure/meta.hpp>
#include <mosure/method.hpp>


namespace mosure::rest {

    template <
        Method method,
        meta::StringLiteral Path,
        MemFn F
    >
    struct Endpoint {
        constexpr static auto function = F.function;
    };
}
