#pragma once

#include <string>

#include <mosure/rest/method.hpp>


template <typename InternalType>
struct Request : InternalType {
    Request(InternalType&& reference) : InternalType(reference) { }

    Method inversify_get_method() = 0;
    const std::string& inversify_get_path() = 0;
};
