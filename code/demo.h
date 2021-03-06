// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `demo.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __demo_h__
#define __demo_h__

#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace Demo
{

typedef ::std::vector< ::Ice::Byte> ByteSeq;

const ::Ice::Int ByteSeqSize = 128000;

typedef ::std::vector< ::std::string> StringSeq;

const ::Ice::Int StringSeqSize = 128000;

struct StringDouble
{
    ::std::string s;
    ::Ice::Double d;
};

typedef ::std::vector< ::Demo::StringDouble> StringDoubleSeq;

const ::Ice::Int StringDoubleSeqSize = 128000;

struct Fixed
{
    ::Ice::Int i;
    ::Ice::Int j;
    ::Ice::Double d;
};

typedef ::std::vector< ::Demo::Fixed> FixedSeq;

typedef ::std::vector< ::Ice::Float> FloatSeq;

const ::Ice::Int FloatSeqSize = 120;

typedef ::std::vector< ::Ice::Double> DoubleSeq;

const ::Ice::Int DoubleSeqSize = 240;

}

namespace Ice
{
template<>
struct StreamableTraits< ::Demo::StringDouble>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 9;
    static const bool fixedLength = false;
};

template<class S>
struct StreamWriter< ::Demo::StringDouble, S>
{
    static void write(S* __os, const ::Demo::StringDouble& v)
    {
        __os->write(v.s);
        __os->write(v.d);
    }
};

template<class S>
struct StreamReader< ::Demo::StringDouble, S>
{
    static void read(S* __is, ::Demo::StringDouble& v)
    {
        __is->read(v.s);
        __is->read(v.d);
    }
};

template<>
struct StreamableTraits< ::Demo::Fixed>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 16;
    static const bool fixedLength = true;
};

template<class S>
struct StreamWriter< ::Demo::Fixed, S>
{
    static void write(S* __os, const ::Demo::Fixed& v)
    {
        __os->write(v.i);
        __os->write(v.j);
        __os->write(v.d);
    }
};

template<class S>
struct StreamReader< ::Demo::Fixed, S>
{
    static void read(S* __is, ::Demo::Fixed& v)
    {
        __is->read(v.i);
        __is->read(v.j);
        __is->read(v.d);
    }
};

}

#endif
