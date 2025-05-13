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

struct oops2 {
    operator double () const {
        return 1.12;
    }
};

inline std::ostream& operator<<(std::ostream& os, const oops2&) {
    return os << 2;
}

struct Value {
    explicit Value(double x) : x(x) {}

    operator double() const {
        return x;
    }

    double x;
};

int main() {
    BOOST_TEST_EQ(boost::lexical_cast<int>(oops{}), 42);
    BOOST_TEST_EQ(boost::lexical_cast<std::string>(oops{}), "42");

    BOOST_TEST_EQ(boost::lexical_cast<double>(oops2{}), 2);
    BOOST_TEST_EQ(boost::lexical_cast<std::string>(oops2{}), "2");

    Value value(128);
    BOOST_TEST_EQ(boost::lexical_cast<std::string>(value), "128");

    Value value_nan(std::numeric_limits<double>::quiet_NaN());
    BOOST_TEST_EQ(boost::lexical_cast<std::string>(value_nan), "nan");

    Value value_inf(std::numeric_limits<double>::infinity());
    BOOST_TEST_EQ(boost::lexical_cast<std::string>(value_inf), "inf");

    return boost::report_errors();
}
