/***************************************************************************
    begin                : Sep 21 2013
    copyright            : (C) 2013 Mirko Montanari
    email                : 57454@studenti.unimore.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include <iostream>
#include <Freeze/Freeze.h>
#include "MapByteSeq.h"
#include "MapFixedSeq.h"
#include "MapStringDouble.h"
#include "MapStringSeq.h"
#include "MapFloatSeq.h"
#include "MapDoubleSeq.h"
#include "mac_clock_gettime.h"

#define NCYCLES 100

using namespace std;

struct timespec start, stop;
struct timespec startg, stopg;

/// write and read the sequence of ByteSeq
/// \param[in] mapByte is the map of ByteSeq
void WriteByteSeq(MapByteSeq &mapByte){
	Demo::ByteSeq bSeq;
	for(int k=0; k<Demo::ByteSeqSize; k++)
		bSeq.push_back((Ice::Byte)(k%256));
	clock_gettime( CLOCK_MONOTONIC, &start);
	/// create the sequence of byte
	for(Ice::Int i=0; i<NCYCLES; i++){
		mapByte.insert(make_pair(i,bSeq));
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Write "<< NCYCLES <<" ByteSeq: MB/s " << (float) (NCYCLES * Demo::ByteSeqSize / time) / 1048576 << std::endl;
}

void ReadByteSeq(MapByteSeq &mapByte){
	/// reade the byte's db
	MapByteSeq::iterator p1;
	Demo::ByteSeq tmp;
	clock_gettime( CLOCK_MONOTONIC, &start);
	long ncycread = 0;
	for(p1=mapByte.begin(); p1!=mapByte.end(); ++p1) {
		tmp = p1->second;
		ncycread++;
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Read " << ncycread << " ByteSeq: MB/s " << (float) (ncycread * Demo::ByteSeqSize / time) / 1048576 << std::endl << std::endl;

}

/// write and read the FixedSeq
/// \param[in] mapFixed is the map of FixedSeq
void WriteReadFixedSeq(MapFixedSeq &mapFixed){
	Demo::Fixed fix[NCYCLES];
	for(Ice::Int i=0; i<NCYCLES; ++i){
		fix[i].i = i;
		fix[i].j = i;
		fix[i].d = (Ice::Double)i;
	}
	clock_gettime( CLOCK_MONOTONIC, &start);
	/// create the fixed's sequence and save in the db
	for(Ice::Int i=0; i<NCYCLES; ++i){
		mapFixed.insert(make_pair(i,fix[i]));
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Write " << NCYCLES << " FixedSeq: MB/s " << (float) (NCYCLES * (2*sizeof(int)+sizeof(double)) / time) / 1048576 << std::endl;

	/// read the fixed's db
	MapFixedSeq::iterator p2;
	clock_gettime( CLOCK_MONOTONIC, &start);
	for(p2=mapFixed.begin(); p2!=mapFixed.end(); ++p2)
		Demo::Fixed tmp = p2->second;
	clock_gettime( CLOCK_MONOTONIC, &stop);
	time = timediff(start, stop);
	std::cout << "Read " << NCYCLES << " FixedSeq: MB/s " << (float) (NCYCLES * (2*sizeof(int)+sizeof(double)) / time) / 1048576 << std::endl << std::endl;
}

/// write and read the sequence of StringDouble
/// \param[in] mapStrDo is the map of StringDouble
void WriteReadStringDouble(MapStringDouble &mapStrDo){
	Demo::StringDouble strdo;
	strdo.s = "prova";
	strdo.d = (Ice::Double)13;
	clock_gettime( CLOCK_MONOTONIC, &start);
	/// create the stringdouble sequence
	for(Ice::Int i=0; i<NCYCLES; ++i){
		mapStrDo.insert(make_pair(i,strdo));
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Write " << NCYCLES << " StringDouble: MB/s " << (float) (NCYCLES * (5+sizeof(double)) / time) / 1048576 << std::endl;

	/// reade the stringdouble db
	MapStringDouble::iterator p3;
	clock_gettime( CLOCK_MONOTONIC, &start);
	for(p3=mapStrDo.begin(); p3!=mapStrDo.end(); ++p3)
		Demo::StringDouble tmp = p3->second;
	clock_gettime( CLOCK_MONOTONIC, &stop);
	time = timediff(start, stop);
	std::cout << "Read " << NCYCLES << " StringDouble: MB/s " << (float) (NCYCLES * (5+sizeof(double)) / time) / 1048576 << std::endl << std::endl;
}

/// write and read the sequence of String
/// \param[in] mapStr is the map of the String
void WriteReadStringSeq(MapStringSeq &mapStr){
	Demo::StringSeq strs;
	for (int k=0; k<Demo::StringSeqSize; k++)
		strs.push_back("prova");
	clock_gettime( CLOCK_MONOTONIC, &start);
	/// create the sequence of strings and insert into the db
	for(Ice::Int i=0; i<NCYCLES; ++i){
		mapStr.insert(make_pair(i,strs));
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Write " << NCYCLES << " StringSeq: MB/s " << (float) (NCYCLES * 5 * Demo::StringSeqSize / time) / 1048576 << std::endl;

	/// read the stringseq's db
	MapStringSeq::iterator p4;
	clock_gettime( CLOCK_MONOTONIC, &start);
	for(p4=mapStr.begin(); p4!=mapStr.end(); p4++)
		Demo::StringSeq tmp = p4->second;
	clock_gettime( CLOCK_MONOTONIC, &stop);
	time = timediff(start, stop);
	std::cout << "Read " << NCYCLES << " StringSeq: MB/s " << (float) (NCYCLES * 5 * Demo::StringSeqSize / time) / 1048576 << std::endl << std::endl;
}

/// write and read a sequence of float
/// \param[in] mapFloat is a map of float sequence
void WriteFloatSeq(MapFloatSeq &mapFloat){
	Demo::FloatSeq fSeq;
	for(int k=0; k<Demo::FloatSeqSize; k++)
		fSeq.push_back((Ice::Float)k);
	clock_gettime( CLOCK_MONOTONIC, &start);
	/// create the sequence of float
	for(Ice::Int i=0; i<NCYCLES; i++){
		mapFloat.insert(make_pair(i,fSeq));
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Write "<< NCYCLES <<" FloatSeq: MB/s " << (float) (NCYCLES * sizeof(float) * Demo::FloatSeqSize / time) / 1048576 << std::endl;

}

void ReadFloatSeq(MapFloatSeq &mapFloat){

	/// read the float's db
	MapFloatSeq::iterator p5;
	Demo::FloatSeq tmp;
	long ncycread = 0;
	clock_gettime( CLOCK_MONOTONIC, &start);
	for(p5=mapFloat.begin(); p5!=mapFloat.end(); ++p5) {
		tmp = p5->second;
		ncycread++;
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Read " << ncycread << " FloatSeq: MB/s " << (float) (ncycread * sizeof(float) * Demo::FloatSeqSize / time) / 1048576 << std::endl << std::endl;
}


/// write and read a double sequence
/// \param[in] mapDouble is a map of double db sequence
void WriteReadDoubleSeq(MapDoubleSeq &mapDouble){
	Demo::DoubleSeq dSeq;
	for(int k=0; k<Demo::FloatSeqSize; k++)
		dSeq.push_back((Ice::Double)(k%256));
	clock_gettime( CLOCK_MONOTONIC, &start);
	/// create the sequence of double
	for(Ice::Int i=0; i<NCYCLES; i++){
		mapDouble.insert(make_pair(i,dSeq));
	}
	clock_gettime( CLOCK_MONOTONIC, &stop);
	double time = timediff(start, stop);
	std::cout << "Write "<< NCYCLES <<" DoubleSeq: MB/s " << (float) (NCYCLES * sizeof(double) * Demo::DoubleSeqSize / time) / 1048576 << std::endl;

	/// reade the double's db
	MapDoubleSeq::iterator p6;
	Demo::DoubleSeq tmp;
	clock_gettime( CLOCK_MONOTONIC, &start);
	for(p6=mapDouble.begin(); p6!=mapDouble.end(); ++p6)
		tmp = p6->second;
	clock_gettime( CLOCK_MONOTONIC, &stop);
	time = timediff(start, stop);
	std::cout << "Read " << NCYCLES << " DoubleSeq: MB/s " << (float) (NCYCLES * sizeof(double) * Demo::DoubleSeqSize / time) / 1048576 << std::endl << std::endl;
}

int main(int argc, char* argv[]){
	if(argc != 2) {
			cerr << "Please, provide the operation 0 (write) or 1 (read)" << endl;
			return 0;
	}

	bool operation = atoi(argv[1]);
	cout << "operation: " << operation << endl;

	/// start clock
	clock_gettime( CLOCK_MONOTONIC, &startg);

	/// set properties for db ice
	Ice::InitializationData initData;
	initData.properties = Ice::createProperties();
	initData.properties->load("config");

	/// initialize che Ice communicator
	Ice::CommunicatorPtr communicator = Ice::initialize(argc,argv,initData);

	/// create the Freeze's db with the BDB in disk
	Freeze::ConnectionPtr connection = Freeze::createConnection(communicator, "db");
	
	/// initialize the maps
	MapByteSeq mapByte(connection, "ByteSeq");
	MapFixedSeq mapFixed(connection, "FixedSeq");
	MapStringDouble mapStrDo(connection, "StringDouble");
	MapStringSeq mapStr(connection, "StringSeq");
	MapFloatSeq mapFloat(connection, "FloatSeq");
	MapDoubleSeq mapDouble(connection, "DoubleSeq");

	/// write and read the datas int the db
	if(operation == 0) {
		mapByte.clear();
		mapFixed.clear();
		mapStrDo.clear();
		mapStr.clear();
		mapFloat.clear();
		mapDouble.clear();
		WriteByteSeq(mapByte);
		//WriteReadFixedSeq(mapFixed);
		//WriteReadStringDouble(mapStrDo);
		//WriteReadStringSeq(mapStr);
		WriteFloatSeq(mapFloat);
		//WriteReadDoubleSeq(mapDouble);
	}
	if(operation == 1) {
		ReadByteSeq(mapByte);
		ReadFloatSeq(mapFloat);
	}

	/// stop the clock
	clock_gettime( CLOCK_MONOTONIC, &stopg);
	double time = timediff(startg, stopg);
	std::cout << "Total time: " << time << std::endl << std::endl;

	/// search a value of index x
	std::cout << "Insert the index to view from Fixed: ";
	string s;
	std::cin >> s;
	int index = atoi(s.c_str());
	MapFixedSeq::iterator p;
	p = mapFixed.find(index);
	std::cout << p->second.i << "\t" << p->second.j << "\t" << p->second.d << std::endl;

	/// view record max to i from FixedSeq
	std::cout <<"Insert value of 'i': ";
	std::cin >> s;
	int val = atoi(s.c_str());
	for(p=mapFixed.begin(); p!=mapFixed.end(); p++){
		if(p->second.i > val)
			std::cout << p->second.i << "\t" << p->second.j << "\t" << p->second.d << std::endl;
	}
	return 0;
}
