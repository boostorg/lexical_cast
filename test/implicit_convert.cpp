//  Copyright Antony Polukhin, 2023-2025.
//
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).

#include <boost/lexical_cast.hpp>

#include <boost/core/lightweight_test.hpp>

struct oops {
    operator int () const {
        return 41;
    }
};

inline std::ostream& operator<<(std::ostream& os, const oops&) {
    return os << 42;
}

struct Value {
    explicit Value(double x) : x(x) {}

    operator double() const {
        return x;
    }

    double x;
};

int main() {
    auto val = boost::lexical_cast<int>(oops{});
    BOOST_TEST_EQ(val, 42);

    Value value(128);
    auto s = boost::lexical_cast<std::string>(value);
    BOOST_TEST_EQ(s, "128");

    Value value2(128128128128128);
    auto s2 = boost::lexical_cast<std::string>(value2);
    BOOST_TEST_EQ(s2, "128128128128128");

    return boost::report_errors();
}
