#pragma once

#include <tuple>

#include <mosure/inversify/meta.hpp>

#include <mosure/rest/meta.hpp>


namespace mosure::rest {

    template <meta::StringLiteral Path>
    struct Path {
        constexpr auto size = sizeof(Path.value);
        constexpr auto value = Path.value;
    };

    template <Path Path_, typename... Args>
    using Paths = meta::tuple_concat_t<Path_, Args...>;

    template <typename... Args>
    using Paths = std::tuple<Args...>;

    template <
        meta::StringLiteral PathA,
        meta::StringLiteral PathB
    >
    struct PathConcat {
        // TODO: set size/value based on concat
    };

    // TODO: is this still used?
    template <typename T>
    using is_path = mosure::inversify::meta::is_specialization<
        T,
        Path
    >;
}

