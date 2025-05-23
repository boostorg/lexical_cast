// Copyright (c) 2016-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// To compile manually use a command like the folowing:
// clang++ -I ../include -std=c++20 --precompile -x c++-module any.cppm

module;

#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <boost/config/workaround.hpp>
#include <boost/container/container_fwd.hpp>
#include <boost/core/cmath.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/core/noncopyable.hpp>
#include <boost/core/snprintf.hpp>
#include <boost/limits.hpp>
#include <boost/throw_exception.hpp>
#include <boost/type_traits/conditional.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_enum.hpp>
#include <boost/type_traits/is_float.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_signed.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/type_traits/make_unsigned.hpp>
#include <boost/type_traits/type_identity.hpp>


#ifndef BOOST_LEXICAL_CAST_USE_STD_MODULE
#include <array>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstring>
#ifndef BOOST_NO_CWCHAR
#   include <cwchar>
#endif
#include <exception>
#include <iosfwd>
#include <istream>
#ifndef BOOST_NO_STD_LOCALE
#   include <locale>
#endif
#include <sstream>
#include <string>
#include <string_view>
#include <typeinfo>
#endif

#define BOOST_LEXICAL_CAST_INTERFACE_UNIT

export module boost.lexical_cast;

#ifdef BOOST_LEXICAL_CAST_USE_STD_MODULE
import std;
#endif

#ifdef __clang__
#   pragma clang diagnostic ignored "-Winclude-angled-in-module-purview"
#endif

#include <boost/lexical_cast.hpp>
