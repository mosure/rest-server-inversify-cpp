#pragma once

#include <mosure/basepath.hpp>


namespace mosure::rest {

    template <typename Endpoints...>
    struct Route {

    };

    // Specialization with base path
    template <
        BasePath BasePath_,
        typename Endpoints...
    >
    struct Route {

    };

}