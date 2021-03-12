#pragma once

#include <mosure/meta.hpp>


namespace mosure::rest {

    template <meta::StringLiteral Path>
    struct BasePath {
        constexpr auto size = sizeof(Path.value);
        constexpr auto value = Path.value;
    };
}

