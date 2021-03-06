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
// Generated from file `MapDoubleSeq.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//


// Freeze types in this file:
// name="MapDoubleSeq", key="int", value="Demo::DoubleSeq"

#ifndef __MapDoubleSeq_h__
#define __MapDoubleSeq_h__

#include <Freeze/Map.h>
#include </home/serge/Desktop/Test_Ice/code/demo.h>

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

class MapDoubleSeqKeyCodec
{
public:

    static void write(::Ice::Int, Freeze::Key&, const ::Ice::CommunicatorPtr&, const Ice::EncodingVersion&);
    static void read(::Ice::Int&, const Freeze::Key&, const ::Ice::CommunicatorPtr&, const Ice::EncodingVersion&);
    static const std::string& typeId();
};

class MapDoubleSeqValueCodec
{
public:

    static void write(const ::Demo::DoubleSeq&, Freeze::Value&, const ::Ice::CommunicatorPtr&, const Ice::EncodingVersion&);
    static void read(::Demo::DoubleSeq&, const Freeze::Value&, const ::Ice::CommunicatorPtr&, const Ice::EncodingVersion&);
    static const std::string& typeId();
};

typedef Freeze::Map< ::Ice::Int, ::Demo::DoubleSeq, MapDoubleSeqKeyCodec, MapDoubleSeqValueCodec, Freeze::IceEncodingCompare > MapDoubleSeq;

#endif
