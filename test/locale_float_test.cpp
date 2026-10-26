// Copyright Treston Cuzzort, 2026.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <clocale>
#include <locale>
#include <string>
#include <limits>
#include <cmath>

#include <boost/core/lightweight_test.hpp>
#include <boost/lexical_cast.hpp>

template<class Char>
class punctuation : public std::numpunct<Char>
{
    Char separator;
    Char do_decimal_point() const override { return separator; }
public:
    explicit punctuation(Char value) : separator(value) {}
};

template<class Float>
void check()
{
    const Float value = Float(1.25);
    const auto narrow = boost::lexical_cast<std::string>(value);
    const auto wide = boost::lexical_cast<std::wstring>(value);
    BOOST_TEST_EQ(narrow, std::string("1#25"));
    BOOST_TEST(wide == L"1@25");
    Float result = 0;
    BOOST_TEST(boost::conversion::try_lexical_convert(narrow, result));
    BOOST_TEST_EQ(result, value);
    result = 0;
    BOOST_TEST(boost::conversion::try_lexical_convert(wide, result));
    BOOST_TEST_EQ(result, value);
    BOOST_TEST_EQ(boost::lexical_cast<Float>("1#25"), value);
    BOOST_TEST_EQ(boost::lexical_cast<Float>(L"1@25"), value);

    const Float values[] = {
        Float(0), -Float(0), Float(1), Float(-1), Float(23.9), Float(-23.9),
        Float(1e-5), Float(100000.25), std::numeric_limits<Float>::epsilon(),
        (std::numeric_limits<Float>::min)(), (std::numeric_limits<Float>::max)()
    };
    for (const Float input : values) {
        const auto text = boost::lexical_cast<std::string>(input);
        const auto wtext = boost::lexical_cast<std::wstring>(input);
        const Float parsed = boost::lexical_cast<Float>(text);
        const Float wparsed = boost::lexical_cast<Float>(wtext);
        BOOST_TEST_EQ(parsed, input);
        BOOST_TEST_EQ(wparsed, input);
        BOOST_TEST_EQ(std::signbit(parsed), std::signbit(input));
        BOOST_TEST_EQ(std::signbit(wparsed), std::signbit(input));
    }
}

int main()
{
    std::setlocale(LC_NUMERIC, "C");
    const std::locale old;
    const std::locale custom(std::locale(std::locale::classic(), new punctuation<char>('#')),
                             new punctuation<wchar_t>(L'@'));
    std::locale::global(custom);
    BOOST_TEST_EQ(custom.name(), std::string("*"));
    BOOST_TEST_EQ(std::string(std::setlocale(LC_NUMERIC, 0)), std::string("C"));
    check<float>();
    check<double>();
    check<long double>();
    std::locale::global(old);
    return boost::report_errors();
}
