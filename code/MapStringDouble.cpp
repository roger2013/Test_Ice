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
// Generated from file `MapStringDouble.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//


// Freeze types in this file:
// name="MapStringDouble", key="Demo::ComplexKey", value="Demo::StringDouble"

#include <Ice/BasicStream.h>
#include <IceUtil/StringUtil.h>
#include <MapStringDouble.h>

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

void
MapStringDoubleKeyCodec::write(const ::Demo::complexKeyPtr& v, Freeze::Key& bytes, const ::Ice::CommunicatorPtr& communicator, const Ice::EncodingVersion& encoding)
{
    IceInternal::InstancePtr instance = IceInternal::getInstance(communicator);
    IceInternal::BasicStream stream(instance.get(), encoding, true);
    stream.write(v);
    stream.writePendingObjects();
    ::std::vector<Ice::Byte>(stream.b.begin(), stream.b.end()).swap(bytes);
}

void
MapStringDoubleKeyCodec::read(::Demo::complexKeyPtr& v, const Freeze::Key& bytes, const ::Ice::CommunicatorPtr& communicator, const Ice::EncodingVersion& encoding)
{
    IceInternal::InstancePtr instance = IceInternal::getInstance(communicator);
    IceInternal::BasicStream stream(instance.get(), encoding, &bytes[0], &bytes[0] + bytes.size());
    stream.sliceObjects(false);
    stream.read(v);
    stream.readPendingObjects();
}

namespace
{
    const ::std::string __MapStringDoubleKeyCodec_typeId = "::Demo::complexKey";
}

const ::std::string&
MapStringDoubleKeyCodec::typeId()
{
    return __MapStringDoubleKeyCodec_typeId;
}

void
MapStringDoubleValueCodec::write(const ::Demo::StringDouble& v, Freeze::Value& bytes, const ::Ice::CommunicatorPtr& communicator, const Ice::EncodingVersion& encoding)
{
    IceInternal::InstancePtr instance = IceInternal::getInstance(communicator);
    IceInternal::BasicStream stream(instance.get(), encoding, true);
    stream.startWriteEncaps();
    stream.write(v);
    stream.endWriteEncaps();
    ::std::vector<Ice::Byte>(stream.b.begin(), stream.b.end()).swap(bytes);
}

void
MapStringDoubleValueCodec::read(::Demo::StringDouble& v, const Freeze::Value& bytes, const ::Ice::CommunicatorPtr& communicator, const Ice::EncodingVersion& encoding)
{
    IceInternal::InstancePtr instance = IceInternal::getInstance(communicator);
    IceInternal::BasicStream stream(instance.get(), encoding, &bytes[0], &bytes[0] + bytes.size());
    stream.startReadEncaps();
    stream.read(v);
    stream.endReadEncaps();
}

namespace
{
    const ::std::string __MapStringDoubleValueCodec_typeId = "::Demo::StringDouble";
}

const ::std::string&
MapStringDoubleValueCodec::typeId()
{
    return __MapStringDoubleValueCodec_typeId;
}
