Test Ice/Freeze
=====================================

First test's project with Ice/Freeze

Note:
For use this script you must create the "db" directory if it's not present.


Guide to create a class Ice from .ice:
slice2cpp name_file.ice

for example:
slice2cpp demo.ice


Guide to create a Freeze's Map:
slice2freeze --dict name_map,type_key,type_value name_map optional_file_ice.ice

for example:
MapByteSeq: slice2freeze --dict MapByteSeq,int,Demo::ByteSeq MapByteSeq demo.ice
MapFloatSeq: slice2freeze --dict MapFloatSeq,int,Demo::FloatSeq MapFloatSeq demo.ice
MapDoubleSeq: slice2freeze --dict MapDoubleSeq,int,Demo::DoubleSeq MapDoubleSeq demo.ice
MapFixedSeq: slice2freeze --dict MapFixedSeq,int,Demo::Fixed MapFixedSeq demo.ice
MapFloatSeq: slice2freeze --dict MapFloatSeq,int,Demo::FloatSeq MapFloatSeq demo.ice
MapStringDouble: slice2freeze --dict MapStringDouble,int,Demo::StringDouble MapStringDouble demo.ice
MapStringSeq: slice2freeze --dict MapStringSeq,int,Demo::StringSeq MapStringSeq demo.ice

If you use an database BerkeleyDB in memory, you must use this command before start the program:
sudo mount tmpfs -t tmpfs db
